#ifndef UTIL_H
#define UTIL_H

#include <SDL2/SDL.h>

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

static inline double ang2rad(double angle){
    return M_PI/180.0f*angle;
}

static inline double rad2ang(double rad){
    return rad/M_PI*180.0f;
}

static inline double rsin(double x){
    return sin(ang2rad(x));
}

static inline double rcos(double x){
    return cos(ang2rad(x));
}

static inline double rtan(double x){
    return tan(ang2rad(x));
}

static inline double rarcsin(double x){
    return rad2ang(asin(x));
}

static inline double rarccos(double x){
    return rad2ang(acos(x));
}

static inline double rarctan(double x){
    return rad2ang(atan(x));
}

// bullet math util
static inline pos ang2vec(double angle, double speed){
    return (pos){rsin(angle)*speed, -rcos(angle)*speed};
}

static inline double vec2ang(pos vec){
    return rarctan(-vec.x/vec.y);
}



// const len array because OpenGL supports least 16 texture slots
extern SDL_Texture* texture_slot[MAX_SLOTS];

void load_basic_texture();

void load_texture(char* path, int solid);
void unload_texture(char idx);

char check_collision(pos axy, pos awh, pos bxy, pos bwh);
char check_out_of_screen(pos p, pos sz);

#endif