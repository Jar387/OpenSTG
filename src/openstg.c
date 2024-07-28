#include <openstg.h>

int tick = 0;

// void test_bullet(int time){
//     for(int i=0;i<36;i++){
//         bullet* bu = gen_bullet((bullet_color){BLUE, 1}, CIRCLE, (pos){LENGTH_X/2, LENGTH_Y/2});
//         bu->vx = sin(M_PI/180.0f*10*i)*2;
//         bu->vy = cos(M_PI/180.0f*10*i)*2;
//         debug("%f %f", bu->vx, bu->vy);
//     }
// }

int main()
{
	init_logger(INFO, NULL);
	info("starting openstg engine");
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		error("cannot initialize sdl2");
		exit(-1);
	}
	IMG_Init(IMG_INIT_PNG);

	init_graphic();

	load_basic_texture();

	create_all_instances();

	init_player();

	while (!should_close()) {
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
