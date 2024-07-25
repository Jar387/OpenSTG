#ifndef TEXTURE_OFFSET_H
#define TEXTURE_OFFSET_H

#include <openstg.h>

// convenient inlines to process pos_t
static inline pos add_x(pos p, int delta){
    p.x += delta;
    return p;
}

static inline pos add_y(pos p, int delta){
    p.y += delta;
    return p;
}

// ascii.png
#define JAPANESE_TITLE_UV (pos){128+256, 0+256}
#define ENGLISH_TITLE_UV (pos){0+256, 0+256}
#define HISCORE_UV (pos){0+256, 80+256}
#define SCORE_UV (pos){0+256, 96+256}
#define PLAYER_UV (pos){0+256, 112+256}
#define BOMB_UV (pos){0+256, 128+256}
#define POWER_UV (pos){0+256, 144+256}
#define GRAZE_UV (pos){0+256, 160+256}
#define POINT_UV (pos){0+256, 176+256}

#define PLAYER_ICON_UV (pos){64+256, 80+256}
#define BOMB_ICON_UV (pos){80+256, 80+256}

#define BACKGROUND_UV (pos){0+256, 224+256}

#define JAPANESE_TITLE_SZ (pos){128, 256}
#define ENGLISH_TITLE_SZ (pos){128, 80}
#define HISCORE_SZ (pos){64, 16}
#define SCORE_SZ (pos){64, 16}
#define PLAYER_SZ (pos){64, 16}
#define BOMB_SZ (pos){64, 16}
#define POWER_SZ (pos){64, 16}
#define GRAZE_SZ (pos){64, 16}
#define POINT_SZ (pos){64, 16}

#define ASCII_SHRINK 12
#define ASCII 16
// background size can up to (128, 32)

// ui render position
#define HISCORE_POS (pos){432, 48}
#define HISCORE_NUM_POS (pos){496, 48}
#define SCORE_POS (pos){432, 64}
#define SCORE_NUM_POS (pos){496, 64}

#define PLAYER_POS (pos){432, 96}
#define PLAYER_NUM_POS (pos){496, 96}
#define BOMB_POS (pos){432, 112}
#define BOMB_NUM_POS (pos){496, 112}

#define POWER_POS (pos){432, 144}
#define POWER_NUM_POS (pos){496, 144}
#define GRAZE_POS (pos){432, 160}
#define GRAZE_NUM_POS (pos){496, 160}

#define JAPANESE_TITLE_POS (pos){480, 208}
#define ENGLISH_TITLE_POS (pos){448, 336}

#define FPS_POS (pos){513, 464}



#endif