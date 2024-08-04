#include <openstg.h>

int tick = 0;

void test_bullet(int time, void *data)
{
	create_bullet(0);
	bstyle(0, TRACE);
	bshape(0, RED, SMALL);
	boffset(0, LENGTH_X / 2, LENGTH_Y / 2);
	bamount(0, 6, 9);
	bspeed(0, 1.0f, 1.0f);
	bangle(0, 0.0f, 10.0f);
	fire(0);
}

int main()
{
	init_logger(INFO, NULL);
	info("starting openstg engine");
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		ABORT("cannot initialize sdl2");
	}
	IMG_Init(IMG_INIT_PNG);

	init_graphic();

	load_basic_texture();

	create_all_instances();

	init_player();

	init_buman();

	add_periodic_task(300, test_bullet, NULL);

	while (!should_close()) {
		tick++;
		pre_frame();
		tick_player();
		tick_bullets();
		tick_sched();
		tick_ui();
		post_frame();
	}
	stop_graphic();
	terminate_logger();
	return 0;
}
