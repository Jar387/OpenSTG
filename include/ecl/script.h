#ifndef SCRIPT_H
#define SCRIPT_H

#include <util/array.h>

extern array_head *line_array_list;
extern array_head *sub_array_list;

typedef struct {
	// local vars
	int i_local_grp_1[4];
	float f_local_grp_1[4];
	int i_local_grp_2[4];
	int return_address;
} ecl_stack_frame;

typedef struct {
	int type;
	char *text;
} ecl_line;

typedef struct {
	char name[16];
	int store_line;
} ecl_sub;

#endif
