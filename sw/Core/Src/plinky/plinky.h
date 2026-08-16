#pragma once
#include "utils.h"

#define FIRMWARE_VERSION "0.4.0"
#define GOLDEN_CHECKSUM 0xb5a7228c

#ifdef EMU
#include <io.h>
#include <windows.h>
static inline void HAL_Delay(int ms) {
	Sleep(ms);
}
int __builtin_popcount(int x);
int __builtin_popcountll(unsigned long long x);
int __builtin_ctz(unsigned long long x);
int __builtin_ctzll(unsigned long long x);

float powerout; // squared power
float gainhistoryrms[512];
int ghi;
float m_compressor;
int emupitchsense;
int emugatesense;
#endif

typedef enum HardwareVersion {
	HW_PLINKY,
	HW_PLINKY_PLUS,
} HardwareVersion;

typedef enum UIMode {
	UI_DEFAULT,       // regular playing mode
	UI_EDITING_A,     // editing any of the A parameters
	UI_EDITING_B,     // editing any of the B parameters
	UI_PTN_START,     // setting the start of the sequencer pattern
	UI_PTN_END,       // setting the end of the sequencer pattern
	UI_LOAD,          // load screen: preset / pattern / sample
	UI_SAMPLE_EDIT,   // sample edit screen
	UI_SETTINGS_MENU, // edit system settings
	UI_EXTENSIONS_MENU, // extensions settings
} UIMode;

typedef enum CalibMode {
	CALIB_NONE = 0,
	CALIB_TOUCH,
	CALIB_CV,
} CalibMode;

#define TIME_LOG_ITEMS 18
extern u32 debug_time[TIME_LOG_ITEMS];
extern const char* debug_label[TIME_LOG_ITEMS];
extern u32 log_time_diff(u32 prevMicros, u8 index);
extern int ext_skip;

extern HardwareVersion hw_version;
extern UIMode ui_mode;
extern CalibMode calib_mode;

#ifndef  EMU
void plinky_codec_tick(u32* audio_out, u32* audio_in);
void plinky_init(void);
void plinky_loop(void);
#endif