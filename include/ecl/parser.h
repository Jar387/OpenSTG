#ifndef PARSER_H
#define PARSER_H

#define STAT_DEALY 1
#define STAT_LABEL 2
#define STAT_INS 3

// parse to pure bin when first exec
#define BIN_DELAY -1
#define BIN_LABEL -2
#define BIN_INS -3

#include <util/array.h>
#include <openssl/md5.h>
#include <config.h>

extern array_head *line_array_list;
extern array_head *sub_array_list;

#define PARAM_TYPE_INT 1
#define PARAM_TYPE_FLOAT 2
#define PARAM_TYPE_VAR 3
#define PARAM_TYPE_SYMBOL 4
#define PARAM_TYPE_SUB 5

extern int line_count;
extern int sub_count;
extern int script_entry;

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
		char symbol_hash[MD5_DIGEST_LENGTH];
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

void load_script(char *path);
void unload_script();

#endif
