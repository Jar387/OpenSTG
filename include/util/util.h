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

/**
* @brief Array of all loaded musics
*/
extern Mix_Music *bgm_slot[MAX_BGMS];

/**
* @brief Array of all loaded textures
* @note "MAX_SLOTS" is 16 because OpenGL ensures all graphic card have at least 16 texture slots
*/
extern SDL_Texture *texture_slot[MAX_SLOTS];

/**
* @brief Load midi music
*
* This function loads a midi file to "bgm_slot" array
*
* @param path the midi file path
* @param idx the slot that midi file loads
* @warning path must not be NULL
* @warning idx must in [0, MAX_BGMS-1]
*/
void load_music(char *path, int idx);

/**
* @brief Unload midi file
*
* This function unloads a midi file from "bgm_slot" array
*
* @param idx the slot that the midi file will be unloaded
* @warning idx must in [0, MAX_BGMS-1]
*/
void unload_music(int idx);

/**
* @brief Play midi file
*
* This function plays a midi file from "bgm_slot" array
*
* @param idx the slot that the midi file will be played
* @warning idx must in [0, MAX_BGMS-1]
*/
void play_music(int idx);

/**
* @brief Stop all bgms
*
* This function stop all bgms, sfxs and other audio operations
*
* @bug cannot stop single midi
*/
void stop_music();

/**
* @brief Load all music files
*
* This function loads all music files in "data/" directory
*
* @warning ensure call this file before game loop
*/
void load_basic_music();

/**
* @brief Terminate all audio function
*
* This function terminates all audio related function and clean up memory
*
* @warning calling this will destroy all things about audio in both OpenSTG and SDL
* @warning do not call any other audio related function or re-init audio system
*/
void terminate_music();

/**
* @brief Load all textures
*
* This function loads all textures in "data/" directory
*
* @warning ensure call this file before game loop
*/
void load_basic_texture();

/**
* @brief Free all textures
*
* This function clean up all textures and free memory
*
* @note this function DO NOT destroy anything about rendering and you can just use it to free all texture in slot
*/
void terminate_texture();

/**
* @brief Load texture
*
* This function loads a texture to "bgm_slot" array
*
* @param path the texture path
* @param idx the slot that texture loads
* @warning path must not be NULL
* @warning idx must in [0, MAX_BGMS-1]
*/
void load_texture(char *path, int solid);


/**
* @brief Unload texture
*
* This function unloads a texture from "texture_slot" array
*
* @param idx the slot that the texture will be unloaded
* @warning idx must in [0, MAX_BGMS-1]
*/
void unload_texture(char idx);

/**
* @brief Check gameobject collision
* @note Using AABB collision aligorithm
*
* This function checks collision from two gameobjects
*
* @param axy the central position of first object
* @param awh the size of first object
* @param bxy the central position of another object
* @param bwh the size of another object
* @return 1 for collision
* @return 0 for not collision
*/
char check_collision(v2d axy, v2d awh, v2d bxy, v2d bwh);

/**
* @brief Check if gameobject out of screen
*
* This function checks if a gameobject is completely out of gaming zone
*
* @param p the central position of the object
* @param sz the size of the object
* @return 1 for completely out of screen
* @return 0 for completely out of screen
*/
char check_out_of_screen(v2d p, v2i sz);

/**
* @brief Read a line from file
*
* This function read from a opened text file and stop when '\n' is read
*
* @param fp file pointer of the file
* @param buffer destination buffer
* @param size size of the buffer
* @return <read chars> for read complete and met with '\\n'
* @return -1 for met EOF and stop
* @return -2 for buffer full but not met '\\n' or EOF
* 
* @warning fp must valid
* @warning buffer must have the right to write
* @warning size must fit with actual buffer size
* @warning may cause buffer overflow if misuse
*/
int read_line(FILE * fp, char *buffer, int size);

#endif
