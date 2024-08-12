#include <openstg.h>

bullet_manager *curr_buman_setup;

#define FREE 0
#define ALLOCATED 1

void init_buman()
{
	// do no initialize
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
		    create_bullet(buman->color, buman->type, buman->offset);
		v2d v = ang2vec(start_angle, buman->curr_spd);
		bu->vx = v.x;
		bu->vy = v.y;
		start_angle += buman->dif;
	}
	buman->curr_spd += buman->spd_delta;
	if (looptime + 1 == buman->count) {
		free(buman);
	}
}

static void style_layer_dif_task(int looptime, void *data)
{
	bullet_manager *buman = (bullet_manager *) data;
	for (int i = 0; i < buman->way; i++) {
		bullet *bu =
		    create_bullet(buman->color, buman->type, buman->offset);
		v2d v = ang2vec(buman->dir, buman->curr_spd);
		bu->vx = v.x;
		bu->vy = v.y;
		buman->dir += 360.0f / buman->way;
	}
	buman->curr_spd += buman->spd_delta;
	buman->dir += buman->dif;
	if (looptime + 1 == buman->count) {
		free(buman);
	}
}

static void style_random_dir_task(int looptime, void *data)
{
	bullet_manager *buman = (bullet_manager *) data;
	for (int i = 0; i < buman->way; i++) {
		bullet *bu =
		    create_bullet(buman->color, buman->type, buman->offset);
		v2d v =
		    ang2vec(zundom
			    (buman->dir - buman->dif, buman->dir + buman->dif),
			    buman->curr_spd);
		bu->vx = v.x;
		bu->vy = v.y;
	}
	buman->curr_spd += buman->spd_delta;
	if (looptime + 1 == buman->count) {
		free(buman);
	}
}

static void style_random_speed_task(int looptime, void *data)
{
	bullet_manager *buman = (bullet_manager *) data;
	for (int i = 0; i < buman->way; i++) {
		bullet *bu =
		    create_bullet(buman->color, buman->type, buman->offset);
		v2d v =
		    ang2vec(buman->dir, zundom(buman->first_v, buman->last_v));
		bu->vx = v.x;
		bu->vy = v.y;
		buman->dir += 360.0f / buman->way;
	}
	buman->dir += buman->dif;
	if (looptime + 1 == buman->count) {
		free(buman);
	}
}

static void style_random_task(int looptime, void *data)
{
	bullet_manager *buman = (bullet_manager *) data;
	for (int i = 0; i < buman->way; i++) {
		bullet *bu =
		    create_bullet(buman->color, buman->type, buman->offset);
		v2d v =
		    ang2vec(zundom
			    (buman->dir - buman->dif, buman->dir + buman->dif),
			    zundom(buman->first_v, buman->last_v));
		bu->vx = v.x;
		bu->vy = v.y;
	}
	if (looptime + 1 == buman->count) {
		free(buman);
	}
}

bullet_manager *create_buman()
{
	bullet_manager *buman = (bullet_manager *) malloc(sizeof(*buman));
	memset(buman, 0, sizeof(*buman));
	curr_buman_setup = buman;
	return buman;
}

void fire()
{
	// bullet speed is liner
	// TODO: add non-liner speed delta
	curr_buman_setup->curr_spd = curr_buman_setup->first_v;
	curr_buman_setup->spd_delta =
	    (curr_buman_setup->last_v -
	     curr_buman_setup->first_v) / curr_buman_setup->count;
	switch (curr_buman_setup->style) {
	case TRACE:
		curr_buman_setup->dir = player_angle(curr_buman_setup->offset);
		add_periodic_times_task(1, curr_buman_setup->count,
					&style_default_task, curr_buman_setup);
		break;
	case DEFAULT:
		add_periodic_times_task(1, curr_buman_setup->count,
					&style_default_task, curr_buman_setup);
		break;
	case LAYER_DIF:
		add_periodic_times_task(1, curr_buman_setup->count,
					&style_layer_dif_task,
					curr_buman_setup);
		break;
	case LAYER_DIF_TRACE:
		curr_buman_setup->dir = player_angle(curr_buman_setup->offset);
		add_periodic_times_task(1, curr_buman_setup->count,
					&style_layer_dif_task,
					curr_buman_setup);
		break;
	case RANDOM_DIR:
		add_periodic_times_task(1, curr_buman_setup->count,
					&style_random_dir_task,
					curr_buman_setup);
		break;
	case RANDOM_SPEED:
		add_periodic_times_task(1, curr_buman_setup->count,
					&style_random_speed_task,
					curr_buman_setup);
		break;
	case RANDOM:
		add_periodic_times_task(1, curr_buman_setup->count,
					&style_random_task, curr_buman_setup);
		break;
	default:
		ILLEGALPARAM("bullet manager style");
		return;
	}

}

void bstyle(int style)
{
	curr_buman_setup->style = style;
}

void bshape(int color, int type)
{
	curr_buman_setup->color = color;
	curr_buman_setup->type = type;
}

void boffset(int offset_x, int offset_y)
{
	curr_buman_setup->offset = (v2d) {
	offset_x, offset_y};
}

void bamount(int way, int count)
{
	curr_buman_setup->way = way;
	curr_buman_setup->count = count;
}

void bspeed(double first, double last)
{
	curr_buman_setup->first_v = first;
	curr_buman_setup->last_v = last;
}

void bangle(double dir, double dif)
{
	curr_buman_setup->dir = dir;
	curr_buman_setup->dif = dif;
}
