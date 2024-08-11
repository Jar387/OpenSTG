#include <openstg.h>

static int animation_frame = 0;
static int lr_frame = 0;
static v2i uv = PLAYER_DEFAULT_ANIMATION_UV;
static v2i lr_uv = PLAYER_LEFT_ANIMATION_UV;
static float rotate_counter = 0.0f;

static inline void draw_focus_border()
{
	draw_game_object(PLAYER_TEX, (v2i) {
			 player_x,
			 player_y}, FOCUS_BORDER_UV,
			 FOCUS_BORDER_SZ, rotate_counter, 1.0f);
}

void init_player()
{
	player_count = curr_cfg->initial_life;
	bomb_count = curr_cfg->bomb_per_life;
	hiscore = 0;		// replace later
	score = 0;
	power = 0;
	invulnerable_frame = 0;
	player_x = LENGTH_X / 2;
	player_y = LENGTH_Y / 7 * 6;
}

void tick_player()
{
	if (invulnerable_frame != 0) {
		invulnerable_frame--;
	}
	int reduce_speed = 0;
	rotate_counter += 1.0f;
	tick_shooter();
	int speed;
	if (is_key_pressed(FOCUS_KEY)) {
		speed = curr_cfg->speed / 2;
	} else {
		speed = curr_cfg->speed;
	}
	if (is_key_pressed(UP_KEY)) {
		player_y -= speed;
		if (player_y <= 15) {
			player_y = 15;
		}
		reduce_speed = speed / M_SQRT2;
	}
	if (is_key_pressed(DOWN_KEY)) {
		player_y += speed;
		if (player_y >= LENGTH_Y - 15) {
			player_y = LENGTH_Y - 15;
		}
		reduce_speed = speed / M_SQRT2;
	}
	if (is_key_pressed(LEFT_KEY)) {
		if (reduce_speed == 0) {
			player_x -= speed;
		} else {
			player_x -= reduce_speed;
		}

		if (player_x <= 7) {
			player_x = 7;
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
		draw_game_object(PLAYER_TEX, PLAYER_POSITION_I, lr_uv,
				 PLAYER_TEXTURE_SZ, 0.0f, 1.0f);
		if (speed == curr_cfg->speed / 2) {
			draw_focus_border();
		}
		return;
	}
	if (is_key_pressed(RIGHT_KEY)) {
		if (reduce_speed == 0) {
			player_x += speed;
		} else {
			player_x += reduce_speed;
		}

		if (player_x >= LENGTH_X - 7) {
			player_x = LENGTH_X - 7;
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
		draw_game_object(PLAYER_TEX, PLAYER_POSITION_I, lr_uv,
				 PLAYER_TEXTURE_SZ, 0.0f, 1.0f);
		if (speed == curr_cfg->speed / 2) {
			draw_focus_border();
		}
		return;
	}
	lr_frame = 0;
	draw_game_object(PLAYER_TEX, PLAYER_POSITION_I, uv,
			 PLAYER_TEXTURE_SZ, 0.0f, 1.0f);
	if (tick % 8 == 0) {
		uv.x += PLAYER_TEXTURE_SZ.x + 2;
		animation_frame++;
		if (animation_frame >= 8) {
			animation_frame = 0;
			uv.x = PLAYER_DEFAULT_ANIMATION_UV.x;
		}
	}
	if (speed == curr_cfg->speed / 2) {
		draw_focus_border();
	}
}

void player_die()
{
	if (invulnerable_frame == 0) {
		if (player_count != 0) {
			player_count--;
		}
		power = 0;
		player_x = LENGTH_X / 2;
		player_y = LENGTH_Y / 7 * 6;
	}
}
