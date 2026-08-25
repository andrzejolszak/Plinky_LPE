#pragma once
#include "utils.h"

#define WAVETABLE_SIZE (1022 + 9) // 9 octaves, top octave is 512 samples
#define NUM_WAVETABLES 17

extern const float lpf_ks[1025];
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

#ifndef EMU
#define __STATIC_FORCEINLINE __attribute__((always_inline)) static inline
#define CORTEX
#else
#define __STATIC_FORCEINLINE static inline
#endif

__STATIC_FORCEINLINE
u16 SATURATEU16(s32 a) {
#ifdef EMU
	if (a < 0)
		a = 0;
	else if (a > 65535)
		a = 65535;
	return a;
#else
	int tmp;
	asm("usat %0, %1, %2" : "=r"(tmp) : "I"(16), "r"(a));
	return tmp;
#endif
}

// 16 bit unsigned input, looked up in a 1024 entry table and linearly interpolated
__STATIC_FORCEINLINE
float table_interp(const float* table, int x) {
	x = SATURATEU16(x);
	table += x >> 6;
	x &= 63;
	float zeroEl = table[0];
	return zeroEl + (table[1] - zeroEl) * (x * (1.f / 64.f));
}

__STATIC_FORCEINLINE
float lpf_k(int x) {
	return table_interp(lpf_ks, x);
}
