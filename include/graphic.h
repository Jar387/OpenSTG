#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <SDL2/SDL.h>

#define FPS 60
#define DELAY 1000/FPS

#define WIDTH 640
#define HEIGHT 480

typedef struct pos_t{
    double x;
    double y;
}pos;

extern int window_w;
extern int window_h;
extern SDL_Window* window;
extern SDL_Renderer* renderer;

extern const Uint8 * keyboard_status;

void init_graphic();

void pre_frame();
void post_frame();

int should_close();
float get_fps();

void draw_texture(int index, pos xy);
void draw_texture_uv(int index, pos xy, pos uv, pos wh);
void draw_texture_transform(int index, pos xy, pos uv, pos wh, float rotation, float scale);

int is_key_pressed(int scancode);

#endif