#ifndef BUMAN_H
#define BUMAN_H

#include <openstg.h>

#define OFFSET_X 32
#define OFFSET_Y 16
#define LENGTH_X 384
#define LENGTH_Y 448

// bullet style macro
#define TRACE 0
#define DEFAULT 1
#define LAYER_DIF 2
#define LAYER_DIF_TRACE 3
#define RANDOM_DIR 4
#define RANDOM_SPEED 5
#define RANDOM 6

typedef struct bullet_manager_t {
	// const data
	int style;
	int color;
	int type;
	v2d offset;
	double first_v;
	double last_v;
	int way;
	int count;
	double dif;
	double dir;
	// runtime value
	double curr_spd;
	double spd_delta;
} bullet_manager;

extern bullet_manager *curr_buman_setup;

void init_buman();
// bullet functions

void fire();
bullet_manager *create_buman();
void bstyle(int style);
void bshape(int color, int type);
void boffset(int offset_x, int offset_y);
void bamount(int way, int count);
void bspeed(double first, double last);
void bangle(double dir, double dif);

void btransform(int channel, int mode, int a, int b, int r, int s);

#endif
