#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <ecl/parser.h>

#define CMD_QUIT 0
#define CMD_QUIT_TXT 'q'
#define CMD_STEP 1
#define CMD_STEP_TXT 's'
#define CMD_DMP 2
#define CMD_DMP_TXT 'r'
#define CMD_CONT 3
#define CMD_CONT_TXT 'c'

void int_handler(int sig);

void init_debugger();
void exec_trig_debug(ecl_line * line, enemy_data * enm);

extern int is_step;

#endif
