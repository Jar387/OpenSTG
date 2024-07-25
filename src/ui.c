#include <openstg.h>

// buffer for any purpose in this file
#define BUF_LEN 1024
static char buffer[BUF_LEN];

void draw_ascii(char c, char highlight, pos position){
    char off = c - ' ';
    char row = off/16;
    char column = off%16;
    pos uv = (pos){column*16, 32+row*16};
    pos wh = (pos){16, 16};
    draw_texture_uv(UI_TEXTURE, position, uv, wh);
}
                          // restrict length to 255
void draw_string(pos position, unsigned char len, char* fmt, ...){
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, 1024, fmt, args);
    if(strlen(buffer)<len){
        len = strlen(buffer);
    }
    for(int i=0;i<len;i++){
        draw_ascii(buffer[i], 0, position);
        position.x+=ASCII_SHRINK;
    }
}

static void draw_widget(){
    draw_texture_uv(UI_TEXTURE, HISCORE_POS, HISCORE_UV, HISCORE_SZ);
    draw_string(HISCORE_NUM_POS, 9, "100000000");
    draw_texture_uv(UI_TEXTURE, SCORE_POS, SCORE_UV, SCORE_SZ);
    draw_string(SCORE_NUM_POS, 9, "000000000");
    draw_texture_uv(UI_TEXTURE, PLAYER_POS, PLAYER_UV, PLAYER_SZ);
    draw_texture_uv(UI_TEXTURE, BOMB_POS, BOMB_UV, BOMB_SZ);
    draw_texture_uv(UI_TEXTURE, POWER_POS, POWER_UV, POWER_SZ);
    draw_texture_uv(UI_TEXTURE, GRAZE_POS, GRAZE_UV, GRAZE_SZ);
    draw_texture_uv(UI_TEXTURE, JAPANESE_TITLE_POS, JAPANESE_TITLE_UV, JAPANESE_TITLE_SZ);
    draw_texture_uv(UI_TEXTURE, ENGLISH_TITLE_POS, ENGLISH_TITLE_UV, ENGLISH_TITLE_SZ);
    draw_string(FPS_POS, 8, "%.2ffps", get_fps());
}

static void draw_background(){
    for(int i=0;i<640/128;i++){
        for(int j=0;j<480/32;j++){
            draw_texture_uv(UI_TEXTURE, (pos){i*128, j*32}, BACKGROUND_UV, (pos){128, 32});
        }
    }
}

void tick_ui(){
    draw_background();
    draw_widget();
}