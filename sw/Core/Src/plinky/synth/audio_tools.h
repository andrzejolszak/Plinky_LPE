#pragma once
#include "utils.h"

#ifndef EMU
#define __STATIC_FORCEINLINE __attribute__((always_inline)) static inline
#define CORTEX
#else
#define __STATIC_FORCEINLINE static inline
#endif

#define RV_SIZE_MASK 16383
#define DL_SIZE_MASK 32767

#define FLOAT2FIXED(x, bits) ((int)((x) * (1 << (bits))))
#define STEREOUNPACK(lr) int lr##l = (s16)lr, lr##r = (s16)(lr >> 16);

__STATIC_FORCEINLINE
u32 STEREOPACK(s16 l, s16 r) {
#ifdef EMU
	return ((u16)l) + (((u16)r) << 16);
#else
	return __PKHBT(l, r, 16);
#endif
}

__STATIC_FORCEINLINE
s16 SATURATE16(s32 a) {
#ifdef EMU
	if (a < -32768)
		a = -32768;
	else if (a > 32767)
		a = 32767;
	return a;
#else
	return (s16)__SSAT(a, 16);
#endif
}

__STATIC_FORCEINLINE
s16 LINEARINTERPDL(const s16* buf, int basei, int wobpos) { // read buf[basei-wobpos>>12] basically
	basei -= wobpos >> 12;
	wobpos &= 0xfff;
	s16 a0 = buf[basei & DL_SIZE_MASK];
	s16 a1 = buf[(basei - 1) & DL_SIZE_MASK];

#ifdef EMU
	// dual mul
	return ((a0 * (0x1000 - wobpos) + a1 * wobpos)) >> 12;
#else
	u32 a = STEREOPACK(a1, a0);
	u32 b = STEREOPACK(wobpos, 0x1000 - wobpos);
	s32 out = __SMUAD(a, b);
	return out >> 12;
#endif
}

__STATIC_FORCEINLINE
u32 MIDSIDESCALE(u32 in, int midscale, int sidescale) {
	STEREOUNPACK(in);
	s32 mid = inl + inr;
	s32 side = inl - inr;
	mid = (mid * midscale) >> 17;
	side = (side * sidescale) >> 17;
	inl = mid + side;
	inr = mid - side;
	return STEREOPACK(inl, inr);
}

__STATIC_FORCEINLINE
u32 STEREOSCALE(u32 in, int scale) {
	STEREOUNPACK(in);
	return STEREOPACK((inl * scale) >> 16, (inr * scale) >> 16);
}

__STATIC_FORCEINLINE
u32 STEREOADDSAT(u32 a, u32 b) {
#ifdef EMU
	STEREOUNPACK(a);
	STEREOUNPACK(b);
	return STEREOPACK(SATURATE16(al + bl), SATURATE16(ar + br));
#else
	return __QADD16(a, b);
#endif
}

__STATIC_FORCEINLINE
u32 STEREOADDAVERAGE(u32 a, u32 b) {
#ifdef EMU
	STEREOUNPACK(a);
	STEREOUNPACK(b);
	return STEREOPACK((al + bl) >> 1, (ar + br) >> 1);
#else
	return __SHADD16(a, b);
#endif
}

__STATIC_FORCEINLINE
s16 LINEARINTERPRV(const s16* buf, int basei, int wobpos) { // read buf[basei-wobpos>>12] basically
	basei -= wobpos >> 12;
	wobpos &= 0xfff;
	s16 a0 = buf[basei & RV_SIZE_MASK];
	s16 a1 = buf[(basei - 1) & RV_SIZE_MASK];
#ifdef EMU
	return ((a0 * (0x1000 - wobpos) + a1 * wobpos)) >> 12;
#else
	u32 a = STEREOPACK(a1, a0);
	u32 b = STEREOPACK(wobpos, 0x1000 - wobpos);
	s32 out = __SMUAD(a, b);
	return out >> 12;
#endif
}

__STATIC_FORCEINLINE
s16 MONOSIGMOID(int in) {
	if (in == 0) {
		return 0;
	}

	in = SATURATE16(in);

	// -32768 .. +32767 -> 0 .. 65535
	u32 x = in + 32768;

	// Index: x / 64
	u32 i = x >> 6;

	// Remainder: x % 64
	u32 f = x & 63;

	s32 a = sigmoid[i];
	s32 b = sigmoid[i + 1];

	// Linear interpolate to the neares integer
	return (s16)(a + (((b - a) * f + 32) >> 6));
}

__STATIC_FORCEINLINE
u32 STEREOSIGMOID(int in) {
	if (in == 0)
	{
		return 0;
	}

	// -32768 .. +32767 -> 0 .. 65535
	u32 x = (s16)in + 32768;

	// Index: x / 64
	u32 i = x >> 6;

	// Remainder: x % 64
	u32 f = x & 63;

	s32 a = sigmoid[i];
	s32 b = sigmoid[i + 1];

	// Linear interpolate to the neares integer
	s16 l = (s16)(a + (((b - a) * f + 32) >> 6)); 

	// -32768 .. +32767 -> 0 .. 65535
	x = (s16)(in >> 16) + 32768;
	
	// Index: x / 64
	i = x >> 6;

	// Remainder: x % 64
	f = x & 63;

	a = sigmoid[i];
	b = sigmoid[i + 1];

	// Linear interpolate to the neares integer
	s16 r = (s16)(a + (((b - a) * f + 32) >> 6));

	return STEREOPACK(l, r);
}

// __STATIC_FORCEINLINE
// s16 MONOSIGMOIDold(int in) {
// 	in = SATURATE16(in);
// 	return sigmoidold[(u16)in];
// }
// 
// __STATIC_FORCEINLINE
// u32 STEREOSIGMOIDold(u32 in) {
// 	u16 l = sigmoidold[(u16)in];
// 	u16 r = sigmoidold[in >> 16];
// 	return STEREOPACK(l, r);
// }