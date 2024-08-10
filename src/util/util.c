#include <openstg.h>

SDL_Texture *texture_slot[MAX_SLOTS];
Mix_Music *bgm_slot[MAX_BGMS];

static char usage_bitmap[MAX_SLOTS] = { 0 };

static char texture_index = 0;

void load_basic_texture()
{
	load_texture(GENERIC_0, 1);
	load_texture(GENERIC_1, 1);
	load_texture(STG6_BOSS, 1);
}

void terminate_texture()
{
	for (int i = 0; i < MAX_SLOTS; i++) {
		if (usage_bitmap[i] != TEXTURE_UNUSED) {
			SDL_DestroyTexture(texture_slot[i]);
		}
	}
}

void load_texture(char *path, int solid)
{
	SDL_Texture *texture = IMG_LoadTexture(renderer, path);
	if (!texture) {
		IOERROR(path);
		return;
	}
	int free_idx = texture_index;
	texture_index++;
	if (texture_index >= MAX_SLOTS - 1) {
		texture_index = MAX_SLOTS + 1;
		// full
		for (int i = 0; i < MAX_SLOTS; i++) {
			if (usage_bitmap[i] == TEXTURE_USED) {
				free_idx = i;
				break;
			}
		}
		if (free_idx == -1) {
			ILLEGALSTATE("texture slot is full");
			return;
		}
	}
	if (solid == 0) {
		usage_bitmap[free_idx] = TEXTURE_USED;
	} else {
		usage_bitmap[free_idx] = TEXTURE_SOLID;
	}
	texture_slot[free_idx] = texture;
}

void unload_texture(char idx)
{
	if (idx < 0 || idx > 15) {
		ILLEGALPARAM("texture index");
		return;
	}
	SDL_DestroyTexture(texture_slot[(int)idx]);
	usage_bitmap[(int)idx] = TEXTURE_UNUSED;
}

int check_collision(v2d axy, v2d awh, v2d bxy, v2d bwh)
{
	if (axy.x < bxy.x + bwh.x &&
	    axy.x + awh.x > bxy.x &&
	    axy.y < bxy.y + bwh.y && axy.y + awh.y > bxy.y) {
		return 1;
	}
	return 0;
}

int check_out_of_screen(v2d p, v2i sz)
{
	if (p.x <= -sz.x / 2 || p.x >= LENGTH_X + sz.x / 2 || p.y <= -sz.y / 2
	    || p.y >= LENGTH_Y + sz.y / 2) {
		return 1;
	}
	return 0;
}

double player_angle(v2d src)
{
	v2d p = player_position;
	if ((p.x - src.x) >= 0) {
		if ((p.y - src.y) <= 0) {
			// alpha dim
			return vec2ang((v2d) {
				       p.x - src.x, p.y - src.y}
			);
		} else {
			// delta dim
			return vec2ang((v2d) {
				       p.x - src.x, p.y - src.y}
			) + 180.0f;
		}
	} else {
		if ((p.y - src.y) > 0) {
			// gamma dim
			return vec2ang((v2d) {
				       p.x - src.x, p.y - src.y}
			) + 180.0f;
		} else {
			// beta dim
			return vec2ang((v2d) {
				       p.x - src.x, p.y - src.y}
			) + 360.0f;
		}
	}
}

void load_music(char *path, int idx)
{
	Mix_Music *music = Mix_LoadMUS(path);
	if (!music) {
		IOERROR(path);
	}
	if (idx < 0 || idx > 2 || bgm_slot[idx] != NULL) {
		ILLEGALPARAM("music index");
	}
	bgm_slot[idx] = music;
}

void unload_music(int idx)
{
	Mix_Music *music = bgm_slot[idx];
	if (!music) {
		NULLOBJ("music");
	}
	Mix_FreeMusic(music);
	bgm_slot[idx] = NULL;
}

void load_basic_music()
{
	load_music(BGM0, 0);
}

void terminate_music()
{
	for (int i = 0; i < MAX_BGMS; i++) {
		if (bgm_slot[i] != NULL) {
			unload_music(i);
		}
	}
}

void play_music(int idx)
{
	Mix_Music *music = bgm_slot[idx];
	if (!music) {
		NULLOBJ("music");
	}
	Mix_PlayMusic(music, 1);
}

void stop_music()
{
	Mix_HaltMusic();
}

int read_line(FILE * fp, char *buffer, int size)
{
	int c;
	for (int i = 0; i < size; i++) {
		c = fgetc(fp);
		if (c == '\n') {
			buffer[i] = '\0';
			return i;
		}
		if (c == EOF) {
			buffer[i] = '\0';
			return -1;
		}
		buffer[i] = c;
	}
	return -2;
}
