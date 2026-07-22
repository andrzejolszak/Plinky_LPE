#pragma once
#include "utils.h"

#ifndef EMU
extern TIM_HandleTypeDef htim3;
#endif

#ifdef EMU
enum {
	OUT_TRIGGER,
	OUT_CLOCK,
	OUT_PRESSURE,
	OUT_GATE,
	OUT_PITCHLO,
	OUT_PITCHHI,
};

int emucvouthist;
float emucvout[6][256];
float emupitchloopback;
#endif

#define ADC_CHANS 8
#define ADC_SAMPLES 8

static u16 adc_buffer[ADC_CHANS * ADC_SAMPLES];

ADC_DAC_Calib* adc_dac_calib_ptr(void);

void init_adc_dac(void);

u16 adc_get_raw(ADC_DAC_Index index);
float adc_get_smooth(ADCSmoothIndex index);

void adc_dac_tick(void);

// cv

bool new_seq_cv_gate(void);
bool cv_try_get_touch(u8 string_id, s16* pressure, s16* position, u8* note_number, s32* note_offset_pitch,
                      u8* start_velocity);
void send_cv_pitch(bool pitch_hi, u16 pitch);
void cv_calib(void);

// pwm cv outs take range 0-256 and generate 6.6V at 256

// 256 * 5 / 6.6 = 194, rounded up so that the measured voltage ends up at 5.00V
#define CV_OUT_5V 195

extern inline void send_cv_clock(bool high);

extern inline void send_cv_trigger(bool high);

extern inline void send_cv_gate(bool high);

extern inline void send_cv_pressure(u16 data);

// #define SENSE1_Pin GPIO_PIN_8
// #define SENSE1_GPIO_Port GPIOE
// #define SENSE2_Pin GPIO_PIN_15
// #define SENSE2_GPIO_Port GPIOE
//
// rj: this is ignoring MX_GPIO_Init() in main.c, could be cleaner after low level hardware setup cleanup

static inline bool cv_pitch_present(void) {
#ifdef EMU
	return emupitchsense;
#else
	return HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_15) == GPIO_PIN_RESET;
#endif
}