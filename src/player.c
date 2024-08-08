#include <openstg.h>

// global game data
int player_count;
int bomb_count;
int hiscore;
int score;
int power;
int graze;
int point;
v2d player_position;

static int animation_frame = 0;
static int lr_frame = 0;
static v2i uv = PLAYER_DEFAULT_ANIMATION_UV;
static v2i lr_uv = PLAYER_LEFT_ANIMATION_UV;
static float rotate_counter = 0.0f;

static inline void draw_focus_border()
{
	draw_game_object(PLAYER_TEX, (v2i) {
			 player_position.x,
			 player_position.y}, FOCUS_BORDER_UV,
			 FOCUS_BORDER_SZ, rotate_counter, 1.0f);
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

void tick_player()
{
	int reduce_speed = 0;
	rotate_counter += 1.0f;
	tick_shooter();
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
		reduce_speed = speed / M_SQRT2;
	}
	if (is_key_pressed(DOWN)) {
		player_position.y += speed;
		if (player_position.y >= LENGTH_Y - 15) {
			player_position.y = LENGTH_Y - 15;
		}
		reduce_speed = speed / M_SQRT2;
	}
	if (is_key_pressed(LEFT)) {
		if (reduce_speed == 0) {
			player_position.x -= speed;
		} else {
			player_position.x -= reduce_speed;
		}

		if (player_position.x <= 7) {
			player_position.x = 7;
		}
		lr_uv = PLAYER_LEFT_ANIMATION_UV;
		lr_uv.x += lr_frame * (PLAYER_TEXTURE_SZ.x + 2);
		if (lr_frame < 5) {
			lr_frame++;
		} else if (tick % 8 == 0) {
			lr_frame++;
			if (lr_frame >= 8) {
				lr_frame = 5;
			}
		}
		draw_game_object(PLAYER_TEX, d2i(player_position), lr_uv,
				 PLAYER_TEXTURE_SZ, 0.0f, 1.0f);
		if (speed == SPEED_SLOW) {
			draw_focus_border();
		}
		return;
	}
	if (is_key_pressed(RIGHT)) {
		if (reduce_speed == 0) {
			player_position.x += speed;
		} else {
			player_position.x += reduce_speed;
		}

		if (player_position.x >= LENGTH_X - 7) {
			player_position.x = LENGTH_X - 7;
		}
		lr_uv = PLAYER_RIGHT_ANIMATION_UV;
		lr_uv.x += lr_frame * (PLAYER_TEXTURE_SZ.x + 2);
		if (lr_frame < 5) {
			lr_frame++;
		} else if (tick % 8 == 0) {
			lr_frame++;
			if (lr_frame >= 8) {
				lr_frame = 5;
			}
		}
		draw_game_object(PLAYER_TEX, d2i(player_position), lr_uv,
				 PLAYER_TEXTURE_SZ, 0.0f, 1.0f);
		if (speed == SPEED_SLOW) {
			draw_focus_border();
		}
		return;
	}
	lr_frame = 0;
	draw_game_object(PLAYER_TEX, d2i(player_position), uv,
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
}
