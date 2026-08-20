#include "oled.h"

u8 oled[OLED_BUFFER_SIZE];

void oled_init(void) {

#ifndef EMU
	// stablise power
	HAL_Delay(100);
#endif

	// ssd130x init settings
	ssd130x_init();
	// first element of the buffer is always 0x40
	oled[0] = 0x40;
	memset(&oled[1], 0, OLED_BUFFER_SIZE - 1);
}

void oled_clear(void) {
	memset(&oled[1], 0, OLED_BUFFER_SIZE - 1);
}

void oled_flip() {
	ssd130x_flip(oled);
}

void oled_flip_with_buffer(const u8* buffer) {
	ssd130x_flip(buffer);
}