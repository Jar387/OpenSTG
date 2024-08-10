#ifndef PLAYER_H
#define PLAYER_H

#include <openstg.h>

// key config
#define SHOOT_KEY SDL_SCANCODE_Z
#define BOMB_KEY SDL_SCANCODE_X
#define FOCUS_KEY SDL_SCANCODE_LSHIFT
#define UP_KEY SDL_SCANCODE_UP
#define DOWN_KEY SDL_SCANCODE_DOWN
#define LEFT_KEY SDL_SCANCODE_LEFT
#define RIGHT_KEY SDL_SCANCODE_RIGHT

void init_player();
void tick_player();

void player_die();

#endif
