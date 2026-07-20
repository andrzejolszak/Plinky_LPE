#pragma once
#include "utils.h"

// This module manages ram and internal flash
//
// Flash is 256 pages of 2048 bytes each, holding:
// - 32 presets
// - 96 pattern quarters (24 patterns x 4)
// - 8 sample infos
// - 1 floating preset
// - 4 floating pattern quarters (1 pattern x 4)
// - 1 calibration page (fixed page id: 255)
//
// The system uses wear leveling to spread the pages out over page id 0-254
// Each of these pages holds a PageFooter and a recent copy of SysParams
//
// At any point, ram holds:
// - 1 preset
// - 1 full pattern (4 quarters)
// - 1 sample info
// - 1 set system parameters
//
// The preset and pattern quarters are floating. This means they do not directly represent any of the preset/pattern
// slots. Instead they exist as the current state of the device. Users can save the floating preset and pattern to a
// slot when desired. They can also (re)load saved patterns and preset slots into the floating items
//
// The preset, pattern quarters and sample info auto-save to flash when necessary and at set intervals. On each
// auto-save, a recent copy of sys_params is included

// ram contents
extern SysParams sys_params;
extern Preset cur_preset;
extern PatternQuarter cur_pattern_qtr[4];
extern SampleInfo cur_sample_info;
extern GlobalData global_data;

// utils
u32 get_sample_address(void);
u16 get_sys_param(SysParam param);
u8 sys_param_range(SysParam param);
bool set_sys_param(SysParam param, u16 value);

// web-editor
u8* preset_flash_ptr(u8 preset_id);
void load_preset(u8 preset_id, bool show_message);

// get ram state
bool preset_outdated(void);  // only for sequencer
bool pattern_outdated(void); // only for sequencer

// init
void check_bootloader_flash(void);
void init_memory(void);

// main
void memory_frame(void);
void revert_presets(void);
void system_reset(void);

// update ram
void log_ram_edit(MemSegment segment);
void update_preset_ram(void);
void update_pattern_ram(void);
void update_sample_ram(void);

// save/load
void apply_cued_mem_items(void);
void cue_mem_item(u8 item_id);

#ifdef EMU
#define FLASH_PAGE_SIZE 2048
extern u8 _flash[512 * 1024];
#define FLASH_ADDR_256 ((u32)&_flash)
#define FLASH_TYPEPROGRAM_DOUBLEWORD 0
// #define NOFILE
#ifndef NOFILE
FILE* _flashf;
#else
bool flashinited;
#endif
void openflash(void) {
#ifdef NOFILE
	if (flashinited)
		return;
	flashinited = true;
	memset(_flash, -1, sizeof(_flash));

#else
	if (_flashf)
		return;
	_flashf = fopen("flashmcu.raw", "rb");
	if (!_flashf) {
		memset(_flash, -1, sizeof(_flash));
		_flashf = fopen("flashmcu.raw", "wb");
		fwrite(_flash, sizeof(_flash), 1, _flashf);
		fclose(_flashf);
	}
	else {
		fread(_flash, sizeof(_flash), 1, _flashf);
		fclose(_flashf);
	}
	_flashf = fopen("flashmcu.raw", "r+b");
#endif
}

int HAL_FLASH_Program(int flags, uint32_t addr, uint64_t val) {
	addr -= (u32)FLASH_ADDR_256;
	if (addr >= sizeof(_flash))
		return 0;
	openflash();
	(*(uint64_t*)&_flash[addr]) = val;
#ifndef NOFILE
	fseek(_flashf, addr, SEEK_SET);
	fwrite(&val, 1, 8, _flashf);
	fflush(_flashf);
#endif
	return 0;
}
void HAL_FLASH_Unlock(void) {
}
void HAL_FLASH_Lock(void) {
#ifndef NOFILE
	if (_flashf)
		fflush(_flashf);
#endif
}
#pragma pack(push, 1)
typedef struct UF2_Block {
	// 32 byte header
	uint32_t magicStart0;
	uint32_t magicStart1;
	uint32_t flags;
	uint32_t targetAddr;
	uint32_t payloadSize;
	uint32_t blockNo;
	uint32_t numBlocks;
	uint32_t familyID; // or fileSize;
	uint8_t data[476];
	uint32_t magicEnd;
} UF2_Block;
static_assert(sizeof(UF2_Block) == 512, "?");
#pragma pack(pop)
void ApplyUF2File(const char* fname) {
	FILE* f = fopen(fname, "rb");
	if (!f)
		return;
	while (f) {
		UF2_Block blk;
		if (1 != fread(&blk, 512, 1, f))
			break;
		if (blk.magicStart0 != 0x0A324655)
			continue;
		if (blk.magicStart1 != 0x9E5D5157)
			continue;
		if (blk.magicEnd != 0x0AB16F30)
			continue;
		if ((blk.flags & 0x00002000) && blk.familyID != 0x00ff6919)
			continue;
		if (blk.payloadSize > 256)
			continue;
		if (blk.flags & 0x00000001)
			continue; // not main flash
		if (blk.targetAddr >= 0x08080000 && blk.targetAddr <= 0x08100000) {
			for (int i = 0; i < blk.payloadSize; i += 8) {
				HAL_FLASH_Program(0, FLASH_ADDR_256 + i + (blk.targetAddr - 0x08080000), *(uint64_t*)&blk.data[i]);
			}
		}
	}
	fclose(f);
}

#endif

// ui
bool press_mem_item(void);
void save_preset(void);

// calib
FlashCalibType flash_read_calib(void);
void flash_write_calib(FlashCalibType flash_calib_type);

// visuals
u8 draw_cued_preset_id(void);
u8 draw_preset_id(void);
u8 draw_cued_pattern_id(bool with_arp_icon);
void draw_pattern_id(bool with_arp_icon);
void draw_preset_name(u8 xtab);
void draw_ui_load_visuals(void);

u8 ui_load_led(u8 x, u8 y, u8 pulse1, u8 pulse2);