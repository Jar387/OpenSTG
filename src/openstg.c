#include <openstg.h>

int tick = 0;

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

    create_all_instances();

    init_player();
    
    while(!should_close()){
        tick++;
        pre_frame();
        tick_player();
        tick_bullets();
        tick_sched();
        tick_ui();
        post_frame();
    }
    return 0;
}