#ifndef SCRIPT_H
#define SCRIPT_H

#include <util/array.h>
#include <openssl/md5.h>

extern array_head *line_array_list;
extern array_head *sub_array_list;

#define PARAM_TYPE_INT 1
#define PARAM_TYPE_FLOAT 2
#define PARAM_TYPE_VAR 3
#define PARAM_TYPE_SYMBOL 4
#define PARAM_TYPE_SUB 5

typedef struct {
	// local vars
	int i_local_grp_1[4];
	float f_local_grp_1[4];
	int i_local_grp_2[4];
	int return_address;
} ecl_stack_frame;

typedef struct {
	int type;
	char *text;		// also store delay cache as Uint32
} ecl_line;

typedef struct {
	int type;
	union {
		int i;
		float f;
		int var_id;
		unsigned char symbol_hash[MD5_DIGEST_LENGTH];
		char sub_name[16];
	};

} param_t;

typedef char label[MD5_DIGEST_LENGTH];
typedef struct {
	int opcode;
	param_t p[];
} ins_call;

typedef struct {
	char name[16];
	int store_line;
} ecl_sub;

#endif
