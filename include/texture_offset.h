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

// ascii.png
#define JAPANESE_TITLE_UV (v2i){128+256, 0+256}
#define ENGLISH_TITLE_UV (v2i){0+256, 0+256}
#define HISCORE_UV (v2i){0+256, 80+256}
#define SCORE_UV (v2i){0+256, 96+256}
#define PLAYER_UV (v2i){0+256, 112+256}
#define BOMB_UV (v2i){0+256, 128+256}
#define POWER_UV (v2i){0+256, 144+256}
#define GRAZE_UV (v2i){0+256, 160+256}
#define POINT_UV (v2i){0+256, 176+256}

#define PLAYER_ICON_UV (v2i){64+256, 80+256}
#define BOMB_ICON_UV (v2i){80+256, 80+256}

#define BACKGROUND_UV (v2i){0+256, 224+256}

#define JAPANESE_TITLE_SZ (v2i){128, 256}
#define ENGLISH_TITLE_SZ (v2i){128, 80}
#define HISCORE_SZ (v2i){64, 16}
#define SCORE_SZ (v2i){64, 16}
#define PLAYER_SZ (v2i){64, 16}
#define BOMB_SZ (v2i){64, 16}
#define POWER_SZ (v2i){64, 16}
#define GRAZE_SZ (v2i){64, 16}
#define POINT_SZ (v2i){64, 16}
#define ICON_SZ (v2i){16, 16}

#define ASCII_SHRINK 12
#define ASCII 16
// background size can up to (128, 32)

// etama2.png
#define FOCUS_BORDER_UV (v2i){0+256, 112}
#define FOCUS_BORDER_SZ (v2i){64, 64}

// etama3.png
#define SPELL_RING_UV (v2i){0, 0+256}
#define SPELL_RING_SZ (v2i){256, 256}

// etama4.png
#define SUPERNATURAL_BORDER_UV (v2i){0+256, 0+256}
#define SUPERNATURAL_BORDER_SZ (v2i){256, 256}

// plxx.png (for both RM,MR and SY)
#define PLAYER_DEFAULT_ANIMATION_UV (v2i){1, 1}
#define PLAYER_DEFAULT_ANIMATION_COUNT 8
#define PLAYER_LEFT_ANIMATION_UV (v2i){1, 49}
#define PLAYER_LEFT_ANIMATION_COUNT 8
#define PLAYER_RIGHT_ANIMATION_UV (v2i){1, 97}
#define PLAYER_RIGHT_ANIMATION_COUNT 8
#define PLAYER_TEXTURE_SZ (v2i){30, 46}

// RM AB bullet info
#define RM_A_BULLET_UV (v2i){200, 146}
#define RM_A_BULLET_SZ (v2i){56, 13}
#define RM_B_BULLET_1_UV (v2i){200, 162}
#define RM_B_BULLET_1_SZ (v2i){56, 12}
#define RM_B_BULLET_2_UV (v2i){68, 179}
#define RM_B_BULLET_2_SZ (v2i){56, 10}

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
#define GRAZE_POS (v2i){432, 160}
#define GRAZE_NUM_POS (v2i){496, 160}

#define JAPANESE_TITLE_POS (v2i){480, 208}
#define ENGLISH_TITLE_POS (v2i){448, 336}

#define FPS_POS (v2i){513, 464}

#endif
