#include <openstg.h>

// global game data
int player_count;
int bomb_count;
int hiscore;
int score;
int power;
int graze;
pos player_position;

void init_player(){
    player_count = INITIAL_LIFE;
    bomb_count = INITIAL_BOMB;
    hiscore = 0; // replace later
    score = 0;
    power = 0;
    player_position = (pos){LENGTH_X/2, LENGTH_Y/2};
}

void tick_player(){
    
}
