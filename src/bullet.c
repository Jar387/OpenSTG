#include <openstg.h>

static int id; // always id of next bullet

bullet* gen_bullet(bullet_color color, char type, pos xy){
    bullet* bu = (bullet*)malloc(sizeof(bullet));
    memset(bu, 0, sizeof(bullet));
    bu->xy = xy;
    bu->tick = 0;
    // calculate texture uv
    pos uv;
    pos wh;
    if(type==LARGE){
        // use etama2
        wh.x = 64;
        wh.y = 64;
        uv.y = 0;
        switch(color.color){
            case RED: uv.x = 0; break;
            case BLUE: uv.x = 64; break;
            case GREEN: uv.x = 128; break;
            case YELLOW: uv.x = 192; break;
            default: warn("illegal bullet color"); free(bu); return NULL;
        }
    }else if (type==MIDDLE||type==LEGACY||type==SAIGYOJI){
        wh.x = 32;
        wh.y = 32;
        if(color.color==ORANGE){
            warn("illegal bullet color");
            free(bu);
            return NULL;
        }
        if(color.color==WHITE){
            uv.x = 224;
        }else{
            uv.x = color.color*32;
        }
        uv.y = 112+32*(type-MIDDLE);
    }else{
        wh.x = 16;
        wh.y = 16;
        uv.y = 16+type*16;
        if(color.highlight==1){
            if(color.color==BLACK||color.color==ORANGE||color.color==WHITE){
                warn("illegal bullet color");
                free(bu);
                return NULL;
            }
            uv.x = 32*color.color;
        }else{
            switch (color.color)
            {
            case BLACK:
                uv.x = 0;
                break;

            case ORANGE:
                uv.x = 224;
                break;

            case WHITE:
                uv.x = 240;
                break;
            
            default:
                uv.x = (color.color-1)*32+16;
                break;
            }
        }
    }
    bu->uv = uv;
    bu->wh = wh;
    bu->id = id;
    id++;
    draw_texture_uv(0, xy, uv, wh);
    return bu;
}
