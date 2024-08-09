#ifndef OPENSTG_H
#define OPENSTG_H

// vectors used to store game object position
typedef struct vec2d_t {
	double x;
	double y;
} v2d;

typedef struct vec2i_t {
	int x;
	int y;
} v2i;

typedef struct vec2c_t {
	char x;
	char y;
} v2c;

// include all ANSI C headers for convenience
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <time.h>

// sdl headers
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

// logger headers
#include <log4c.h>

// openstg headers
#include <media/graphic.h>
#include <util/util.h>

#include <bullet.h>
#include <buman.h>
#include <item.h>
#include <player.h>
#include <sched.h>
#include <shooter.h>


extern int tick;

#endif
