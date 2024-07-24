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
    
    load_texture("../data/etama.png", 1);
    load_texture("../data/etama2.png", 1);

    while(!should_close()){
        pre_frame();
        free(gen_bullet((bullet_color){RED, 0}, LARGE, (pos){32, 128}));
        post_frame();
    }
    return 0;
}