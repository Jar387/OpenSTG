#ifndef UTIL_H
#define UTIL_H

#include <openstg.h>

// solid texture names
#define TEX0 "../data/ascii.png"
#define TEX1 "../data/etama.png"
#define TEX2 "../data/pl00.png"

// solid texture id
#define UI_TEXTURE 0
#define BULLET_TEXTURE 1
#define PLAYER_TEXTURE 2

#define MAX_SLOTS 16

#define TEXTURE_UNUSED 0
#define TEXTURE_USED 1
#define TEXTURE_SOLID 2

// math util
#ifndef M_PI
#define M_PI 3.1415926535897932384626433832
#endif

typedef struct vec2d_t {
	double x;
	double y;
} v2d;

typedef struct vec2i_t {
	int x;
	int y;
} v2i;

static inline v2d i2d(v2i i)
{
	return (v2d) {
	(double)i.x, (double)i.y};
}

static inline v2i d2i(v2d d)
{
	return (v2i) {
	(int)d.x, (int)d.y};
}

static inline double ang2rad(double angle)
{
	return M_PI / 180.0f * angle;
}

static inline double rad2ang(double rad)
{
	return rad / M_PI * 180.0f;
}

static inline double rsin(double x)
{
	return sin(ang2rad(x));
}

static inline double rcos(double x)
{
	return cos(ang2rad(x));
}

static inline double rtan(double x)
{
	return tan(ang2rad(x));
}

static inline double rarcsin(double x)
{
	return rad2ang(asin(x));
}

static inline double rarccos(double x)
{
	return rad2ang(acos(x));
}

static inline double rarctan(double x)
{
	return rad2ang(atan(x));
}

// bullet math util
static inline v2d ang2vec(double angle, double speed)
{
	return (v2d) {
	rsin(angle) * speed, -rcos(angle) * speed};
}

static inline double vec2ang(v2d vec)
{
	if (vec.y == 0) {
		return 0.0f;	// fix this if vec.y==0 will cause return a -Nan
	}
	return rarctan(-vec.x / vec.y);
}

double player_angle(v2d src);

// const len array because OpenGL supports least 16 texture slots
extern SDL_Texture *texture_slot[MAX_SLOTS];

void load_basic_texture();
void terminate_texture();

void load_texture(char *path, int solid);
void unload_texture(char idx);

char check_collision(v2d axy, v2i awh, v2d bxy, v2i bwh);
char check_out_of_screen(v2d p, v2i sz);

#endif
