#include <openstg.h>

// buffer for any purpose in this file
#define BUF_LEN 1024
static char buffer[BUF_LEN];

void draw_ascii(char c, char highlight, v2i position)
{
	char off = c - ' ';
	char row = off / 16;
	char column = off % 16;
	v2i uv = (v2i) { column * 16, 32 + row * 16 };
	v2i wh = (v2i) { 16, 16 };
	if (highlight == 1) {
		uv.x += 256;
	}
	draw_texture_uv(ASCII_TEX, position, uv, wh);
}

			  // restrict length to 255
void draw_string(v2i position, unsigned char len, char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	vsnprintf(buffer, 1024, fmt, args);
	if (strlen(buffer) < len) {
		len = strlen(buffer);
	}
	for (int i = 0; i < len; i++) {
		draw_ascii(buffer[i], 0, position);
		position.x += ASCII_SHRINK;
	}
}

static void draw_widget()
{
	draw_texture_uv(UI_TEX, HISCORE_POS, HISCORE_UV, HISCORE_SZ);
	draw_string(HISCORE_NUM_POS, 9, "%09d", hiscore % 1000000000);
	draw_texture_uv(UI_TEX, SCORE_POS, SCORE_UV, SCORE_SZ);
	draw_string(SCORE_NUM_POS, 9, "%09d", score % 1000000000);
	draw_texture_uv(UI_TEX, PLAYER_POS, PLAYER_UV, PLAYER_SZ);
	v2i tmp = PLAYER_NUM_POS;
	for (int i = 0; i < player_count; i++) {
		draw_texture_uv(UI_TEX, tmp, PLAYER_ICON_UV, ICON_SZ);
		tmp.x += ICON_SZ.x;
	}
	tmp = BOMB_NUM_POS;
	for (int i = 0; i < bomb_count; i++) {
		draw_texture_uv(UI_TEX, tmp, BOMB_ICON_UV, ICON_SZ);
		tmp.x += ICON_SZ.x;
	}
	if (power <= 9) {
		draw_string(POWER_NUM_POS, 1, "%i", power);
	} else if (power <= 99) {
		draw_string(POWER_NUM_POS, 2, "%i", power);
	} else if (power < 128) {
		draw_string(POWER_NUM_POS, 3, "%i", power);
	} else {
		draw_string(POWER_NUM_POS, 3, "MAX", power);
	}

	if (graze <= 9) {
		draw_string(GRAZE_NUM_POS, 1, "%i", graze);
	} else if (graze <= 99) {
		draw_string(GRAZE_NUM_POS, 2, "%i", graze);
	} else if (graze <= 999) {
		draw_string(GRAZE_NUM_POS, 3, "%i", graze);
	} else if (graze <= 9999) {
		draw_string(GRAZE_NUM_POS, 4, "%i", graze);
	}

	if (graze <= 9) {
		draw_string(POINT_NUM_POS, 1, "%i", point);
	} else if (graze <= 99) {
		draw_string(POINT_NUM_POS, 2, "%i", point);
	} else if (graze <= 999) {
		draw_string(POINT_NUM_POS, 3, "%i", point);
	} else if (graze <= 9999) {
		draw_string(POINT_NUM_POS, 4, "%i", point);
	}

	draw_texture_uv(UI_TEX, BOMB_POS, BOMB_UV, BOMB_SZ);
	draw_texture_uv(UI_TEX, POWER_POS, POWER_UV, POWER_SZ);
	draw_texture_uv(UI_TEX, GRAZE_POS, GRAZE_UV, GRAZE_SZ);
	draw_texture_uv(UI_TEX, POINT_POS, POINT_UV, POINT_SZ);
	draw_texture_uv(UI_TEX, ENGLISH_TITLE_POS, ENGLISH_TITLE_UV,
			ENGLISH_TITLE_SZ);
	draw_texture_uv(UI_TEX, JAPANESE_TITLE_PART_1_POS,
			JAPANESE_TITLE_PART_1_UV, JAPANESE_TITLE_SZ);
	draw_texture_uv(UI_TEX, JAPANESE_TITLE_PART_2_POS,
			JAPANESE_TITLE_PART_2_UV, JAPANESE_TITLE_SZ);
	draw_texture_uv(UI_TEX, JAPANESE_TITLE_PART_3_POS,
			JAPANESE_TITLE_PART_3_UV, JAPANESE_TITLE_SZ);
	draw_texture_uv(UI_TEX, JAPANESE_TITLE_PART_4_POS,
			JAPANESE_TITLE_PART_4_UV, JAPANESE_TITLE_SZ);
	draw_texture_uv(UI_TEX, JAPANESE_TITLE_PART_5_POS,
			JAPANESE_TITLE_PART_5_UV, JAPANESE_TITLE_SZ);
	draw_string(FPS_POS, 8, "%.2ffps", get_fps());
}

static void draw_background()
{
	for (int i = 0; i < WIDTH; i += BACKGROUND_NARROW_SZ.x) {
		draw_texture_uv(UI_TEX, (v2i) {
				i, 0}, BACKGROUND_UV, BACKGROUND_NARROW_SZ);
		draw_texture_uv(UI_TEX, (v2i) {
				i, OFFSET_Y + LENGTH_Y}, BACKGROUND_UV,
				BACKGROUND_NARROW_SZ);
	}
	for (int i = 0; i < HEIGHT; i += BACKGROUND_SZ.y) {
		draw_texture_uv(UI_TEX, (v2i) {
				0, i}, BACKGROUND_UV, BACKGROUND_SZ);
		for (int j = OFFSET_X + LENGTH_X; j < WIDTH;
		     j += BACKGROUND_SZ.x) {
			draw_texture_uv(UI_TEX, (v2i) {
					j, i}, BACKGROUND_UV, BACKGROUND_SZ);
		}
	}
}

void tick_ui()
{
	draw_background();
	draw_widget();
}
