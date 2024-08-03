#include <openstg.h>

SDL_Texture *texture_slot[MAX_SLOTS];

static char usage_bitmap[MAX_SLOTS] = { 0 };

static char texture_index = 0;

void load_basic_texture()
{
	load_texture(TEX0, 1);
	load_texture(TEX1, 1);
	load_texture(TEX2, 1);
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

char check_collision(v2d axy, v2i awh, v2d bxy, v2i bwh)
{
	if (axy.x <= bxy.x + bwh.x &&
	    axy.x + awh.x >= bxy.x &&
	    axy.y <= bxy.y + bwh.y && axy.y + awh.y >= bxy.y) {
		return 1;
	}
	return 0;
}

char check_out_of_screen(v2d p, v2i sz)
{
	if (p.x <= -sz.x || p.x >= LENGTH_X || p.y <= -sz.y || p.y >= LENGTH_Y) {
		return 1;
	}
	return 0;
}

double player_angle(v2d src)
{
	v2d p = player_hitbox();
	if ((p.x - src.x) >= 0) {
		if ((p.y - src.y) <= 0) {
			// alpha dim
			info("a");
			return vec2ang((v2d) {
				       p.x - src.x, p.y - src.y}
			);
		} else {
			// beta dim
			info("b");
			return vec2ang((v2d) {
				       p.x - src.x, p.y - src.y}
			) + 180.0f;
		}
	} else {
		if ((p.y - src.y) > 0) {
			// gamma dim
			info("c");
			return vec2ang((v2d) {
				       p.x - src.x, p.y - src.y}
			) + 180.0f;
		} else {
			// delta dim
			info("d");
			return vec2ang((v2d) {
				       p.x - src.x, p.y - src.y}
			) + 360.0f;
		}
	}
}
