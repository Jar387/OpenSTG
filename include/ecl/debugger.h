#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <ecl/parser.h>

#define CMD_QUIT 0
#define CMD_QUIT_TXT 'q'
#define CMD_STEP 1
#define CMD_STEP_TXT 's'
#define CMD_DMP 2
#define CMD_DMP_TXT 'r'

void int_handler(int sig);

void init_debugger();
void exec_trig_debug(ecl_line * line, enemy_data * enm);

#endif
