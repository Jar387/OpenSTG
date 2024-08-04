#ifndef UTIL_H
#define UTIL_H

#include <openstg.h>

// solid texture names
#define TEX0 "../data/ascii.png"
#define TEX1 "../data/etama.png"
#define TEX2 "../data/pl00.png"

// solid texture id
#define UI_TEXTURE 0
#define BULLET_TEXTURE 1
#define PLAYER_TEXTURE 2

#define MAX_SLOTS 16

#define TEXTURE_UNUSED 0
#define TEXTURE_USED 1
#define TEXTURE_SOLID 2

// const len array because OpenGL supports least 16 texture slots
extern SDL_Texture *texture_slot[MAX_SLOTS];

void load_basic_texture();
void terminate_texture();

void load_texture(char *path, int solid);
void unload_texture(char idx);

char check_collision(v2d axy, v2i awh, v2d bxy, v2i bwh);
char check_out_of_screen(v2d p, v2i sz);

#endif
