#ifndef BULLET_H
#define BULLET_H

#include <openstg.h>

typedef struct bullet_t bullet;
typedef struct bullet_t{
    int id;
    pos xy;

    int tick;
    float vx;
    float vy;
    float dvx;
    float dvy;
    float angle; // angle between bullet forward direction and negtive Y axis
    /*  
              |
       270~360|0~90
    ----------|----------    support >360 warp
       180~270|90~180
              |
    */
    // calculated texture info
    pos uv;
    pos wh;
    // chain
    bullet* prev;
    bullet* next;
}bullet;

typedef struct bullet_color_t bullet_color;
typedef struct bullet_color_t{
    char color;
    char highlight;
}bullet_color;

bullet* gen_bullet(bullet_color color, char type, pos xy);
void delete_bullet(bullet* bu);
void delete_bullet_id(int id);
bullet* query_bullet(int id);

void tick_bullets();

// bullet color define
#define BLACK 0 // cannot highlight
#define RED 1
#define MAGENTA 2
#define BLUE 3
#define CYAN 4
#define GREEN 5
#define YELLOW 6
#define ORANGE 7 // cannot highlight
#define WHITE 8 // cannot highlight

// bullet type define (except laser)
#define ARROW 0
#define CIRCLE 1
#define SMALL 2
#define RICE 3
#define DAGGER 4
#define CHAIN 5
#define MIDDLE 6
#define LEGACY 7
#define SAIGYOJI 8
#define LARGE 9

#endif