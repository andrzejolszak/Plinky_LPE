#pragma once
#include "utils.h"

// this manages drawing visuals on the oled display

#ifdef EMU
void flash_message(Font fnt, const char* msg_fmt, const char* submsg, ...);
#else
void flash_message(Font fnt, const char* msg_fmt, const char* submsg, ...) __attribute__((format(printf, 2, 0)));
#endif

void clear_scope_pixel(u8 x);
void put_scope_pixel(u8 x, u8 y);

void draw_oled_visuals(void);
