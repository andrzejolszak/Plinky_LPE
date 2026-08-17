#pragma once
#include "utils.h"

#define WAVETABLE_SIZE (1022 + 9) // 9 octaves, top octave is 512 samples
#define NUM_WAVETABLES 17

extern const u8 zero[2048];
extern const float pitches[1025];
extern const short sigmoid[1026];
// extern const short sigmoidold[65536];

// TODO: flash space optimization opportunity here, 32K should be very easy to fetch, probably more possible
extern const u8 rndtab[65536];
extern const u16 wavetable_octave_offset[17];

extern
#ifndef EMU
__attribute__((section(".wavetableSection")))
#endif
const short wavetable[NUM_WAVETABLES][WAVETABLE_SIZE];

extern const u8 steps_in_scale[NUM_SCALES];
extern const u16 scale_table[NUM_SCALES][12];

float table_interp(const float* table, int x);
float lpf_k(int x);