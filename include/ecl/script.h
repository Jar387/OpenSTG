#ifndef SCRIPT_H
#define SCRIPT_H

#include <openstg.h>

extern array_head *line_array_list;
extern array_head *sub_array_list;

typedef struct {
	int type;
	char *text;
} ecl_line;

typedef struct {
	char name[16];
	int store_line;
} ecl_sub;

#endif
