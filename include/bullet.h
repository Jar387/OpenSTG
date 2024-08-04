#ifndef BULLET_H
#define BULLET_H

#include <openstg.h>

typedef struct bullet_t bullet;
typedef struct bullet_t {
	v2d xy;			// centered coord

	int tick;
	double vx;
	double vy;
	double dvx;
	double dvy;
	float angle;		// angle between bullet forward direction and negtive Y axis
	/*  
	   |
	   270~360|0~90
	   ----------|----------    support >360 warp
	   180~270|90~180
	   |
	 */
	// calculated texture info
	v2i uv;
	v2i wh;

	v2i hitbox_sz;

	list_node node;
} bullet;

bullet *gen_bullet(int color, char type, v2d xy);
void delete_bullet(bullet * bu);
void delete_bullet_id(int id);
bullet *query_bullet(int id);

void tick_bullets();

// bullet color define
#define BLACK 0
#define RED 1
#define LIGHT_RED 2
#define MAGENTA 3
#define LIGHT_MAGENTA 4
#define BLUE 5
#define LIGHT_BLUE 6
#define CYAN 7
#define LIGHT_CYAN 8
#define GREEN 9
#define LIGHT_GREEN 10
#define COLOR_11 11
#define YELLOW 12
#define LIGHT_YELLOW 13
#define ORANGE 14
#define WHITE 15

// bullet type define (except laser)
#define ARROW 0
#define CIRCLE 1
#define SMALL 2
#define RICE 3
#define DAGGER 4
#define CHAIN 5
#define MIDDLE 6
#define LEGACY 7
#define SAIGYOJI 8
#define LARGE 9

#endif
