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
		ecl_line *line = (ecl_line *) (get_obj(line_array_list, i));
		if (line->type != BIN_LABEL) {
			continue;
		}
		unsigned char hash[MD5_DIGEST_LENGTH];
		MD5((const unsigned char *)symbol, strlen(symbol), hash);
		if (memcmp(hash, line->text, MD5_DIGEST_LENGTH) == 0) {
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

static void parse_single_param(char *text, param_t * target)
{
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
		memcpy(target->symbol_hash, text, 16);
		return;
	}
}

static void exec_ins(ecl_line * line, enemy_data * enm)
{
	ins_call *call = (ins_call *) (line->text);
	int param_count = ins_arg_count[call->opcode];
	void *prg = ins_prg[call->opcode];
	if (prg == NULL) {
		warn("ins %i not found", call->opcode);
		return;
	}
	switch (param_count) {
	case 0:{
			void (*p) (enemy_data *) = prg;
			p(enm);
			break;
		}
	case 1:{
			void (*p) (enemy_data *, param_t *) = prg;
			p(enm, &call->p[0]);
			break;
		}
	case 2:{
			void (*p) (enemy_data *, param_t *, param_t *) = prg;
			p(enm, &call->p[0], &call->p[1]);
			break;
		}
	case 3:{
			void (*p) (enemy_data *, param_t *, param_t *,
				   param_t *) = prg;
			p(enm, &call->p[0], &call->p[1], &call->p[2]);
			break;
		}
	case 4:{
			void (*p) (enemy_data *, param_t *, param_t *,
				   param_t *, param_t *) = prg;
			p(enm, &call->p[0], &call->p[1], &call->p[2],
			  &call->p[3]);
			break;
		}
	case 5:{
			void (*p) (enemy_data *, param_t *, param_t *,
				   param_t *, param_t *, param_t *) = prg;
			p(enm, &call->p[0], &call->p[1], &call->p[2],
			  &call->p[3], &call->p[4]);
			break;
		}
	case 6:{
			void (*p) (enemy_data *, param_t *, param_t *,
				   param_t *, param_t *, param_t *, param_t *) =
			    prg;
			p(enm, &call->p[0], &call->p[1], &call->p[2],
			  &call->p[3], &call->p[4], &call->p[5]);
			break;
		}
	case 7:{
			void (*p) (enemy_data *, param_t *, param_t *,
				   param_t *, param_t *, param_t *, param_t *,
				   param_t *) = prg;
			p(enm, &call->p[0], &call->p[1], &call->p[2],
			  &call->p[3], &call->p[4], &call->p[5], &call->p[6]);
			break;
		}
	case 8:{
			void (*p) (enemy_data *, param_t *, param_t *,
				   param_t *, param_t *, param_t *, param_t *,
				   param_t *, param_t *) = prg;
			p(enm, &call->p[0], &call->p[1], &call->p[2],
			  &call->p[3], &call->p[4], &call->p[5], &call->p[6],
			  &call->p[7]);
			break;
		}
	case 9:{
			void (*p) (enemy_data *, param_t *, param_t *,
				   param_t *, param_t *, param_t *, param_t *,
				   param_t *, param_t *, param_t *) = prg;
			p(enm, &call->p[0], &call->p[1], &call->p[2],
			  &call->p[3], &call->p[4], &call->p[5], &call->p[6],
			  &call->p[7], &call->p[8]);
			break;
		}
	case 14:{
			void (*p) (enemy_data *, param_t *, param_t *,
				   param_t *, param_t *, param_t *, param_t *,
				   param_t *, param_t *, param_t *, param_t *,
				   param_t *, param_t *, param_t *, param_t *) =
			    prg;
			p(enm, &call->p[0], &call->p[1], &call->p[2],
			  &call->p[3], &call->p[4], &call->p[5], &call->p[6],
			  &call->p[7], &call->p[8], &call->p[9], &call->p[10],
			  &call->p[11], &call->p[12], &call->p[13]);
			break;
		}
	default:{
			warn("unsupported param number: %d", param_count);
		}
	}
}

static void parse_ins(ecl_line * line)
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
	line->type = BIN_INS;
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
	if (boss_data.curr_delay != 0) {
		boss_data.curr_delay--;
		return;
	}
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
			code->type = BIN_DELAY;
			break;
		}
	case STAT_LABEL:{
			break;
		}
	case STAT_INS:{
			parse_ins(code);
			exec_ins(code, &boss_data);
			break;
		}
	case BIN_LABEL:
		break;
	case BIN_DELAY:{
			long l = (long)(code->text);
			int d = (int)l;
			boss_data.curr_delay = d;
			break;
		}
	case BIN_INS:{
			exec_ins(code, &boss_data);
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
