#include "extensions_menu.h"
#include "gfx/gfx.h"
#include "hardware/leds.h"

int debug_display = -1;
int ext_skip = -1;

typedef enum Items {
	ITEM_0_TIMING,
	ITEM_1_SKIP,
	ITEMS_COUNT,
} Items;

static s8 item_values[ITEMS_COUNT] = { -1, -1 };
static s8 cur_item = 0;
static s8 cur_value = 0;
static bool value_selected = false;

static s8 get_item_idx(u8 x, u8 y) {
	if (x == 1 && y == 3)
		return ITEM_0_TIMING;
	if (x == 2 && y == 3)
		return ITEM_1_SKIP;

	return -1;
}

void extensions_menu_leds(u8 pulse) {
	memset(leds, 0, sizeof(leds));
	leds[1][3] = 32;
	leds[2][3] = 32;
	switch (cur_item) {
	case ITEM_0_TIMING:
		leds[1][3] = 255;
		break;
	case ITEM_1_SKIP:
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
	s8 minVal = 0;
	switch (cur_item) {
		case ITEM_0_TIMING:
			minVal = -1;
			maxVal = TIME_LOG_ITEMS - 1;
			break;
		case ITEM_1_SKIP:
		    minVal = -1;
			maxVal = 10;
			break;
		default:
			break;
	}

	if (cur_value + inc < minVal)
		cur_value = minVal;
	else if (cur_value + inc > maxVal) {
		cur_value = maxVal;
	}
	else {
		cur_value = cur_value + inc;
	}

	// Input/Audio thread
	item_values[cur_item] = cur_value;

	switch (cur_item) {
		case ITEM_0_TIMING:
			debug_display = cur_value;
			break;
		case ITEM_1_SKIP:
		    ext_skip = cur_value;
			break;
		default:
			break;
	}
}

static const char* get_param_str(s8 item, s8 value, char* val_buf) {
	switch (item) {
	case ITEM_0_TIMING:
		if (value == -1) {
			return "OFF";
		}
		else {
			sprintf(val_buf, "%d %s", value, debug_label[value]);
			return val_buf;
		}

	case ITEM_1_SKIP:
		if (value == -1) {
			return "OFF";
		}
		else {
			sprintf(val_buf, "idx_%d", value);
			return val_buf;
		}
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
	case ITEM_0_TIMING:
		item_name = "Timing";
		break;
	case ITEM_1_SKIP:
		item_name = "Skip";
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