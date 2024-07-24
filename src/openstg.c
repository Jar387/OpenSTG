#include <openstg.h>

#define FRAME_DELAY 1000/1

int main(){
    init_logger(DEBUG, NULL);
    info("starting openstg engine");
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)<0){
        error("cannot initialize sdl2");
        exit(-1);
    }
    IMG_Init(IMG_INIT_PNG);

    init_graphic();

    load_basic_texture();

    
    
    while(!should_close()){
        pre_frame();
        tick_ui();
        tick_bullets();
        post_frame();
    }
    return 0;
}