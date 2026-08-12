#include "extensions_menu.h"
#include "gfx/gfx.h"
#include "hardware/adc_dac.h"
#include "hardware/leds.h"
#include "hardware/memory.h"
#include "hardware/midi.h"
#include "hardware/touchstrips.h"
#include "synth/synth.h"
#include "ui/oled_viz.h"

typedef enum Items {
	ITEM_0_DEBUG,
	ITEM_1_TEST,
	ITEMS_COUNT,
} Items;

static u8 item_values[ITEMS_COUNT] = { 0 };
static s8 cur_item = 0;
static u8 cur_value = 0;
static bool value_selected = false;

static s8 get_item_idx(u8 x, u8 y) {
	if (x == 1 && y == 3)
		return ITEM_0_DEBUG;
	if (x == 2 && y == 3)
		return ITEM_1_TEST;

	return -1;
}

void extensions_menu_leds(u8 pulse) {
	memset(leds, 0, sizeof(leds));
	leds[1][3] = 64;
	leds[2][3] = 64;
	switch (cur_item) {
	case ITEM_0_DEBUG:
		leds[1][3] = 255;
		break;
	case ITEM_1_TEST:
		leds[2][3] = 255;
		break;
	default:
		break;
	}
	// pulse extensions pad
	leds[4][7] = pulse;
}

static void save_value(s8 enc_diff) {
	s8 inc = enc_diff > 0 ? 1 : -1;
	s8 maxVal = 1;
	switch (cur_item) {
	case ITEM_0_DEBUG:
		maxVal = 1;
		break;
	case ITEM_1_TEST:
		maxVal = 2;
		break;
	default:
		break;
	}

	if (cur_value + inc < 0)
		cur_value = 0;
	else if (cur_value + inc > maxVal) {
		cur_value = maxVal;
	}
	else {
		cur_value = cur_value + inc;
	}

	// Input/Audio thread
	item_values[cur_item] = cur_value;
}

static const char* get_param_str(s8 item, u8 value, char* val_buf) {
	switch (item) {
	case ITEM_0_DEBUG:
		return value ? "Yes" : "No";
	case ITEM_1_TEST:
		switch (value) {
			case 0:
				return "x0";
			case 1:
				return "x1";
			case 2:
				return "x2";
		}
		return val_buf;
	default:
		sprintf(val_buf, "%d", value);
		return val_buf;
	}
}

void open_extensions_menu(void) {
	ui_mode = UI_EXTENSIONS_MENU;
	cur_value = item_values[cur_item];
	value_selected = false;
}

static void select_item(s8 item_idx) {
	cur_item = item_idx;
	cur_value = item_values[item_idx];
}

void press_extensions_menu_pad(u8 x, u8 y) {
	s8 item_idx = get_item_idx(x, y);
	if (item_idx >= 0)
		select_item(item_idx);
}

void extensions_encoder_press(bool pressed) {
	static bool enc_pressed = false;
	if (pressed && !enc_pressed)
		value_selected = !value_selected;
	enc_pressed = pressed;
}

void edit_extensions_from_encoder(s8 enc_diff) {
	// edit value
	if (value_selected) {
		save_value(enc_diff);
		return;
	}

	// edit item selection
	while (enc_diff > 0) {
		if (cur_item + 1 >= ITEMS_COUNT) {
			break;
		}
		cur_item++;
		enc_diff--;
	}
	while (enc_diff < 0) {
		if (cur_item - 1 < 0) {
			break;
		}
		cur_item--;
		enc_diff--;
	}

	select_item(cur_item);
}

void draw_extensions_menu(void) {
	// "extensions"
	draw_str(79, 1, F_8, "EXTENSIONS");
	vline(OLED_WIDTH / 2, 0, 9, 1);
	vline(OLED_WIDTH - 1, 0, 9, 1);
	hline(OLED_WIDTH / 2, 9, OLED_WIDTH, 1);
	draw_str(1, 0, F_16_BOLD, "Ext");
	Font font = F_16;

	// selection arrow
	const u8 arrow_width = 15;
	draw_str(value_selected ? 113 : 0, 15, font, value_selected ? I_LEFT : I_RIGHT);
	// name
	char* item_name = "?";
	switch (cur_item) {
	case ITEM_0_DEBUG:
		item_name = "Debug";
		break;
	case ITEM_1_TEST:
		item_name = "Test";
		break;
	default:
		item_name = "?";
	}
	draw_str(2 + (value_selected ? 0 : arrow_width), 16, font, item_name);

	u8 right_offset = OLED_WIDTH - 1 - (value_selected ? arrow_width : 0);
	char val_buf[16];
	const char* val_str = get_param_str(cur_item, cur_value, val_buf);
	u8 width = str_width(font, val_str);
	draw_str(right_offset - width, 16, font, val_str);
}