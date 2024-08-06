#include <openstg.h>

// global game data
int player_count;
int bomb_count;
int hiscore;
int score;
int power;
int graze;
v2d player_position;

static int animation_frame = 0;
static int lr_frame = 0;
static v2i uv = PLAYER_DEFAULT_ANIMATION_UV;
static v2i lr_uv = PLAYER_LEFT_ANIMATION_UV;
static float rotate_counter = 0.0f;

static inline void draw_focus_border()
{
	draw_game_object(BULLET_TEXTURE, (v2i) {
			 player_position.x,
			 player_position.y}, FOCUS_BORDER_UV,
			 FOCUS_BORDER_SZ, rotate_counter, 1.0f);
	draw_game_object(BULLET_TEXTURE, (v2i) {
			 player_position.x,
			 player_position.y}, FOCUS_BORDER_UV,
			 FOCUS_BORDER_SZ, -rotate_counter, 1.0f);
}

void init_player()
{
	player_count = INITIAL_LIFE;
	bomb_count = INITIAL_BOMB;
	hiscore = 0;		// replace later
	score = 0;
	power = 0;
	player_position = (v2d) {
	LENGTH_X / 2, LENGTH_Y / 7 * 6};
}

static void tick_player_shooter()
{
	if (!is_key_pressed(FOCUS)) {
		draw_game_object(PLAYER_TEXTURE, (v2i) {
				 d2i(player_position).x + 25,
				 d2i(player_position).y}
				 , RM_B_OPTION_UV, RM_OPTION_SZ,
				 rotate_counter * 5, 1.0f);
		draw_game_object(PLAYER_TEXTURE, (v2i) {
				 d2i(player_position).x - 25,
				 d2i(player_position).y}
				 , RM_B_OPTION_UV, RM_OPTION_SZ,
				 -rotate_counter * 5 + 180.0f, 1.0f);
	} else {
		draw_game_object(PLAYER_TEXTURE, (v2i) {
				 d2i(player_position).x + 10,
				 d2i(player_position).y - 30}
				 , RM_B_OPTION_UV, RM_OPTION_SZ,
				 rotate_counter * 5, 1.0f);
		draw_game_object(PLAYER_TEXTURE, (v2i) {
				 d2i(player_position).x - 10,
				 d2i(player_position).y - 30}
				 , RM_B_OPTION_UV, RM_OPTION_SZ,
				 -rotate_counter * 5 + 180.0f, 1.0f);
	}
}

void tick_player()
{
	rotate_counter += 1.0f;
	int speed;
	if (is_key_pressed(FOCUS)) {
		speed = SPEED_SLOW;
	} else {
		speed = SPEED;
	}
	if (is_key_pressed(UP)) {
		player_position.y -= speed;
		if (player_position.y <= 15) {
			player_position.y = 15;
		}
	}
	if (is_key_pressed(DOWN)) {
		player_position.y += speed;
		if (player_position.y >= LENGTH_Y - 15) {
			player_position.y = LENGTH_Y - 15;
		}
	}
	if (is_key_pressed(LEFT)) {
		player_position.x -= speed;
		if (player_position.x <= 7) {
			player_position.x = 7;
		}
		lr_uv = PLAYER_LEFT_ANIMATION_UV;
		lr_uv.x += lr_frame * (PLAYER_TEXTURE_SZ.x + 2);
		if (tick % 8 == 0) {
			lr_frame++;
			if (lr_frame >= 8) {
				lr_frame = 5;
			}
		}
		draw_game_object(PLAYER_TEXTURE, d2i(player_position), lr_uv,
				 PLAYER_TEXTURE_SZ, 0.0f, 1.0f);
		if (speed == SPEED_SLOW) {
			draw_focus_border();
		}
		// tick_player_shooter();
		return;
	}
	if (is_key_pressed(RIGHT)) {
		player_position.x += speed;
		if (player_position.x >= LENGTH_X - 7) {
			player_position.x = LENGTH_X - 7;
		}
		lr_uv = PLAYER_RIGHT_ANIMATION_UV;
		lr_uv.x += lr_frame * (PLAYER_TEXTURE_SZ.x + 2);
		if (tick % 8 == 0) {
			lr_frame++;
			if (lr_frame >= 8) {
				lr_frame = 5;
			}
		}
		draw_game_object(PLAYER_TEXTURE, d2i(player_position), lr_uv,
				 PLAYER_TEXTURE_SZ, 0.0f, 1.0f);
		if (speed == SPEED_SLOW) {
			draw_focus_border();
		}
		// tick_player_shooter();
		return;
	}
	lr_frame = 0;
	draw_game_object(PLAYER_TEXTURE, d2i(player_position), uv,
			 PLAYER_TEXTURE_SZ, 0.0f, 1.0f);
	if (tick % 8 == 0) {
		uv.x += PLAYER_TEXTURE_SZ.x + 2;
		animation_frame++;
		if (animation_frame >= 8) {
			animation_frame = 0;
			uv.x = PLAYER_DEFAULT_ANIMATION_UV.x;
		}
	}
	if (speed == SPEED_SLOW) {
		draw_focus_border();
	}
	// tick_player_shooter();
}
