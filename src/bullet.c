#include <openstg.h>

bullet *gen_bullet(int color, char type, v2d xy)
{
	bullet *bu = (bullet *) malloc(sizeof(bullet));
	memset(bu, 0, sizeof(bullet));
	bu->xy = xy;
	bu->tick = 0;
	// calculate texture uv
	// remake at commit 2c5cda
	v2i uv;
	v2i wh;
	if (type == LARGE) {
		// use etama2
		wh.x = 64;
		wh.y = 64;
		uv.y = 0;
		switch (color) {
		case RED:
			uv.x = 0 + 256;
			break;
		case BLUE:
			uv.x = 64 + 256;
			break;
		case GREEN:
			uv.x = 128 + 256;
			break;
		case YELLOW:
			uv.x = 192 + 256;
			break;
		default:
			ILLEGALPARAM("bullet color");	// large bullet only have 4 colors
			free(bu);
			return NULL;
		}
		bu->hitbox_sz = (v2i) {
		32, 32};
	} else if (type == MIDDLE || type == LEGACY || type == SAIGYOJI) {
		wh.x = 32;
		wh.y = 32;
		switch (color) {
		case LIGHT_RED:
		case LIGHT_MAGENTA:
		case LIGHT_BLUE:
		case LIGHT_CYAN:
		case LIGHT_GREEN:
		case COLOR_11:
		case LIGHT_YELLOW:
		case ORANGE:{
				ILLEGALPARAM("bullet color");
				free(bu);
				return NULL;
			}

		}
		int index;	// texture index
		if (color < COLOR_11) {
			index = (color + 1) / 2;
		} else if (color == WHITE) {
			index = 7;
		} else {
			index = 6;
		}
		uv.x = index * 32;
		uv.y = 112 + 32 * (type - MIDDLE);
		bu->hitbox_sz = (v2i) {
		16, 16};
	} else {
		wh.x = 16;
		wh.y = 16;
		uv.y = 16 + type * 16;
		uv.x = 16 * color;
		bu->hitbox_sz = (v2i) {
		8, 8};
	}
	// calculate bullet hitbox
	uv.x++;			// fix texture offset bug
	bu->uv = uv;
	bu->wh = wh;
	// add it to bullet list
	bu->node.data = bu;
	insert_tail(bullet_list, &bu->node);
	return bu;
}

static void tick_bullet(void *data, int id)
{
	bullet *bu = (bullet *) data;
	bu->tick++;
	bu->vx += bu->dvx;
	bu->vy += bu->dvy;
	bu->xy.x += bu->vx;
	bu->xy.y += bu->vy;
	bu->angle = vec2ang((v2d) {
			    bu->vx, bu->vy});
	if (check_out_of_screen((v2d) {
				bu->xy.x, bu->xy.y}
				, bu->wh) == 1) {
		delete_bullet(bu);
		return;
	}
	draw_game_object(BULLET_TEX, d2i(bu->xy), bu->uv, bu->wh, bu->angle,
			 1.0f);
}

void delete_bullet(bullet * bu)
{
	delete_object(bullet_list, &bu->node);
}

bullet *query_bullet(int id)
{
	return query_object(bullet_list, id)->data;
}

void delete_bullet_id(int id)
{
	delete_object_id(bullet_list, id);
}

void tick_bullets()
{
	if (bullet_list->head == NULL) {
		return;
	}
	list_foreach(bullet_list, &tick_bullet);
}
