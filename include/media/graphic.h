#ifndef GRAPHIC_H
#define GRAPHIC_H

#define FPS 60
#define DELAY 1000/FPS

#define WIDTH 640
#define HEIGHT 480

extern int window_w;
extern int window_h;
extern SDL_Window *window;
extern SDL_Renderer *renderer;

extern const Uint8 *keyboard_status;

void init_graphic();
void stop_graphic();

void pre_frame();
void post_frame();

int should_close();
float get_fps();

void draw_texture(int index, v2i xy);
void draw_texture_uv(int index, v2i xy, v2i uv, v2i wh);
void draw_texture_transform(int index, v2i xy, v2i uv, v2i wh, float rotation,
			    float scale);
void draw_game_object(int index, v2i xy, v2i uv, v2i wh,
		      float rotation, float scale);

int is_key_pressed(int scancode);

#endif
