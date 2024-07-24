#include <openstg.h>

SDL_Texture* texture_slot[MAX_SLOTS];

static char usage_bitmap[MAX_SLOTS] = {0};
static char texture_index = 0;

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