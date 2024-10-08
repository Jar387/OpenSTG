#ifndef PLAYER_CFG_H
#define PLAYER_CFG_H

#define CFG_REIMU_A "data/pl00a.cfg"
#define CFG_REIMU_B "data/pl00b.cfg"

#define CFG_REIMU_A_ID 0
#define CFG_REIMU_B_ID 1

#define CONFIG_HEADER "VERSION 1.0"
#define CONFIG_BIG_SPLIT ">>"
#define CONFIG_SPLIT ">"

#define CONFIG_COUNT 9

typedef struct shootercfg_data_t {
	int fire_rate;
	int start_dalay;
	v2i position;
	v2i hitbox;
	int dmg;
	int speed;
	int flags;
	int ang;
	int cd_counter;
	int option;
} shooter_cfg_data;

typedef struct playercfg_data_t {
	int config_id;
	int initial_life;
	int bomb_per_life;
	int deathbomb_frame;
	double hitbox;
	double grazebox;
	double itembox;
	int speed;
	shooter_cfg_data shooters[9][16];
	shooter_cfg_data shooters_focus[9][16];
} player_cfg_data;

extern player_cfg_data *curr_cfg;

void load_player_config(char *path);

// void create_player_config();

#endif
