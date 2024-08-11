#include <openstg.h>

const int bullet_spirit[10] = {SPR_DOT, SPR_RING, SPR_RICE, SPR_SMALL, SPR_CHAIN, SPR_NIDDLE, SPR_MIDDLE, SPR_FIRE, SPR_KNIFE, SPR_BIG};

// ECL global vars
int rank; // -10013
int difficulty; // -10014, unused
float player_x; // -10018
float player_y; // -10019
float player_z; // -10020, unused
int aim; // -10021
int dist; // -10023, unused
int shot_type; // -10025

// player related game data
int player_count;
int bomb_count;
int hiscore;
int score;
int power;
int graze;
int point;
int invulnerable_frame;

void init_ecl(){
    rank = RANK_LUNATIC;
    shot_type = curr_cfg->config_id;
}

void tick_ecl(){

}
