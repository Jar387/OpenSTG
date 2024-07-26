#ifndef UI_H
#define UI_H

void tick_ui();

void draw_ascii(char c, char highlight, pos position);
void draw_string(pos position, unsigned char len, char* fmt, ...);

static inline void draw_game_object(int index, pos xy, pos uv, pos wh, float rotation, float scale){
    xy.x+=OFFSET_X;
    xy.y+=OFFSET_Y;
    draw_texture_transform(index, xy, uv, wh, rotation, scale);
}

#endif