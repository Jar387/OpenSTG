#include <openstg.h>

const int bullet_spirit[10] =
    { SPR_DOT, SPR_RING, SPR_RICE, SPR_SMALL, SPR_CHAIN, SPR_NIDDLE, SPR_MIDDLE,
	SPR_FIRE, SPR_KNIFE, SPR_BIG
};

const int bullet_color[16] =
    { BLACK, RED, LIGHT_RED, MAGENTA, LIGHT_MAGENTA, BLUE, LIGHT_BLUE, CYAN,
	LIGHT_CYAN, GREEN, LIGHT_GREEN, COLOR_11, YELLOW, LIGHT_YELLOW, ORANGE,
	    WHITE
};

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
	bshape(bullet_color[col], bullet_spirit[spr]);
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
	bshape(bullet_color[col], bullet_spirit[spr]);
	boffset(192, 96);	// TODO
	bamount(way, layer);
	bspeed(spd1, spd2);
	bangle(rad2ang(r1), rad2ang(r2));
	fire();
}
