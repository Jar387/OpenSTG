#include <openstg.h>

list_head *bullet_list;

bullet *create_bullet(int color, int type, v2d xy)
{
	// check all params in entry to avoid free
	if (color < BLACK || color > WHITE) {
		ILLEGALPARAM("color");
	}
	if (type < DOT || type > BIG) {
		ILLEGALPARAM("type");
	}
	bullet *bu = (bullet *) malloc(sizeof(bullet));
	memset(bu, 0, sizeof(bullet));
	bu->xy = xy;
	bu->tick = 0;
	bu->fire = -1;
	// calculate texture uv and hibox
	// make at commit 19aafbc with basic function
	// remake at commit bebc3f with full function
	// remake at commit 0cf748 with generic offset fix
	// remake at commit 483c9a with EoSD texture
	// remake at commit cdcc56 with EoSD texture and id
	// this is such a fucking part :(
	v2i uv, wh, hitbox;
	if (type == DOT) {
		wh.x = 8;
		wh.y = 8;
		hitbox.x = 6;
		hitbox.y = 6;
		if (color < 8) {
			// first row
			uv.x = 128 + color * 8;
			uv.y = 207;
		} else {
			color -= 8;
			uv.x = 128 + color * 8;
			uv.y = 215;
		}
	} else if (type == MIDDLE) {
		wh.x = 32;
		wh.y = 32;
		hitbox.x = 16;
		hitbox.y = 16;
		uv.x = color * 32;
		uv.y = 128;
	} else if (type == KNIFE) {
		wh.x = 32;
		wh.y = 32;
		hitbox.x = 6;
		hitbox.y = 30;
		uv.x = color * 32;
		uv.y = 160;
	} else if (type == BIG) {
		wh.x = 64;
		wh.y = 64;
		hitbox.x = 32;
		hitbox.y = 32;
		uv.x = 256 + color * 64;
		uv.y = 0;
	} else if (type == FIRE) {
		bu->fire = 1;
	} else {
		// all 16x16 normal bullet
		hitbox.x = 8;
		hitbox.y = 8;
		wh.x = 16;
		wh.y = 16;
		uv.x = 16 * color;
		switch (type) {
		case RING:
			uv.y = 32;
			break;
		case RICE:
			uv.y = 64;
			break;
		case SMALL:
			uv.y = 48;
			break;
		case CHAIN:
			uv.y = 80;
			break;
		case NIDDLE:
			uv.y = 96;
			break;
			// not default situation
		}
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
	if (check_collision(PLAYER_POSITION_D, (v2d) {
			    curr_cfg->hitbox, curr_cfg->hitbox}
			    , bu->xy, i2d(bu->hitbox_sz))) {
		player_die();
		delete_bullet(bu);
	}
	if (check_collision(PLAYER_POSITION_D, (v2d) {
			    curr_cfg->grazebox, curr_cfg->grazebox}
			    , bu->xy, i2d(bu->hitbox_sz))) {
		graze++;
	}
	if (bu->fire == -1) {
		draw_game_object(BULLET_TEX, d2i(bu->xy), bu->uv, bu->wh,
				 bu->angle, 1.0f);
	} else {
		draw_game_object(BULLET_TEX, d2i(bu->xy), (v2i) {
				 bu->fire * 32, 192}
				 , (v2i) {
				 32, 32}
				 , bu->angle, 1.0f);
		if (bu->fire == 3) {
			bu->fire = 0;
		} else {
			bu->fire++;
		}
	}

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
