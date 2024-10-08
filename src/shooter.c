#include <openstg.h>

list_head *player_bullet_list;

static void tick_shooter_animation()
{
	static float rotate_counter;
	static float switch_anim_frame;
	if (is_key_pressed(FOCUS_KEY)) {
		if (switch_anim_frame != 5) {
			switch_anim_frame++;
		}
	} else {
		if (switch_anim_frame > 0) {
			switch_anim_frame--;
		}
	}
	draw_game_object(PLAYER_TEX, (v2i) {
			 player_x - 20 +
			 switch_anim_frame * 2,
			 player_y - switch_anim_frame * 5}
			 , RM_OPTION_UV, RM_OPTION_SZ, rotate_counter * 5,
			 1.0f);
	draw_game_object(PLAYER_TEX, (v2i) {
			 player_x + 20 -
			 switch_anim_frame * 2,
			 player_y - switch_anim_frame * 5}
			 , RM_OPTION_UV, RM_OPTION_SZ, -rotate_counter * 5,
			 1.0f);
	rotate_counter++;
}

player_bullet *create_player_bullet(int id, v2d xy, v2i hitbox, int angle,
				    int speed)
{
	player_bullet *bu = (player_bullet *) malloc(sizeof(*bu));
	memset(bu, 0, sizeof(*bu));
	bu->xy = (v2d) {
	player_x + xy.x, player_y + xy.y};
	bu->dxy = ang2vec((double)angle, (double)speed);
	bu->hitbox = hitbox;
	switch (id) {
	case 0:{
			bu->uv = RM_BULLET_0_UV;
			bu->wh = RM_BULLET_0_SZ;
			break;
		}
	case 1:{
			bu->uv = RM_BULLET_1_UV;
			bu->wh = RM_BULLET_1_SZ;
			break;
		}
	case 2:{
			bu->uv = RM_BULLET_2_UV;
			bu->wh = RM_BULLET_2_SZ;
			break;
		}
	default:
		ILLEGALPARAM("bullet texture id");
		free(bu);
		return NULL;
	}
	bu->node.data = bu;
	insert_tail(player_bullet_list, &bu->node);
	return bu;
}

static void delete_player_bullet(player_bullet * bu)
{
	delete_object(player_bullet_list, &bu->node);
}

static void tick_player_bullet(void *data, int id)
{
	player_bullet *bu = (player_bullet *) data;
	bu->xy.x += bu->dxy.x;
	bu->xy.y += bu->dxy.y;
	bu->angle = vec2ang((v2d) {
			    bu->dxy.x, bu->dxy.y});
	if (check_out_of_screen((v2d) {
				bu->xy.x, bu->xy.y}
				, bu->wh) == 1) {
		delete_player_bullet(bu);
		return;
	}
	draw_game_object(PLAYER_TEX, d2i(bu->xy), bu->uv, bu->wh, bu->angle,
			 1.0f);
}

static void tick_player_bullets()
{
	if (player_bullet_list->head == NULL) {
		return;
	}
	list_foreach(player_bullet_list, &tick_player_bullet);
}

static void tick_player_power(int power_level)
{
	shooter_cfg_data *data;
	if (is_key_pressed(FOCUS_KEY)) {
		data = curr_cfg->shooters_focus[power_level];
	} else {
		data = curr_cfg->shooters[power_level];
	}
	for (int i = 0;; i++) {
		if (data[i].fire_rate == 0) {
			break;
		}
		if (is_key_pressed(SHOOT_KEY) == 0) {
			data[i].cd_counter = data[i].start_dalay;
			continue;
		}
		if (data[i].cd_counter != 0) {
			data[i].cd_counter--;
			continue;
		}
		if (tick % data[i].fire_rate == 0) {
			if (data[i].option == 0) {
				create_player_bullet(data[i].flags,
						     i2d(data[i].position)
						     , data[i].hitbox,
						     data[i].ang,
						     data[i].speed);
			}
			if (data[i].option == 1) {
				create_player_bullet(data[i].flags, (v2d) {
						     data[i].position.x - 25,
						     data[i].position.y}
						     , data[i].hitbox,
						     data[i].ang,
						     data[i].speed);
			}
			if (data[i].option == 2) {
				create_player_bullet(data[i].flags, (v2d) {
						     data[i].position.x + 25,
						     data[i].position.y}
						     , data[i].hitbox,
						     data[i].ang,
						     data[i].speed);
			}
		}
	}
}

void tick_shooter()
{
	int power_level = get_power_level();
	tick_shooter_animation();
	tick_player_power(power_level);
	tick_player_bullets();
}
