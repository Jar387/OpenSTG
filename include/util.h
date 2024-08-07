#ifndef UTIL_H
#define UTIL_H

#include <openstg.h>

// solid texture names
#define TEX0 "../data/ascii.png"
#define TEX1 "../data/etama.png"
#define TEX2 "../data/pl00.png"
#define TEX3 "../data/bga.png"
#define TEX4 "../data/bgb.png"
#define TEX5 "../data/bgc.png"
#define TEX6 "../data/enm.png"

// solid texture id
#define UI_TEXTURE 0
#define BULLET_TEXTURE 1
#define PLAYER_TEXTURE 2
#define BG_A_TEXTURE 3
#define BG_B_TEXTURE 4
#define BG_C_TEXTURE 5
#define ENM_TEXTURE 6

#define MAX_SLOTS 16

#define TEXTURE_UNUSED 0
#define TEXTURE_USED 1
#define TEXTURE_SOLID 2

// music names
#define BGM0 "../data/6a.wav"	// アルティメットトゥルース
#define BGM1 "../data/6b.wav"	// 幽雅に咲かせ、墨染の桜　～ Border of Life
#define BGM2 "../data/6c.wav"	// ボーダーオブライフ

#define MAX_BGMS 3

#define MAIN_CHANNEL -1

extern Mix_Chunk *bgm_slot[MAX_BGMS];

// music utils
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

char check_collision(v2d axy, v2i awh, v2d bxy, v2i bwh);
char check_out_of_screen(v2d p, v2i sz);

// file utils
int read_line(FILE * fp, char *buffer, int size);

#endif
