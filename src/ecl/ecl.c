#include <openstg.h>

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

int check_ip_onbound(enemy_data* data){
	ecl_sub* sub = (ecl_sub*)get_obj(sub_array_list, data->fp+1);
	if(data->ip+1==sub->store_line){
		return 1;
	}
	return 0;
}

int search_symbol(enemy_data* data, char* symbol){
	ecl_sub* curr_sub = (ecl_sub*)get_obj(sub_array_list, data->fp);
	ecl_sub* next_sub = (ecl_sub*)get_obj(sub_array_list, data->fp+1);
	for(int i=curr_sub->store_line; i<next_sub->store_line;i++){
		if(strcmp(((ecl_line*)get_obj(line_array_list, i))->text, symbol)==0){
			// TODO: replace this with hash
			return i+1;
		}
	}
	return -1;
}

void parse_label(ecl_line* line){
	unsigned char* md5buf = (unsigned char*)malloc(MD5_DIGEST_LENGTH);
	const unsigned char *t = (const unsigned char *)(line->text);
	MD5(t, strlen(line->text), md5buf);
	free(line->text);
	line->text = (char*)md5buf;
	line->type = BIN_LABEL;
}

void exec_ins(char* ins){
	info("exec %s", ins);
	char* param = strchr(ins, '(');
	char* fin = strchr(ins, ')');
	*fin = '\0';
}

void init_ecl()
{
	rank = RANK_LUNATIC;
	shot_type = curr_cfg->config_id;
	memset(&boss_data, 0, sizeof(boss_data));
	boss_data.sp = 0;
	boss_data.ip = 232; // sub 15 line 326
	boss_data.fp = 15;
	boss_data.stack[0].return_address = -1; // return and crash
}

void tick_ecl()
{
	if(boss_data.lock==1){
		return;
	}
	if(boss_data.curr_delay!=0){
		boss_data.curr_delay--;
		return;
	}
	if(check_ip_onbound(&boss_data)==1){
		boss_data.lock = 1;
	}
	// exec code
	ecl_line* code = (ecl_line*)get_obj(line_array_list, boss_data.ip);
	switch(code->type){
		case STAT_DEALY: {
			int d;
			sscanf(code->text, "+%d", &d);
			boss_data.curr_delay = d;
			// generate binary cache
			free(code->text);
			long l = (long)d;
			code->text = (char*)l;
			info("delay %d", d);
			code->type = BIN_DELAY;
			break;
		}
		case STAT_LABEL: {
			parse_label(code);
			break;
		}
		case STAT_INS: {
			exec_ins(code->text);
			break;
		}
		case BIN_LABEL: break;
		case BIN_DELAY: {
			long l = (long)(code->text);
			int d = (int)l;
			boss_data.curr_delay = d;
			info("delay %d", d);
			break;
		}
		case BIN_INS: {
			break;
		}
		default: {
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
