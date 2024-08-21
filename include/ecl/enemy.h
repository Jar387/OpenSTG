#ifndef ENEMY_H
#define ENEMY_H

#define MAX_STACK_DEPTH 16

typedef struct {
	// local vars
	int i_local_grp_1[4];
	float f_local_grp_1[4];
	int i_local_grp_2[4];
	int return_address;
} ecl_stack_frame;

typedef struct {
	int x;			// -10015
	int y;			// -10016
	int z;			// -10017, only used by extra boss
	float aim;		// -10021
	int tick;		// -10022
	float dist;		// -10023, unused
	int life;		// -10024
	ecl_stack_frame stack[MAX_STACK_DEPTH];
	int sp;			// stack pointer
	int ip;			// instruction pointer
	int fp;			// function pointer
	int curr_delay;		// remain ticks until activate
} enemy_data;

#endif
