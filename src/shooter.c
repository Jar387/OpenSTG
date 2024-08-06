#include <openstg.h>

static void tick_shooter_animation(int count)
{
	static float rotate_counter;
	static float switch_anim_frame;
	if (tick % 1 == 0) {
		if (is_key_pressed(FOCUS)) {
			if (switch_anim_frame != 5) {
				switch_anim_frame++;
			}
		} else {
			if (switch_anim_frame > 0) {
				switch_anim_frame--;
			}
		}
	}
	if (count == 1) {
		draw_game_object(PLAYER_TEXTURE, (v2i) {
				 d2i(player_position).x,
				 d2i(player_position).y - 35 +
				 switch_anim_frame * 2}
				 , RM_B_OPTION_UV, RM_OPTION_SZ,
				 rotate_counter * 5, 1.0f);
	}
	if (count == 2) {
		draw_game_object(PLAYER_TEXTURE, (v2i) {
				 d2i(player_position).x - 35 +
				 switch_anim_frame * 2, d2i(player_position).y}
				 , RM_B_OPTION_UV, RM_OPTION_SZ,
				 rotate_counter * 5, 1.0f);
		draw_game_object(PLAYER_TEXTURE, (v2i) {
				 d2i(player_position).x + 35 -
				 switch_anim_frame * 2, d2i(player_position).y}
				 , RM_B_OPTION_UV, RM_OPTION_SZ,
				 rotate_counter * 5, 1.0f);
	}
	if (count == 3) {
		draw_game_object(PLAYER_TEXTURE, (v2i) {
				 d2i(player_position).x,
				 d2i(player_position).y - 35 +
				 switch_anim_frame * 2}
				 , RM_B_OPTION_UV, RM_OPTION_SZ,
				 rotate_counter * 5, 1.0f);
		draw_game_object(PLAYER_TEXTURE, (v2i) {
				 d2i(player_position).x - 35 -
				 switch_anim_frame * 2, d2i(player_position).y}
				 , RM_B_OPTION_UV, RM_OPTION_SZ,
				 rotate_counter * 5, 1.0f);
		draw_game_object(PLAYER_TEXTURE, (v2i) {
				 d2i(player_position).x + 35 -
				 switch_anim_frame * 2, d2i(player_position).y}
				 , RM_B_OPTION_UV, RM_OPTION_SZ,
				 rotate_counter * 5, 1.0f);
	}
	if (count == 4) {
		draw_game_object(PLAYER_TEXTURE, (v2i) {
				 d2i(player_position).x - 17 +
				 switch_anim_frame,
				 d2i(player_position).y - 35 +
				 switch_anim_frame * 2}
				 , RM_B_OPTION_UV, RM_OPTION_SZ,
				 rotate_counter * 5, 1.0f);
		draw_game_object(PLAYER_TEXTURE, (v2i) {
				 d2i(player_position).x + 17 -
				 switch_anim_frame,
				 d2i(player_position).y - 35 +
				 switch_anim_frame * 2}
				 , RM_B_OPTION_UV, RM_OPTION_SZ,
				 rotate_counter * 5, 1.0f);
		draw_game_object(PLAYER_TEXTURE, (v2i) {
				 d2i(player_position).x - 35 +
				 switch_anim_frame * 2, d2i(player_position).y}
				 , RM_B_OPTION_UV, RM_OPTION_SZ,
				 rotate_counter * 5, 1.0f);
		draw_game_object(PLAYER_TEXTURE, (v2i) {
				 d2i(player_position).x + 35 -
				 switch_anim_frame * 2, d2i(player_position).y}
				 , RM_B_OPTION_UV, RM_OPTION_SZ,
				 rotate_counter * 5, 1.0f);
	}

	rotate_counter++;
}

void tick_shooter()
{
	int power_level = get_power_level();
	if (power_level != 0) {
		tick_shooter_animation(4);	// (power_level+1)/2
	}
}
