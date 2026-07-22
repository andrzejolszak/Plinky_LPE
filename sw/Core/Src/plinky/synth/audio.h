#pragma once
#include "utils.h"

// this module handles mixing audio levels throughout the synth and applying audio effects
#ifdef EMU
#define TWENTY_OVER_LOG2_10 6.02059991328f // (20.f/log2(10.f));
static inline float lin2db(float lin) {
	return log2f(lin) * TWENTY_OVER_LOG2_10;
}
static inline float db2lin(float db) {
	return exp2f(db * (1.f / TWENTY_OVER_LOG2_10));
}
#endif

#ifdef EMU
#define RVMASK 16383
#define DLMASK 32767
extern short reverb_ram_buf[RVMASK + 1];
extern short delay_ram_buf[DLMASK + 1];
#else
extern short* reverb_ram_buf;
extern short* delay_ram_buf;
#endif

// sampler stuff
extern s16 audio_in_peak;
extern s16 audio_in_hold;
void reverb_clear(void);
void delay_clear(void);

// possibly move to sampler

extern ValueSmoother ext_gain_smoother;
void init_ext_gain_for_recording(void);

// helpers

u32 delay_samples_from_param(u32 param_val);

// main

void init_audio(void);
void audio_pre(u32* audio_out, u32* audio_in);
void audio_post(u32* audio_out, u32* audio_in);
