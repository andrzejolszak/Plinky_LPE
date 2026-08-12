#pragma once
#include "utils.h"


// Codec/audio flow
void open_extensions_menu(void);
void press_extensions_menu_pad(u8 x, u8 y);
void extensions_encoder_press(bool pressed);
void edit_extensions_from_encoder(s8 end_diff);

// UI flow
void draw_extensions_menu(void);
void extensions_menu_leds(u8 pulse);