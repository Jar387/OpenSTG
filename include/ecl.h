#ifndef ECL_H
#define ECL_H

#define OFFSET_X 32
#define OFFSET_Y 16
#define LENGTH_X 384
#define LENGTH_Y 448

// bullet style macro
#define TRACE 0
#define DEFAULT 1
#define LAYER_DIF 2
#define RANDOM_DIR 3
#define RANDOM_SPEED 4
#define RANDOM 5

typedef struct bullet_manager_t {
	int id;
	int style;
	int color;
	int type;
	pos offset;
	double min;
	double max;
	int way;
	int count;
} bullet_manager;

#define MAX_BUMAN_INSTANCE 16

extern bullet_manager buman_list[MAX_BUMAN_INSTANCE];

void init_buman();

// bullet functions
void create_bullet(int id);	// have id from 0 to 15
void fire(int id);

void bshape(int id, int color, int type);
void boffset(int id, int offset_x, int offset_y);
void bspeed(int id, double min, double max);
void bamount(int id, int way, int count);
void bstyle(int id, int style);

void btransform(int id, int channel, int mode, int a, int b, int r, int s);

#endif
