#include <openstg.h>

int is_debug = 0;
int is_step = 0;

int last_ins = -1;

void int_handler(int sig)
{
	if (is_debug == 1) {
		is_step = 1;
	}
}

static void dump_stat(enemy_data * enm)
{
	printf("CURRENT CONTEXT:\n");
	printf("$i0: %i\t", enm->stack[enm->sp].i_local_grp_1[0]);
	printf("$i1: %i\t", enm->stack[enm->sp].i_local_grp_1[1]);
	printf("$i2: %i\t", enm->stack[enm->sp].i_local_grp_1[2]);
	printf("$i3: %i\n", enm->stack[enm->sp].i_local_grp_1[3]);
	printf("$i4: %i\t", enm->stack[enm->sp].i_local_grp_1[4]);
	printf("$i5: %i\t", enm->stack[enm->sp].i_local_grp_1[5]);
	printf("$i6: %i\t", enm->stack[enm->sp].i_local_grp_1[6]);
	printf("$i7: %i\n", enm->stack[enm->sp].i_local_grp_1[7]);
	printf("%%f0: %f\t", enm->stack[enm->sp].f_local_grp_1[0]);
	printf("%%f1: %f\t", enm->stack[enm->sp].f_local_grp_1[1]);
	printf("%%f2: %f\t", enm->stack[enm->sp].f_local_grp_1[2]);
	printf("%%f3: %f\n", enm->stack[enm->sp].f_local_grp_1[3]);
	printf("ip: %i\t", enm->ip);
	printf("sp: %i\t", enm->sp);
	printf("func: %i (%s)\n", enm->fp, get_sub(enm->fp)->name);
	printf("flags: CMP=%i ", enm->cmp_reg);
	if (enm->is_clip == 0) {
		printf("clip ");
	} else {
		printf("CLIP ");
	}
	if (enm->hit_flag == 0) {
		printf("hit ");
	} else {
		printf("HIT ");
	}
	if (enm->hurt_flag == 0) {
		printf("hurt ");
	} else {
		printf("HURT ");
	}
	printf("\n");
}

static void dump_enemy(enemy_data * enm)
{
	printf("CURRENT ENEMY:\n");
	printf("position:(%i,%i,%i)\n", enm->x, enm->y, enm->z);
	printf("aim=%f\ttick=%i\tlife=%i\n", enm->aim, enm->tick, enm->life);
	printf("v=%f\tdv=%f\tdir=%f\tddir=%f\n", enm->v, enm->deltav, enm->dir,
	       enm->delta_dir);
	if (enm->is_clip == 1) {
		printf("clip:(%f,%f),(%f,%f)\n", enm->clip_lu.x, enm->clip_lu.y,
		       enm->clip_rd.x, enm->clip_rd.y);
	} else {
		printf("no clip\n");
	}
	printf("hitbox:(%f,%f,%f)\n", enm->w, enm->h, enm->d);
	printf("bullet offset:(%f,%f)\n", enm->launch_off_x, enm->launch_off_y);
}

void exec_trig_debug(ecl_line * line, enemy_data * enm)
{
	if (is_debug == 0 || is_step == 0) {
		return;
	}
	int c;
	char cmd_buf;
	printf("%i %i %s\n", line->src_line, enm->ip,
	       get_debug_code(line->src_line));
	while (1) {
		printf("(debug) ");
		scanf("%c", &cmd_buf);
		if (cmd_buf != '\n') {
			while ((c = getchar()) != '\n') {
			}
		}
		switch (cmd_buf) {
		case CMD_QUIT_TXT:
			last_ins = CMD_QUIT;
			exit(0);
		case CMD_STEP_TXT:
			last_ins = CMD_STEP;
			is_step = 1;
			return;
		case CMD_DMP_TXT:
			last_ins = CMD_DMP;
			dump_stat(enm);
			dump_enemy(enm);
			break;
		case CMD_CONT_TXT:
			last_ins = CMD_CONT;
			is_step = 0;
			return;
		case '\n':
			switch (last_ins) {
			case CMD_QUIT:
				exit(0);
			case CMD_STEP:
				is_step = 1;
				return;
			case CMD_DMP:
				dump_stat(enm);
				dump_enemy(enm);
				break;
			case CMD_CONT:
				is_step = 0;
				return;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}

void init_debugger()
{
	signal(SIGINT, &int_handler);
	is_debug = 1;
	is_step = 1;
	info("debugger loaded successfully, raise SIGINT to enter debug mode");
}

int get_step()
{
	return is_step;
}
