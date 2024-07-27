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
    draw_string(HISCORE_NUM_POS, 9, "%09d", hiscore%1000000000);
    draw_texture_uv(UI_TEXTURE, SCORE_POS, SCORE_UV, SCORE_SZ);
    draw_string(SCORE_NUM_POS, 9, "%09d", score%1000000000);
    draw_texture_uv(UI_TEXTURE, PLAYER_POS, PLAYER_UV, PLAYER_SZ);
    pos tmp = PLAYER_NUM_POS;
    for(int i=0;i<player_count;i++){
        draw_texture_uv(UI_TEXTURE, tmp, PLAYER_ICON_UV, ICON_SZ);
        tmp.x+=ICON_SZ.x;
    }
    tmp = BOMB_NUM_POS;
    for(int i=0;i<bomb_count;i++){
        draw_texture_uv(UI_TEXTURE, tmp, BOMB_ICON_UV, ICON_SZ);
        tmp.x+=ICON_SZ.x;
    }
    if(power<=9){
        draw_string(POWER_NUM_POS, 1, "%i", power);
    }else if (power<=99){
        draw_string(POWER_NUM_POS, 2, "%i", power);
    }else if (power<128){
        draw_string(POWER_NUM_POS, 3, "%i", power);
    }else{
        draw_string(POWER_NUM_POS, 3, "MAX", power);
    }

    if(graze<=9){
        draw_string(GRAZE_NUM_POS, 1, "%i", graze);
    }else if (graze<=99){
        draw_string(GRAZE_NUM_POS, 2, "%i", graze);
    }else if (graze<=999){
        draw_string(GRAZE_NUM_POS, 3, "%i", graze);
    }else if (graze<=999){
        draw_string(GRAZE_NUM_POS, 4, "%i", graze);
    }
    
    draw_texture_uv(UI_TEXTURE, BOMB_POS, BOMB_UV, BOMB_SZ);
    draw_texture_uv(UI_TEXTURE, POWER_POS, POWER_UV, POWER_SZ);
    draw_texture_uv(UI_TEXTURE, GRAZE_POS, GRAZE_UV, GRAZE_SZ);
    draw_texture_uv(UI_TEXTURE, JAPANESE_TITLE_POS, JAPANESE_TITLE_UV, JAPANESE_TITLE_SZ);
    draw_texture_uv(UI_TEXTURE, ENGLISH_TITLE_POS, ENGLISH_TITLE_UV, ENGLISH_TITLE_SZ);
    draw_string(FPS_POS, 8, "%.2ffps", get_fps());
}

static void draw_background(){
    // draw upper and down frame
    for(int i=0;i<WIDTH/128;i++){
        draw_texture_uv(UI_TEXTURE, (pos){i*128, 0}, BACKGROUND_UV, (pos){128, 16});
        draw_texture_uv(UI_TEXTURE, (pos){i*128, HEIGHT-16}, BACKGROUND_UV, (pos){128, 16});
    }
    // draw left frame
    for(int i=0;i<HEIGHT/32;i++){
        draw_texture_uv(UI_TEXTURE, (pos){0, i*32}, BACKGROUND_UV, (pos){32, 32});
        draw_texture_uv(UI_TEXTURE, (pos){OFFSET_X+LENGTH_X, i*32}, BACKGROUND_UV, (pos){128, 32});
        draw_texture_uv(UI_TEXTURE, (pos){OFFSET_X+LENGTH_X+128, i*32}, BACKGROUND_UV, (pos){192, 32});
    }
}

void tick_ui(){
    draw_background();
    draw_widget();
}