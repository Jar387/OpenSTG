#include <openstg.h>

#define VOID enemy_data* enm
#define P1 enemy_data* enm, param_t p1
#define P2 enemy_data* enm, param_t p1, param_t p2
#define P3 enemy_data* enm, param_t p1, param_t p2, param_t p3
#define P4 enemy_data* enm, param_t p1, param_t p2, param_t p3, param_t p4
#define P5 enemy_data* enm, param_t p1, param_t p2, param_t p3, param_t p4, param_t p5
#define P6 enemy_data* enm, param_t p1, param_t p2, param_t p3, param_t p4, param_t p5, param_t p6
#define P7 enemy_data* enm, param_t p1, param_t p2, param_t p3, param_t p4, param_t p5, param_t p6, param_t p7
#define P8 enemy_data* enm, param_t p1, param_t p2, param_t p3, param_t p4, param_t p5, param_t p6, param_t p7, param_t p8
#define P9 enemy_data* enm, param_t p1, param_t p2, param_t p3, param_t p4, param_t p5, param_t p6, param_t p7, param_t p8, param_t p9
#define P14 enemy_data* enm, param_t p1, param_t p2, param_t p3, param_t p4, param_t p5, param_t p6, param_t p7, param_t p8, param_t p9, param_t p10, param_t p11, param_t p12, param_t p13, param_t p14

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

ECL_INS nop(VOID)
{
	info("nop");
}

void *ins_prg[] =
    { nop, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
