#ifndef PLAYER_CFG_H
#define PLAYER_CFG_H

#include <openstg.h>

typedef struct shootercfg_data_t {
	char fire_rate;
	char start_dalay;
	v2c position;
	v2c hitbox;
	char dmg;
	char speed;
	char flags;
	char texture;		// unused as padding
	int padding1;
} shooter_cfg_data;

typedef struct playercfg_data_t {
	int sig;
	int bomb_per_life;
	int deathbomb_frame;
	double hitbox;
	double grazebox;
	double itembox;
	int speed;
	int padding;
	shooter_cfg_data shooters[9][16];
} player_cfg_data;

void create_player_config();

#endif
