#pragma once
#include "utils.h"

// this module manages physical touches on the touch-sensors
// - we define nine touchstrips (8 synth columns + 1 function strip), each of which have two capacitive sensors
// - each touchstrip gets read up to two times per cycle, leading to 18 touch readings and 36 saved sensor values
// - after processing, these readings are reduced to 9 touches

#ifdef EMU
int htsc;
typedef struct TSC_IOConfigTypeDef {
	u32 ChannelIOs;
	u32 SamplingIOs;
} TSC_IOConfigTypeDef;
typedef int TSC_GroupStatusTypeDef;
#define TSC_GROUP1_IO1 (1 << 0)
#define TSC_GROUP1_IO2 (1 << 1)
#define TSC_GROUP1_IO3 (1 << 2)
#define TSC_GROUP1_IO4 (1 << 3)
#define TSC_GROUP2_IO1 (1 << 4)
#define TSC_GROUP2_IO2 (1 << 5)
#define TSC_GROUP2_IO3 (1 << 6)
#define TSC_GROUP2_IO4 (1 << 7)
#define TSC_GROUP3_IO1 (1 << 8)
#define TSC_GROUP3_IO2 (1 << 9)
#define TSC_GROUP3_IO3 (1 << 10)
#define TSC_GROUP3_IO4 (1 << 11)
#define TSC_GROUP4_IO1 (1 << 12)
#define TSC_GROUP4_IO2 (1 << 13)
#define TSC_GROUP4_IO3 (1 << 14)
#define TSC_GROUP4_IO4 (1 << 15)
#define TSC_GROUP5_IO1 (1 << 16)
#define TSC_GROUP5_IO2 (1 << 17)
#define TSC_GROUP5_IO3 (1 << 18)
#define TSC_GROUP5_IO4 (1 << 19)
#define TSC_GROUP6_IO1 (1 << 20)
#define TSC_GROUP6_IO2 (1 << 21)
#define TSC_GROUP6_IO3 (1 << 22)
#define TSC_GROUP6_IO4 (1 << 23)
#define TSC_GROUP7_IO1 (1 << 24)
#define TSC_GROUP7_IO2 (1 << 25)
#define TSC_GROUP7_IO3 (1 << 26)
#define TSC_GROUP7_IO4 (1 << 27)

#define ENABLE 1
#define TSC_GROUP_COMPLETED 1
u32 _chanios;
void HAL_TSC_IOConfig(int* htsc, TSC_IOConfigTypeDef* config);
void HAL_TSC_IODischarge(int* htsc, int enable);
void HAL_TSC_Start(int* htsc);
void HAL_TSC_Stop(int* htsc);
TSC_GroupStatusTypeDef HAL_TSC_GroupGetStatus(int* htsc, int groupidx);
short HAL_TSC_GroupGetValue(int* htsc, int groupidx);
#endif

u8 get_touch_frame(void);
u16 get_strip_touched(void);
const Touch* get_touch(u8 touch_id, u8 frames_back);
void fill_latch(u8 touch_id, LatchTouch* latch_touch);

// main

void init_touchstrips(void);
u8 read_touchstrips(void);

// calib

TouchCalibData* touch_calib_ptr(void);
void touch_calib(FlashCalibType flash_calib_type);
