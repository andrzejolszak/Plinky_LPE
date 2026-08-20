#pragma once
#include "utils.h"
#include "SSD130x.h"

// first element of the buffer is always 0x40, hence refer to as oled + 1
extern u8 oled[OLED_BUFFER_SIZE];

void oled_init(void);
void oled_clear(void);
void oled_flip(void);
void oled_flip_with_buffer(const u8* buffer);