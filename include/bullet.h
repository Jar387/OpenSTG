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

	int fire; // is fire bullet? need animation

	list_node node;
} bullet;

bullet *create_bullet(int color, char type, v2d xy);
void delete_bullet(bullet * bu);
void delete_bullet_id(int id);
bullet *query_bullet(int id);

void tick_bullets();

#endif
