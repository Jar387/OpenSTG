#ifndef ITEM_H
#define ITEM_H

#include <openstg.h>

// global game data
extern int player_count;
extern int bomb_count;
extern int hiscore;
extern int score;
extern int power;
extern int graze;
extern int point;
extern int invulnerable_frame;
extern v2d player_position;

// game consts
#define MAX_PLAYER 7
#define MAX_BOMB 7
#define MAX_POWER 128
#define MAX_POINT 9999
#define MAX_GRAZE 9999
#define MAX_SCORE 999999999

#define BIG_P_CONTAIN_POWER 8

enum ITEM_TYPE {
	POWER,
	POINT,
	BIG_P,
	BOMB,
	FULL,
	PLAYER,
	STAR
};

#define ITEM_DV 0.01		// (pixels/frame^2)
#define INITIAL_ITEM_V -1

typedef struct item_t {
	v2d pos;
	double speed;
	enum ITEM_TYPE type;
	v2i uv;
	v2i sign_uv;

	list_node node;
} item;

item *create_item(v2d pos, enum ITEM_TYPE type);
void delete_all_item();

void tick_items();

#endif
