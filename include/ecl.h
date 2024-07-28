#ifndef ECL_H
#define ECL_H

#define OFFSET_X 32
#define OFFSET_Y 16
#define LENGTH_X 384
#define LENGTH_Y 448

// bullet style macro
#define TRACE 0
#define TRACE_ABS_DIR 1
#define TRACE_REL_DIR 2
#define RANDOM 3
#define RANDOM_SPEED 4

typedef struct bullet_manager_t {

} bullet_manager;

// bullet functions
void create_bullet(int id);	// have id from 0 to 15
void fire(int id);

void bshape(int id, int color, int type);
void boffset(int id, int offset_x, int offset_y);
void bspeed(int id, int min, int max);
void bamount(int id, int way, int count);
void bstyle(int id, int style);

void btransform(int id, int channel, int mode, int a, int b, int r, int s);

#endif
