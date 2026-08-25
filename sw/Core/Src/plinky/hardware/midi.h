#pragma once
#include "utils.h"

// utils
void midi_precalc_bends(void);
void midi_clear_all(void);
void midi_panic(void);

// main
void init_midi(void);
void midi_tick(void);
void midi_update_mpe_mapping(void);
void midi_push_preset(void);
bool midi_try_get_touch(u8 string_id, s16* pressure, s16* position, u8* note_number, s32* note_offset_pitch,
                        u8* start_velocity);

// cue midi out
void midi_send_clock(void);
void midi_send_transport(MidiMessageType transport_type);
void midi_send_param(Param param_id, ModSource mod_src);
void midi_send_multi_param(MultiParam mp_id, u8 mask);

// visuals
void draw_sysex_flag(void);

// reverse lookup table
const static u8 midi_cc_table_rvs[NUM_PARAMS] = {
    [P_SHAPE] = 13,        [P_DISTORTION] = 4,    [P_PITCH] = 9,
    [P_OCT] = 255,         [P_GLIDE] = 5,         [P_INTERVAL] = 14, // Sound 1
    [P_NOISE] = 2,         [P_RESO] = 71,         [P_DEGREE] = 255,
    [P_SCALE] = 255,       [P_MICROTONE] = 255,   [P_COLUMN] = 255, // Sound 2
    [P_ENV_LVL1] = 3,      [P_ATTACK1] = 73,      [P_DECAY1] = 75,
    [P_SUSTAIN1] = 74,     [P_RELEASE1] = 72,     [P_ROOT] = 255, // Envelope 1
    [P_ENV_LVL2] = 19,     [P_ATTACK2] = 20,      [P_DECAY2] = 21,
    [P_SUSTAIN2] = 22,     [P_RELEASE2] = 23,     [P_ENV2_UNUSED] = 255, // Envelope 2
    [P_DLY_SEND] = 94,     [P_DLY_TIME] = 12,     [P_PING_PONG] = 112,
    [P_DLY_WOBBLE] = 113,  [P_DLY_FEEDBACK] = 95, [P_TEMPO] = 255, // Delay
    [P_RVB_SEND] = 91,     [P_RVB_TIME] = 92,     [P_SHIMMER] = 93,
    [P_RVB_WOBBLE] = 114,  [P_RVB_UNUSED] = 255,  [P_SWING] = 255, // Reverb
    [P_ARP_TGL] = 102,     [P_ARP_ORDER] = 103,   [P_ARP_CLK_DIV] = 104,
    [P_ARP_CHANCE] = 105,  [P_ARP_EUC_LEN] = 106, [P_ARP_OCTAVES] = 107, // Arp
    [P_LATCH_TGL] = 101,   [P_SEQ_ORDER] = 108,   [P_SEQ_CLK_DIV] = 109,
    [P_SEQ_CHANCE] = 110,  [P_SEQ_EUC_LEN] = 111, [P_GATE_LENGTH] = 11, // Sequencer
    [P_SCRUB] = 15,        [P_GR_SIZE] = 16,      [P_PLAY_SPD] = 17,
    [P_SMP_STRETCH] = 18,  [P_SAMPLE] = 82,       [P_PATTERN] = 83, // Sampler 1
    [P_SCRUB_JIT] = 116,   [P_GR_SIZE_JIT] = 117, [P_PLAY_SPD_JIT] = 118,
    [P_SMP_UNUSED1] = 119, [P_SMP_UNUSED2] = 255, [P_STEP_OFFSET] = 85, // Sampler 2
    [P_A_SCALE] = 255,     [P_A_OFFSET] = 26,     [P_A_DEPTH] = 25,
    [P_A_RATE] = 24,       [P_A_SHAPE] = 255,     [P_A_SYM] = 255, // LFO A
    [P_B_SCALE] = 255,     [P_B_OFFSET] = 29,     [P_B_DEPTH] = 28,
    [P_B_RATE] = 27,       [P_B_SHAPE] = 255,     [P_B_SYM] = 255, // LFO B
    [P_X_SCALE] = 255,     [P_X_OFFSET] = 78,     [P_X_DEPTH] = 77,
    [P_X_RATE] = 76,       [P_X_SHAPE] = 255,     [P_X_SYM] = 255, // LFO X
    [P_Y_SCALE] = 255,     [P_Y_OFFSET] = 81,     [P_Y_DEPTH] = 80,
    [P_Y_RATE] = 79,       [P_Y_SHAPE] = 255,     [P_Y_SYM] = 255, // LFO Y
    [P_SYN_LVL] = 7,       [P_SYN_WET_DRY] = 8,   [P_HPF] = 31,
    [P_MIX_UNUSED1] = 255, [P_SETTINGS1] = 255,   [P_VOLUME] = 255, // Mixer 1
    [P_IN_LVL] = 89,       [P_IN_WET_DRY] = 90,   [P_SYS_UNUSED1] = 255,
    [P_MIX_UNUSED2] = 255, [P_SETTINGS2] = 255,   [P_MIX_WIDTH] = 255, // Mixer 2
};