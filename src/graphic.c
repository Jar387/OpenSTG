#include <openstg.h>

// global renderer info
int window_w = WIDTH;
int window_h = HEIGHT;
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

const Uint8 *keyboard_status;

// global texture part
static SDL_Rect src = { 0, 0, 0, 0 };
static SDL_Rect dst = { 0, 0, 0, 0 };

// private global stuff
static float actual_fps;
static int should_exit = 0;
static int last_frame;		// this may loopback after 47 days
static SDL_Event e;

void init_graphic()
{
	window =
	    SDL_CreateWindow("OpenSTG", SDL_WINDOWPOS_UNDEFINED,
			     SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT,
			     SDL_WINDOW_HIDDEN);
	if (window == NULL) {
		ABORT("cannot create window");
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		ABORT("cannot create renderer");
	}
	SDL_ShowWindow(window);
}

void stop_graphic()
{
	terminate_texture();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void pre_frame()
{
	last_frame = SDL_GetTicks();
	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_QUIT) {
			should_exit = 1;
		}
	}
	keyboard_status = SDL_GetKeyboardState(NULL);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void post_frame()
{
	SDL_RenderPresent(renderer);
	unsigned int delay = SDL_GetTicks() - last_frame;
	if (delay < DELAY) {
		SDL_Delay(DELAY - delay);
		actual_fps = FPS;
	} else {
		actual_fps = 1000.0f / (SDL_GetTicks() - last_frame);
	}
}

int should_close()
{
	return should_exit;
}

float get_fps()
{
	return actual_fps;
}

void draw_texture(int index, v2i xy)
{
	SDL_Texture *texture = texture_slot[index];
	if (!texture) {
		NULLOBJ("list head");
		return;
	}
	SDL_QueryTexture(texture, NULL, NULL, &src.w, &src.h);
	src.x = 0;
	src.y = 0;
	dst.x = xy.x;
	dst.y = xy.y;
	dst.w = src.w;
	dst.h = src.h;
	SDL_RenderCopy(renderer, texture, &src, &dst);
}

void draw_texture_uv(int index, v2i xy, v2i uv, v2i wh)
{
	SDL_Texture *texture = texture_slot[index];
	if (!texture) {
		NULLOBJ("list head");
		return;
	}
	src.x = uv.x;
	src.y = uv.y;
	src.w = wh.x;
	src.h = wh.y;

	dst.x = xy.x;
	dst.y = xy.y;
	dst.w = wh.x;
	dst.h = wh.y;
	SDL_RenderCopy(renderer, texture, &src, &dst);
}

void draw_texture_transform(int index, v2i xy, v2i uv, v2i wh, float rotation,
			    float scale)
{
	SDL_Texture *texture = texture_slot[index];
	if (!texture) {
		NULLOBJ("texture");
		return;
	}
	src.x = uv.x;
	src.y = uv.y;
	src.w = wh.x;
	src.h = wh.y;

	dst.x = xy.x;
	dst.y = xy.y;
	dst.w = wh.x * scale;
	dst.h = wh.y * scale;
	SDL_Point center;
	center.x = wh.x * scale / 2;
	center.y = wh.y * scale / 2;
	SDL_RenderCopyEx(renderer, texture, &src, &dst, rotation, &center, 0);
}

int is_key_pressed(int scancode)
{
	return keyboard_status[scancode];
}

void draw_game_object(int index, v2i xy, v2i uv, v2i wh,
		      float rotation, float scale)
{
	xy.x -= wh.x / 2;
	xy.y -= wh.y / 2;
	xy.x += OFFSET_X;
	xy.y += OFFSET_Y;
	draw_texture_transform(index, xy, uv, wh, rotation, scale);
}
