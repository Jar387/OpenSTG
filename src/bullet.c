#include <openstg.h>

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
    // add it to bullet list
    bu->node.data = bu;
    insert_tail(bullet_list, &bu->node);
    return bu;
}

static void tick_bullet(void* data, int id){
    bullet* bu = (bullet*)data;
    bu->tick++;
    bu->vx += bu->dvx;
    bu->vy += bu->dvy;
    bu->xy.x += bu->vx;
    bu->xy.y += bu->vy;
    if(check_out_of_screen(bu->xy, (pos){16, 16})==1){
        delete_bullet(bu);
        return;
    }
    draw_game_object(BULLET_TEXTURE, bu->xy, bu->uv, bu->wh, bu->angle, 1.0f);
}

void delete_bullet(bullet* bu){
    delete_object(bullet_list, &bu->node);
}

bullet* query_bullet(int id){
    return query_object(bullet_list, id)->data;
}

void delete_bullet_id(int id){
    delete_object_id(bullet_list, id);
}

void tick_bullets(){
    if(bullet_list->head==NULL){
        return;
    }
    list_foreach(bullet_list, &tick_bullet);
}