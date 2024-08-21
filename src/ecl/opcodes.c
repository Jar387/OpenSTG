#include <openstg.h>

#define VOID enemy_data* enm
#define P1 enemy_data* enm, param_t *p1
#define P2 enemy_data* enm, param_t *p1, param_t *p2
#define P3 enemy_data* enm, param_t *p1, param_t *p2, param_t *p3
#define P4 enemy_data* enm, param_t *p1, param_t *p2, param_t *p3, param_t *p4
#define P5 enemy_data* enm, param_t *p1, param_t *p2, param_t *p3, param_t *p4, param_t *p5
#define P6 enemy_data* enm, param_t *p1, param_t *p2, param_t *p3, param_t *p4, param_t *p5, param_t *p6
#define P7 enemy_data* enm, param_t *p1, param_t *p2, param_t *p3, param_t *p4, param_t *p5, param_t *p6, param_t *p7
#define P8 enemy_data* enm, param_t *p1, param_t *p2, param_t *p3, param_t *p4, param_t *p5, param_t *p6, param_t *p7, param_t *p8
#define P9 enemy_data* enm, param_t *p1, param_t *p2, param_t *p3, param_t *p4, param_t *p5, param_t *p6, param_t *p7, param_t *p8, param_t *p9
#define P14 enemy_data* enm, param_t *p1, param_t *p2, param_t *p3, param_t *p4, param_t *p5, param_t *p6, param_t *p7, param_t *p8, param_t *p9, param_t *p10, param_t *p11, param_t *p12, param_t *p13, param_t *p14

#define ECL_INS void

// only void, 1, 2, 3, 4, 5, 6, 7, 8, 9, 14 
int ins_arg_count[] =
    { 0, 1, 2, 3, 2, 2, 2, 3, 2, 3, 1, 1, 1, 3, 3, 3, 3, 3, 1, 1, 3, 3, 3, 3, 3,
	5, 1, 2, 2, 2, 2, 2, 2, 2, 2, 3, 0, 5, 5, 5, 5, 5, 5, 3, 3, 2, 1, 1, 1,
	2, 2, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 4, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 1, 1,
	0, 0, 0, 3, 8,
	0, 1, 14, 14, 1, 2, 2, 4, 1, 1, 3, 0, 7, 0, 1, 5, 2, 1, 1, 5, 3, 1, 1,
	1, 1, 1, 2, 1,
	1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 2, 1, 1, 1, 0, 1, 1, 1, 2, 1, 6, 1, 0, 0,
	1
};

int read_int_var(enemy_data * enm, int var_id)
{				// only used to get int
	if (var_id >= 0 && var_id < FIELD_RANK_ID) {
		// local var
		ecl_stack_frame *frame = &(enm->stack[enm->sp]);
		if (var_id <= 3) {
			return frame->i_local_grp_1[var_id];
		} else if (var_id <= 7) {
			return -1;
		} else {
			var_id -= 8;
			return frame->i_local_grp_2[var_id];
		}
	}
	switch (var_id) {
	case FIELD_RANK_ID:{
			return rank;
		}
	case FIELD_DIFFICULTY_ID:{
			return difficulty;
		}
	case FIELD_TIME_ID:{
			return enm->tick;
		}
	case FIELD_LIFE_ID:{
			return enm->life;
		}
	case FIELD_SHOT_TYPE_ID:{
			return shot_type;
		}
	}
	return -1;
}

float read_float_var(enemy_data * enm, int var_id)
{				// only used to get float
	if (var_id >= 0 && var_id < FIELD_RANK_ID) {
		// local var
		ecl_stack_frame *frame = &(enm->stack[enm->sp]);
		if (var_id <= 3) {
			return -NAN;
		} else if (var_id <= 7) {
			var_id -= 4;
			return frame->f_local_grp_1[var_id];
		} else {
			return -NAN;
		}
	}
	switch (var_id) {
	case FIELD_X_ID:{
			return enm->x;
		}
	case FIELD_Y_ID:{
			return enm->y;
		}
	case FIELD_Z_ID:{
			return enm->z;
		}
	case FIELD_PLAYER_X_ID:{
			return player_x;
		}
	case FIELD_PLAYER_Y_ID:{
			return player_y;
		}
	case FIELD_PLAYER_Z_ID:{
			return player_z;
		}
	case FIELD_AIM_ID:{
			return enm->aim;
		}
	case FIELD_DIST_ID:{
			return enm->dist;
		}
	}
	return -NAN;
}

void write_int_var(enemy_data * enm, int var_id, int data)
{				// only used to put int
	if (var_id >= 0 && var_id < FIELD_RANK_ID) {
		// local var
		ecl_stack_frame *frame = &(enm->stack[enm->sp]);
		if (var_id <= 3) {
			frame->i_local_grp_1[var_id] = data;
			return;
		} else if (var_id <= 7) {
			return;
		} else {
			var_id -= 8;
			frame->i_local_grp_2[var_id] = data;
			return;
		}
	}
	switch (var_id) {
	case FIELD_TIME_ID:{
			enm->tick = data;
			return;
		}
	case FIELD_LIFE_ID:{
			enm->life = data;
			return;
		}
	}
}

void write_float_var(enemy_data * enm, int var_id, float data)
{				// only used to put float
	if (var_id >= 0 && var_id < FIELD_RANK_ID) {
		// local var
		ecl_stack_frame *frame = &(enm->stack[enm->sp]);
		if (var_id <= 3) {
			return;
		} else if (var_id <= 7) {
			var_id -= 4;
			frame->f_local_grp_1[var_id] = data;
			return;
		} else {
			return;
		}
	}
	switch (var_id) {
	case FIELD_X_ID:{
			enm->x = data;
			return;
		}
	case FIELD_Y_ID:{
			enm->y = data;
			return;
		}
	case FIELD_Z_ID:{
			enm->z = data;
			return;
		}
	case FIELD_PLAYER_X_ID:{
			player_x = data;
			return;
		}
	case FIELD_PLAYER_Y_ID:{
			player_y = data;
			return;
		}
	case FIELD_PLAYER_Z_ID:{
			player_z = data;
			return;
		}
	}
}

ECL_INS nop(VOID)
{
}

ECL_INS delete(P1)
{
	// TODO: finish this after bossrush finished
	info("multi enemy not supported yet");
}

ECL_INS jmp(P2)
{
	write_int_var(enm, FIELD_TIME_ID, p1->i);
	int ip = search_symbol(enm, p2->symbol_hash);
	if (ip == -1) {
		return;
	}
	enm->ip = ip - 1;
}

ECL_INS loop(P3)
{
	int cx = read_int_var(enm, p3->var_id);
	if (cx == 0) {
		return;
	}
	write_int_var(enm, p3->var_id, cx - 1);
	write_int_var(enm, FIELD_TIME_ID, p1->i);
	int ip = search_symbol(enm, p2->symbol_hash);
	if (ip == -1) {
		return;
	}
	enm->ip = ip - 1;
}

ECL_INS iset(P2)
{
	write_int_var(enm, p1->var_id, p2->i);
}

ECL_INS fset(P2)
{
	write_float_var(enm, p1->var_id, p2->f);
}

ECL_INS iset_r(P2)
{
	write_int_var(enm, p1->var_id, zundom_raw() % p2->i);
}

ECL_INS iset_r2(P3)
{
	write_int_var(enm, p1->var_id, p2->i + zundom_raw() % p3->i);
}

ECL_INS fset_r(P2)
{
}

ECL_INS fset_r2(P3)
{

}

void *ins_prg[] =
    { nop, delete, jmp, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};
