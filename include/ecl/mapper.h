#ifndef MAPPER_H
#define MAPPER_H

// instruction mapper
#define NR_INS 137

#define INS_000 "nop"
#define INS_001 "delete"
#define INS_002 "jmp"
#define INS_003 "loop"
#define INS_004 "iset"
#define INS_005 "fset"
#define INS_006 "iset_r"
#define INS_007 "iset_r2"
#define INS_008 "fset_r"
#define INS_009 "fset_r2"
#define INS_010 "get_x"
#define INS_011 "get_y"
#define INS_012 "get_z"
#define INS_013 "iadd"
#define INS_014 "isub"
#define INS_015 "imul"
#define INS_016 "idiv"
#define INS_017 "imod"
#define INS_018 "inc"
#define INS_019 "dec"
#define INS_020 "fadd"
#define INS_021 "fsub"
#define INS_022 "fmul"
#define INS_023 "fdiv"
#define INS_024 "fmod"
#define INS_025 "atan2"
#define INS_026 "norm_r"
#define INS_027 "itest"
#define INS_028 "ftest"
#define INS_029 "jmp_l"
#define INS_030 "jmp_le"
#define INS_031 "jmp_e"
#define INS_032 "jmp_g"
#define INS_033 "jmp_ge"
#define INS_034 "jmp_n"
#define INS_035 "call"
#define INS_036 "return"
#define INS_037 "call_l"
#define INS_038 "call_le"
#define INS_039 "call_e"
#define INS_040 "call_g"
#define INS_041 "call_ge"
#define INS_042 "call_n"
#define INS_043 "pos"
#define INS_044 "ins_44"
#define INS_045 "dir"
#define INS_046 "rot"
#define INS_047 "spd"
#define INS_048 "acc"
#define INS_049 "rot_r"
#define INS_050 "rot_r2"
#define INS_051 "rot_aim"
#define INS_052 "it_dec"
#define INS_053 "it_dec2"
#define INS_054 "it_acc"
#define INS_055 "it_acc2"
#define INS_056 "it_pt_lin"
#define INS_057 "it_pt_dec"
#define INS_058 "it_pt_dec2"
#define INS_059 "it_pt_acc"
#define INS_060 "it_pt_acc2"
#define INS_061 "it_t_dec"
#define INS_062 "it_t_dec2"
#define INS_063 "it_t_acc"
#define INS_064 "it_t_acc2"
#define INS_065 "clip"
#define INS_066 "unclip"
#define INS_067 "et_on_fan_aim"
#define INS_068 "et_on_fan"
#define INS_069 "et_on_cir_aim"
#define INS_070 "et_on_cir"
#define INS_071 "et_on_cir2_aim"
#define INS_072 "et_on_cir2"
#define INS_073 "et_on_random_r"
#define INS_074 "et_on_random_sp"
#define INS_075 "et_on_random"
#define INS_076 "et_auto"
#define INS_077 "et_auto_delay"
#define INS_078 "et_delay"
#define INS_079 "et_on"
#define INS_080 "et_on2"
#define INS_081 "et_ofs"
#define INS_082 "et_ex"
#define INS_083 "et_clear"
#define INS_084 "et_se"
#define INS_085 "laser_on"
#define INS_086 "laser_on_aim"
#define INS_087 "laser_id"
#define INS_088 "laser_rot"
#define INS_089 "laser_aim"
#define INS_090 "laser_ofs"
#define INS_091 "laser_test"
#define INS_092 "laser_break"
#define INS_093 "card"
#define INS_094 "card_end"
#define INS_095 "enm_new"
#define INS_096 "enm_clear"
#define INS_097 "anm_at"
#define INS_098 "anm_at_move"
#define INS_099 "anm_at2"
#define INS_100 "anm_at_dead"
#define INS_101 "boss_set"
#define INS_102 "boss_card"
#define INS_103 "hitbox_set"
#define INS_104 "hit_set"
#define INS_105 "hurt_set"
#define INS_106 "se_play"
#define INS_107 "flag_death_set"
#define INS_108 "death_at"
#define INS_109 "interrupt"
#define INS_110 "interrupt_run"
#define INS_111 "life"
#define INS_112 "timeout"
#define INS_113 "life_at_amt"
#define INS_114 "life_at"
#define INS_115 "time_at_amt"
#define INS_116 "time_at"
#define INS_117 "invinc_set"
#define INS_118 "eff_at"
#define INS_119 "item_drop"
#define INS_120 "anm_rot_set"
#define INS_121 "func_call"
#define INS_122 "func_set"
#define INS_123 "func_time_set"
#define INS_124 "item_drop2"
#define INS_125 "ins_125"
#define INS_126 "boss_lives_set"
#define INS_127 "debug_watch"
#define INS_128 "anm_break"
#define INS_129 "anm_break2"
#define INS_130 "flag_call_stack_disable"
#define INS_131 "et_diff_set"
#define INS_132 "inv_set"
#define INS_133 "ins_133"
#define INS_134 "laser_clear"
#define INS_135 "time_card_set"
#define INS_136 "bp"

#define INS_LIST {INS_000, INS_001, INS_002, INS_003, INS_004, INS_005, INS_006, INS_007, INS_008, INS_009, INS_010, INS_011, INS_012, INS_013, INS_014, INS_015, INS_016, INS_017, INS_018, INS_019, INS_020, INS_021, INS_022, INS_023, INS_024, INS_025, INS_026, INS_027, INS_028, INS_029, INS_030, INS_031, INS_032, INS_033, INS_034, INS_035, INS_036, INS_037, INS_038, INS_039, INS_040, INS_041, INS_042, INS_043, INS_044, INS_045, INS_046, INS_047, INS_048, INS_049, INS_050, INS_051, INS_052, INS_053, INS_054, INS_055, INS_056, INS_057, INS_058, INS_059, INS_060, INS_061, INS_062, INS_063, INS_064, INS_065, INS_066, INS_067, INS_068, INS_069, INS_070, INS_071, INS_072, INS_073, INS_074, INS_075, INS_076, INS_077, INS_078, INS_079, INS_080, INS_081, INS_082, INS_083, INS_084, INS_085, INS_086, INS_087, INS_088, INS_089, INS_090, INS_091, INS_092, INS_093, INS_094, INS_095, INS_096, INS_097, INS_098, INS_099, INS_100, INS_101, INS_102, INS_103, INS_104, INS_105, INS_106, INS_107, INS_108, INS_109, INS_110, INS_111, INS_112, INS_113, INS_114, INS_115, INS_116, INS_117, INS_118, INS_119, INS_120, INS_121, INS_122, INS_123, INS_124, INS_125, INS_126, INS_127, INS_128, INS_129, INS_130, INS_131, INS_132, INS_133, INS_134, INS_135, INS_136}

#define NR_FIELD 25

#define FIELD_RANK "RANK"
#define FIELD_DIFFICULTY "DIFFICULTY"
#define FIELD_X "X"
#define FIELD_Y "Y"
#define FIELD_Z "Z"
#define FIELD_PLAYER_X "PLAYER_X"
#define FIELD_PLAYER_Y "PLAYER_Y"
#define FIELD_PLAYER_Z "PLAYER_Z"
#define FIELD_AIM "AIM"
#define FIELD_TIME "TIME"
#define FIELD_DIST "DIST"
#define FIELD_LIFE "LIFE"
#define FIELD_SHOT_TYPE "SHOT_TYPE"

#define FIELD_RANK_ID 12
#define FIELD_DIFFICULTY_ID 13
#define FIELD_X_ID 14
#define FIELD_Y_ID 15
#define FIELD_Z_ID 16
#define FIELD_PLAYER_X_ID 17
#define FIELD_PLAYER_Y_ID 18
#define FIELD_PLAYER_Z_ID 19
#define FIELD_AIM_ID 20
#define FIELD_TIME_ID 21
#define FIELD_DIST_ID 22
#define FIELD_LIFE_ID 23
#define FIELD_SHOT_TYPE_ID 24

#define LOCAL_LIST {"I0", "I1", "I2", "I3", "F0", "F1", "F2", "F3", "I4", "I5", "I6", "I7", FIELD_RANK, FIELD_DIFFICULTY, FIELD_X, FIELD_Y, FIELD_Z, FIELD_PLAYER_X, FIELD_PLAYER_Y, FIELD_PLAYER_Z, FIELD_AIM, FIELD_TIME, FIELD_DIST, FIELD_LIFE, FIELD_SHOT_TYPE};

extern int ins_arg_count[];
extern void *ins_prg[];

#endif
