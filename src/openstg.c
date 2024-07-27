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
        bullet* bu = gen_bullet((bullet_color){BLUE, 1}, CIRCLE, (pos){LENGTH_X/2, LENGTH_Y/2});
        bu->vx = -10;
        bu = gen_bullet((bullet_color){RED, 1}, CIRCLE, (pos){LENGTH_X/2, LENGTH_Y/2});
        bu->vx = 10;
        bu = gen_bullet((bullet_color){GREEN, 1}, CIRCLE, (pos){LENGTH_X/2, LENGTH_Y/2});
        bu->vy = 10;
        bu = gen_bullet((bullet_color){YELLOW, 1}, CIRCLE, (pos){LENGTH_X/2, LENGTH_Y/2});
        bu->vy = -10;
        tick_ui();
        tick_player();
        tick_bullets();
        post_frame();
    }
    return 0;
}