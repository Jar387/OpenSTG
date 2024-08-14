#ifndef UI_H
#define UI_H

void tick_ui();

void draw_ascii(char c, char highlight, v2i position);
void draw_string(v2i position, unsigned char len, char *fmt, ...);

#endif
