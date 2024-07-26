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
extern pos player_position;

// player config
// TEST DATA(RM B)
#define HITBOX 1.65
#define GRAZEBOX 2.8
#define INITIAL_LIFE 2
#define INITIAL_BOMB 3

// key config
#define SHOOT SDL_SCANCODE_Z
#define BOMB SDL_SCANCODE_X
#define FOCUS SDL_SCANCODE_LSHIFT
#define UP SDL_SCANCODE_UP
#define DOWN SDL_SCANCODE_DOWN
#define LEFT SDL_SCANCODE_LEFT
#define RIGHT SDL_SCANCODE_RIGHT


typedef struct shooter_config_t{
    int fire_rate;
    pos offset;
    pos hitbox;
    int speed;
    int dmg;
    pos uv;
    pos wh;
    float rotation;
    int is_trace;
}shooter_config;

void init_player();
void tick_player();

#endif