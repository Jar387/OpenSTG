#ifndef BULLET_H
#define BULLET_H

extern list_head *bullet_list;

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

	int fire;		// is fire bullet? need animation

	list_node node;
} bullet;

// bullet colour (for EoSD only)
// 16x16 bullet
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

// 32x32 bullet
#define BLACK_32 0
#define RED_32 1
#define MAGENTA_32 2
#define BLUE_32 3
#define CYAN_32 4
#define GREEN_32 5
#define YELLOW_32 6
#define WHITE_32 7

// 64x64 bullet
#define RED_64 0
#define BLUE_64 1
#define GREEN_64 2
#define YELLOW_64 3

// bullet type (for EoSD only)
#define DOT 0
#define RING 1
#define RICE 2
#define SMALL 3
#define CHAIN 4
#define NIDDLE 5
#define MIDDLE 6
#define FIRE 7
#define KNIFE 8
#define BIG 9

bullet *create_bullet(int color, int type, v2d xy);
void delete_bullet(bullet * bu);
void delete_bullet_id(int id);
bullet *query_bullet(int id);

void tick_bullets();

#endif
