#include <openstg.h>

int tick = 0;

void callback(int looptime, void *data)
{
	// test code
	create_buman(0);
	bamount(0, 12, 1);
	boffset(0, 192, 144);
	bangle(0, 15.0f, 15.0f);
	bshape(0, BLUE, KNIFE);
	bspeed(0, 4.8f, 1.0f);
	bstyle(0, TRACE);
	fire(0);
	create_buman(1);
	bamount(1, 12, 12);
	boffset(1, 192, 144);
	bangle(1, -15.0f, 15.0f);
	bshape(1, BLUE, KNIFE);
	bspeed(1, 4.8f, 1.0f);
	bstyle(1, TRACE);
	fire(1);
}

int main()
{
	init_logger(INFO, NULL);
	info("starting openstg engine");
	srand(time(NULL));
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		ABORT("cannot initialize sdl2");
	}
	if (IMG_Init(IMG_INIT_PNG) == 0) {
		ABORT("cannot initailize sdl2 image module");
	}
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		ABORT("cannot initialize sdl2 mixer module");
	}

	init_graphic();
	load_basic_texture();
	load_basic_music();
	load_player_config(CFG_REIMU_B);
	create_all_instances();
	init_player();
	init_buman();

	set_background_style(SC_BACKGROUND);

	add_periodic_times_task(32, 1020, &callback, NULL);

	while (!should_close()) {
		tick++;
		pre_frame();
		tick_background();
		tick_player();
		tick_bullets();
		tick_items();
		tick_sched();
		tick_ui();
		post_frame();
	}
	stop_graphic();
	terminate_music();
	terminate_logger();
	return 0;
}
