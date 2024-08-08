#ifndef TEXTURE_OFFSET_H
#define TEXTURE_OFFSET_H

#include <openstg.h>

// convenient inlines to process pos_t
static inline v2i add_x(v2i p, int delta)
{
	p.x += delta;
	return p;
}

static inline v2i add_y(v2i p, int delta)
{
	p.y += delta;
	return p;
}

// generic_0.png
// left top
#define P_ITEM_UV (v2i){0*16, 0}
#define POINT_ITEM_UV (v2i){1*16, 0}
#define BIG_P_ITEM_UV (v2i){2*16, 0}
#define BOMB_ITEM_UV (v2i){3*16, 0}
#define FULL_ITEM_UV (v2i){4*16, 0}
#define PLAYER_ITEM_UV (v2i){5*16, 0}
#define BULLET_ITEM_UV (v2i){6*16, 0}
#define P_SIGN_UV (v2i){8*16, 0}
#define POINT_SIGN_UV (v2i){9*16, 0}
#define BIG_P_SIGN_UV (v2i){10*16, 0}
#define BOMB_SIGN_UV (v2i){11*16, 0}
#define FULL_SIGN_UV (v2i){12*16, 0}
#define PLAYER_SIGN_UV (v2i){13*16, 0}
#define BULLET_SIGN_UV (v2i){14*16, 0}
#define ITEM_SZ (v2i){16, 15}

// colour define (X coord for 16x16 bullet)
#define BLACK 0*16
#define RED 1*16
#define LIGHT_RED 2*16
#define MAGENTA 3*16
#define LIGHT_MAGENTA 4*16
#define BLUE 5*16
#define LIGHT_BLUE 6*16
#define CYAN 7*16
#define LIGHT_CYAN 8*16
#define GREEN 9*16
#define LIGHT_GREEN 10*16
#define COLOR_11 11*16
#define YELLOW 12*16
#define LIGHT_YELLOW 13*16
#define ORANGE 14*16
#define WHITE 15*16

//bullet type
#define LASER 0*16+16
#define RING 1*16+16
#define SMALL_BALL 2*16+16
#define ELLIPSE 3*16+16
#define NIDDLE 4*16+16
#define CRYSTAL 5*16+16
#define MINI_BALL -1
#define MINI_CIRCLE -2
#define MIDDLE_BALL -3
#define KNIFE -4
#define MICRO_BALL -5
#define GLOWING_BALL -6
#define BIG_BALL -7

// left bottom
#define JAPANESE_TITLE_PART_1_UV (v2i){1, 1+256}
#define JAPANESE_TITLE_PART_2_UV (v2i){65, 1+256}
#define JAPANESE_TITLE_PART_3_UV (v2i){129, 1+256}
#define JAPANESE_TITLE_PART_4_UV (v2i){193, 1+256}
#define JAPANESE_TITLE_PART_5_UV (v2i){1, 65+256}
#define ENGLISH_TITLE_UV (v2i){128, 128+256}
#define HISCORE_UV (v2i){0, 192+256}
#define SCORE_UV (v2i){0, 208+256}
#define PLAYER_UV (v2i){0, 176+256}
#define BOMB_UV (v2i){0, 160+256}
#define POWER_UV (v2i){32, 208+256}
#define GRAZE_UV (v2i){32, 224+256}
#define POINT_UV (v2i){48, 160+256}

#define PLAYER_ICON_UV (v2i){32, 240+256}
#define BOMB_ICON_UV (v2i){48, 240+256}

#define BACKGROUND_UV (v2i){0, 224+256}

#define JAPANESE_TITLE_SZ (v2i){62, 62}
#define ENGLISH_TITLE_SZ (v2i){128, 128}
#define HISCORE_SZ (v2i){64, 16}
#define SCORE_SZ (v2i){32, 16}
#define PLAYER_SZ (v2i){48, 16}
#define BOMB_SZ (v2i){48, 16}
#define POWER_SZ (v2i){48, 16}
#define GRAZE_SZ (v2i){48, 16}
#define POINT_SZ (v2i){16, 16}
#define ICON_SZ (v2i){16, 16}
#define BACKGROUND_SZ (v2i){32, 32}
#define BACKGROUND_NARROW_SZ (v2i){32, 16}

#define ASCII_SHRINK 12
#define ASCII 16

// generic_1.png
// left bottom

// RM animation info
#define FOCUS_BORDER_UV (v2i){3, 448}
#define FOCUS_BORDER_SZ (v2i){60, 60}
#define PLAYER_DEFAULT_ANIMATION_UV (v2i){1, 1+256}
#define PLAYER_DEFAULT_ANIMATION_COUNT 8
#define PLAYER_LEFT_ANIMATION_UV (v2i){1, 49+256}
#define PLAYER_LEFT_ANIMATION_COUNT 8
#define PLAYER_RIGHT_ANIMATION_UV (v2i){1, 97+256}
#define PLAYER_RIGHT_ANIMATION_COUNT 8
#define PLAYER_TEXTURE_SZ (v2i){30, 46}

// RM AB bullet info
#define RM_BULLET_0_UV (v2i){3, 418}	// non-trace universal bullet
#define RM_BULLET_0_SZ (v2i){12, 12}
#define RM_BULLET_1_UV (v2i){18, 417}	// config A trace bullet
#define RM_BULLET_1_SZ (v2i){14, 14}
#define RM_BULLET_2_UV (v2i){70, 418}	// config B laser
#define RM_BULLET_2_SZ (v2i){7, 45}
#define RM_OPTION_UV (v2i){2, 400}
#define RM_OPTION_SZ (v2i){15, 15}

// ui render position
#define HISCORE_POS (v2i){432, 48}
#define HISCORE_NUM_POS (v2i){496, 48}
#define SCORE_POS (v2i){432, 64}
#define SCORE_NUM_POS (v2i){496, 64}

#define PLAYER_POS (v2i){432, 96}
#define PLAYER_NUM_POS (v2i){496, 96}
#define BOMB_POS (v2i){432, 112}
#define BOMB_NUM_POS (v2i){496, 112}

#define POWER_POS (v2i){432, 144}
#define POWER_NUM_POS (v2i){496, 144}
#define GRAZE_POS (v2i){432, 162}
#define GRAZE_NUM_POS (v2i){496, 162}
#define POINT_POS (v2i){432, 180}
#define POINT_NUM_POS (v2i){496, 180}

#define JAPANESE_TITLE_PART_1_POS (v2i){440, 290}
#define JAPANESE_TITLE_PART_2_POS (v2i){498, 290}
#define JAPANESE_TITLE_PART_3_POS (v2i){498, 346}
#define JAPANESE_TITLE_PART_4_POS (v2i){498, 404}
#define JAPANESE_TITLE_PART_5_POS (v2i){554, 404}
#define ENGLISH_TITLE_POS (v2i){464, 312}

#define FPS_POS (v2i){513, 464}

#endif
