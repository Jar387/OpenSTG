#ifndef ECL_H
#define ECL_H

#include <openstg.h>

#include <boss.h>
#include <buman.h>
#include <enemy.h>

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

typedef struct ecl_local_t {
	int local_i[8];		// -10001~-10004 -10009~-10012
	float local_f[4];	// -10005~-10008
	int x;			// -10015
	int y;			// -10016
	int z;			// -10017, only used by extra boss
	float aim;		// -10021
	int tick;		// -10022
	float dist;		// -10023, unused
	int life;		// -10024
} ecl_local;

void init_ecl();
void tick_ecl();

// ecl ins
void et_on_fan_aim(int spr, int col, int way, int layer, double spd1,
		   double spd2, double r1, double r2, int flags);
void et_on_fan(int spr, int col, int way, int layer, double spd1, double spd2,
	       double r1, double r2, int flags);
void et_on_cir_aim(int spr, int col, int way, int layer, double spd1,
		   double spd2, double r1, double r2, int flags);
void et_on_cir(int spr, int col, int way, int layer, double spd1, double spd2,
	       double r1, double r2, int flags);
void et_on_random_r(int spr, int col, int way, int layer, double spd1,
		    double spd2, double r1, double r2, int flags);
void et_on_random_sp(int spr, int col, int way, int layer, double spd1,
		     double spd2, double r1, double r2, int flags);
void et_on_random(int spr, int col, int way, int layer, double spd1,
		  double spd2, double r1, double r2, int flags);

#endif
