#include <openstg.h>

static int id; // always id of next bullet

static bullet* head = NULL;
static bullet* last = NULL;

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
    // add it to bullet list
    if(head==NULL){
        head = bu;
    }else{
        bu->prev = last;
        last->next = bu;
    }
    last = bu;
    return bu;
}

static void tick_bullet(bullet* bu){
    bu->tick++;
    bu->vx += bu->dvx;
    bu->vy += bu->dvy;
    bu->xy.x += bu->vx;
    bu->xy.y += bu->vy;
    draw_texture_transform(BULLET_TEXTURE, bu->xy, bu->uv, bu->wh, bu->angle, 1.0f);
}

void delete_bullet(bullet* bu){
    if(bu==NULL){
        warn("trying to free null bullet");
        return;
    }
    if (bu->prev != NULL) {
        bu->prev->next = bu->next;
    } else {
        head = bu->next; // Update head if deleting the first bullet
    }

    if (bu->next != NULL) {
        bu->next->prev = bu->prev;
    } else {
        last = bu->prev; // Update last if deleting the last bullet
    }
    free(bu);
}

bullet* query_bullet(int id){
    if(head == NULL){
        warn("not bullets exist for operation");
        return NULL;
    }
    bullet* index = head;
    while(index->id!=id){
        if(index->next==NULL){
            warn("cannot find bullet id %i", id);
            return NULL;
        }
        index = index->next;
    }
}

void delete_bullet_id(int id){
    bullet* bu = query_bullet(id);
    if(bu!=NULL){
        delete_bullet(bu);
    }
}

void tick_bullets(){
    bullet* index = head;
    while(index!=NULL){
        tick_bullet(index);
        index = index->next;
    }
}