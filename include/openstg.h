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

typedef struct vec2f_t {
	float x;
	float y;
} v2f;

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

// libcrypto headers
#include <openssl/md5.h>

// openstg headers
#include <ecl/boss.h>
#include <ecl/buman.h>
#include <ecl/debugger.h>
#include <ecl/ecl.h>
#include <ecl/enemy.h>
#include <ecl/mapper.h>
#include <ecl/parser.h>

#include <media/background.h>
#include <media/graphic.h>
#include <media/texture_offset.h>
#include <media/ui.h>

#include <util/array.h>
#include <util/error.h>
#include <util/list.h>
#include <util/mathutil.h>
#include <util/playercfg.h>
#include <util/util.h>

#include <config.h>

#include <bullet.h>
#include <item.h>
#include <player.h>
#include <sched.h>
#include <shooter.h>

extern int tick;

#endif
