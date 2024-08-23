#include <openstg.h>

void tick_enemy()
{
	enemy_data *enm = &boss_data;	// changle this after multi enemy
	v2d mov_vec = ang2vec(enm->dir, enm->v);
	enm->x += mov_vec.x;
	enm->y += mov_vec.y;
	if (enm->is_clip == 1) {
		if (enm->x < enm->clip_lu.x) {
			enm->x = enm->clip_lu.x;
			goto no_move;
		}
		if (enm->x > enm->clip_rd.x) {
			enm->x = enm->clip_rd.x;
			goto no_move;
		}
		if (enm->y < enm->clip_lu.y) {
			enm->y = enm->clip_lu.y;
			goto no_move;
		}
		if (enm->y > enm->clip_rd.y) {
			enm->y = enm->clip_rd.y;
			goto no_move;
		}
	}
	enm->v += enm->deltav;
	enm->dir += enm->delta_dir;
 no_move:
	// render enemy stuff
}
