#include <openstg.h>

#define STAT_DEALY 1
#define STAT_LABEL 2
#define STAT_INS 3

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

static void store_sub(char *name)
{
	ecl_sub sub;
	strncpy(sub.name, name, 16);
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
		int delay;
		sscanf(buf, "+%d", &delay);
		char ibuf[2 * sizeof(int)];
		int *iptr = (int *)ibuf;
		iptr[0] = delay;
		iptr[1] = 0;
		store_line(ibuf, STAT_DEALY);
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
		store_line(buf, STAT_LABEL);
		return;
	}
	label = strchr(buf, '(');
	if (label != NULL) {
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
	info("script %s loaded with %i sub(s) and %i legal statement(s)", path,
	     sub_count, line_count);
}
