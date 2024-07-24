#include <openstg.h>

void draw_ascii(char c, char highlight, pos position){
    char off = c - ' ';
    char row = off/16;
    char column = off%16;
    pos uv = (pos){column*16, 32+row*16};
    pos wh = (pos){16, 16};
    draw_texture_uv(UI_TEXTURE, position, uv, wh);
}

void tick_ui(){
    float fps = get_fps();
    if(fps>=99.0f){
        draw_ascii('9', 0, (pos){512, 464});
        draw_ascii('9', 0, (pos){526, 464});
        draw_ascii('.', 0, (pos){540, 464});
        draw_ascii('9', 0, (pos){554, 464});
        draw_ascii('9', 0, (pos){568, 464});
    }else if(fps>=10.0f){
        char buf[10];
        sprintf(buf, "%.2f", fps);
        draw_ascii(buf[0], 0, (pos){512, 464});
        draw_ascii(buf[1], 0, (pos){526, 464});
        draw_ascii('.', 0, (pos){540, 464});
        draw_ascii(buf[3], 0, (pos){554, 464});
        draw_ascii(buf[4], 0, (pos){568, 464});
    }else{
        char buf[10];
        sprintf(buf, "%.2f", fps);
        draw_ascii(buf[0], 0, (pos){512, 464});
        draw_ascii('.', 0, (pos){526, 464});
        draw_ascii(buf[2], 0, (pos){540, 464});
        draw_ascii(buf[3], 0, (pos){554, 464});
        draw_ascii('f', 0, (pos){568, 464});
        draw_ascii('p', 0, (pos){582, 464});
        draw_ascii('s', 0, (pos){596, 464});
        return;
    }
    draw_ascii('f', 0, (pos){582, 464});
    draw_ascii('p', 0, (pos){596, 464});
    draw_ascii('s', 0, (pos){610, 464});
}