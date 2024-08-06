#include <openstg.h>

player_cfg_data *curr_cfg;

static inline void load_option_config(char *buffer, shooter_cfg_data * data)
{
	sscanf(buffer, "%i,%i,%i,%i,%i,%i,%i,%i,%i", &(data->fire_rate),
	       &(data->start_dalay), &(data->position.x), &(data->position.y),
	       &(data->hitbox.x), &(data->hitbox.y), &(data->speed),
	       &(data->dmg), &(data->flags));
}

void load_player_config(char *path)
{
	if (!path) {
		NULLOBJ("player config path");
		return;
	}
	FILE *fp = fopen(path, "r");
	if (!fp) {
		IOERROR(path);
		return;
	}
	curr_cfg = (player_cfg_data *) malloc(sizeof(*curr_cfg));
	memset(curr_cfg, 0, sizeof(*curr_cfg));
	char buffer[256];
	read_line(fp, buffer, 256);
	if (strcmp(buffer, CONFIG_HEADER) != 0) {
		ABORT("bad config file header");
	}
	read_line(fp, buffer, 256);
	sscanf(buffer, "%i,%i,%lf,%lf,%lf,%i", &(curr_cfg->bomb_per_life),
	       &(curr_cfg->deathbomb_frame), &(curr_cfg->hitbox),
	       &(curr_cfg->grazebox), &(curr_cfg->itembox), &(curr_cfg->speed));
	read_line(fp, buffer, 256);
	if (strcmp(buffer, CONFIG_BIG_SPLIT) != 0) {
		ABORT("bad config file format");
	}
	for (int i = 0;; i++) {
		for (int j = 0;; j++) {
			read_line(fp, buffer, 256);
			if (strcmp(buffer, CONFIG_SPLIT) == 0) {
				curr_cfg->shooter_counts[i] = j + 1;
				break;
			}
			if (strcmp(buffer, CONFIG_BIG_SPLIT) == 0) {
				curr_cfg->shooter_exist = i + 1;
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
				curr_cfg->shooter_focus_counts[i] = j + 1;
				break;
			}
			if (strcmp(buffer, CONFIG_BIG_SPLIT) == 0) {
				curr_cfg->shooter_focus_exist = i + 1;
				info("player config loaded: with %i/%i power setups", curr_cfg->shooter_exist, curr_cfg->shooter_focus_exist);
				return;
			}
			load_option_config(buffer,
					   &(curr_cfg->shooters_focus[i][j]));
		}
	}
}
