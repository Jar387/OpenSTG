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
	info("nop invoked");
}

ECL_INS delete(P1)
{
	// TODO: finish this after bossrush finished
	info("multi enemy not supported yet");
}

ECL_INS jmp(P2)
{
	write_int_var(enm, FIELD_TIME_ID, p1->i);
	int ip = search_symbol(enm, p2->hash);
	if (ip == -1) {
		ABORT("bad symbol");
	}
	enm->ip = ip - 1;
	info("aaa");
}

ECL_INS loop(P3)
{
	int cx = read_int_var(enm, p3->var_id);
	if (cx == 0) {
		return;
	}
	write_int_var(enm, p3->var_id, cx - 1);
	jmp(enm, p1, p2);
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
	write_int_var(enm, p1->var_id, zundom_i(p2->i));
}

ECL_INS iset_r2(P3)
{
	write_int_var(enm, p1->var_id, zundom_i2(p2->i, p3->i));
}

ECL_INS fset_r(P2)
{
	write_float_var(enm, p1->var_id, zundom_f(p2->f));
}

ECL_INS fset_r2(P3)
{
	write_float_var(enm, p1->var_id, zundom_f2(p2->f, p3->f));
}

ECL_INS get_x(P1)
{
	write_float_var(enm, p1->var_id, enm->x);
}

ECL_INS get_y(P1)
{
	write_float_var(enm, p1->var_id, enm->y);
}

ECL_INS get_z(P1)
{
	write_float_var(enm, p1->var_id, enm->z);
}

ECL_INS iadd(P3)
{
	write_int_var(enm, p1->var_id, (p2->i) + (p3->i));
}

ECL_INS isub(P3)
{
	write_int_var(enm, p1->var_id, (p2->i) - (p3->i));
}

ECL_INS imul(P3)
{
	write_int_var(enm, p1->var_id, (p2->i) * (p3->i));
}

ECL_INS idiv(P3)
{
	write_int_var(enm, p1->var_id, (p2->i) / (p3->i));
}

ECL_INS imod(P3)
{
	write_int_var(enm, p1->var_id, (p2->i) % (p3->i));
}

ECL_INS inc(P1)
{
	if (p1->type == PARAM_TYPE_INT) {
		write_int_var(enm, p1->var_id,
			      read_int_var(enm, p1->var_id) + 1);
	} else if (p1->type == PARAM_TYPE_FLOAT) {
		write_float_var(enm, p1->var_id,
				read_float_var(enm, p1->var_id) + 1.0f);
	}
}

ECL_INS dec(P1)
{
	if (p1->type == PARAM_TYPE_INT) {
		write_int_var(enm, p1->var_id,
			      read_int_var(enm, p1->var_id) - 1);
	} else if (p1->type == PARAM_TYPE_FLOAT) {
		write_float_var(enm, p1->var_id,
				read_float_var(enm, p1->var_id) - 1.0f);
	}
}

ECL_INS fadd(P3)
{
	write_float_var(enm, p1->var_id, (p2->f) + (p3->f));
}

ECL_INS fsub(P3)
{
	write_float_var(enm, p1->var_id, (p2->f) - (p3->f));
}

ECL_INS fmul(P3)
{
	write_float_var(enm, p1->var_id, (p2->f) * (p3->f));
}

ECL_INS fdiv(P3)
{
	write_float_var(enm, p1->var_id, (p2->f) / (p3->f));
}

ECL_INS ecl_fmod(P3)		// name conflict by libm
{				// IEEE 754 remainder
	write_float_var(enm, p1->var_id, IEEE_754_remainder(p2->f, p3->f));
}

ECL_INS ecl_atan2(P5)		// name conflict by libm
{
	write_float_var(enm, p1->var_id,
			atan((p4->f - p2->f) / (p5->f - p3->f)));
}

ECL_INS norm_r(P1)
{
	float f = read_float_var(enm, p1->var_id);
	int pi_count = (int)(f / M_PI);
	if (f <= 0.0f) {
		f += pi_count * M_PI;
	} else {
		f -= pi_count * M_PI;
	}
	write_float_var(enm, p1->var_id, f);
}

ECL_INS itest(P2)
{
	if (p1->i < p2->i) {
		enm->flags = -1;
	} else if (p1->i == p2->i) {
		enm->flags = 0;
	} else {
		enm->flags = 1;
	}
}

ECL_INS ftest(P2)
{
	if (p1->f < p2->f) {
		enm->flags = -1;
	} else if (p1->f == p2->f) {
		enm->flags = 0;
	} else if (p1->f > p2->f) {
		enm->flags = 1;
	}
}

ECL_INS jmp_l(P2)
{
	if (enm->flags == -1) {
		jmp(enm, p1, p2);
	}
}

ECL_INS jmp_le(P2)
{
	if (enm->flags == -1 || enm->flags == 0) {
		jmp(enm, p1, p2);
	}
}

ECL_INS jmp_e(P2)
{
	if (enm->flags == 0) {
		jmp(enm, p1, p2);
	}
}

ECL_INS jmp_g(P2)
{
	if (enm->flags == 1) {
		jmp(enm, p1, p2);
	}
}

ECL_INS jmp_ge(P2)
{
	if (enm->flags == 0 || enm->flags == 1) {
		jmp(enm, p1, p2);
	}
}

ECL_INS jmp_n(P2)
{
	if (enm->flags == -1 || enm->flags == 1) {
		jmp(enm, p1, p2);
	}
}

ECL_INS call(P3)
{
	enm->sp++;
	if (enm->sp >= MAX_STACK_DEPTH) {
		ABORT("stack overflow");
	}
	ecl_stack_frame *curr_stack = &(enm->stack[enm->sp]);
	// enm->ip always point to currently executing instruction
	// as ip will automaticly increase by 1 after any instruction exection
	// point return addr to currently "call" and after "return", ip will point to the next ins after "call"
	curr_stack->return_address = enm->ip;
	// set param
	curr_stack->i_local_grp_1[0] = p2->i;
	curr_stack->f_local_grp_1[0] = p3->f;
	curr_stack->return_function = enm->fp;
	int ip = search_sub(p1->hash, &enm->fp);
	if (ip == -1) {
		ABORT("bad sub");
	}
	enm->ip = ip - 1;
}

ECL_INS ret(VOID)
{
	if (enm->sp == 0 || (enm->stack)[enm->sp].return_address == -1
	    || (enm->stack)[enm->sp].return_function == -1) {
		ABORT("stack underflow");
	}
	enm->ip = (enm->stack)[enm->sp].return_address;
	enm->fp = (enm->stack)[enm->sp].return_function;
	enm->sp--;
	info("%i %i", enm->fp, enm->ip);
}

ECL_INS call_l(P3)
{
	if (enm->flags == -1) {
		call(enm, p1, p2, p3);
	}
}

ECL_INS call_le(P3)
{
	if (enm->flags == -1 || enm->flags == 0) {
		call(enm, p1, p2, p3);
	}
}

ECL_INS call_e(P3)
{
	if (enm->flags == 0) {
		call(enm, p1, p2, p3);
	}
}

ECL_INS call_g(P3)
{
	if (enm->flags == 1) {
		call(enm, p1, p2, p3);
	}
}

ECL_INS call_ge(P3)
{
	if (enm->flags == 0 || enm->flags == 1) {
		call(enm, p1, p2, p3);
	}
}

ECL_INS call_n(P3)
{
	if (enm->flags == -1 || enm->flags == 1) {
		call(enm, p1, p2, p3);
	}
}

ECL_INS pos(P3)
{
	enm->x = p1->f;
	enm->y = p2->f;
	enm->z = p3->f;
}

void *ins_prg[] =
    { nop, delete, jmp, loop, iset, fset, iset_r, iset_r2, fset_r, fset_r2,
	get_x, get_y,
	get_z, iadd, isub, imul, idiv, imod, inc, dec, fadd, fsub, fmul, fdiv,
	fmod,
	ecl_atan2, norm_r, itest, ftest, jmp_l, jmp_le, jmp_e, jmp_g, jmp_ge,
	jmp_n, call, ret,
	call_l, call_le,	// spectre instruction
	call_e, call_g, call_ge, call_n, pos, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL,
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
