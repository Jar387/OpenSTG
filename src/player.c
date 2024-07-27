#include <openstg.h>

// global game data
int player_count;
int bomb_count;
int hiscore;
int score;
int power;
int graze;
pos player_position;

static int animation_frame = 0;
static int lr_frame = 0;
static pos uv = PLAYER_DEFAULT_ANIMATION_UV;
static pos lr_uv = PLAYER_LEFT_ANIMATION_UV;

static inline void draw_focus_border(){
    static float focus_border_angle;
    draw_game_object(BULLET_TEXTURE, (pos){player_position.x+PLAYER_TEXTURE_SZ.x/2-FOCUS_BORDER_SZ.x/2, \
    player_position.y+PLAYER_TEXTURE_SZ.y/2-FOCUS_BORDER_SZ.y/2}, FOCUS_BORDER_UV, FOCUS_BORDER_SZ, focus_border_angle, 1.0f);
    draw_game_object(BULLET_TEXTURE, (pos){player_position.x+PLAYER_TEXTURE_SZ.x/2-FOCUS_BORDER_SZ.x/2, \
    player_position.y+PLAYER_TEXTURE_SZ.y/2-FOCUS_BORDER_SZ.y/2}, FOCUS_BORDER_UV, FOCUS_BORDER_SZ, -focus_border_angle, 1.0f);
    focus_border_angle+=1.0f;
}

void init_player(){
    player_count = INITIAL_LIFE;
    bomb_count = INITIAL_BOMB;
    hiscore = 0; // replace later
    score = 0;
    power = 0;
    player_position = (pos){LENGTH_X/2, LENGTH_Y/2};
}

void tick_player(){
    int speed;
    if(is_key_pressed(FOCUS)){
        speed = SPEED_SLOW;
    }else{
        speed = SPEED;
    }
    if(is_key_pressed(UP)){
        player_position.y-=speed;
        if(player_position.y+6<=0){
            player_position.y+=speed;
        }
    }
    if(is_key_pressed(DOWN)){
        player_position.y+=speed;
        if(player_position.y-6>=LENGTH_Y-PLAYER_TEXTURE_SZ.y){
            player_position.y-=speed;
        }
    }
    if(is_key_pressed(LEFT)){
        player_position.x-=speed;
        if(player_position.x+14<=0){
            player_position.x+=speed;
        }
        lr_uv = PLAYER_LEFT_ANIMATION_UV;
        lr_uv.x+=lr_frame*(PLAYER_TEXTURE_SZ.x+2);
        lr_frame++;
        if(lr_frame>=8){
            lr_frame = 7;
        }
        draw_game_object(PLAYER_TEXTURE, player_position, lr_uv, PLAYER_TEXTURE_SZ, 0.0f, 1.0f);
        if(speed==SPEED_SLOW){
            draw_focus_border();
        }
        return;
    }
    if(is_key_pressed(RIGHT)){
        player_position.x+=speed;
        if(player_position.x-14>=LENGTH_X-PLAYER_TEXTURE_SZ.x){
            player_position.x-=speed;
        }
        lr_uv = PLAYER_RIGHT_ANIMATION_UV;
        lr_uv.x+=lr_frame*(PLAYER_TEXTURE_SZ.x+2);
        lr_frame++;
        if(lr_frame>=8){
            lr_frame = 7;
        }
        draw_game_object(PLAYER_TEXTURE, player_position, lr_uv, PLAYER_TEXTURE_SZ, 0.0f, 1.0f);
        if(speed==SPEED_SLOW){
            draw_focus_border();
        }
        return;
    }
    lr_frame = 0;
    draw_game_object(PLAYER_TEXTURE, player_position, uv, PLAYER_TEXTURE_SZ, 0.0f, 1.0f);
    if(tick%8==0){
        uv.x+=PLAYER_TEXTURE_SZ.x+2;
        animation_frame++;
        if(animation_frame>=8){
            animation_frame = 0;
            uv.x = PLAYER_DEFAULT_ANIMATION_UV.x;
        }
    }
    if(speed==SPEED_SLOW){
            draw_focus_border();
    }
}
