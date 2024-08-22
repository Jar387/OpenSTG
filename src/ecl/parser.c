#include <openstg.h>

int line_count = 0;
int sub_count = 0;
int script_entry = -1;

static void store_line(char *text, int type)
{
	char *comment_test = strchr(text, '/');
	if (comment_test != NULL) {
		if (comment_test[1] == '/') {
			*comment_test = '\0';
		}
	}
	char *cpy_buffer = (char *)malloc(strlen(text) + 1);
	strcpy(cpy_buffer, text);
	ecl_line line;
	line.text = cpy_buffer;
	line.type = type;
	put_obj(line_array_list, &line, line_count);
	line_count++;
}

static void store_hash(char *unhash, int type)
{
	unsigned char *hash = (unsigned char *)malloc(MD5_DIGEST_LENGTH);
	MD5((const unsigned char *)unhash, strlen(unhash), hash);
	ecl_line line;
	line.text = (char *)hash;
	line.type = type;
	put_obj(line_array_list, &line, line_count);
	line_count++;
}

static void store_sub(char *name)
{
	ecl_sub sub;
	MD5((const unsigned char *)name, strlen(name),
	    (unsigned char *)sub.hash);
	sub.store_line = line_count;
	put_obj(sub_array_list, &sub, sub_count);
	sub_count++;
}

static char *skip_trash(char *buf, int *len)
{
	if (*len == 0) {
		return NULL;
	}
	int i;
	for (i = 0; i < *len; i++) {
		if (buf[i] <= ' ' || buf[i] > '~') {
			// not printable char
			continue;
		}
		if (buf[i] == '/' && buf[i + 1] == '/') {
			return NULL;	// pure comment
		}
		if (buf[i] == '{' || buf[i] == '}') {
			return NULL;	// drop brackets
		}
		(*len) -= i;
		break;
	}
	return buf + i;
}

static void parse_line(char *buf, int len)
{
	buf = skip_trash(buf, &len);
	if (buf == NULL) {
		return;
	}
	if (buf[0] == '+') {
		// delay statement
		char *tok = strchr(buf, ':');
		*tok = '\0';
		store_line(buf, STAT_DEALY);
		return;
	}
	if (strncmp(buf, "sub ", 4) == 0) {
		// sub define
		buf += 4;
		*(strchr(buf, '(')) = '\0';
		store_sub(buf);
		return;
	}
	char *label = strchr(buf, ':');
	if (label != NULL) {
		*label = '\0';
		// use hash to speed up
		store_hash(buf, BIN_LABEL);
		return;
	}
	label = strchr(buf, '(');
	if (label != NULL) {
		// check difficulty
		if (buf[0] == '!') {
			*label = '\0';
			if (!(strchr(buf, 'E') && rank == RANK_EASY)) {
				if (!(strchr(buf, 'N') && rank == RANK_NORMAL)) {
					if (!(strchr(buf, 'H')
					      && rank == RANK_HARD)) {
						if (!(strchr(buf, 'L')
						      && rank == RANK_LUNATIC)) {
							if (!strchr(buf, '*')) {
								return;
							}
						}
					}
				}
			}
			*label = '(';
			buf += 2;
			while (buf[0] == 'E' || buf[0] == 'N' || buf[0] == 'H'
			       || buf[0] == 'L' || buf[0] == ' ') {
				buf++;
			}
		}
		label = strchr(buf, ';');
		if (label != NULL) {
			*label = '\0';
			store_line(buf, STAT_INS);
			return;
		}

	}
	if (strncmp(buf, "timeline ", 9) == 0) {
		// found program entry
		script_entry = line_count;
		info("found script entry in line %d(stripped)", script_entry);
		return;
	}
	warn("illegal statement %s", buf);
}

void load_script(char *path)
{
	FILE *fp = fopen(path, "r");
	if (fp == NULL) {
		IOERROR(path);
	}
	info("loading script %s", path);
	char buffer[256];
	line_array_list = create_array(-1, sizeof(ecl_line));
	sub_array_list = create_array(-1, sizeof(ecl_sub));
	while (read_line(fp, buffer, 256) != -1) {
		parse_line(buffer, strlen(buffer));
	}
	sub_count--;
	line_count--;
	if (script_entry == -1) {
		ABORT("cannot find entry in script");
	}
#ifdef DUMP_SCRIPT
#endif
	info("script %s loaded with %i sub(s) and %i legal statement(s)", path,
	     sub_count, line_count);
}

void unload_script()
{
	for (int i = 0; i < line_count; i++) {
		free(((ecl_line *) get_obj(line_array_list, i))->text);
	}
	destroy_array(line_array_list);
	destroy_array(sub_array_list);
	line_array_list = NULL;
	sub_array_list = NULL;
}
