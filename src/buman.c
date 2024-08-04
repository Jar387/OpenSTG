#include <openstg.h>

bullet_manager buman_list[MAX_BUMAN_INSTANCE];

void init_buman()
{
	memset(buman_list, 0, sizeof(buman_list));
}

static void style_default_task(int looptime, void *data)
{
	bullet_manager *buman = (bullet_manager *) data;
	float start_angle;
	if (buman->way == 1) {
		start_angle = buman->dir;
	} else if ((buman->way) % 2 == 1) {
		start_angle = buman->dir - (buman->dif) * ((buman->way) / 2);
	} else {
		start_angle =
		    buman->dir - (buman->dif) * ((buman->way) / 2 - 1) -
		    ((buman->dif) / 2);
	}
	for (int i = 0; i < buman->way; i++) {
		bullet *bu =
		    gen_bullet(buman->color, buman->type, buman->offset);
		v2d v = ang2vec(start_angle, buman->curr_spd);
		bu->vx = v.x;
		bu->vy = v.y;
		start_angle += buman->dif;
	}
	buman->curr_spd += buman->spd_delta;
}

static void style_layer_dif_task(int looptime, void *data)
{
	bullet_manager *buman = (bullet_manager *) data;
	for (int i = 0; i < buman->way; i++) {
		bullet *bu =
		    gen_bullet(buman->color, buman->type, buman->offset);
		v2d v = ang2vec(buman->dir, buman->curr_spd);
		bu->vx = v.x;
		bu->vy = v.y;
		buman->dir += 360.0f / buman->way;
	}
	buman->curr_spd += buman->spd_delta;
	buman->dir += buman->dif;
}

static void style_random_dir_task(int looptime, void *data)
{
	bullet_manager *buman = (bullet_manager *) data;
	for (int i = 0; i < buman->way; i++) {
		bullet *bu =
		    gen_bullet(buman->color, buman->type, buman->offset);
		v2d v =
		    ang2vec(zundom
			    (buman->dir - buman->dif, buman->dir + buman->dif),
			    buman->curr_spd);
		bu->vx = v.x;
		bu->vy = v.y;
	}
	buman->curr_spd += buman->spd_delta;
}

static void style_random_speed_task(int looptime, void *data)
{
	bullet_manager *buman = (bullet_manager *) data;
	for (int i = 0; i < buman->way; i++) {
		bullet *bu =
		    gen_bullet(buman->color, buman->type, buman->offset);
		v2d v =
		    ang2vec(buman->dir, zundom(buman->first_v, buman->last_v));
		bu->vx = v.x;
		bu->vy = v.y;
		buman->dir += 360.0f / buman->way;
	}
	buman->dir += buman->dif;
}

static void style_random_task(int looptime, void *data)
{
	bullet_manager *buman = (bullet_manager *) data;
	for (int i = 0; i < buman->way; i++) {
		bullet *bu =
		    gen_bullet(buman->color, buman->type, buman->offset);
		v2d v =
		    ang2vec(zundom
			    (buman->dir - buman->dif, buman->dir + buman->dif),
			    zundom(buman->first_v, buman->last_v));
		bu->vx = v.x;
		bu->vy = v.y;
	}
}

void create_bullet(int id)
{
	// clear buman data
	memset(&buman_list[id], 0, sizeof(bullet_manager));
}

void fire(int id)
{
	// bullet speed is liner
	// TODO: add non-liner speed delta
	buman_list[id].curr_spd = buman_list[id].first_v;
	buman_list[id].spd_delta =
	    (buman_list[id].last_v -
	     buman_list[id].first_v) / buman_list[id].count;
	switch (buman_list[id].style) {
	case TRACE:
		buman_list[id].dir = player_angle(buman_list[id].offset);
		add_periodic_times_task(1, buman_list[id].count,
					&style_default_task, &buman_list[id]);
		break;
	case DEFAULT:
		add_periodic_times_task(1, buman_list[id].count,
					&style_default_task, &buman_list[id]);
		break;
	case LAYER_DIF:
		add_periodic_times_task(1, buman_list[id].count,
					&style_layer_dif_task, &buman_list[id]);
		break;
	case LAYER_DIF_TRACE:
		buman_list[id].dir = player_angle(buman_list[id].offset);
		add_periodic_times_task(1, buman_list[id].count,
					&style_layer_dif_task, &buman_list[id]);
		break;
	case RANDOM_DIR:
		add_periodic_times_task(1, buman_list[id].count,
					&style_random_dir_task,
					&buman_list[id]);
		break;
	case RANDOM_SPEED:
		add_periodic_times_task(1, buman_list[id].count,
					&style_random_speed_task,
					&buman_list[id]);
		break;
	case RANDOM:
		add_periodic_times_task(1, buman_list[id].count,
					&style_random_task, &buman_list[id]);
		break;
	default:
		ILLEGALPARAM("bullet manager style");
		return;
	}

}

void bstyle(int id, int style)
{
	buman_list[id].style = style;
}

void bshape(int id, int color, int type)
{
	buman_list[id].color = color;
	buman_list[id].type = type;
}

void boffset(int id, int offset_x, int offset_y)
{
	buman_list[id].offset = (v2d) {
	offset_x, offset_y};
}

void bamount(int id, int way, int count)
{
	buman_list[id].way = way;
	buman_list[id].count = count;
}

void bspeed(int id, double first, double last)
{
	buman_list[id].first_v = first;
	buman_list[id].last_v = last;
}

void bangle(int id, double dir, double dif)
{
	buman_list[id].dir = dir;
	buman_list[id].dif = dif;
}
