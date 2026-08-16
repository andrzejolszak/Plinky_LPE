# Complete Memory Usage Report - RAM and FLASH Sections

## Quick Navigation

- [.bss Section Summary](#summary-by-module)
- [.data Section Summary](#summary-by-module-1)
- [.rodata Section Summary](#summary-by-module-2)

---

## RAM Section Overview

| Section | Actual Size | Parsed Size | Discrepancy | % of Total |
|---------|-------------|-------------|-------------|------------|
| .data (initialized) | 584 bytes | 452 bytes | 132 bytes | 1.8% |
| .bss (uninitialized) | 29,736 bytes | 29,372 bytes | 364 bytes | 90.5% |
| ._user_heap_stack | 1,536 bytes | N/A | N/A | 4.7% |

**Total RAM Used:** 31,856 bytes (31.11 KB)
**Total Parsed:** 29,824 bytes (29.12 KB)
**Total Discrepancy:** 496 bytes (0.48 KB) - padding/alignment/library

**Available RAM:** 32,768 bytes (32 KB)
v **Free RAM:** 912 bytes (0.89 KB)

---

## .bss Section (Uninitialized Data)

### Summary by Module

| **Module** | **.bss (bytes)** | **% of 32KB RAM** | **Num Variables** |
|--------|--------------|---------------|---------------|
| [`plinky/hardware/memory`](#plinkyhardwarememory) | 10,826 | 33.0% | 16 |
| [`plinky/synth/synth`](#plinkysynthsynth) | 7,291 | 22.3% | 34 |
| [`main`](#main) | 2,676 | 8.2% | 22 |
| [`plinky/hardware/touchstrips`](#plinkyhardwaretouchstrips) | 1,170 | 3.6% | 15 |
| [`plinky/gfx/oled/oled`](#plinkygfxoledoled) | 1,036 | 3.2% | 5 |
| [`plinky/hardware/codec`](#plinkyhardwarecodec) | 1,024 | 3.1% | 2 |
| [`plinky/synth/params`](#plinkysynthparams) | 812 | 2.5% | 18 |
| [`plinky/hardware/midi`](#plinkyhardwaremidi) | 602 | 1.8% | 46 |
| [`plinky/ui/oled_viz`](#plinkyuioled_viz) | 558 | 1.7% | 6 |
| [`plinky/hardware/spi`](#plinkyhardwarespi) | 527 | 1.6% | 5 |
| [`plinky/ui/led_viz`](#plinkyuiled_viz) | 518 | 1.6% | 6 |
| [`plinky/usb/tinyusb/src/class/vendor/vendor_device`](#plinkyusbtinyusbsrcclassvendorvendor_device) | 428 | 1.3% | 1 |
| [`plinky/usb/tinyusb/src/class/midi/midi_device`](#plinkyusbtinyusbsrcclassmidimidi_device) | 312 | 1.0% | 1 |
| [`plinky/usb/tinyusb/src/device/usbd`](#plinkyusbtinyusbsrcdeviceusbd) | 260 | 0.8% | 5 |
| [`plinky/hardware/adc_dac`](#plinkyhardwareadc_dac) | 236 | 0.7% | 8 |
| [`plinky/usb/tinyusb/src/portable/st/synopsys/dcd_synopsys`](#plinkyusbtinyusbsrcportablestsynopsysdcd_synopsys) | 160 | 0.5% | 5 |
| [`plinky/synth/audio`](#plinkysynthaudio) | 124 | 0.4% | 35 |
| [`plinky/synth/lfos`](#plinkysynthlfos) | 124 | 0.4% | 6 |
| [`plinky/synth/time`](#plinkysynthtime) | 88 | 0.3% | 28 |
| [`plinky/usb/tinyusb/src/device/usbd_control`](#plinkyusbtinyusbsrcdeviceusbd_control) | 84 | 0.3% | 2 |
| [`plinky/plinky`](#plinkyplinky) | 80 | 0.2% | 6 |
| [`plinky/synth/sampler`](#plinkysynthsampler) | 78 | 0.2% | 12 |
| [`plinky/hardware/leds`](#plinkyhardwareleds) | 73 | 0.2% | 2 |
| [`plinky/usb/tinyusb/src/usb_descriptors`](#plinkyusbtinyusbsrcusb_descriptors) | 64 | 0.2% | 1 |
| [`plinky/synth/sequencer`](#plinkysynthsequencer) | 51 | 0.2% | 12 |
| [`plinky/synth/arp`](#plinkysyntharp) | 29 | 0.1% | 9 |
| [`plinky/hardware/accelerometer`](#plinkyhardwareaccelerometer) | 28 | 0.1% | 4 |
| [`plinky/hardware/encoder`](#plinkyhardwareencoder) | 23 | 0.1% | 8 |
| [`plinky/usb/web_editor`](#plinkyusbweb_editor) | 22 | 0.1% | 4 |
| [`plinky/ui/pad_actions`](#plinkyuipad_actions) | 21 | 0.1% | 9 |
| [`plinky/hardware/midi_sysex`](#plinkyhardwaremidi_sysex) | 18 | 0.1% | 7 |
| [`plinky/usb/tinyusb/src/usbmidi`](#plinkyusbtinyusbsrcusbmidi) | 8 | 0.0% | 2 |
| [`plinky/ui/settings_menu`](#plinkyuisettings_menu) | 6 | 0.0% | 6 |
| [`plinky/ui/extensions_menu`](#plinkyuiextensions_menu) | 4 | 0.0% | 4 |
| [`stm32l4xx_hal_msp`](#stm32l4xx_hal_msp) | 4 | 0.0% | 1 |
| [`sysmem`](#sysmem) | 4 | 0.0% | 1 |
| [`plinky/usb/usb`](#plinkyusbusb) | 2 | 0.0% | 2 |
| [`plinky/usb/tinyusb/src/tusb`](#plinkyusbtinyusbsrctusb) | 1 | 0.0% | 1 |
| **TOTAL** | **29,372** | **89.6%** | **357** |

### Per-Module Breakdown

#### plinky/hardware/memory

**Total:** 10,826 bytes (10.57 KB) | **Variables:** 16

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `cur_pattern_qtr` | 7,168 | 66.2% | 21.88% |
| `cur_preset` | 2,016 | 18.6% | 6.15% |
| `cur_sample_info` | 1,072 | 9.9% | 3.27% |
| `global_data` | 304 | 2.8% | 0.93% |
| `lastest_flash_page_id` | 142 | 1.3% | 0.43% |
| `last_flash_write` | 32 | 0.3% | 0.10% |
| `last_ram_write` | 32 | 0.3% | 0.10% |
| `recent_load_msg` | 24 | 0.2% | 0.07% |
| `sys_params` | 16 | 0.1% | 0.05% |
| `recent_load_time` | 4 | 0.0% | 0.01% |
| `next_footer_seq` | 4 | 0.0% | 0.01% |
| `next_free_flash_page (3 padding)` | 4 | 0.0% | 0.01% |
| `force_load_preset (2 padding)` | 3 | 0.0% | 0.01% |
| `flash_busy (2 padding)` | 3 | 0.0% | 0.01% |
| `force_load_pattern` | 1 | 0.0% | 0.00% |
| `ram_initialized` | 1 | 0.0% | 0.00% |
| **TOTAL** | **10,826** | **100.0%** | **33.04%** |

#### plinky/synth/synth

**Total:** 7,291 bytes (7.12 KB) | **Variables:** 34

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `grain_buf` | 4,352 | 59.7% | 13.28% |
| `voices` | 1,600 | 21.9% | 4.88% |
| `synth_string` | 512 | 7.0% | 1.56% |
| `touch_sorted` | 256 | 3.5% | 0.78% |
| `touch_frames` | 256 | 3.5% | 0.78% |
| `grain_pos` | 128 | 1.8% | 0.39% |
| `grain_buf_end (4 padding)` | 68 | 0.9% | 0.21% |
| `string_hash.12` | 16 | 0.2% | 0.05% |
| `start_step.13` | 16 | 0.2% | 0.05% |
| `root_pitch.14` | 16 | 0.2% | 0.05% |
| `buf.2 (3 padding)` | 8 | 0.1% | 0.02% |
| `multisampletime.3` | 8 | 0.1% | 0.02% |
| `prev_latch.6` | 8 | 0.1% | 0.02% |
| `oct.10` | 8 | 0.1% | 0.02% |
| `scale.15` | 8 | 0.1% | 0.02% |
| `curofscenter.1` | 4 | 0.1% | 0.01% |
| `tuning_offset` | 4 | 0.1% | 0.01% |
| `jumpable.0 (2 padding)` | 3 | 0.0% | 0.01% |
| `suppress_latch.5 (2 padding)` | 3 | 0.0% | 0.01% |
| `do_second_half.9 (1 padding)` | 2 | 0.0% | 0.01% |
| `max_env_lvl` | 2 | 0.0% | 0.01% |
| `trig_count.4` | 1 | 0.0% | 0.00% |
| `no_arp_touch_mask_1back.7` | 1 | 0.0% | 0.00% |
| `phys_string_touch_1back.8` | 1 | 0.0% | 0.00% |
| `string_root_pitch_valid` | 1 | 0.0% | 0.00% |
| `string_start_step_valid` | 1 | 0.0% | 0.00% |
| `string_scale_valid` | 1 | 0.0% | 0.00% |
| `string_oct_valid` | 1 | 0.0% | 0.00% |
| `cv_gate_out_high` | 1 | 0.0% | 0.00% |
| `cv_trig_out_high` | 1 | 0.0% | 0.00% |
| `before_arp_touch_mask` | 1 | 0.0% | 0.00% |
| `phys_touch_mask` | 1 | 0.0% | 0.00% |
| `play_frame` | 1 | 0.0% | 0.00% |
| `write_frame` | 1 | 0.0% | 0.00% |
| **TOTAL** | **7,291** | **100.0%** | **22.25%** |

#### main

**Total:** 2,676 bytes (2.61 KB) | **Variables:** 22

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `hpcd_USB_OTG_FS` | 1,032 | 38.6% | 3.15% |
| `hsai_BlockB1` | 132 | 4.9% | 0.40% |
| `hsai_BlockA1` | 132 | 4.9% | 0.40% |
| `huart3` | 128 | 4.8% | 0.39% |
| `hspi2` | 100 | 3.7% | 0.31% |
| `hadc1` | 100 | 3.7% | 0.31% |
| `hi2c2` | 76 | 2.8% | 0.23% |
| `hdma_usart3_rx` | 72 | 2.7% | 0.22% |
| `hdma_usart3_tx` | 72 | 2.7% | 0.22% |
| `hdma_spi2_rx` | 72 | 2.7% | 0.22% |
| `hdma_spi2_tx` | 72 | 2.7% | 0.22% |
| `hdma_sai1_b` | 72 | 2.7% | 0.22% |
| `hdma_sai1_a` | 72 | 2.7% | 0.22% |
| `hdma_adc1` | 72 | 2.7% | 0.22% |
| `htsc` | 68 | 2.5% | 0.21% |
| `htim6` | 64 | 2.4% | 0.20% |
| `htim5` | 64 | 2.4% | 0.20% |
| `htim4` | 64 | 2.4% | 0.20% |
| `htim3` | 64 | 2.4% | 0.20% |
| `htim2` | 64 | 2.4% | 0.20% |
| `htim1` | 64 | 2.4% | 0.20% |
| `hdac1` | 20 | 0.7% | 0.06% |
| **TOTAL** | **2,676** | **100.0%** | **8.17%** |

#### plinky/hardware/touchstrips

**Total:** 1,170 bytes (1.14 KB) | **Variables:** 15

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `touch_calib_data` | 576 | 49.2% | 1.76% |
| `touches` | 288 | 24.6% | 0.88% |
| `sensor_max` | 72 | 6.2% | 0.22% |
| `sensor_min` | 72 | 6.2% | 0.22% |
| `sensor_val` | 72 | 6.2% | 0.22% |
| `touch_ticks` | 72 | 6.2% | 0.22% |
| `tsc_started (3 padding)` | 4 | 0.3% | 0.01% |
| `module_ticks (3 padding)` | 4 | 0.3% | 0.01% |
| `group_id.4 (1 padding)` | 2 | 0.2% | 0.01% |
| `read_this_frame` | 2 | 0.2% | 0.01% |
| `strip_touched` | 2 | 0.2% | 0.01% |
| `read_phase.1` | 1 | 0.1% | 0.00% |
| `reading_id.2` | 1 | 0.1% | 0.00% |
| `sensor_id.3` | 1 | 0.1% | 0.00% |
| `touch_frame` | 1 | 0.1% | 0.00% |
| **TOTAL** | **1,170** | **100.0%** | **3.57%** |

#### plinky/gfx/oled/oled

**Total:** 1,036 bytes (1.01 KB) | **Variables:** 5

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `oled_debug (3 padding)` | 516 | 49.8% | 1.57% |
| `oled` | 513 | 49.5% | 1.57% |
| `debug_start_time` | 4 | 0.4% | 0.01% |
| `debug_view_active (1 padding)` | 2 | 0.2% | 0.01% |
| `debug_buffer_active` | 1 | 0.1% | 0.00% |
| **TOTAL** | **1,036** | **100.0%** | **3.16%** |

#### plinky/hardware/codec

**Total:** 1,024 bytes (1.00 KB) | **Variables:** 2

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `rx_buf` | 512 | 50.0% | 1.56% |
| `tx_buf` | 512 | 50.0% | 1.56% |
| **TOTAL** | **1,024** | **100.0%** | **3.12%** |

#### plinky/synth/params

**Total:** 812 bytes (0.79 KB) | **Variables:** 18

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `cc14_values.5` | 512 | 63.1% | 1.56% |
| `multi_param_lfo_offset` | 132 | 16.3% | 0.40% |
| `envelope2` | 64 | 7.9% | 0.20% |
| `edit_strip_pos` | 64 | 7.9% | 0.20% |
| `buf.0` | 5 | 0.6% | 0.02% |
| `last_seen_duration.2` | 4 | 0.5% | 0.01% |
| `clear_mods_duration` | 4 | 0.5% | 0.01% |
| `arp_toggle (3 padding)` | 4 | 0.5% | 0.01% |
| `max_pres_global` | 4 | 0.5% | 0.01% |
| `max_envelope2 (2 padding)` | 4 | 0.5% | 0.01% |
| `selected_edit_strip (3 padding)` | 4 | 0.5% | 0.01% |
| `press_used_up.1 (2 padding)` | 3 | 0.4% | 0.01% |
| `edit_strip_start_pos` | 2 | 0.2% | 0.01% |
| `selected_mod_src (1 padding)` | 2 | 0.2% | 0.01% |
| `mod_action_snap` | 1 | 0.1% | 0.00% |
| `src_snap` | 1 | 0.1% | 0.00% |
| `param_snap` | 1 | 0.1% | 0.00% |
| `latch_toggle` | 1 | 0.1% | 0.00% |
| **TOTAL** | **812** | **100.0%** | **2.48%** |

#### plinky/hardware/midi

**Total:** 602 bytes (0.59 KB) | **Variables:** 46

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `midi_string` | 160 | 26.6% | 0.49% |
| `send_param_val` | 96 | 15.9% | 0.29% |
| `last_sent_string` | 64 | 10.6% | 0.20% |
| `thru_buffer` | 48 | 8.0% | 0.15% |
| `send_multi_param_val (3 padding)` | 36 | 6.0% | 0.11% |
| `midi_send_buffer` | 32 | 5.3% | 0.10% |
| `midi_receive_buffer` | 32 | 5.3% | 0.10% |
| `mpe_zone` | 24 | 4.0% | 0.07% |
| `received_n_rpn_data` | 16 | 2.7% | 0.05% |
| `n_rpn_value` | 16 | 2.7% | 0.05% |
| `last_read_pos.15 (4 padding)` | 5 | 0.8% | 0.02% |
| `buffer.9` | 4 | 0.7% | 0.01% |
| `running_status.10 (3 padding)` | 4 | 0.7% | 0.01% |
| `last_zone_pitchbend.11` | 4 | 0.7% | 0.01% |
| `last_sent_lfo` | 4 | 0.7% | 0.01% |
| `last_channel_pressure (3 padding)` | 4 | 0.7% | 0.01% |
| `pushing_preset (3 padding)` | 4 | 0.7% | 0.01% |
| `sysex_start_time` | 4 | 0.7% | 0.01% |
| `channel_pitchbend_pitch` | 4 | 0.7% | 0.01% |
| `string_id.8 (2 padding)` | 3 | 0.5% | 0.01% |
| `msg.14` | 3 | 0.5% | 0.01% |
| `max_string_pressure.6` | 2 | 0.3% | 0.01% |
| `last_channel_pitchbend.12` | 2 | 0.3% | 0.01% |
| `state.13 (1 padding)` | 2 | 0.3% | 0.01% |
| `thru_buffer_head (1 padding)` | 2 | 0.3% | 0.01% |
| `non_mpe_start_string_in (1 padding)` | 2 | 0.3% | 0.01% |
| `channel_pitchbend` | 2 | 0.3% | 0.01% |
| `channel_pressure (1 padding)` | 2 | 0.3% | 0.01% |
| `max_string_bend_pitch_out` | 2 | 0.3% | 0.01% |
| `max_string_bend_pitch_in` | 2 | 0.3% | 0.01% |
| `max_channel_bend_pitch_in` | 2 | 0.3% | 0.01% |
| `lfo_id.0` | 1 | 0.2% | 0.00% |
| `poly_pres.2` | 1 | 0.2% | 0.00% |
| `chan_pres.4` | 1 | 0.2% | 0.00% |
| `max_velocity.5` | 1 | 0.2% | 0.00% |
| `msg_state.7` | 1 | 0.2% | 0.00% |
| `thru_buffer_count` | 1 | 0.2% | 0.00% |
| `thru_buffer_tail` | 1 | 0.2% | 0.00% |
| `send_transport` | 1 | 0.2% | 0.00% |
| `clocks_to_send` | 1 | 0.2% | 0.00% |
| `midi_out_channel` | 1 | 0.2% | 0.00% |
| `rpn_last_received` | 1 | 0.2% | 0.00% |
| `receiving_sysex` | 1 | 0.2% | 0.00% |
| `non_mpe_start_string_out` | 1 | 0.2% | 0.00% |
| `midi_send_tail` | 1 | 0.2% | 0.00% |
| `midi_send_head` | 1 | 0.2% | 0.00% |
| **TOTAL** | **602** | **100.0%** | **1.84%** |

#### plinky/ui/oled_viz

**Total:** 558 bytes (0.54 KB) | **Variables:** 6

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `scope` | 512 | 91.8% | 1.56% |
| `message` | 20 | 3.6% | 0.06% |
| `submessage` | 16 | 2.9% | 0.05% |
| `message_time` | 4 | 0.7% | 0.01% |
| `message_font (3 padding)` | 4 | 0.7% | 0.01% |
| `val.0` | 2 | 0.4% | 0.01% |
| **TOTAL** | **558** | **100.0%** | **1.70%** |

#### plinky/hardware/spi

**Total:** 527 bytes (0.51 KB) | **Variables:** 5

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `spi_bit_tx` | 260 | 49.3% | 0.79% |
| `spi_big_rx` | 260 | 49.3% | 0.79% |
| `spi_state (3 padding)` | 4 | 0.8% | 0.01% |
| `dummy.0 (1 padding)` | 2 | 0.4% | 0.01% |
| `alex_dma_mode` | 1 | 0.2% | 0.00% |
| **TOTAL** | **527** | **100.0%** | **1.61%** |

#### plinky/ui/led_viz

**Total:** 518 bytes (0.51 KB) | **Variables:** 6

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `surf.0` | 512 | 98.8% | 1.56% |
| `pulse_half (1 padding)` | 2 | 0.4% | 0.01% |
| `frame.1` | 1 | 0.2% | 0.00% |
| `sync_pulse` | 1 | 0.2% | 0.00% |
| `pulse_2x` | 1 | 0.2% | 0.00% |
| `pulse` | 1 | 0.2% | 0.00% |
| **TOTAL** | **518** | **100.0%** | **1.58%** |

#### plinky/usb/tinyusb/src/class/vendor/vendor_device

**Total:** 428 bytes (0.42 KB) | **Variables:** 1

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `_vendord_itf` | 428 | 100.0% | 1.31% |
| **TOTAL** | **428** | **100.0%** | **1.31%** |

#### plinky/usb/tinyusb/src/class/midi/midi_device

**Total:** 312 bytes (0.30 KB) | **Variables:** 1

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `_midid_itf` | 312 | 100.0% | 0.95% |
| **TOTAL** | **312** | **100.0%** | **0.95%** |

#### plinky/usb/tinyusb/src/device/usbd

**Total:** 260 bytes (0.25 KB) | **Variables:** 5

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `_usbd_qdef_buf` | 192 | 73.8% | 0.59% |
| `_usbd_dev (1 padding)` | 56 | 21.5% | 0.17% |
| `_usbd_q` | 4 | 1.5% | 0.01% |
| `_app_driver_count (3 padding)` | 4 | 1.5% | 0.01% |
| `_app_driver` | 4 | 1.5% | 0.01% |
| **TOTAL** | **260** | **100.0%** | **0.79%** |

#### plinky/hardware/adc_dac

**Total:** 236 bytes (0.23 KB) | **Variables:** 8

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `adc_buffer` | 128 | 54.2% | 0.39% |
| `adc_smoother` | 64 | 27.1% | 0.20% |
| `cv_touch` | 12 | 5.1% | 0.04% |
| `hz_v_lower_limit.0` | 8 | 3.4% | 0.02% |
| `hz_v_upper_limit.1` | 8 | 3.4% | 0.02% |
| `hz_v_dac_scale.2` | 8 | 3.4% | 0.02% |
| `dac_octave_size.3` | 4 | 1.7% | 0.01% |
| `calib_calculated.4 (3 padding)` | 4 | 1.7% | 0.01% |
| **TOTAL** | **236** | **100.0%** | **0.72%** |

#### plinky/usb/tinyusb/src/portable/st/synopsys/dcd_synopsys

**Total:** 160 bytes (0.16 KB) | **Variables:** 5

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `xfer_status` | 144 | 90.0% | 0.44% |
| `_setup_packet` | 8 | 5.0% | 0.02% |
| `ep0_pending` | 4 | 2.5% | 0.01% |
| `_out_ep_closed (1 padding)` | 2 | 1.2% | 0.01% |
| `_allocated_fifo_words_tx` | 2 | 1.2% | 0.01% |
| **TOTAL** | **160** | **100.0%** | **0.49%** |

#### plinky/synth/audio

**Total:** 124 bytes (0.12 KB) | **Variables:** 35

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `ext_gain_smoother` | 8 | 6.5% | 0.02% |
| `wetlr.0` | 4 | 3.2% | 0.01% |
| `dc.5` | 4 | 3.2% | 0.01% |
| `lpf.6` | 4 | 3.2% | 0.01% |
| `k_fb.7` | 4 | 3.2% | 0.01% |
| `delaypos.9 (2 padding)` | 4 | 3.2% | 0.01% |
| `peak.11` | 4 | 3.2% | 0.01% |
| `power.12` | 4 | 3.2% | 0.01% |
| `ic2r.13` | 4 | 3.2% | 0.01% |
| `ic1r.14` | 4 | 3.2% | 0.01% |
| `ic2l.15` | 4 | 3.2% | 0.01% |
| `ic1l.16` | 4 | 3.2% | 0.01% |
| `dwobpos.17` | 4 | 3.2% | 0.01% |
| `wobpos.18` | 4 | 3.2% | 0.01% |
| `wobcount.19` | 4 | 3.2% | 0.01% |
| `dcr.21` | 4 | 3.2% | 0.01% |
| `dcl.22` | 4 | 3.2% | 0.01% |
| `lpf2.23` | 4 | 3.2% | 0.01% |
| `dc.24` | 4 | 3.2% | 0.01% |
| `lpf.25` | 4 | 3.2% | 0.01% |
| `fb1.26` | 4 | 3.2% | 0.01% |
| `shimmerfade` | 4 | 3.2% | 0.01% |
| `reverbpos` | 4 | 3.2% | 0.01% |
| `k_reverbsend` | 4 | 3.2% | 0.01% |
| `a_in_lvl_full` | 4 | 3.2% | 0.01% |
| `bestedge.1` | 2 | 1.6% | 0.01% |
| `antiturningpointli.2` | 2 | 1.6% | 0.01% |
| `prevprevli.3` | 2 | 1.6% | 0.01% |
| `prevli.4` | 2 | 1.6% | 0.01% |
| `scopex` | 2 | 1.6% | 0.01% |
| `audio_in_hold_time` | 2 | 1.6% | 0.01% |
| `noise_gate` | 2 | 1.6% | 0.01% |
| `audioin_is_stereo` | 2 | 1.6% | 0.01% |
| `audio_in_hold` | 2 | 1.6% | 0.01% |
| `audio_in_peak` | 2 | 1.6% | 0.01% |
| **TOTAL** | **124** | **100.0%** | **0.38%** |

#### plinky/synth/lfos

**Total:** 124 bytes (0.12 KB) | **Variables:** 6

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `lfo_scope_data` | 64 | 51.6% | 0.20% |
| `lfo_clock_q32.1` | 32 | 25.8% | 0.10% |
| `lfo_cur` | 16 | 12.9% | 0.05% |
| `prev_scope_pos.0` | 4 | 3.2% | 0.01% |
| `new_scope_frame (3 padding)` | 4 | 3.2% | 0.01% |
| `lfo_scope_frame (3 padding)` | 4 | 3.2% | 0.01% |
| **TOTAL** | **124** | **100.0%** | **0.38%** |

#### plinky/synth/time

**Total:** 88 bytes (0.09 KB) | **Variables:** 28

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `bpm_smoother` | 8 | 9.1% | 0.02% |
| `swing_q21.2` | 4 | 4.5% | 0.01% |
| `swing_param.3` | 4 | 4.5% | 0.01% |
| `tap_start_tick.4` | 4 | 4.5% | 0.01% |
| `tap_count.5 (3 padding)` | 4 | 4.5% | 0.01% |
| `tap_latest_tick.6` | 4 | 4.5% | 0.01% |
| `length_32nd_q21` | 4 | 4.5% | 0.01% |
| `cur_32nd_start_q21` | 4 | 4.5% | 0.01% |
| `last_cv_in_pulse_ticks` | 4 | 4.5% | 0.01% |
| `ticks_since_cv_in_pulse` | 4 | 4.5% | 0.01% |
| `start_seq_from_midi_start (3 padding)` | 4 | 4.5% | 0.01% |
| `last_midi_pulse_ticks` | 4 | 4.5% | 0.01% |
| `ticks_since_midi_pulse` | 4 | 4.5% | 0.01% |
| `pos_in_32nd_q21` | 4 | 4.5% | 0.01% |
| `clock_32nds_q21` | 4 | 4.5% | 0.01% |
| `synth_tick` | 4 | 4.5% | 0.01% |
| `clock_type (3 padding)` | 4 | 4.5% | 0.01% |
| `num_swing_32nds.1 (2 padding)` | 3 | 3.4% | 0.01% |
| `reset_clock_next_tick (1 padding)` | 2 | 2.3% | 0.01% |
| `counter_32nds` | 2 | 2.3% | 0.01% |
| `pulse_32nd (1 padding)` | 2 | 2.3% | 0.01% |
| `prev_midi_out_pulse.0` | 1 | 1.1% | 0.00% |
| `cv_in_pulse_counter` | 1 | 1.1% | 0.00% |
| `cv_irq_pulse_handled` | 1 | 1.1% | 0.00% |
| `cv_irq_pulse` | 1 | 1.1% | 0.00% |
| `start_seq_from_midi_continue` | 1 | 1.1% | 0.00% |
| `midi_pulse_counter` | 1 | 1.1% | 0.00% |
| `midi_pulse` | 1 | 1.1% | 0.00% |
| **TOTAL** | **88** | **100.0%** | **0.27%** |

#### plinky/usb/tinyusb/src/device/usbd_control

**Total:** 84 bytes (0.08 KB) | **Variables:** 2

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `_usbd_ctrl_buf` | 64 | 76.2% | 0.20% |
| `_ctrl_xfer` | 20 | 23.8% | 0.06% |
| **TOTAL** | **84** | **100.0%** | **0.26%** |

#### plinky/plinky

**Total:** 80 bytes (0.08 KB) | **Variables:** 6

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `debug_time` | 72 | 90.0% | 0.22% |
| `knob_b_start.0` | 2 | 2.5% | 0.01% |
| `knob_a_start.1` | 2 | 2.5% | 0.01% |
| `ui_mode (1 padding)` | 2 | 2.5% | 0.01% |
| `calib_mode` | 1 | 1.2% | 0.00% |
| `hw_version` | 1 | 1.2% | 0.00% |
| **TOTAL** | **80** | **100.0%** | **0.24%** |

#### plinky/synth/sampler

**Total:** 78 bytes (0.08 KB) | **Variables:** 12

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `peak_hist` | 32 | 41.0% | 0.10% |
| `buf.0 (3 padding)` | 8 | 10.3% | 0.02% |
| `slice_pos_smoother.1` | 8 | 10.3% | 0.02% |
| `start_touch_pos.2 (2 padding)` | 4 | 5.1% | 0.01% |
| `start_slice_pos.3` | 4 | 5.1% | 0.01% |
| `peak_hist_pos (3 padding)` | 4 | 5.1% | 0.01% |
| `buf_read_pos` | 4 | 5.1% | 0.01% |
| `buf_write_pos` | 4 | 5.1% | 0.01% |
| `buf_start_pos` | 4 | 5.1% | 0.01% |
| `record_flashaddr_base` | 4 | 5.1% | 0.01% |
| `cur_slice_id` | 1 | 1.3% | 0.00% |
| `sampler_mode` | 1 | 1.3% | 0.00% |
| **TOTAL** | **78** | **100.0%** | **0.24%** |

#### plinky/hardware/leds

**Total:** 73 bytes (0.07 KB) | **Variables:** 2

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `leds` | 72 | 98.6% | 0.22% |
| `active_column` | 1 | 1.4% | 0.00% |
| **TOTAL** | **73** | **100.0%** | **0.22%** |

#### plinky/usb/tinyusb/src/usb_descriptors

**Total:** 64 bytes (0.06 KB) | **Variables:** 1

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `_desc_str` | 64 | 100.0% | 0.20% |
| **TOTAL** | **64** | **100.0%** | **0.20%** |

#### plinky/synth/sequencer

**Total:** 51 bytes (0.05 KB) | **Variables:** 12

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `c_step` | 12 | 23.5% | 0.04% |
| `record_to_substep.1` | 8 | 15.7% | 0.02% |
| `random_steps_avail` | 8 | 15.7% | 0.02% |
| `ticks_since_step` | 4 | 7.8% | 0.01% |
| `last_step_ticks` | 4 | 7.8% | 0.01% |
| `step_32nds (2 padding)` | 4 | 7.8% | 0.01% |
| `visuals_substep (2 padding)` | 3 | 5.9% | 0.01% |
| `cur_seq_step (2 padding)` | 3 | 5.9% | 0.01% |
| `substep_recorded.0 (1 padding)` | 2 | 3.9% | 0.01% |
| `string_recording.3` | 1 | 2.0% | 0.00% |
| `cur_seq_start` | 1 | 2.0% | 0.00% |
| `seq_flags` | 1 | 2.0% | 0.00% |
| **TOTAL** | **51** | **100.0%** | **0.16%** |

#### plinky/synth/arp

**Total:** 29 bytes (0.03 KB) | **Variables:** 9

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `c_step` | 12 | 41.4% | 0.04% |
| `free_clock` | 4 | 13.8% | 0.01% |
| `strings_used_by_rand1 (2 padding)` | 3 | 10.3% | 0.01% |
| `arp_touch_mask (2 padding)` | 3 | 10.3% | 0.01% |
| `arp_order (2 padding)` | 3 | 10.3% | 0.01% |
| `step_next_strings_frame.1` | 1 | 3.4% | 0.00% |
| `strings_used_by_rand2` | 1 | 3.4% | 0.00% |
| `moving_down` | 1 | 3.4% | 0.00% |
| `arp_oct_offset` | 1 | 3.4% | 0.00% |
| **TOTAL** | **29** | **100.0%** | **0.09%** |

#### plinky/hardware/accelerometer

**Total:** 28 bytes (0.03 KB) | **Variables:** 4

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `accel_smooth` | 8 | 28.6% | 0.02% |
| `accel_lpf` | 8 | 28.6% | 0.02% |
| `accel_raw (2 padding)` | 8 | 28.6% | 0.02% |
| `accel_counter.0 (2 padding)` | 4 | 14.3% | 0.01% |
| **TOTAL** | **28** | **100.0%** | **0.09%** |

#### plinky/hardware/encoder

**Total:** 23 bytes (0.02 KB) | **Variables:** 8

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `prev_encoder_pressed.0 (3 padding)` | 4 | 17.4% | 0.01% |
| `last_encoder_use` | 4 | 17.4% | 0.01% |
| `encoder_press_duration (2 padding)` | 4 | 17.4% | 0.01% |
| `encoder_press_start` | 4 | 17.4% | 0.01% |
| `encoder_acc` | 4 | 17.4% | 0.01% |
| `prev_hardware_state` | 1 | 4.3% | 0.00% |
| `encoder_value` | 1 | 4.3% | 0.00% |
| `encoder_pressed` | 1 | 4.3% | 0.00% |
| **TOTAL** | **23** | **100.0%** | **0.07%** |

#### plinky/usb/web_editor

**Total:** 22 bytes (0.02 KB) | **Variables:** 4

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `header` | 14 | 63.6% | 0.04% |
| `state_start` | 4 | 18.2% | 0.01% |
| `receiving_web_preset (1 padding)` | 2 | 9.1% | 0.01% |
| `state (1 padding)` | 2 | 9.1% | 0.01% |
| **TOTAL** | **22** | **100.0%** | **0.07%** |

#### plinky/ui/pad_actions

**Total:** 21 bytes (0.02 KB) | **Variables:** 9

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `function_press_ms` | 4 | 19.0% | 0.01% |
| `function_press_start` | 4 | 19.0% | 0.01% |
| `main_press_ms` | 4 | 19.0% | 0.01% |
| `main_press_start` | 4 | 19.0% | 0.01% |
| `main_press_canceled` | 1 | 4.8% | 0.00% |
| `keep_edit_mode_open` | 1 | 4.8% | 0.00% |
| `keep_ui_open` | 1 | 4.8% | 0.00% |
| `press_start_ui_mode` | 1 | 4.8% | 0.00% |
| `action_on_main_strip` | 1 | 4.8% | 0.00% |
| **TOTAL** | **21** | **100.0%** | **0.06%** |

#### plinky/hardware/midi_sysex

**Total:** 18 bytes (0.02 KB) | **Variables:** 7

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `save_byte.0 (3 padding)` | 4 | 22.2% | 0.01% |
| `save_byte.3 (2 padding)` | 4 | 22.2% | 0.01% |
| `save_byte.1` | 3 | 16.7% | 0.01% |
| `sysex_sub_id` | 2 | 11.1% | 0.01% |
| `sysex_manuf_id (1 padding)` | 2 | 11.1% | 0.01% |
| `sysex_status` | 2 | 11.1% | 0.01% |
| `num_changes.2` | 1 | 5.6% | 0.00% |
| **TOTAL** | **18** | **100.0%** | **0.05%** |

#### plinky/usb/tinyusb/src/usbmidi

**Total:** 8 bytes (0.01 KB) | **Variables:** 2

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `serialno` | 4 | 50.0% | 0.01% |
| `web_serial_connected (3 padding)` | 4 | 50.0% | 0.01% |
| **TOTAL** | **8** | **100.0%** | **0.02%** |

#### plinky/ui/settings_menu

**Total:** 6 bytes (0.01 KB) | **Variables:** 6

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `enc_pressed.0` | 1 | 16.7% | 0.00% |
| `perform_action` | 1 | 16.7% | 0.00% |
| `value_selected` | 1 | 16.7% | 0.00% |
| `cur_value` | 1 | 16.7% | 0.00% |
| `display_section` | 1 | 16.7% | 0.00% |
| `cur_item` | 1 | 16.7% | 0.00% |
| **TOTAL** | **6** | **100.0%** | **0.02%** |

#### plinky/ui/extensions_menu

**Total:** 4 bytes (0.00 KB) | **Variables:** 4

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `enc_pressed.0` | 1 | 25.0% | 0.00% |
| `value_selected` | 1 | 25.0% | 0.00% |
| `cur_value` | 1 | 25.0% | 0.00% |
| `cur_item` | 1 | 25.0% | 0.00% |
| **TOTAL** | **4** | **100.0%** | **0.01%** |

#### stm32l4xx_hal_msp

**Total:** 4 bytes (0.00 KB) | **Variables:** 1

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `SAI1_client` | 4 | 100.0% | 0.01% |
| **TOTAL** | **4** | **100.0%** | **0.01%** |

#### sysmem

**Total:** 4 bytes (0.00 KB) | **Variables:** 1

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `heap_end.0` | 4 | 100.0% | 0.01% |
| **TOTAL** | **4** | **100.0%** | **0.01%** |

#### plinky/usb/usb

**Total:** 2 bytes (0.00 KB) | **Variables:** 2

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `tud_task_running` | 1 | 50.0% | 0.00% |
| `web_serial_was_connected` | 1 | 50.0% | 0.00% |
| **TOTAL** | **2** | **100.0%** | **0.01%** |

#### plinky/usb/tinyusb/src/tusb

**Total:** 1 bytes (0.00 KB) | **Variables:** 1

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `_initialized` | 1 | 100.0% | 0.00% |
| **TOTAL** | **1** | **100.0%** | **0.00%** |


---

## .data Section (Initialized Data)

### Summary by Module

| **Module** | **.data (bytes)** | **% of 32KB RAM** | **Num Variables** |
|--------|---------------|---------------|---------------|
| [`plinky/hardware/adc_dac`](#plinkyhardwareadc_dac) | 84 | 0.3% | 3 |
| [`plinky/plinky`](#plinkyplinky) | 72 | 0.2% | 1 |
| [`plinky/synth/audio`](#plinkysynthaudio) | 68 | 0.2% | 13 |
| [`plinky/hardware/midi`](#plinkyhardwaremidi) | 38 | 0.1% | 8 |
| [`plinky/synth/params`](#plinkysynthparams) | 26 | 0.1% | 6 |
| [`plinky/usb/tinyusb/src/device/usbd`](#plinkyusbtinyusbsrcdeviceusbd) | 24 | 0.1% | 1 |
| [`plinky/synth/synth`](#plinkysynthsynth) | 20 | 0.1% | 6 |
| [`plinky/usb/tinyusb/src/usb_descriptors`](#plinkyusbtinyusbsrcusb_descriptors) | 20 | 0.1% | 1 |
| [`plinky/synth/arp`](#plinkysyntharp) | 12 | 0.0% | 4 |
| [`plinky/hardware/accelerometer`](#plinkyhardwareaccelerometer) | 12 | 0.0% | 1 |
| [`plinky/ui/pad_actions`](#plinkyuipad_actions) | 12 | 0.0% | 4 |
| [`plinky/hardware/memory`](#plinkyhardwarememory) | 10 | 0.0% | 10 |
| [`plinky/usb/web_editor`](#plinkyusbweb_editor) | 8 | 0.0% | 2 |
| [`plinky/ui/extensions_menu`](#plinkyuiextensions_menu) | 8 | 0.0% | 2 |
| [`plinky/hardware/expander`](#plinkyhardwareexpander) | 8 | 0.0% | 1 |
| [`plinky/synth/sequencer`](#plinkysynthsequencer) | 6 | 0.0% | 3 |
| [`plinky/hardware/codec`](#plinkyhardwarecodec) | 4 | 0.0% | 1 |
| [`plinky/ui/settings_menu`](#plinkyuisettings_menu) | 4 | 0.0% | 1 |
| [`plinky/gfx/gfx`](#plinkygfxgfx) | 4 | 0.0% | 1 |
| [`system_stm32l4xx`](#system_stm32l4xx) | 4 | 0.0% | 1 |
| [`plinky/hardware/touchstrips`](#plinkyhardwaretouchstrips) | 2 | 0.0% | 1 |
| [`plinky/ui/oled_viz`](#plinkyuioled_viz) | 2 | 0.0% | 2 |
| [`plinky/hardware/spi`](#plinkyhardwarespi) | 2 | 0.0% | 1 |
| [`plinky/synth/time`](#plinkysynthtime) | 2 | 0.0% | 1 |
| **TOTAL** | **452** | **1.4%** | **75** |

### Per-Module Breakdown

#### plinky/hardware/adc_dac

**Total:** 84 bytes (0.08 KB) | **Variables:** 3

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `adc_dac_calib` | 80 | 95.2% | 0.24% |
| `prev_map_string.6 (2 padding)` | 3 | 3.6% | 0.01% |
| `prev_gate.5` | 1 | 1.2% | 0.00% |
| **TOTAL** | **84** | **100.0%** | **0.26%** |

#### plinky/plinky

**Total:** 72 bytes (0.07 KB) | **Variables:** 1

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `debug_label` | 72 | 100.0% | 0.22% |
| **TOTAL** | **72** | **100.0%** | **0.22%** |

#### plinky/synth/audio

**Total:** 68 bytes (0.07 KB) | **Variables:** 13

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `aplfo2` | 12 | 17.6% | 0.04% |
| `aplfo` | 12 | 17.6% | 0.04% |
| `peaktrack.8` | 4 | 5.9% | 0.01% |
| `delaytime.10` | 4 | 5.9% | 0.01% |
| `ext_gain_goal.20 (2 padding)` | 4 | 5.9% | 0.01% |
| `dshimmerfade` | 4 | 5.9% | 0.01% |
| `shimmerpos2` | 4 | 5.9% | 0.01% |
| `shimmerpos1` | 4 | 5.9% | 0.01% |
| `k_reverb_wob` | 4 | 5.9% | 0.01% |
| `k_reverb_shim` | 4 | 5.9% | 0.01% |
| `k_reverb_fade` | 4 | 5.9% | 0.01% |
| `delay_ram_buf` | 4 | 5.9% | 0.01% |
| `reverb_ram_buf` | 4 | 5.9% | 0.01% |
| **TOTAL** | **68** | **100.0%** | **0.21%** |

#### plinky/hardware/midi

**Total:** 38 bytes (0.04 KB) | **Variables:** 8

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `rpn_id` | 16 | 42.1% | 0.05% |
| `nrpn_id` | 16 | 42.1% | 0.05% |
| `min_diff.1` | 1 | 2.6% | 0.00% |
| `min_diff.3` | 1 | 2.6% | 0.00% |
| `sending_param_progress` | 1 | 2.6% | 0.00% |
| `sending_param_id` | 1 | 2.6% | 0.00% |
| `high_mpe_start_string_out` | 1 | 2.6% | 0.00% |
| `high_mpe_start_string_in` | 1 | 2.6% | 0.00% |
| **TOTAL** | **38** | **100.0%** | **0.12%** |

#### plinky/synth/params

**Total:** 26 bytes (0.03 KB) | **Variables:** 6

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `sample_hold` | 16 | 61.5% | 0.05% |
| `sample_hold_global (2 padding)` | 4 | 15.4% | 0.01% |
| `saved_raw.3` | 2 | 7.7% | 0.01% |
| `param_hash.4` | 2 | 7.7% | 0.01% |
| `mem_param` | 1 | 3.8% | 0.00% |
| `selected_param` | 1 | 3.8% | 0.00% |
| **TOTAL** | **26** | **100.0%** | **0.08%** |

#### plinky/usb/tinyusb/src/device/usbd

**Total:** 24 bytes (0.02 KB) | **Variables:** 1

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `_usbd_qdef` | 24 | 100.0% | 0.07% |
| **TOTAL** | **24** | **100.0%** | **0.07%** |

#### plinky/synth/synth

**Total:** 20 bytes (0.02 KB) | **Variables:** 6

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `string_start_semis.11` | 8 | 40.0% | 0.02% |
| `play_strings` | 4 | 20.0% | 0.01% |
| `write_strings` | 4 | 20.0% | 0.01% |
| `low_string_id (1 padding)` | 2 | 10.0% | 0.01% |
| `high_string_note` | 1 | 5.0% | 0.00% |
| `high_string_id` | 1 | 5.0% | 0.00% |
| **TOTAL** | **20** | **100.0%** | **0.06%** |

#### plinky/usb/tinyusb/src/usb_descriptors

**Total:** 20 bytes (0.02 KB) | **Variables:** 1

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `string_desc_arr` | 20 | 100.0% | 0.06% |
| **TOTAL** | **20** | **100.0%** | **0.06%** |

#### plinky/synth/arp

**Total:** 12 bytes (0.01 KB) | **Variables:** 4

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `first_swing_note.0 (3 padding)` | 4 | 33.3% | 0.01% |
| `strings_frame_tick` | 4 | 33.3% | 0.01% |
| `cur_string (2 padding)` | 3 | 25.0% | 0.01% |
| `non_pedal_string` | 1 | 8.3% | 0.00% |
| **TOTAL** | **12** | **100.0%** | **0.04%** |

#### plinky/hardware/accelerometer

**Total:** 12 bytes (0.01 KB) | **Variables:** 1

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `accelerometer` | 12 | 100.0% | 0.04% |
| **TOTAL** | **12** | **100.0%** | **0.04%** |

#### plinky/ui/pad_actions

**Total:** 12 bytes (0.01 KB) | **Variables:** 4

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `prev_action_pad.0` | 9 | 75.0% | 0.03% |
| `main_press_param` | 1 | 8.3% | 0.00% |
| `main_press_item` | 1 | 8.3% | 0.00% |
| `function_pressed` | 1 | 8.3% | 0.00% |
| **TOTAL** | **12** | **100.0%** | **0.04%** |

#### plinky/hardware/memory

**Total:** 10 bytes (0.01 KB) | **Variables:** 10

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `edit_item_id` | 1 | 10.0% | 0.00% |
| `cued_sample_id` | 1 | 10.0% | 0.00% |
| `cued_pattern_id` | 1 | 10.0% | 0.00% |
| `cued_preset_id` | 1 | 10.0% | 0.00% |
| `ram_sample_id` | 1 | 10.0% | 0.00% |
| `ram_pattern_id` | 1 | 10.0% | 0.00% |
| `ram_preset_id` | 1 | 10.0% | 0.00% |
| `load_sample_id` | 1 | 10.0% | 0.00% |
| `load_pattern_id` | 1 | 10.0% | 0.00% |
| `load_preset_id` | 1 | 10.0% | 0.00% |
| **TOTAL** | **10** | **100.0%** | **0.03%** |

#### plinky/usb/web_editor

**Total:** 8 bytes (0.01 KB) | **Variables:** 2

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `remaining_bytes` | 4 | 50.0% | 0.01% |
| `data_buf` | 4 | 50.0% | 0.01% |
| **TOTAL** | **8** | **100.0%** | **0.02%** |

#### plinky/ui/extensions_menu

**Total:** 8 bytes (0.01 KB) | **Variables:** 2

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `item_values (2 padding)` | 4 | 50.0% | 0.01% |
| `debug_display` | 4 | 50.0% | 0.01% |
| **TOTAL** | **8** | **100.0%** | **0.02%** |

#### plinky/hardware/expander

**Total:** 8 bytes (0.01 KB) | **Variables:** 1

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `expander_out` | 8 | 100.0% | 0.02% |
| **TOTAL** | **8** | **100.0%** | **0.02%** |

#### plinky/synth/sequencer

**Total:** 6 bytes (0.01 KB) | **Variables:** 3

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `cued_ptn_start (3 padding)` | 4 | 66.7% | 0.01% |
| `last_seen_substep.2` | 1 | 16.7% | 0.00% |
| `last_seen_step.4` | 1 | 16.7% | 0.00% |
| **TOTAL** | **6** | **100.0%** | **0.02%** |

#### plinky/hardware/codec

**Total:** 4 bytes (0.00 KB) | **Variables:** 1

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `cur_vol.0 (3 padding)` | 4 | 100.0% | 0.01% |
| **TOTAL** | **4** | **100.0%** | **0.01%** |

#### plinky/ui/settings_menu

**Total:** 4 bytes (0.00 KB) | **Variables:** 1

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `fill_start (3 padding)` | 4 | 100.0% | 0.01% |
| **TOTAL** | **4** | **100.0%** | **0.01%** |

#### plinky/gfx/gfx

**Total:** 4 bytes (0.00 KB) | **Variables:** 1

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `gfx_text_color (3 padding)` | 4 | 100.0% | 0.01% |
| **TOTAL** | **4** | **100.0%** | **0.01%** |

#### system_stm32l4xx

**Total:** 4 bytes (0.00 KB) | **Variables:** 1

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `SystemCoreClock` | 4 | 100.0% | 0.01% |
| **TOTAL** | **4** | **100.0%** | **0.01%** |

#### plinky/hardware/touchstrips

**Total:** 2 bytes (0.00 KB) | **Variables:** 1

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `phase_read_mask.0` | 2 | 100.0% | 0.01% |
| **TOTAL** | **2** | **100.0%** | **0.01%** |

#### plinky/ui/oled_viz

**Total:** 2 bytes (0.00 KB) | **Variables:** 2

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `frame.1` | 1 | 50.0% | 0.00% |
| `frame.3` | 1 | 50.0% | 0.00% |
| **TOTAL** | **2** | **100.0%** | **0.01%** |

#### plinky/hardware/spi

**Total:** 2 bytes (0.00 KB) | **Variables:** 1

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `cur_spi_pin (1 padding)` | 2 | 100.0% | 0.01% |
| **TOTAL** | **2** | **100.0%** | **0.01%** |

#### plinky/synth/time

**Total:** 2 bytes (0.00 KB) | **Variables:** 1

| **Variable** | **Size (bytes)** | **% of Module** | **% of 32KB RAM** |
|----------|--------------|-------------|---------------|
| `bpm_10x` | 2 | 100.0% | 0.01% |
| **TOTAL** | **2** | **100.0%** | **0.01%** |


---

## FLASH Usage Overview

| **Section** | **Size (bytes)** | **% of Total FLASH** |
|-------------|------------------|----------------------|
| `.isr_vector` - Interrupt vectors / startup code | 392 | 0.1% |
| `.text` - Executable code | 173,988 | 41.2% |
| `.rodata` - Read-only data (const arrays, strings, lookup tables) | 99,200 | 23.5% |
| `.ARM.extab` - Exception handling tables | 0 | 0.0% |
| `.ARM` - ARM-specific metadata | 8 | 0.0% |
| `.preinit_array` - Pre-initialization functions | 0 | 0.0% |
| `.init_array` - Initialization functions | 4 | 0.0% |
| `.fini_array` - Finalization functions | 4 | 0.0% |
| **TOTAL** | **273,596** | **64.9%** |

**Total FLASH Available:** 421,888 bytes (412 KB)
**FLASH Used:** 273,596 bytes (267.18 KB)
**FLASH Remaining:** 148,292 bytes (144.82 KB)

---

## .rodata Section (Read-Only Data)

### Summary by Module

| **Module** | **.rodata (bytes)** | **% of .rodata** | **Num Symbols** |
|------------|---------------------|------------------|-----------------|
| [`plinky/data/tables`](#plinkydatatables) | 78,543 | 79.2% | 8 |
| [`plinky/gfx/gfx`](#plinkygfxgfx) | 9,551 | 9.6% | 4 |
| [`plinky/synth/params`](#plinkysynthparams) | 5,086 | 5.1% | 25 |
| [`plinky/plinky`](#plinkyplinky) | 4,489 | 4.5% | 2 |
| [`plinky/hardware/memory`](#plinkyhardwarememory) | 1,222 | 1.2% | 21 |
| [`plinky/ui/settings_menu`](#plinkyuisettings_menu) | 1,190 | 1.2% | 9 |
| [`plinky/data/logo`](#plinkydatalogo) | 1,026 | 1.0% | 2 |
| [`plinky/usb/tinyusb/src/usb_descriptors`](#plinkyusbtinyusbsrcusb_descriptors) | 431 | 0.4% | 7 |
| [`plinky/hardware/adc_dac`](#plinkyhardwareadc_dac) | 404 | 0.4% | 3 |
| [`plinky/hardware/touchstrips`](#plinkyhardwaretouchstrips) | 269 | 0.3% | 7 |
| [`plinky/hardware/midi`](#plinkyhardwaremidi) | 223 | 0.2% | 7 |
| [`hard\libc_nano.a(libc_a-rand`](#hardlibc_nanoalibc_a-rand) | 222 | 0.2% | 1 |
| [`plinky/synth/sampler`](#plinkysynthsampler) | 160 | 0.2% | 4 |
| [`plinky/synth/lfos`](#plinkysynthlfos) | 100 | 0.1% | 2 |
| [`plinky/synth/sequencer`](#plinkysynthsequencer) | 99 | 0.1% | 3 |
| [`plinky/ui/extensions_menu`](#plinkyuiextensions_menu) | 82 | 0.1% | 3 |
| [`plinky/ui/pad_actions`](#plinkyuipad_actions) | 74 | 0.1% | 1 |
| [`system_stm32l4xx`](#system_stm32l4xx) | 72 | 0.1% | 3 |
| [`plinky/synth/synth`](#plinkysynthsynth) | 65 | 0.1% | 2 |
| [`hard\libc_nano.a(libc_a-assert`](#hardlibc_nanoalibc_a-assert) | 61 | 0.1% | 1 |
| [`plinky/synth/arp`](#plinkysyntharp) | 56 | 0.1% | 1 |
| [`plinky/synth/audio`](#plinkysynthaudio) | 56 | 0.1% | 1 |
| [`plinky/usb/tinyusb/src/device/usbd`](#plinkyusbtinyusbsrcdeviceusbd) | 48 | 0.0% | 1 |
| [`plinky/ui/oled_viz`](#plinkyuioled_viz) | 42 | 0.0% | 2 |
| [`plinky/synth/time`](#plinkysynthtime) | 40 | 0.0% | 2 |
| [`hard\libc_nano.a(libc_a-nano-vfprintf_i`](#hardlibc_nanoalibc_a-nano-vfprintf_i) | 34 | 0.0% | 1 |
| [`plinky/usb/tinyusb/src/usbmidi`](#plinkyusbtinyusbsrcusbmidi) | 30 | 0.0% | 1 |
| [`plinky/hardware/midi_sysex`](#plinkyhardwaremidi_sysex) | 24 | 0.0% | 1 |
| [`plinky/hardware/leds`](#plinkyhardwareleds) | 20 | 0.0% | 1 |
| [`hard\libc_nano.a(libc_a-nano-svfprintf`](#hardlibc_nanoalibc_a-nano-svfprintf) | 17 | 0.0% | 1 |
| [`hard\libc_nano.a(libc_a-nano-vfprintf`](#hardlibc_nanoalibc_a-nano-vfprintf) | 17 | 0.0% | 1 |
| [`plinky/hardware/encoder`](#plinkyhardwareencoder) | 16 | 0.0% | 1 |
| [`hard\libm.a(libm_a-e_fmod`](#hardlibmalibm_a-e_fmod) | 16 | 0.0% | 1 |
| [`plinky/usb/web_editor`](#plinkyusbweb_editor) | 8 | 0.0% | 2 |
| [`hard\libm.a(libm_a-wf_log`](#hardlibmalibm_a-wf_log) | 1 | 0.0% | 1 |
| **TOTAL** | **103,794** | **104.6%** | **133** |

**Actual .rodata size:** 99,200 bytes
**Parsed .rodata size:** 103,794 bytes
**Discrepancy:** -4,594 bytes (padding/alignment/library)

### Per-Module Breakdown

#### plinky/data/tables

**Total:** 78,543 bytes (76.70 KB) | **Symbols:** 8

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `rndtab` | 65,536 | 83.4% | 15.53% |
| `pitches` | 4,100 | 5.2% | 0.97% |
| `lpf_ks` | 4,100 | 5.2% | 0.97% |
| `sigmoid` | 2,050 | 2.6% | 0.49% |
| `zero` | 2,048 | 2.6% | 0.49% |
| `scale_table` | 648 | 0.8% | 0.15% |
| `wavetable_octave_offset` | 34 | 0.0% | 0.01% |
| `steps_in_scale` | 27 | 0.0% | 0.01% |
| **TOTAL** | **78,543** | **100.0%** | **79.18%** |

#### plinky/gfx/gfx

**Total:** 9,551 bytes (9.33 KB) | **Symbols:** 4

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `font_data` | 7,488 | 78.4% | 1.77% |
| `icons` | 2,048 | 21.4% | 0.49% |
| `font_offsets` | 10 | 0.1% | 0.00% |
| `font_heights` | 5 | 0.1% | 0.00% |
| **TOTAL** | **9,551** | **100.0%** | **9.63%** |

#### plinky/synth/params

**Total:** 5,086 bytes (4.97 KB) | **Symbols:** 25

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `init_params` | 2,016 | 39.6% | 0.48% |
| `str1.4` | 1,405 | 27.6% | 0.33% |
| `param_name` | 384 | 7.6% | 0.09% |
| `draw_cur_param.str1.4` | 198 | 3.9% | 0.05% |
| `get_param_str.str1.4` | 147 | 2.9% | 0.03% |
| `midi_cc_table` | 128 | 2.5% | 0.03% |
| `scale_name` | 108 | 2.1% | 0.03% |
| `toggle_multi_edit.str1.4` | 99 | 1.9% | 0.02% |
| `range_type` | 96 | 1.9% | 0.02% |
| `param_row_name` | 64 | 1.3% | 0.02% |
| `arp_mode_name` | 60 | 1.2% | 0.01% |
| `multi_param_from_param` | 57 | 1.1% | 0.01% |
| `sync_divs_32nds` | 56 | 1.1% | 0.01% |
| `lfo_shape_name` | 44 | 0.9% | 0.01% |
| `param_info` | 42 | 0.8% | 0.01% |
| `param_from_multi_param` | 33 | 0.6% | 0.01% |
| `mod_src_name` | 32 | 0.6% | 0.01% |
| `mod_clear_visuals.str1.4` | 24 | 0.5% | 0.01% |
| `seq_mode_name` | 24 | 0.5% | 0.01% |
| `hold_encoder_for_params.str1.4` | 23 | 0.5% | 0.01% |
| `layout_param_from_param` | 18 | 0.4% | 0.00% |
| `try_restore_param.str1.4` | 10 | 0.2% | 0.00% |
| `press_mod_pad.str1.4` | 8 | 0.2% | 0.00% |
| `draw_latch_flag.str1.4` | 6 | 0.1% | 0.00% |
| `draw_arp_flag.str1.4` | 4 | 0.1% | 0.00% |
| **TOTAL** | **5,086** | **100.0%** | **5.13%** |

#### plinky/plinky

**Total:** 4,489 bytes (4.38 KB) | **Symbols:** 2

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `plinky_init.str1.4` | 4,367 | 97.3% | 1.04% |
| `str1.4` | 122 | 2.7% | 0.03% |
| **TOTAL** | **4,489** | **100.0%** | **4.53%** |

#### plinky/hardware/memory

**Total:** 1,222 bytes (1.19 KB) | **Symbols:** 21

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `draw_ui_load_visuals.str1.4` | 177 | 14.5% | 0.04% |
| `sys_param_setters` | 140 | 11.5% | 0.03% |
| `sys_param_getters` | 140 | 11.5% | 0.03% |
| `str1.4` | 138 | 11.3% | 0.03% |
| `check_bootloader_flash.str1.4` | 123 | 10.1% | 0.03% |
| `memory_frame.str1.4` | 122 | 10.0% | 0.03% |
| `preset_category_name` | 72 | 5.9% | 0.02% |
| `init_memory.str1.4` | 60 | 4.9% | 0.01% |
| `revert_presets.str1.4` | 48 | 3.9% | 0.01% |
| `draw_ram_id.str1.4` | 47 | 3.8% | 0.01% |
| `load_preset.str1.4` | 39 | 3.2% | 0.01% |
| `sys_param_ranges` | 35 | 2.9% | 0.01% |
| `press_mem_item.str1.4` | 18 | 1.5% | 0.00% |
| `draw_cued_preset_id.str1.4` | 13 | 1.1% | 0.00% |
| `icons.0` | 12 | 1.0% | 0.00% |
| `draw_cued_pattern_id.str1.4` | 11 | 0.9% | 0.00% |
| `draw_preset_id.str1.4` | 9 | 0.7% | 0.00% |
| `draw_pattern_id.str1.4` | 7 | 0.6% | 0.00% |
| `cue_mem_item.str1.4` | 5 | 0.4% | 0.00% |
| `icon_widths.1` | 3 | 0.2% | 0.00% |
| `section_widths.2` | 3 | 0.2% | 0.00% |
| **TOTAL** | **1,222** | **100.0%** | **1.23%** |

#### plinky/ui/settings_menu

**Total:** 1,190 bytes (1.16 KB) | **Symbols:** 9

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `str1.4` | 364 | 30.6% | 0.09% |
| `item_name` | 336 | 28.2% | 0.08% |
| `draw_settings_menu.str1.4` | 305 | 25.6% | 0.07% |
| `item_to_sys_param` | 84 | 7.1% | 0.02% |
| `settings_menu_actions.str1.4` | 54 | 4.5% | 0.01% |
| `section_name` | 20 | 1.7% | 0.00% |
| `CSWTCH.110` | 12 | 1.0% | 0.00% |
| `bend_ranges` | 8 | 0.7% | 0.00% |
| `ppqn_values` | 7 | 0.6% | 0.00% |
| **TOTAL** | **1,190** | **100.0%** | **1.20%** |

#### plinky/data/logo

**Total:** 1,026 bytes (1.00 KB) | **Symbols:** 2

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `plinky_plus_logo` | 513 | 50.0% | 0.12% |
| `plinky_logo` | 513 | 50.0% | 0.12% |
| **TOTAL** | **1,026** | **100.0%** | **1.03%** |

#### plinky/usb/tinyusb/src/usb_descriptors

**Total:** 431 bytes (0.42 KB) | **Symbols:** 7

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `desc_ms_os_20` | 178 | 41.3% | 0.04% |
| `desc_fs_configuration` | 124 | 28.8% | 0.03% |
| `desc_bos` | 57 | 13.2% | 0.01% |
| `str1.4` | 47 | 10.9% | 0.01% |
| `desc_device` | 18 | 4.2% | 0.00% |
| `tud_descriptor_string_cb.str1.4` | 5 | 1.2% | 0.00% |
| `__compound_literal.0` | 2 | 0.5% | 0.00% |
| **TOTAL** | **431** | **100.0%** | **0.43%** |

#### plinky/hardware/adc_dac

**Total:** 404 bytes (0.39 KB) | **Symbols:** 3

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `cv_calib.str1.4` | 287 | 71.0% | 0.07% |
| `str1.4` | 97 | 24.0% | 0.02% |
| `(unnamed)` | 20 | 5.0% | 0.00% |
| **TOTAL** | **404** | **100.0%** | **0.41%** |

#### plinky/hardware/touchstrips

**Total:** 269 bytes (0.26 KB) | **Symbols:** 7

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `(unnamed)` | 64 | 23.8% | 0.02% |
| `sample_io` | 52 | 19.3% | 0.01% |
| `channels_io` | 52 | 19.3% | 0.01% |
| `reading_group` | 37 | 13.8% | 0.01% |
| `reading_sensor` | 37 | 13.8% | 0.01% |
| `touch_calib.str1.4` | 14 | 5.2% | 0.00% |
| `max_readings_in_phase` | 13 | 4.8% | 0.00% |
| **TOTAL** | **269** | **100.0%** | **0.27%** |

#### plinky/hardware/midi

**Total:** 223 bytes (0.22 KB) | **Symbols:** 7

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `midi_cc_table_rvs` | 96 | 43.0% | 0.02% |
| `multi_param_from_param` | 57 | 25.6% | 0.01% |
| `midi_panic.str1.4` | 28 | 12.6% | 0.01% |
| `init_midi_string` | 20 | 9.0% | 0.00% |
| `init_last_sent_string` | 8 | 3.6% | 0.00% |
| `bend_ranges` | 8 | 3.6% | 0.00% |
| `draw_sysex_flag.str1.4` | 6 | 2.7% | 0.00% |
| **TOTAL** | **223** | **100.0%** | **0.22%** |

#### hard\libc_nano.a(libc_a-rand

**Total:** 222 bytes (0.22 KB) | **Symbols:** 1

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `srand.str1.1` | 222 | 100.0% | 0.05% |
| **TOTAL** | **222** | **100.0%** | **0.22%** |

#### plinky/synth/sampler

**Total:** 160 bytes (0.16 KB) | **Symbols:** 4

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `sampler_oled_visuals.str1.4` | 121 | 75.6% | 0.03% |
| `str1.4` | 19 | 11.9% | 0.00% |
| `CSWTCH.140` | 12 | 7.5% | 0.00% |
| `draw_sample_erasing.str1.4` | 8 | 5.0% | 0.00% |
| **TOTAL** | **160** | **100.0%** | **0.16%** |

#### plinky/synth/lfos

**Total:** 100 bytes (0.10 KB) | **Symbols:** 2

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `sync_divs_32nds` | 56 | 56.0% | 0.01% |
| `lfo_funcs` | 44 | 44.0% | 0.01% |
| **TOTAL** | **100** | **100.0%** | **0.10%** |

#### plinky/synth/sequencer

**Total:** 99 bytes (0.10 KB) | **Symbols:** 3

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `sync_divs_32nds` | 56 | 56.6% | 0.01% |
| `seq_ptn_start_visuals.str1.4` | 24 | 24.2% | 0.01% |
| `seq_ptn_end_visuals.str1.4` | 19 | 19.2% | 0.00% |
| **TOTAL** | **99** | **100.0%** | **0.10%** |

#### plinky/ui/extensions_menu

**Total:** 82 bytes (0.08 KB) | **Symbols:** 3

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `draw_extensions_menu.str1.4` | 59 | 72.0% | 0.01% |
| `CSWTCH.44` | 12 | 14.6% | 0.00% |
| `str1.4` | 11 | 13.4% | 0.00% |
| **TOTAL** | **82** | **100.0%** | **0.08%** |

#### plinky/ui/pad_actions

**Total:** 74 bytes (0.07 KB) | **Symbols:** 1

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `oled_function_visuals.str1.4` | 74 | 100.0% | 0.02% |
| **TOTAL** | **74** | **100.0%** | **0.07%** |

#### system_stm32l4xx

**Total:** 72 bytes (0.07 KB) | **Symbols:** 3

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `MSIRangeTable` | 48 | 66.7% | 0.01% |
| `AHBPrescTable` | 16 | 22.2% | 0.00% |
| `APBPrescTable` | 8 | 11.1% | 0.00% |
| **TOTAL** | **72** | **100.0%** | **0.07%** |

#### plinky/synth/synth

**Total:** 65 bytes (0.06 KB) | **Symbols:** 2

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `draw_high_note.str1.4` | 33 | 50.8% | 0.01% |
| `ref_pitch_offset` | 32 | 49.2% | 0.01% |
| **TOTAL** | **65** | **100.0%** | **0.07%** |

#### hard\libc_nano.a(libc_a-assert

**Total:** 61 bytes (0.06 KB) | **Symbols:** 1

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `__assert_func.str1.1` | 61 | 100.0% | 0.01% |
| **TOTAL** | **61** | **100.0%** | **0.06%** |

#### plinky/synth/arp

**Total:** 56 bytes (0.05 KB) | **Symbols:** 1

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `sync_divs_32nds` | 56 | 100.0% | 0.01% |
| **TOTAL** | **56** | **100.0%** | **0.06%** |

#### plinky/synth/audio

**Total:** 56 bytes (0.05 KB) | **Symbols:** 1

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `sync_divs_32nds` | 56 | 100.0% | 0.01% |
| **TOTAL** | **56** | **100.0%** | **0.06%** |

#### plinky/usb/tinyusb/src/device/usbd

**Total:** 48 bytes (0.05 KB) | **Symbols:** 1

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `_usbd_driver` | 48 | 100.0% | 0.01% |
| **TOTAL** | **48** | **100.0%** | **0.05%** |

#### plinky/ui/oled_viz

**Total:** 42 bytes (0.04 KB) | **Symbols:** 2

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `draw_oled_visuals.str1.4` | 26 | 61.9% | 0.01% |
| `dither.2` | 16 | 38.1% | 0.00% |
| **TOTAL** | **42** | **100.0%** | **0.04%** |

#### plinky/synth/time

**Total:** 40 bytes (0.04 KB) | **Symbols:** 2

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `clock_tick.str1.4` | 33 | 82.5% | 0.01% |
| `ppqn_values` | 7 | 17.5% | 0.00% |
| **TOTAL** | **40** | **100.0%** | **0.04%** |

#### hard\libc_nano.a(libc_a-nano-vfprintf_i

**Total:** 34 bytes (0.03 KB) | **Symbols:** 1

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `_printf_i.str1.1` | 34 | 100.0% | 0.01% |
| **TOTAL** | **34** | **100.0%** | **0.03%** |

#### plinky/usb/tinyusb/src/usbmidi

**Total:** 30 bytes (0.03 KB) | **Symbols:** 1

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `desc_url` | 30 | 100.0% | 0.01% |
| **TOTAL** | **30** | **100.0%** | **0.03%** |

#### plinky/hardware/midi_sysex

**Total:** 24 bytes (0.02 KB) | **Symbols:** 1

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `process_sysex_byte.str1.4` | 24 | 100.0% | 0.01% |
| **TOTAL** | **24** | **100.0%** | **0.02%** |

#### plinky/hardware/leds

**Total:** 20 bytes (0.02 KB) | **Symbols:** 1

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `OutputEnableBits` | 20 | 100.0% | 0.00% |
| **TOTAL** | **20** | **100.0%** | **0.02%** |

#### hard\libc_nano.a(libc_a-nano-svfprintf

**Total:** 17 bytes (0.02 KB) | **Symbols:** 1

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `_svfprintf_r.str1.1` | 17 | 100.0% | 0.00% |
| **TOTAL** | **17** | **100.0%** | **0.02%** |

#### hard\libc_nano.a(libc_a-nano-vfprintf

**Total:** 17 bytes (0.02 KB) | **Symbols:** 1

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `_vfprintf_r.str1.1` | 17 | 100.0% | 0.00% |
| **TOTAL** | **17** | **100.0%** | **0.02%** |

#### plinky/hardware/encoder

**Total:** 16 bytes (0.02 KB) | **Symbols:** 1

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `enc_deltas.1` | 16 | 100.0% | 0.00% |
| **TOTAL** | **16** | **100.0%** | **0.02%** |

#### hard\libm.a(libm_a-e_fmod

**Total:** 16 bytes (0.02 KB) | **Symbols:** 1

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `Zero` | 16 | 100.0% | 0.00% |
| **TOTAL** | **16** | **100.0%** | **0.02%** |

#### plinky/usb/web_editor

**Total:** 8 bytes (0.01 KB) | **Symbols:** 2

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `magic_32` | 4 | 50.0% | 0.00% |
| `magic_16` | 4 | 50.0% | 0.00% |
| **TOTAL** | **8** | **100.0%** | **0.01%** |

#### hard\libm.a(libm_a-wf_log

**Total:** 1 bytes (0.00 KB) | **Symbols:** 1

| **Symbol** | **Size (bytes)** | **% of Module** | **% of Total FLASH** |
|------------|------------------|-----------------|----------------------|
| `logf.str1.4` | 1 | 100.0% | 0.00% |
| **TOTAL** | **1** | **100.0%** | **0.00%** |

