#pragma once
#include "utils.h"

// the msb indicates whether the range is signed
#define UNSIGNED 0
#define SIGNED 128
// the actual range is stored in the 7 lsb of a byte
#define RANGE_MASK 127

#define RAW_QUART (RAW_SIZE / 4)
#define RAW_EIGHTH (RAW_SIZE / 8)

typedef enum RangeType {
	R_UVALUE, // unsigned value
	R_SVALUE, // signed value
	R_BINARY, // on/off
	R_OCTAVE, // octave
	R_DEGREE, // degree
	R_SCALE,  // scale
	R_COLUMN, // column
	R_ROOT,   // root note
	R_DLYCLK, // delay clock
	R_SEQCLK, // sequencer clock
	R_DUACLK, // dual clock, synced & free (arp, lfos)
	R_EUCLEN, // euclid length
	R_ARPORD, // arp order
	R_ARPOCT, // arp octaves
	R_SEQORD, // seq order
	R_SAMPLE, // sample id
	R_PATN,   // pattern
	R_STOFFS, // step offset
	R_LFOSHP, // lfo shape
	R_VOLUME, // volume
	R_UNUSED,
	NUM_RANGE_TYPES,
} RangeType;

const static u16 param_info[NUM_RANGE_TYPES] = {
    [R_UVALUE] = UNSIGNED,
    [R_SVALUE] = SIGNED,
    [R_BINARY] = UNSIGNED + 2,
    [R_OCTAVE] = SIGNED + 5,
    [R_DEGREE] = SIGNED + 25,
    [R_SCALE] = UNSIGNED + NUM_SCALES,
    [R_COLUMN] = UNSIGNED + 13,
    [R_ROOT] = UNSIGNED + 12,
    [R_DLYCLK] = SIGNED + 13, // max 1 bar synced
    [R_SEQCLK] = UNSIGNED + NUM_SYNC_DIVS + 1,
    [R_DUACLK] = SIGNED + NUM_SYNC_DIVS,
    [R_EUCLEN] = UNSIGNED + 16,
    [R_ARPORD] = UNSIGNED + NUM_ARP_ORDERS,
    [R_ARPOCT] = UNSIGNED + 4,
    [R_SEQORD] = UNSIGNED + NUM_SEQ_ORDERS,
    [R_SAMPLE] = UNSIGNED + NUM_SAMPLES + 1,
    [R_PATN] = UNSIGNED + NUM_PATTERNS,
    [R_STOFFS] = SIGNED + 65,
    [R_LFOSHP] = UNSIGNED + NUM_LFO_SHAPES,
    [R_UNUSED] = 0,
};

// clang-format off

const static RangeType range_type[NUM_PARAMS] = {
   [P_SHAPE] = R_SVALUE,       [P_DISTORTION] = R_UVALUE,   [P_PITCH] = R_SVALUE,         [P_OCT] = R_OCTAVE,         [P_GLIDE] = R_UVALUE,         [P_INTERVAL] = R_SVALUE,      // Sound 1
   [P_NOISE] = R_UVALUE,       [P_RESO] = R_UVALUE,         [P_DEGREE] = R_DEGREE,        [P_SCALE] = R_SCALE,        [P_MICROTONE] = R_UVALUE,     [P_COLUMN] = R_COLUMN,        // Sound 2
   [P_ENV_LVL1] = R_UVALUE,    [P_ATTACK1] = R_UVALUE,      [P_DECAY1] = R_UVALUE,        [P_SUSTAIN1] = R_UVALUE,    [P_RELEASE1] = R_UVALUE,      [P_ROOT] = R_ROOT,            // Envelope 1
   [P_ENV_LVL2] = R_UVALUE,    [P_ATTACK2] = R_UVALUE,      [P_DECAY2] = R_UVALUE,        [P_SUSTAIN2] = R_UVALUE,    [P_RELEASE2] = R_UVALUE,      [P_ENV2_UNUSED] = R_UNUSED,   // Envelope 2
   [P_DLY_SEND] = R_UVALUE,    [P_DLY_TIME] = R_DLYCLK,     [P_PING_PONG] = R_UVALUE,     [P_DLY_WOBBLE] = R_UVALUE,  [P_DLY_FEEDBACK] = R_UVALUE,  [P_TEMPO] = R_SVALUE,         // Delay
   [P_RVB_SEND] = R_UVALUE,    [P_RVB_TIME] = R_UVALUE,     [P_SHIMMER] = R_UVALUE,       [P_RVB_WOBBLE] = R_UVALUE,  [P_RVB_UNUSED] = R_UNUSED,    [P_SWING] = R_SVALUE,         // Reverb
   [P_ARP_TGL] = R_BINARY,     [P_ARP_ORDER] = R_ARPORD,    [P_ARP_CLK_DIV] = R_DUACLK,   [P_ARP_CHANCE] = R_SVALUE,  [P_ARP_EUC_LEN] = R_EUCLEN,   [P_ARP_OCTAVES] = R_ARPOCT,   // Arp
   [P_LATCH_TGL] = R_BINARY,   [P_SEQ_ORDER] = R_SEQORD,    [P_SEQ_CLK_DIV] = R_SEQCLK,   [P_SEQ_CHANCE] = R_SVALUE,  [P_SEQ_EUC_LEN] = R_EUCLEN,   [P_GATE_LENGTH] = R_UVALUE,   // Sequencer
   [P_SCRUB] = R_UVALUE,       [P_GR_SIZE] = R_UVALUE,      [P_PLAY_SPD] = R_SVALUE,      [P_SMP_STRETCH] = R_SVALUE, [P_SAMPLE] = R_SAMPLE,        [P_PATTERN] = R_PATN,         // Sampler 1
   [P_SCRUB_JIT] = R_UVALUE,   [P_GR_SIZE_JIT] = R_UVALUE,  [P_PLAY_SPD_JIT] = R_UVALUE,  [P_SMP_UNUSED1] = R_UNUSED, [P_SMP_UNUSED2] = R_UNUSED,   [P_STEP_OFFSET] = R_STOFFS,   // Sampler 2
   [P_A_SCALE] = R_SVALUE,     [P_A_OFFSET] = R_SVALUE,     [P_A_DEPTH] = R_SVALUE,       [P_A_RATE] = R_DUACLK,      [P_A_SHAPE] = R_LFOSHP,       [P_A_SYM] = R_SVALUE,         // LFO A
   [P_B_SCALE] = R_SVALUE,     [P_B_OFFSET] = R_SVALUE,     [P_B_DEPTH] = R_SVALUE,       [P_B_RATE] = R_DUACLK,      [P_B_SHAPE] = R_LFOSHP,       [P_B_SYM] = R_SVALUE,         // LFO B
   [P_X_SCALE] = R_SVALUE,     [P_X_OFFSET] = R_SVALUE,     [P_X_DEPTH] = R_SVALUE,       [P_X_RATE] = R_DUACLK,      [P_X_SHAPE] = R_LFOSHP,       [P_X_SYM] = R_SVALUE,         // LFO X
   [P_Y_SCALE] = R_SVALUE,     [P_Y_OFFSET] = R_SVALUE,     [P_Y_DEPTH] = R_SVALUE,       [P_Y_RATE] = R_DUACLK,      [P_Y_SHAPE] = R_LFOSHP,       [P_Y_SYM] = R_SVALUE,         // LFO Y
   [P_SYN_LVL] = R_UVALUE,     [P_SYN_WET_DRY] = R_UVALUE,  [P_HPF] = R_UVALUE,           [P_MIX_UNUSED1] = R_UNUSED, [P_SETTINGS1] = R_UNUSED,     [P_VOLUME] = R_UVALUE,        // Mixer 1
   [P_IN_LVL] = R_UVALUE,      [P_IN_WET_DRY] = R_UVALUE,   [P_SYS_UNUSED1] = R_UNUSED,   [P_MIX_UNUSED2] = R_UNUSED, [P_SETTINGS2] = R_UNUSED,     [P_MIX_WIDTH] = R_UVALUE,     // Mixer 2
};

const static Preset init_params = {
    .seq_start = 0,
    .seq_len = 8,
    .version = LPE_PRESET_VERSION,
    .params = {
        [P_SHAPE] = {0},            [P_DISTORTION] = {RAW_HALF},                                [P_PITCH] = {0},                                    [P_OCT] = {0},                  [P_GLIDE] = {0},                            [P_INTERVAL] = {0},                 // Sound 1
        [P_NOISE] = {0},            [P_RESO] = {0},                                             [P_DEGREE] = {0},                                   [P_SCALE] = {0},                [P_MICROTONE] = {RAW_EIGHTH},               [P_COLUMN] = {INDEX_TO_RAW(7, 13)}, // Sound 2
        [P_ENV_LVL1] = {RAW_HALF},  [P_ATTACK1] = {RAW_EIGHTH},                                 [P_DECAY1] = {RAW_QUART},                           [P_SUSTAIN1] = {RAW_SIZE},      [P_RELEASE1] = {RAW_EIGHTH},                [P_ROOT] = {0},                     // Envelope 1
        [P_ENV_LVL2] = {RAW_HALF},  [P_ATTACK2] = {RAW_EIGHTH},                                 [P_DECAY2] = {RAW_QUART},                           [P_SUSTAIN2] = {RAW_SIZE},      [P_RELEASE2] = {RAW_EIGHTH},                [P_ENV2_UNUSED] = {0},               // Envelope 2
        [P_DLY_SEND] = {0},         [P_DLY_TIME] = {INDEX_TO_RAW(3, NUM_SYNC_DIVS)},            [P_PING_PONG] = {RAW_SIZE},                         [P_DLY_WOBBLE] = {RAW_QUART},   [P_DLY_FEEDBACK] = {RAW_HALF},              [P_TEMPO] = {0},                    // Delay
        [P_RVB_SEND] = {RAW_QUART}, [P_RVB_TIME] = {RAW_HALF},                                  [P_SHIMMER] = {RAW_QUART},                          [P_RVB_WOBBLE] = {RAW_QUART},   [P_RVB_UNUSED] = {0},                        [P_SWING] = {0},                    // Reverb
        [P_ARP_TGL] = {0},          [P_ARP_ORDER] = {INDEX_TO_RAW(ARP_UP, NUM_ARP_ORDERS)},     [P_ARP_CLK_DIV] = {INDEX_TO_RAW(2, NUM_SYNC_DIVS)}, [P_ARP_CHANCE] = {RAW_SIZE},    [P_ARP_EUC_LEN] = {INDEX_TO_RAW(8, 17)},    [P_ARP_OCTAVES] = {0},              // Arp
        [P_LATCH_TGL] = {0},        [P_SEQ_ORDER] = {INDEX_TO_RAW(SEQ_ORD_FWD, NUM_SEQ_ORDERS)},[P_SEQ_CLK_DIV] = {INDEX_TO_RAW(5, NUM_SYNC_DIVS)}, [P_SEQ_CHANCE] = {RAW_SIZE},    [P_SEQ_EUC_LEN] = {INDEX_TO_RAW(8, 17)},    [P_GATE_LENGTH] = {RAW_SIZE},       // Sequencer
        [P_SCRUB] = {0},            [P_GR_SIZE] = {RAW_HALF},                                   [P_PLAY_SPD] = {RAW_HALF},                          [P_SMP_STRETCH] = {RAW_HALF},   [P_SAMPLE] = {0},                           [P_PATTERN] = {0},                  // Sampler 1
        [P_SCRUB_JIT] = {0},        [P_GR_SIZE_JIT] = {0},                                      [P_PLAY_SPD_JIT] = {0},                             [P_SMP_UNUSED1] = {0},           [P_SMP_UNUSED2] = {0},                       [P_STEP_OFFSET] = {0},              // Sampler 2
        [P_A_SCALE] = {RAW_HALF},   [P_A_OFFSET] = {0},                                         [P_A_DEPTH] = {0},                                  [P_A_RATE] = {-RAW_HALF},       [P_A_SHAPE] = {0},                          [P_A_SYM] = {0},                    // LFO A
        [P_B_SCALE] = {RAW_HALF},   [P_B_OFFSET] = {0},                                         [P_B_DEPTH] = {0},                                  [P_B_RATE] = {-562},            [P_B_SHAPE] = {0},                          [P_B_SYM] = {0},                    // LFO B
        [P_X_SCALE] = {RAW_HALF},   [P_X_OFFSET] = {0},                                         [P_X_DEPTH] = {0},                                  [P_X_RATE] = {-451},            [P_X_SHAPE] = {0},                          [P_X_SYM] = {0},                    // LFO X
        [P_Y_SCALE] = {RAW_HALF},   [P_Y_OFFSET] = {0},                                         [P_Y_DEPTH] = {0},                                  [P_Y_RATE] = {-355},            [P_Y_SHAPE] = {0},                          [P_Y_SYM] = {0},                    // LFO Y
        [P_SYN_LVL] = {RAW_HALF},   [P_SYN_WET_DRY] = {RAW_HALF},                               [P_HPF] = {0},                                      [P_MIX_UNUSED1] = {0},           [P_SETTINGS1] = {0},                         [P_VOLUME] = {0},                   // Mixer 1
        [P_IN_LVL] = {RAW_HALF},    [P_IN_WET_DRY] = {RAW_HALF},                                [P_SYS_UNUSED1] = {0},                               [P_MIX_UNUSED2] = {0},           [P_SETTINGS2] = {0},                         [P_MIX_WIDTH] = {RAW_SIZE * 7 / 8}, // Mixer 2
    },
    .multi_params = {
        [MP_SHAPE]       = {0, 0, 0, 0, 0, 0, 0},
        [MP_DISTORTION]  = {RAW_HALF, RAW_HALF, RAW_HALF, RAW_HALF, RAW_HALF, RAW_HALF, RAW_HALF},
        [MP_PITCH]       = {0, 0, 0, 0, 0, 0, 0},
        [MP_OCT]         = {0, 0, 0, 0, 0, 0, 0},
        [MP_GLIDE]       = {0, 0, 0, 0, 0, 0, 0},
        [MP_INTERVAL]    = {0, 0, 0, 0, 0, 0, 0},
        [MP_NOISE]       = {0, 0, 0, 0, 0, 0, 0},
        [MP_RESO]        = {0, 0, 0, 0, 0, 0, 0},
        [MP_DEGREE]      = {0, 0, 0, 0, 0, 0, 0},
        [MP_SCALE]       = {0, 0, 0, 0, 0, 0, 0},
        [MP_MICROTONE]   = {RAW_EIGHTH, RAW_EIGHTH, RAW_EIGHTH, RAW_EIGHTH, RAW_EIGHTH, RAW_EIGHTH, RAW_EIGHTH},
        [MP_COLUMN]      = {INDEX_TO_RAW(7, 13), INDEX_TO_RAW(7, 13), INDEX_TO_RAW(7, 13), INDEX_TO_RAW(7, 13), INDEX_TO_RAW(7, 13), INDEX_TO_RAW(7, 13), INDEX_TO_RAW(7, 13)},
        [MP_ENV_LVL1]    = {RAW_HALF, RAW_HALF, RAW_HALF, RAW_HALF, RAW_HALF, RAW_HALF, RAW_HALF},
        [MP_ATTACK1]     = {RAW_EIGHTH, RAW_EIGHTH, RAW_EIGHTH, RAW_EIGHTH, RAW_EIGHTH, RAW_EIGHTH, RAW_EIGHTH},
        [MP_DECAY1]      = {RAW_QUART, RAW_QUART, RAW_QUART, RAW_QUART, RAW_QUART, RAW_QUART, RAW_QUART},
        [MP_SUSTAIN1]    = {RAW_SIZE, RAW_SIZE, RAW_SIZE, RAW_SIZE, RAW_SIZE, RAW_SIZE, RAW_SIZE},
        [MP_RELEASE1]    = {RAW_EIGHTH, RAW_EIGHTH, RAW_EIGHTH, RAW_EIGHTH, RAW_EIGHTH, RAW_EIGHTH, RAW_EIGHTH},
        [MP_ROOT]        = {0, 0, 0, 0, 0, 0, 0},
        [MP_ENV_LVL2]    = {RAW_HALF, RAW_HALF, RAW_HALF, RAW_HALF, RAW_HALF, RAW_HALF, RAW_HALF},
        [MP_ATTACK2]     = {RAW_EIGHTH, RAW_EIGHTH, RAW_EIGHTH, RAW_EIGHTH, RAW_EIGHTH, RAW_EIGHTH, RAW_EIGHTH},
        [MP_DECAY2]      = {RAW_QUART, RAW_QUART, RAW_QUART, RAW_QUART, RAW_QUART, RAW_QUART, RAW_QUART},
        [MP_SUSTAIN2]    = {RAW_SIZE, RAW_SIZE, RAW_SIZE, RAW_SIZE, RAW_SIZE, RAW_SIZE, RAW_SIZE},
        [MP_RELEASE2]    = {RAW_EIGHTH, RAW_EIGHTH, RAW_EIGHTH, RAW_EIGHTH, RAW_EIGHTH, RAW_EIGHTH, RAW_EIGHTH},
        [MP_ARP_TGL]     = {0, 0, 0, 0, 0, 0, 0},
        [MP_LATCH_TGL]   = {0, 0, 0, 0, 0, 0, 0},
        [MP_GATE_LENGTH] = {RAW_SIZE, RAW_SIZE, RAW_SIZE, RAW_SIZE, RAW_SIZE, RAW_SIZE, RAW_SIZE},
        [MP_SCRUB]       = {0, 0, 0, 0, 0, 0, 0},
        [MP_GR_SIZE]     = {RAW_HALF, RAW_HALF, RAW_HALF, RAW_HALF, RAW_HALF, RAW_HALF, RAW_HALF},
        [MP_PLAY_SPD]    = {RAW_HALF, RAW_HALF, RAW_HALF, RAW_HALF, RAW_HALF, RAW_HALF, RAW_HALF},
        [MP_SMP_STRETCH] = {RAW_HALF, RAW_HALF, RAW_HALF, RAW_HALF, RAW_HALF, RAW_HALF, RAW_HALF},
        [MP_SCRUB_JIT]   = {0, 0, 0, 0, 0, 0, 0},
        [MP_GR_SIZE_JIT] = {0, 0, 0, 0, 0, 0, 0},
        [MP_PLAY_SPD_JIT] = {0, 0, 0, 0, 0, 0, 0},
    }
};

const static char* const param_row_name[R_NUM_ROWS] = {

    [R_SOUND1] = I_SLIDERS "Sound", [R_SOUND2] = I_SLIDERS "Sound", [R_ENV1] = I_ENV "Env 1",
    [R_ENV2] = I_ENV "Env 2",       [R_ARP] = I_NOTES "Arp",        [R_SEQ] = I_NOTES "Seq",
    [R_DLY] = I_DELAY "Delay",      [R_RVB] = I_REVERB "Reverb",    [R_A] = I_ALFO "LFO",
    [R_B] = I_BLFO "LFO",           [R_X] = I_XLFO "LFO",           [R_Y] = I_YLFO "LFO",
    [R_SMP1] = I_WAVE "Sample",     [R_SMP2] = I_WAVE "Sample",     [R_MIX1] = I_SLIDERS "Mixer",
    [R_MIX2] = I_SLIDERS "Mixer"

};

const static Param param_from_multi_param[NUM_MULTI_PARAMS] = {
    [MP_SHAPE] = P_SHAPE,           [MP_DISTORTION] = P_DISTORTION,     [MP_PITCH] = P_PITCH,           [MP_OCT] = P_OCT,               [MP_GLIDE] = P_GLIDE,           [MP_INTERVAL] = P_INTERVAL,	// Sound 1
    [MP_NOISE] = P_NOISE,           [MP_RESO] = P_RESO,                 [MP_DEGREE] = P_DEGREE,         [MP_SCALE] = P_SCALE,           [MP_MICROTONE] = P_MICROTONE,   [MP_COLUMN] = P_COLUMN,   	// Sound 2
    [MP_ENV_LVL1] = P_ENV_LVL1,     [MP_ATTACK1] = P_ATTACK1,           [MP_DECAY1] = P_DECAY1,         [MP_SUSTAIN1] = P_SUSTAIN1,     [MP_RELEASE1] = P_RELEASE1,     [MP_ROOT] = P_ROOT,         // Envelope 1
    [MP_ENV_LVL2] = P_ENV_LVL2,     [MP_ATTACK2] = P_ATTACK2,           [MP_DECAY2] = P_DECAY2,         [MP_SUSTAIN2] = P_SUSTAIN2,     [MP_RELEASE2] = P_RELEASE2,                               	// Envelope 2
	[MP_ARP_TGL] = P_ARP_TGL,		[MP_LATCH_TGL] = P_LATCH_TGL,		[MP_GATE_LENGTH] = P_GATE_LENGTH,
    [MP_SCRUB] = P_SCRUB,           [MP_GR_SIZE] = P_GR_SIZE,           [MP_PLAY_SPD] = P_PLAY_SPD,     [MP_SMP_STRETCH] = P_SMP_STRETCH,                                                          	// Sampler 1
    [MP_SCRUB_JIT] = P_SCRUB_JIT,   [MP_GR_SIZE_JIT] = P_GR_SIZE_JIT,   [MP_PLAY_SPD_JIT] = P_PLAY_SPD_JIT,                                                                                       	// Sampler 2
};

const static MultiParam multi_param_from_param[P_PLAY_SPD_JIT + 1] = {
    [P_SHAPE] = MP_SHAPE,           [P_DISTORTION] = MP_DISTORTION,     [P_PITCH] = MP_PITCH,           [P_OCT] = MP_OCT,               [P_GLIDE] = MP_GLIDE,           [P_INTERVAL] = MP_INTERVAL,	// Sound 1
    [P_NOISE] = MP_NOISE,           [P_RESO] = MP_RESO,                 [P_DEGREE] = MP_DEGREE,         [P_SCALE] = MP_SCALE,           [P_MICROTONE] = MP_MICROTONE,   [P_COLUMN] = MP_COLUMN,   	// Sound 2
    [P_ENV_LVL1] = MP_ENV_LVL1,     [P_ATTACK1] = MP_ATTACK1,           [P_DECAY1] = MP_DECAY1,         [P_SUSTAIN1] = MP_SUSTAIN1,     [P_RELEASE1] = MP_RELEASE1,     [P_ROOT] = MP_ROOT,         // Envelope 1
    [P_ENV_LVL2] = MP_ENV_LVL2,     [P_ATTACK2] = MP_ATTACK2,           [P_DECAY2] = MP_DECAY2,         [P_SUSTAIN2] = MP_SUSTAIN2,     [P_RELEASE2] = MP_RELEASE2,                               	// Envelope 2
	[P_ARP_TGL] = MP_ARP_TGL,		[P_LATCH_TGL] = MP_LATCH_TGL,		[P_GATE_LENGTH] = MP_GATE_LENGTH,
    [P_SCRUB] = MP_SCRUB,           [P_GR_SIZE] = MP_GR_SIZE,           [P_PLAY_SPD] = MP_PLAY_SPD,     [P_SMP_STRETCH] = MP_SMP_STRETCH,                                                          	// Sampler 1
    [P_SCRUB_JIT] = MP_SCRUB_JIT,   [P_GR_SIZE_JIT] = MP_GR_SIZE_JIT,   [P_PLAY_SPD_JIT] = MP_PLAY_SPD_JIT,    
};

const static LayoutParam layout_param_from_param[P_ROOT + 1] = {
	[P_ROOT] = LP_ROOT, [P_OCT] = LP_OCT, [P_SCALE] = LP_SCALE, [P_COLUMN] = LP_COLUMN,
};

// clang-format off

const static char* const param_name[NUM_PARAMS] = {
   [P_SHAPE] = I_SHAPE "WTable Pos",      	[P_DISTORTION] = I_DISTORT "Distortion",   	[P_PITCH] = I_PIANO "Pitch",         		[P_OCT] = I_OCTAVE "Octave",         	[P_GLIDE] = I_GLIDE "Glide",         		[P_INTERVAL] = I_OFFSET "Interval",			// Sound 1
   [P_NOISE] = I_WAVE "Noise",       		[P_RESO] = I_DISTORT "Resonance",         	[P_DEGREE] = I_OFFSET "Degree",       		[P_SCALE] = I_PIANO "Scale",        	[P_MICROTONE] = I_MICRO "Microtone",     	[P_COLUMN] = I_OFFSET "Column Semis",		// Sound 2
   [P_ENV_LVL1] = I_TOUCH "Sens",			[P_ATTACK1] = I_ADSR_A "Attack",      		[P_DECAY1] = I_ADSR_D "Decay",        		[P_SUSTAIN1] = I_ADSR_S "Sustain",    	[P_RELEASE1] = I_ADSR_R "Release",      	[P_ROOT] = I_PIANO "Root",   				// Envelope 1
   [P_ENV_LVL2] = I_AMPLITUDE "Level",  	[P_ATTACK2] = I_ADSR_A "Attack",      		[P_DECAY2] = I_ADSR_D "Decay",        		[P_SUSTAIN2] = I_ADSR_S "Sustain",    	[P_RELEASE2] = I_ADSR_R "Release",      	[P_ENV2_UNUSED] = I_CROSS "<unused>",   	// Envelope 2
   [P_DLY_SEND] = I_SEND "Send",    		[P_DLY_TIME] = I_TEMPO "Clock Div",     	[P_PING_PONG] = I_TILT "2nd Tap",     		[P_DLY_WOBBLE] = I_WAVE "Wobble",  		[P_DLY_FEEDBACK] = I_FEEDBACK "Feedback",	[P_TEMPO] = I_PLAY "Tempo",         		// Delay
   [P_RVB_SEND] = I_SEND "Send",    		[P_RVB_TIME] = I_TIME "Time",     			[P_SHIMMER] = I_FEEDBACK "Shimmer",     	[P_RVB_WOBBLE] = I_WAVE "Wobble",  		[P_RVB_UNUSED] = I_CROSS "<unused>",    	[P_SWING] = I_TILT "Swing 8th",         	// Reverb
   [P_ARP_TGL] = I_PLAY "Enable",     		[P_ARP_ORDER] = I_ORDER "Order",    		[P_ARP_CLK_DIV] = I_TEMPO "Clock Div",   	[P_ARP_CHANCE] = I_PERCENT "Chance (S)",[P_ARP_EUC_LEN] = I_LENGTH "Euclid Len",   	[P_ARP_OCTAVES] = I_OCTAVE "Octaves",   	// Arp
   [P_LATCH_TGL] = I_PLAY "Enable",   		[P_SEQ_ORDER] = I_ORDER "Order",    		[P_SEQ_CLK_DIV] = I_TEMPO "Clock Div",   	[P_SEQ_CHANCE] = I_PERCENT "Chance (S)",[P_SEQ_EUC_LEN] = I_LENGTH "Euclid Len",   	[P_GATE_LENGTH] = I_INTERVAL "Gate Len",	// Sequencer
   [P_SCRUB] = I_RIGHT "Scrub",       		[P_GR_SIZE] = I_PERIOD "Grain Size",      	[P_PLAY_SPD] = I_RIGHT "Play Spd",      	[P_SMP_STRETCH] = I_TIME "Stretch", 	[P_SAMPLE] = I_SEQ "ID",        			[P_PATTERN] = I_SEQ "Pattern ID",      		// Sampler 1
   [P_SCRUB_JIT] = I_RIGHT "Scrub Jit",		[P_GR_SIZE_JIT] = I_PERIOD "Size Jit",		[P_PLAY_SPD_JIT] = I_RIGHT "Spd Jit",		[P_SMP_UNUSED1] = I_CROSS "<unused>", 	[P_SMP_UNUSED2] = I_CROSS "<unused>",   	[P_STEP_OFFSET] = I_OFFSET "Step Ofs",   	// Sampler 2
   [P_A_SCALE] = I_AMPLITUDE "CV Depth",    [P_A_OFFSET] = I_OFFSET "Offset",     		[P_A_DEPTH] = I_AMPLITUDE "Depth",			[P_A_RATE] = I_TEMPO "Clock Div",		[P_A_SHAPE] = I_SHAPE "Shape",       		[P_A_SYM] = I_WARP "Symmetry",         		// LFO A
   [P_B_SCALE] = I_AMPLITUDE "CV Depth",    [P_B_OFFSET] = I_OFFSET "Offset",     		[P_B_DEPTH] = I_AMPLITUDE "Depth",			[P_B_RATE] = I_TEMPO "Clock Div",      	[P_B_SHAPE] = I_SHAPE "Shape",       		[P_B_SYM] = I_WARP "Symmetry",         		// LFO B
   [P_X_SCALE] = I_AMPLITUDE "CV Depth",    [P_X_OFFSET] = I_OFFSET "Offset",     		[P_X_DEPTH] = I_AMPLITUDE "Depth",			[P_X_RATE] = I_TEMPO "Clock Div",      	[P_X_SHAPE] = I_SHAPE "Shape",       		[P_X_SYM] = I_WARP "Symmetry",         		// LFO X
   [P_Y_SCALE] = I_AMPLITUDE "CV Depth",    [P_Y_OFFSET] = I_OFFSET "Offset",     		[P_Y_DEPTH] = I_AMPLITUDE "Depth",			[P_Y_RATE] = I_TEMPO "Clock Div",      	[P_Y_SHAPE] = I_SHAPE "Shape",       		[P_Y_SYM] = I_WARP "Symmetry",         		// LFO Y
   [P_SYN_LVL] = I_WAVE "Synth Lvl",    	[P_SYN_WET_DRY] = I_REVERB "Wet/Dry",		[P_HPF] = I_HPF "High Pass",           		[P_MIX_UNUSED1] = I_CROSS "<unused>",  	[P_SETTINGS1] = I_CROSS "<unused>",     	[P_VOLUME] = I_PHONES "Volume",        		// Mixer 1
   [P_IN_LVL] = I_JACK "Input Lvl",     	[P_IN_WET_DRY] = I_JACK "In Wet/Dry",   	[P_SYS_UNUSED1] = I_CROSS "<unused>",   	[P_MIX_UNUSED2] = I_CROSS "<unused>",	[P_SETTINGS2] = I_CROSS "<unused>",			[P_MIX_WIDTH] = I_PHONES "Width",			// Mixer 2
};

// clang-format on

const static char* const mod_src_name[NUM_MOD_SOURCES] = {
    [SRC_BASE] = I_SLIDERS "Base", [SRC_ENV2] = I_ENV "Env 2 >>",  [SRC_PRES] = I_TOUCH "Pres >>",
    [SRC_LFO_A] = I_A "Mod A >>",  [SRC_LFO_B] = I_B "Mod B >>",   [SRC_LFO_X] = I_X "Mod X >>",
    [SRC_LFO_Y] = I_Y "Mod Y >>",  [SRC_RND] = I_RANDOM "Rand >>",
};

const static char* const arp_mode_name[NUM_ARP_ORDERS] = {
    [ARP_UP] = "Up",
    [ARP_DOWN] = "Down",
    [ARP_UPDOWN] = "Up/Down",
    [ARP_UPDOWN_REP] = "Up/Down\nRepeat",
    [ARP_PEDAL_UP] = "Up\nPedal",
    [ARP_PEDAL_DOWN] = "Down\nPedal",
    [ARP_PEDAL_UPDOWN] = "Up/Down\nPedal",
    [ARP_SHUFFLE] = "Shuffle",
    [ARP_SHUFFLE2] = "Shuffle 2x",
    [ARP_CHORD] = "Chord",
    [ARP_UP8] = "Up\n8 Steps",
    [ARP_DOWN8] = "Down\n8 Steps",
    [ARP_UPDOWN8] = "Up/Down\n8 Steps",
    [ARP_SHUFFLE8] = "Shuffle\n8 Steps",
    [ARP_SHUFFLE28] = "Shuffle 2x\n8 Steps",
};

const static char* const seq_mode_name[NUM_SEQ_ORDERS] = {
    [SEQ_ORD_PAUSE] = "Pause",
    [SEQ_ORD_FWD] = "Forward",
    [SEQ_ORD_BACK] = "Reverse",
    [SEQ_ORD_PINGPONG] = "Ping Pong",
    [SEQ_ORD_PINGPONG_REP] = "Ping Pong\nRepeat",
    [SEQ_ORD_SHUFFLE] = "Shuffle",
};

static const char* const lfo_shape_name[NUM_LFO_SHAPES] = {
    [LFO_TRI] = "Triangle",
    [LFO_SIN] = "Sine",
    [LFO_SMOOTH_RAND] = "Random\nSmooth",
    [LFO_STEP_RAND] = "Random\nStepped",
    [LFO_BI_SQUARE] = "Square\nBipolar",
    [LFO_SQUARE] = "Square\nUnipolar",
    [LFO_CASTLE] = "Castle",
    [LFO_SAW] = "Saw",
    [LFO_BI_TRIGS] = "Triggers\nBipolar",
    [LFO_TRIGS] = "Triggers\nUnipolar",
    [LFO_ENV] = "Envelope",
};

const static char* const scale_name[NUM_SCALES] = {
    [S_MAJOR] = "Major",
    [S_MINOR] = "Minor",
    [S_HARMMINOR] = "Harmonic",
    [S_PENTA] = "Penta\nMajor",
    [S_PENTAMINOR] = "Penta\nMinor",
    [S_HIRAJOSHI] = "Hirajoshi",
    [S_INSEN] = "Insen",
    [S_IWATO] = "Iwato",
    [S_MINYO] = "Minyo",
    [S_FIFTHS] = "Fifths",
    [S_TRIADMAJOR] = "Triad\nMajor",
    [S_TRIADMINOR] = "Triad\nMinor",
    [S_DORIAN] = "Dorian",
    [S_PHYRGIAN] = "Phrygian",
    [S_LYDIAN] = "Lydian",
    [S_MIXOLYDIAN] = "Mixolydian",
    [S_AEOLIAN] = "Aeolian",
    [S_LOCRIAN] = "Lacrian",
    [S_BLUESMINOR] = "Blues\nMinor",
    [S_BLUESMAJOR] = "Blues\nMajor",
    [S_ROMANIAN] = "Romanian",
    [S_WHOLETONE] = "Wholetone",
    [S_HARMONICS] = "Harmonics",
    [S_HEXANY] = "Hexany",
    [S_JUST] = "Just",
    [S_CHROMATIC] = "Chromatic",
    [S_DIMINISHED] = "Diminished",
};