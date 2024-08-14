#ifndef PARSER_H
#define PARSER_H

#define STAT_DEALY 1
#define STAT_LABEL 2
#define STAT_INS 3

extern int line_count;
extern int sub_count;
extern int script_entry;

void load_script(char *path);
void unload_script();

#endif
