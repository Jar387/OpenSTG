#ifndef UI_H
#define UI_H

#include <openstg.h>

void tick_ui();

void draw_ascii(char c, char highlight, v2i position);
void draw_string(v2i position, unsigned char len, char *fmt, ...);

static inline void draw_game_object(int index, v2i xy, v2i uv, v2i wh,
				    float rotation, float scale)
{
	xy.x += OFFSET_X;
	xy.y += OFFSET_Y;
	draw_texture_transform(index, xy, uv, wh, rotation, scale);
}

#endif
