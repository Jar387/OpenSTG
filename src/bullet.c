#include <openstg.h>

bullet *gen_bullet(int color, char type, v2d xy)
{
	bullet *bu = (bullet *) malloc(sizeof(bullet));
	memset(bu, 0, sizeof(bullet));
	bu->xy = xy;
	bu->tick = 0;
	// calculate texture uv and hibox
	// remake at commit 483c9ae with EoSD texture
	v2i uv, wh, hitbox;
	if (type == RING ||
	    type == SMALL_BALL ||
	    type == ELLIPSE || type == NIDDLE || type == CRYSTAL) {
		uv.x = color;
		uv.y = type;
		wh.x = 16;
		wh.y = 16;
		hitbox.x = 8;
		hitbox.x = 8;
	} else if (type == MINI_BALL) {
		wh.x = 12;
		wh.y = 12;
		hitbox.x = 8;
		hitbox.x = 8;
		uv.y = 113;
		switch (color) {
		case BLACK:{
				uv.x = 66;
				break;
			}
		case RED:{
				uv.x = 82;
				break;
			}
		case BLUE:{
				uv.x = 98;
				break;
			}
		case GREEN:{
				uv.x = 114;
				break;
			}
		case YELLOW:{
				uv.x = 130;
				break;
			}
		default:{
				ILLEGALPARAM("color");
			}
		}
	} else if (type == MINI_CIRCLE) {
		wh.x = 12;
		wh.y = 12;
		hitbox.x = 8;
		hitbox.x = 8;
		uv.y = 113;
		switch (color) {
		case BLACK:{
				uv.x = 146;
				break;
			}
		case RED:{
				uv.x = 162;
				break;
			}
		case BLUE:{
				uv.x = 178;
				break;
			}
		case GREEN:{
				uv.x = 194;
				break;
			}
		case YELLOW:{
				uv.x = 210;
				break;
			}
		default:{
				ILLEGALPARAM("color");
			}
		}
	} else if (type == MIDDLE_BALL) {
		wh.x = 32;
		wh.y = 32;
		hitbox.x = 16;
		hitbox.x = 16;
		uv.y = 128;
		switch (color) {
		case BLACK:{
				uv.x = 0 * 32;
				break;
			}
		case RED:{
				uv.x = 1 * 32;
				break;
			}
		case MAGENTA:{
				uv.x = 2 * 32;
				break;
			}
		case BLUE:{
				uv.x = 3 * 32;
				break;
			}
		case CYAN:{
				uv.x = 4 * 32;
				break;
			}
		case GREEN:{
				uv.x = 5 * 32;
				break;
			}
		case YELLOW:{
				uv.x = 6 * 32;
				break;
			}
		case WHITE:{
				uv.x = 7 * 32;
				break;
			}
		default:{
				ILLEGALPARAM("color");
			}
		}
	} else if (type == KNIFE) {
		wh.x = 32;
		wh.y = 32;
		hitbox.x = 6;
		hitbox.x = 30;
		uv.y = 160;
		switch (color) {
		case BLACK:{
				uv.x = 0 * 32;
				break;
			}
		case RED:{
				uv.x = 1 * 32;
				break;
			}
		case MAGENTA:{
				uv.x = 2 * 32;
				break;
			}
		case BLUE:{
				uv.x = 3 * 32;
				break;
			}
		case CYAN:{
				uv.x = 4 * 32;
				break;
			}
		case GREEN:{
				uv.x = 5 * 32;
				break;
			}
		case YELLOW:{
				uv.x = 6 * 32;
				break;
			}
		case WHITE:{
				uv.x = 7 * 32;
				break;
			}
		default:{
				ILLEGALPARAM("color");
			}
		}
	} else if (type == GLOWING_BALL) {
		wh.x = 32;
		wh.y = 32;
		hitbox.x = 12;
		hitbox.x = 12;
		uv.y = 224;
		switch (color) {
		case BLACK:{
				uv.x = 0 * 32;
				break;
			}
		case RED:{
				uv.x = 1 * 32;
				break;
			}
		case MAGENTA:{
				uv.x = 2 * 32;
				break;
			}
		case BLUE:{
				uv.x = 3 * 32;
				break;
			}
		case CYAN:{
				uv.x = 4 * 32;
				break;
			}
		case GREEN:{
				uv.x = 5 * 32;
				break;
			}
		case YELLOW:{
				uv.x = 6 * 32;
				break;
			}
		case WHITE:{
				uv.x = 7 * 32;
				break;
			}
		default:{
				ILLEGALPARAM("color");
			}
		}
	} else if (type == BIG_BALL) {
		wh.x = 64;
		wh.y = 64;
		hitbox.x = 45;
		hitbox.x = 45;
		uv.y = 0;
		switch (color) {
		case RED:{
				uv.x = 256 + 0 * 64;
				break;
			}
		case BLUE:{
				uv.x = 256 + 1 * 64;
				break;
			}
		case GREEN:{
				uv.x = 256 + 2 * 64;
				break;
			}
		case YELLOW:{
				uv.x = 256 + 3 * 64;
				break;
			}
		default:{
				ILLEGALPARAM("color");
			}
		}
	} else {
		ILLEGALPARAM("type");
	}

	bu->uv = uv;
	bu->wh = wh;
	bu->hitbox_sz = hitbox;
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
