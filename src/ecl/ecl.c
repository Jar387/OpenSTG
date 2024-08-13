#include <openstg.h>

// ECL global vars
int rank;			// -10013
int difficulty;			// -10014, unused
float player_x;			// -10018
float player_y;			// -10019
float player_z;			// -10020, unused
int shot_type;			// -10025

// player related game data
int player_count;
int bomb_count;
int hiscore;
int score;
int power;
int graze;
int point;
int invulnerable_frame;

void init_ecl()
{
	rank = RANK_LUNATIC;
	shot_type = curr_cfg->config_id;
}

void tick_ecl()
{
}

void et_on_fan_aim(int spr, int col, int way, int layer, double spd1,
		   double spd2, double r1, double r2, int flags)
{
	create_buman();
	bstyle(TRACE);
	bshape(col, spr);
	boffset(192, 96);	// TODO
	bamount(way, layer);
	bspeed(spd1, spd2);
	bangle(rad2ang(r1), rad2ang(r2));
	fire();
}

void et_on_fan(int spr, int col, int way, int layer, double spd1, double spd2,
	       double r1, double r2, int flags)
{
	create_buman();
	bstyle(DEFAULT);
	bshape(col, spr);
	boffset(192, 96);	// TODO
	bamount(way, layer);
	bspeed(spd1, spd2);
	bangle(rad2ang(r1), rad2ang(r2));
	fire();
}
