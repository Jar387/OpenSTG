#ifndef UTIL_H
#define UTIL_H

#include <SDL2/SDL.h>

#define MAX_SLOTS 16

#define TEXTURE_UNUSED 0
#define TEXTURE_USED 1
#define TEXTURE_SOLID 2

// const len array because OpenGL supports least 16 texture slots
extern SDL_Texture* texture_slot[MAX_SLOTS];

void load_texture(char* path, int solid);
void unload_texture(char idx);

#endif