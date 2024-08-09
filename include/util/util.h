#ifndef UTIL_H
#define UTIL_H

#include <openstg.h>

#include <error.h>
#include <list.h>
#include <mathutil.h>
#include <playercfg.h>

// solid texture names
#define GENERIC_0 "data/generic_0.png"
#define GENERIC_1 "data/generic_1.png"
#define STG6_BOSS "data/stage_6_boss.png"

// solid texture id
#define BULLET_TEX 0
#define ITEM_TEX 0
#define UI_TEX 0
#define ASCII_TEX 1
#define TEXT_TEX 1
#define PLAYER_TEX 1

#define MAX_SLOTS 16

#define TEXTURE_UNUSED 0
#define TEXTURE_USED 1
#define TEXTURE_SOLID 2

// music names
#define BGM0 "data/th06_13.mid"	// 亡き王女の為のセプテット

#define MAX_BGMS 1

#define MAIN_CHANNEL -1

// array of all loaded musics
extern Mix_Music *bgm_slot[MAX_BGMS];

/**
* @brief Load midi music
*
* This function loads a midi file to "bgm_slot" array
* @param path the midi file path
* @param idx the slot that midi file loads
* @return void
*/
void load_music(char *path, int idx);


void unload_music(int idx);

void play_music(int idx);
void stop_music();

void load_basic_music();
void terminate_music();

// texture utils
// const len array because OpenGL supports least 16 texture slots
extern SDL_Texture *texture_slot[MAX_SLOTS];

void load_basic_texture();
void terminate_texture();

void load_texture(char *path, int solid);
void unload_texture(char idx);

char check_collision(v2d axy, v2d awh, v2d bxy, v2d bwh);
char check_out_of_screen(v2d p, v2i sz);

// file utils
int read_line(FILE * fp, char *buffer, int size);

#endif
