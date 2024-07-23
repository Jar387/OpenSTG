#include <log4c.h>
#include <openstg.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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
    
    load_texture("../rsrc/pl00.png", 1);

    while(!should_close()){
        pre_frame();
        post_frame();
        info("FPS: %f", get_fps());
    }
    return 0;
}