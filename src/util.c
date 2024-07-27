#include <openstg.h>

SDL_Texture* texture_slot[MAX_SLOTS];

static char usage_bitmap[MAX_SLOTS] = {0};
static char texture_index = 0;

void load_basic_texture(){
    load_texture(TEX0, 1);
    load_texture(TEX1, 1);
    load_texture(TEX2, 1);
}

void load_texture(char* path, int solid){
    SDL_Texture* texture = IMG_LoadTexture(renderer, path);
    if(!texture){
        warn("cannot load texture %s: %s", path, IMG_GetError());
        return;
    }
    int free_idx = texture_index;
    texture_index++;
    if(texture_index>=MAX_SLOTS-1){
        texture_index = MAX_SLOTS+1;
        // full
        for(int i=0;i<MAX_SLOTS;i++){
            if(usage_bitmap[i]==TEXTURE_USED){
                free_idx = i;
                break;
            }
        }
        if(free_idx==-1){
            warn("cannot load texture because texture slot is full");
            return;
        }
    }
    if(solid==0){
        usage_bitmap[free_idx] = TEXTURE_USED;
    }else{
        usage_bitmap[free_idx] = TEXTURE_SOLID;
    }
    texture_slot[free_idx] = texture;
}

void unload_texture(char idx){
    if(idx<0||idx>15){
        error("illegal texture index: %i", idx);
        return;
    }
    SDL_DestroyTexture(texture_slot[idx]);
    usage_bitmap[idx] = TEXTURE_UNUSED;
}

char check_collision(pos axy, pos awh, pos bxy, pos bwh){
    if(axy.x<=bxy.x+bwh.x&&
       axy.x+awh.x>=bxy.x&&
       axy.y<=bxy.y+bwh.y&&
       axy.y+awh.y>=bxy.y){
        return 1;
       }
    return 0;
}
char check_out_of_screen(pos p, pos sz){
    if(p.x<=-sz.x||
       p.x>=LENGTH_X|
       p.y<=-sz.y||
       p.y>=LENGTH_Y){
        return 1;
       }
    return 0;
}