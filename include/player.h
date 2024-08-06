#ifndef PLAYER_H
#define PLAYER_H

#include <openstg.h>

// global game data
extern int player_count;
extern int bomb_count;
extern int hiscore;
extern int score;
extern int power;
extern int graze;
extern v2d player_position;

// player config
// TEST DATA(RM B)
#define HITBOX curr_cfg->hitbox
#define GRAZEBOX curr_cfg->grazebox
#define INITIAL_LIFE 2
#define INITIAL_BOMB curr_cfg->bomb_per_life
#define SPEED curr_cfg->speed
#define SPEED_SLOW SPEED/2

// key config
#define SHOOT SDL_SCANCODE_Z
#define BOMB SDL_SCANCODE_X
#define FOCUS SDL_SCANCODE_LSHIFT
#define UP SDL_SCANCODE_UP
#define DOWN SDL_SCANCODE_DOWN
#define LEFT SDL_SCANCODE_LEFT
#define RIGHT SDL_SCANCODE_RIGHT

void init_player();
void tick_player();

#endif
