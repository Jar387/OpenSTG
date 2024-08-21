#ifndef ECL_H
#define ECL_H

#include <ecl/enemy.h>
#include <ecl/parser.h>

#define PLAYER_POSITION_I (v2i){player_x, player_y}
#define PLAYER_POSITION_D (v2d){player_x, player_y}
#define PLAYER_POSITION_F (v2f){player_x, player_y}

// ECL global vars
extern int rank;		// -10013
extern int difficulty;		// -10014, unused
extern float player_x;		// -10018
extern float player_y;		// -10019
extern float player_z;		// -10020, unused
extern int aim;			// -10021
extern int dist;		// -10023, unused
extern int shot_type;		// -10025

// global game data
extern int player_count;
extern int bomb_count;
extern int hiscore;
extern int score;
extern int power;
extern int graze;
extern int point;
extern int invulnerable_frame;

// game consts
#define MAX_PLAYER 7
#define MAX_BOMB 7
#define MAX_POWER 128
#define MAX_POINT 9999
#define MAX_GRAZE 9999
#define MAX_SCORE 999999999

#define BIG_P_CONTAIN_POWER 8

#define RANK_EASY 0
#define RANK_NORMAL 1
#define RANK_HARD 2
#define RANK_LUNATIC 3
#define RANK_EXTRA 4

void init_ecl();
void tick_ecl();

int search_symbol(enemy_data * data, char *symbol);
void parse_label(ecl_line * line);
int check_ip_onbound(enemy_data * data);

#endif
