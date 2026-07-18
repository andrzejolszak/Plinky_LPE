#include "plinky.h"
#include "gfx/gfx.h"
#include "hardware/accelerometer.h"
#include "hardware/adc_dac.h"
#include "hardware/codec.h"
#include "hardware/encoder.h"
#include "hardware/leds.h"
#include "hardware/memory.h"
#include "hardware/midi.h"
#include "hardware/spi.h"
#include "hardware/touchstrips.h"
#include "synth/arp.h"
#include "synth/audio.h"
#include "synth/params.h"
#include "synth/sampler.h"
#include "synth/sequencer.h"
#include "synth/synth.h"
#include "synth/time.h"
#include "ui/led_viz.h"
#include "ui/oled_viz.h"
#include "ui/pad_actions.h"
#include "ui/settings_menu.h"
#include "usb/usb.h"

u32 debug_time[TIME_LOG_ITEMS];
const char* debug_label[TIME_LOG_ITEMS] = {"ts",     "au_pre", "pr_ram", "seq",    "s_tch", "prm_t",
                                           "sp_ram", "vcs",    "spi",    "au_pst", "frame", "fps"};

UIMode ui_mode = UI_DEFAULT;

HardwareVersion hw_version;

CalibMode calib_mode = CALIB_NONE;

#ifdef EMU
uint32_t emupixels[128 * 32];
void OledFlipEmu(const u8* vram) {
	if (!vram)
		return;
	const u8* src = vram + 1;
	for (int y = 0; y < 32; y += 8) {
		for (int x = 0; x < 128; x++) {
			u8 b = *src++;
			for (int yy = 0; yy < 8; ++yy) {
				u32 c = (b & 1) ? 0xffffffff : 0xff000000;
				int y2 = y + yy;
#ifdef ROTATE_OLED
				// pixels[(y2 + (127-x) * 32)] = c; // rotated, pins at bottom
				emupixels[((31 - y2) + x * 32)] = c; // rotated, pins at top
#else
				emupixels[(y2 * 128 + x)] = c;
#endif
				b >>= 1;
			}
		}
	}
}

int* getemubitmap(void) {
	return (int*)emupixels;
}
uint8_t* getemuleds() {
	return (uint8_t*)leds;
}

u8 emuleds[9][8];
int16_t accel_raw[3];
float accel_lpf[2];
float accel_smooth[2];
bool web_serial_connected = false;
void tud_task(void) {
}

#endif

void emu_setadc(float araw, float braw, float pitchcv, float gatecv, float xcv, float ycv,
                                     float acv, float bcv, int gateforce, int pitchsense, int gatesense) {
#ifdef EMU
	emupitchsense = pitchsense;
	emugatesense = gatesense;
#endif
	u16* a = adc_buffer;
	for (int i = 0; i < 8; ++i) {
		a[0] = clampi((int)(52100 - 9334.83f * pitchcv * 1.f / 12.f), 0, 65535);
		a[1] = gateforce ? 0 : clampi((int)(31716 - 6548.11f * gatecv), 0, 65535);
		a[2] = clampi((int)(31665 - 6548.11f * xcv), 0, 65535);
		a[3] = clampi((int)(31666 - 6548.11f * ycv), 0, 65535);
		a[4] = clampi((int)(31041 - 6548.11f * acv), 0, 65535);
		a[5] = clampi((int)(31712 - 6548.11f * bcv), 0, 65535);
		a[7] = (u16)((1.f - araw) * 65535);
		a[6] = (u16)((1.f - braw) * 65535);
		a += 8;
	}
}

#ifdef EMU
#define TWENTY_OVER_LOG2_10 6.02059991328f // (20.f/log2(10.f));
static inline float lin2db(float lin) { return log2f(lin) * TWENTY_OVER_LOG2_10; }
static inline float db2lin(float db) { return exp2f(db * (1.f / TWENTY_OVER_LOG2_10)); }
#define STEREOUNPACK(lr) int lr##l = (s16)lr, lr##r = (s16)(lr >> 16);
float m_compressor, m_dry, m_audioin, m_dry2wet, m_delaysend, m_delayreturn, m_reverbin, m_reverbout, m_fxout, m_output;
void MONITORPEAK(float* mon, u32 stereoin) {
	STEREOUNPACK(stereoin);
	float peak = (1.f / 32768.f) * maxi(abs(stereoinl), abs(stereoinr));
	if (peak > *mon)
		*mon = peak;
	else
		*mon += (peak - *mon) * 0.0001f;
}
#else
#define MONITORPEAK(mon, stereoin)
#endif

static void define_hardware_version(void) {
#ifdef EMU
	hw_version = HW_PLINKY;
	return;
#else
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_PIN_1;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	HAL_Delay(1);
	GPIO_PinState state = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1);
	hw_version = state == GPIO_PIN_SET ? HW_PLINKY_PLUS : HW_PLINKY;
#endif
}

static void open_usb_bootloader(void) {
	oled_clear();
	draw_str(0, 0, F_16_BOLD, "Re-flash");
	draw_str(0, 16, F_16, "over USB DFU");
	oled_flip();

#ifdef EMU
	return;
#else
	HAL_Delay(100);

	// https://community.st.com/s/question/0D50X00009XkeeW/stm32l476rg-jump-to-bootloader-from-software
	typedef void (*pFunction)(void);
	pFunction JumpToApplication;
	HAL_RCC_DeInit();
	HAL_DeInit();
	SysTick->CTRL = 0;
	SysTick->LOAD = 0;
	SysTick->VAL = 0;
	__disable_irq();
	__DSB();
	__HAL_SYSCFG_REMAPMEMORY_SYSTEMFLASH(); /* Remap is bot visible at once. Execute some unrelated command! */
	__DSB();
	__ISB();
	JumpToApplication = (void (*)(void))(*((uint32_t*)(0x1FFF0000 + 4)));
	__set_MSP(*(__IO uint32_t*)0x1FFF0000);
	JumpToApplication();
#endif
}

static void launch_calib(u8 phase) {
	static u16 knob_a_start = 0;
	static u16 knob_b_start = 0;

	switch (phase) 
	{
		// first phase: auto-launch calibration if none found, save knob values
		case 0: 
		{
			FlashCalibType flash_calib_type = flash_read_calib();
			if (!(flash_calib_type & FLASH_CALIB_TOUCH))
				touch_calib(flash_calib_type | FLASH_CALIB_TOUCH);
			if (!(flash_calib_type & FLASH_CALIB_ADC_DAC))
				cv_calib();
			HAL_Delay(80);
			knob_a_start = adc_get_raw(ADC_A_KNOB);
			knob_b_start = adc_get_raw(ADC_B_KNOB);
			break;
		}
		// second phase: launch calib/bootloader based on knob turns
		case 1:
		{
			u16 knob_a_delta = abs(knob_a_start - adc_get_raw(ADC_A_KNOB));
			u16 knob_b_delta = abs(knob_b_start - adc_get_raw(ADC_B_KNOB));
			if (knob_a_delta > 4096 && knob_b_delta > 4096)
				open_usb_bootloader();
			// legacy implementation, calibration can now be called from the settings menu
			if (knob_a_delta > 4096)
				touch_calib(FLASH_CALIB_COMPLETE);
			if (knob_b_delta > 4096)
				cv_calib();
			if (knob_a_delta > 4096 || knob_b_delta > 4096) {
				draw_logo();
				leds_bootswish();
			}
			break;
		}
	}
}

void plinky_init(void) {
	init_accel();
	define_hardware_version();
	init_gfx(); // including oled
	check_bootloader_flash();
	init_touchstrips();
	init_audio();
	init_codec();
	init_adc_dac();
	init_spi();
	init_memory();
	init_midi();
	init_usb();
	init_leds();
	launch_calib(0);
	leds_bootswish();
	launch_calib(1);
	init_encoder();
	init_synth();

#ifdef EMU
	emu_setadc(0.5f, 0.5f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, false, false, false);
#endif
#ifdef EMU
	void EmuStartSound(void);
	EmuStartSound();
#endif
}

static void log_time(void) {
	static u8 index = 0;
	static u32 frame_start = 0;
	static u32 last_us = 0;
	u32 new_us = micros();
	// frame start
	if (index == 0)
		frame_start = new_us;
	// log section
	else
		debug_time[index - 1] = new_us - last_us;
	// last section (logs section and full frame time)
	if (index == TIME_LOG_ITEMS - 2)
		debug_time[index] = new_us - frame_start;
	last_us = new_us;
	// leave last index open for the slow frame fps
	index = (index + 1) % (TIME_LOG_ITEMS - 1);
}

// this runs with precise audio timing
void plinky_codec_tick(u32* audio_out, u32* audio_in) {
	log_time();

	// read physical touches
	u8 read_phase = read_touchstrips();

	log_time();

	// once per touchstrip read cycle:
	if (!read_phase) {
		encoder_tick();
		pad_actions_frame();
	}

	// update all leds
	leds_update();

	// pre-process audio
	audio_pre(audio_out, audio_in);

	log_time();

	// don't do anything else while calibrating
	if (calib_mode)
		return;

	// in the process of recording a new sample
	if (sampler_mode > SM_PREVIEW) {
		// handle recording audio and exit
		sampler_recording_tick(audio_out, audio_in);
		return;
	}

	// make sure preset ram is up to date
	update_preset_ram();

	log_time();

	// midi
	midi_tick();

	// adc / dac
	adc_dac_tick();

	// clock
	clock_tick();

	// sequencer
	seq_tick();

	log_time();

	// combine physical, latch, sequencer, arp touches
	generate_string_touches();

	log_time();

	// evaluate parameters and modulations
	params_tick();

	log_time();

	// make sure sample and pattern ram is up to date
	update_sample_ram();
	update_pattern_ram();

	log_time();

	// generate the voices, based on touches and parameters
	handle_synth_voices(audio_out);

	log_time();

	// restart spi loop if necessary
	spi_tick();

	log_time();

	// apply audio effects and send result to output buffer
	audio_post(audio_out, audio_in);

	log_time();
}

// this is the main loop, only code that is blocking in some way lives here
#if defined(TIME_LOGGING) || defined(FPS_WINDOW)
void plinky_loop(void) {
	while (1) {
		// save frame fps to last debug item
		static u32 last_us = 0;
		u32 new_us = micros();
		debug_time[TIME_LOG_ITEMS - 1] = 100000000 / (new_us - last_us); // 100x fps
		last_us = new_us;

#ifdef TIME_LOGGING
		// serial log one saved  item per loop
		static u8 log_index = 0;
		if (log_index == TIME_LOG_ITEMS)
			debug_log("Frame Start\n");
		else
			debug_log("%s %u\n", debug_label[log_index], debug_time[log_index]);
		log_index = (log_index + 1) % (TIME_LOG_ITEMS + 1);
#endif
#else

void plinky_loop(void) {
	while (1) {
#endif
		// set output volume
		codec_update_volume();
		// handle spi flash writes for the sampler
		if (ui_mode == UI_SAMPLE_EDIT) {
			switch (sampler_mode) {
			case SM_ERASING:
				// this fully blocks the loop until the sample is erased, also draws its own visuals
				clear_flash_sample();
				break;
			case SM_RECORDING:
			case SM_STOPPING1:
			case SM_STOPPING2:
			case SM_STOPPING3:
			case SM_STOPPING4:
				// pump blocks of the ram delay buffer to spi flash
				write_flash_sample_blocks();
			default:
				break;
			}
		}
		// visuals
		take_param_snapshots();
		draw_oled_visuals();
		draw_led_visuals();
		// read accelerometer values
		accel_read();
		// ram updates and writing ram to flash
		memory_frame();
		// web editor and usd midi data
		usb_frame();
		// execute actions triggered by setting menu
		settings_menu_actions();
	}
}