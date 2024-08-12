#include <openstg.h>

player_cfg_data *curr_cfg;

static inline int zun2std(double zun)
{
	int ang = (int)rad2ang(zun) + 90;
	if (ang < 0) {
		ang += 360;
	}
	return ang;
}

static inline void load_option_config(char *buffer, shooter_cfg_data * data)
{
	double zun;
	sscanf(buffer, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%lf,%i", &(data->fire_rate),
	       &(data->start_dalay), &(data->position.x), &(data->position.y),
	       &(data->hitbox.x), &(data->hitbox.y), &(data->speed),
	       &(data->dmg), &(data->flags), &zun, &(data->option));
	data->ang = zun2std(zun);
}

void load_player_config(char *path)
{
	int c;
	if (!path) {
		NULLOBJ("player config path");
		return;
	}
	FILE *fp = fopen(path, "r");
	if (!fp) {
		IOERROR(path);
		return;
	}
	if (path == CFG_REIMU_A) {
		curr_cfg->config_id = CFG_REIMU_A_ID;
	} else if (path == CFG_REIMU_B) {
		curr_cfg->config_id = CFG_REIMU_B_ID;
	}
	curr_cfg = (player_cfg_data *) malloc(sizeof(*curr_cfg));
	memset(curr_cfg, 0, sizeof(*curr_cfg));
	char buffer[256];
	read_line(fp, buffer, 256);
	if (strcmp(buffer, CONFIG_HEADER) != 0) {
		ABORT("bad config file header");
	}
	read_line(fp, buffer, 256);
	sscanf(buffer, "%i,%i,%lf,%lf,%lf,%i,%i", &(curr_cfg->bomb_per_life),
	       &(curr_cfg->deathbomb_frame), &(curr_cfg->hitbox),
	       &(curr_cfg->grazebox), &(curr_cfg->itembox), &(curr_cfg->speed),
	       &(curr_cfg->initial_life));
	read_line(fp, buffer, 256);
	if (strcmp(buffer, CONFIG_BIG_SPLIT) != 0) {
		ABORT("bad config file format");
	}
	for (int i = 0;; i++) {
		for (int j = 0;; j++) {
			read_line(fp, buffer, 256);
			if (strcmp(buffer, CONFIG_SPLIT) == 0) {
				break;
			}
			if (strcmp(buffer, CONFIG_BIG_SPLIT) == 0) {
				c = i;
				goto fin;
			}
			load_option_config(buffer, &(curr_cfg->shooters[i][j]));
		}
	}
 fin:
	for (int i = 0;; i++) {
		for (int j = 0;; j++) {
			read_line(fp, buffer, 256);
			if (strcmp(buffer, CONFIG_SPLIT) == 0) {
				break;
			}
			if (strcmp(buffer, CONFIG_BIG_SPLIT) == 0) {
				if (c != CONFIG_COUNT - 1
				    || i != CONFIG_COUNT - 1) {
					ABORT("bad player config");
				}
				info("player config loaded: with %i/%i power setups", c + 1, i + 1);
				return;
			}
			load_option_config(buffer,
					   &(curr_cfg->shooters_focus[i][j]));
		}
	}
}
