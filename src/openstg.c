#include <openstg.h>

int tick = 0;

int main(int argc, char *argv[])
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
	create_all_lists();
	init_player();
	init_buman();
	init_ecl();

	load_script("data/stg6.ecl");

	set_background_style(SC_BACKGROUND);

	if (argv[1] != NULL) {
		if (strcmp(argv[1], "--debug") == 0) {
			init_debugger();
		}
	}

	while (!should_close()) {
		tick++;
		pre_frame();
		tick_background();
		tick_player();
		tick_ecl();
		tick_enemy();
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
