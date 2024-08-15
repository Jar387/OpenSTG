#include <openstg.h>

// mapper list
char *ins_list[NR_INS] = INS_LIST;
char *field_list[NR_FIELD] = LOCAL_LIST;

// ECL global vars
int rank;			// -10013
int difficulty;			// -10014, unused
float player_x;			// -10018
float player_y;			// -10019
float player_z;			// -10020, unused
int shot_type;			// -10025

// player related game data
int player_count;
int bomb_count;
int hiscore;
int score;
int power;
int graze;
int point;
int invulnerable_frame;

int check_ip_onbound(enemy_data * data)
{
	ecl_sub *sub = (ecl_sub *) get_obj(sub_array_list, data->fp + 1);
	if (data->ip + 1 == sub->store_line) {
		return 1;
	}
	return 0;
}

int search_symbol(enemy_data * data, char *symbol)
{
	ecl_sub *curr_sub = (ecl_sub *) get_obj(sub_array_list, data->fp);
	ecl_sub *next_sub = (ecl_sub *) get_obj(sub_array_list, data->fp + 1);
	for (int i = curr_sub->store_line; i < next_sub->store_line; i++) {
		unsigned char hash[MD5_DIGEST_LENGTH];
		MD5((const unsigned char *)symbol, strlen(symbol), hash);
		if (memcmp
		    (hash, ((ecl_line *) (get_obj(line_array_list, i)))->text,
		     MD5_DIGEST_LENGTH)) {
			return i + 1;
		}
	}
	return -1;
}

void parse_label(ecl_line * line)
{
	unsigned char *md5buf = (unsigned char *)malloc(MD5_DIGEST_LENGTH);
	const unsigned char *t = (const unsigned char *)(line->text);
	MD5(t, strlen(line->text), md5buf);
	free(line->text);
	line->text = (char *)md5buf;
	line->type = BIN_LABEL;
}

void parse_single_param(char *text, param_t * target)
{
	info("parse");
	char *last = text + strlen(text) - 1;
	if (text[0] == '$') {
		target->type = PARAM_TYPE_VAR;
		for (int i = 0; i < NR_FIELD; i++) {
			if (strcmp(text + 1, field_list[i]) == 0) {
				target->var_id = i;
				return;
			}
		}
	} else if (text[0] == '%') {
		target->type = PARAM_TYPE_VAR;
		for (int i = 0; i < NR_FIELD; i++) {
			if (strcmp(text + 1, field_list[i]) == 0) {
				target->var_id = i;
				return;
			}
		}
	} else if (last[0] == 'f') {
		target->type = PARAM_TYPE_FLOAT;
		float f;
		sscanf(text, "%f", &f);
		target->f = f;
		return;
	} else if (text[0] == '\"' && last[0] == '\"') {
		target->type = PARAM_TYPE_SUB;
		last[0] = '\0';
		text++;
		strncpy(target->sub_name, text, 16);
		return;
	}
	int i;
	if (sscanf(text, "%d", &i) == 1) {
		target->type = PARAM_TYPE_INT;
		target->i = i;
		return;
	} else {
		target->type = PARAM_TYPE_SYMBOL;
		MD5((const unsigned char *)text, strlen(text),
		    target->symbol_hash);
		return;
	}
}

void exec_ins(ecl_line * line)
{

}

void parse_ins(ecl_line * line)
{
	int opcode;
	ins_call *call;
	char *text = line->text;
	char *param = strchr(text, '(');
	char *end = strchr(text, ')');	// call this first and get rid of string truncate
	*end = '\0';
	*param = '\0';
	param++;		// point to real param list
	for (int i = 0; i < NR_INS; i++) {
		if (strcmp(text, ins_list[i]) == 0) {
			opcode = i;
			break;
		}
	}
	if (param != end) {
		char *count_buffer = (char *)malloc(strlen(param) + 1);
		strcpy(count_buffer, param);
		// have param
		int param_count = 1;
		// count param first
		// we have to scan whole string for 2 times
		char *token = strtok(count_buffer, ", ");
		while (token != NULL) {
			token = strtok(NULL, ", ");
			param_count++;
		}
		// then parse param
		call =
		    (ins_call *) malloc(sizeof(int) +
					(param_count + 1) * sizeof(param_t));
		token = strtok(param, ", ");
		if (param_count == 1) {
			parse_single_param(param, &((call->p)[0]));
			goto fin;
		}
		for (int i = 0; i < param_count - 1; i++) {
			parse_single_param(token, &((call->p)[i]));
			token = strtok(NULL, ", ");
		}
	} else {
		call = (ins_call *) malloc(sizeof(int));
	}
 fin:
	call->opcode = opcode;
	line->text = (char *)call;
}

void init_ecl()
{
	rank = RANK_LUNATIC;
	shot_type = curr_cfg->config_id;
	memset(&boss_data, 0, sizeof(boss_data));
	boss_data.sp = 0;
	boss_data.ip = 232;	// sub 15 line 326
	boss_data.fp = 15;
	boss_data.stack[0].return_address = -1;	// return and crash
}

void tick_ecl()
{
	if (boss_data.lock == 1) {
		return;
	}
	if (boss_data.curr_delay != 0) {
		boss_data.curr_delay--;
		return;
	}
	if (check_ip_onbound(&boss_data) == 1) {
		boss_data.lock = 1;
	}
	// exec code
	ecl_line *code = (ecl_line *) get_obj(line_array_list, boss_data.ip);
	switch (code->type) {
	case STAT_DEALY:{
			int d;
			sscanf(code->text, "+%d", &d);
			boss_data.curr_delay = d;
			// generate binary cache
			free(code->text);
			long l = (long)d;
			code->text = (char *)l;
			info("delay %d", d);
			code->type = BIN_DELAY;
			break;
		}
	case STAT_LABEL:{
			parse_label(code);
			break;
		}
	case STAT_INS:{
			parse_ins(code);
			exec_ins(code);
			break;
		}
	case BIN_LABEL:
		break;
	case BIN_DELAY:{
			long l = (long)(code->text);
			int d = (int)l;
			boss_data.curr_delay = d;
			info("delay %d", d);
			break;
		}
	case BIN_INS:{
			exec_ins(code);
			break;
		}
	default:{
			ABORT("illegal opcode");
		}
	}
	boss_data.ip++;
}

void et_on_fan_aim(int spr, int col, int way, int layer, double spd1,
		   double spd2, double r1, double r2, int flags)
{
	create_buman();
	bstyle(TRACE);
	bshape(col, spr);
	boffset(192, 96);	// TODO
	bamount(way, layer);
	bspeed(spd1, spd2);
	bangle(rad2ang(r1), rad2ang(r2));
	fire();
}

void et_on_fan(int spr, int col, int way, int layer, double spd1, double spd2,
	       double r1, double r2, int flags)
{
	create_buman();
	bstyle(DEFAULT);
	bshape(col, spr);
	boffset(192, 96);	// TODO
	bamount(way, layer);
	bspeed(spd1, spd2);
	bangle(rad2ang(r1), rad2ang(r2));
	fire();
}
