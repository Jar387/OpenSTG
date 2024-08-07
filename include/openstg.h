#ifndef OPENSTG_H
#define OPENSTG_H

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

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <log4c.h>

#include <error.h>
#include <graphic.h>
#include <list.h>
#include <mathutil.h>
#include <playercfg.h>
#include <sched.h>
#include <texture_offset.h>
#include <util.h>

#include <background.h>
#include <bullet.h>
#include <buman.h>
#include <player.h>
#include <shooter.h>
#include <ui.h>

extern int tick;

#endif
