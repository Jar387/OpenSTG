#include <openstg.h>

#define SC_SCOLL_SPEED 1

static void nsc_bg_1_callback()
{
	static float rotate = 0.0f;
	static float scale = 1.0f;
	static int symbol = 0;
	static int symbola = 0;
	static Uint8 a = 255;
	char alpha;
	SDL_GetTextureAlphaMod(texture_slot[BG_A_TEXTURE], &alpha);
	SDL_SetTextureAlphaMod(texture_slot[BG_A_TEXTURE], a);
	draw_texture_uv(BG_B_TEXTURE, (v2i) {
			OFFSET_X, OFFSET_Y}, (v2i) {
			0, 0}, (v2i) {
			LENGTH_X, LENGTH_Y});
	draw_game_object(BG_A_TEXTURE, (v2i) {
			 LENGTH_X / 2 - 128 * (scale - 1.0f),
			 180 - 128 * (scale - 1.0f)}, (v2i) {
			 256, 256}, (v2i) {
			 256, 256}, rotate, scale);
	rotate += 1.0f;
	if (symbol == 0) {
		scale += 0.005f;
	} else {
		scale -= 0.005f;
	}
	if (scale <= 1.0f) {
		symbol = 0;
	}
	if (scale >= 1.5f) {
		symbol = 1;
	}
	if (symbola == 0) {
		a -= 2;
	} else {
		a += 2;
	}
	if (a <= 2) {
		symbola = 1;
	}
	if (a >= 254) {
		symbola = 0;
	}
	SDL_SetTextureAlphaMod(texture_slot[BG_A_TEXTURE], alpha);
}

static void nsc_bg_2_callback()
{

}

static void sc_bg_callback()
{
	static int y_a = 0;
	static int y_b = LENGTH_Y;
	draw_texture_transform(BG_C_TEXTURE, (v2i) {
			       OFFSET_X, OFFSET_Y + y_a}, (v2i) {
			       0, 256}, (v2i) {
			       256, 256}, 0.0f, 1.75f);
	draw_texture_transform(BG_C_TEXTURE, (v2i) {
			       OFFSET_X, OFFSET_Y + y_b}, (v2i) {
			       0, 256}, (v2i) {
			       256, 256}, 0.0f, 1.75f);
	y_a -= SC_SCOLL_SPEED;
	y_b -= SC_SCOLL_SPEED;
	if (y_a <= -LENGTH_Y) {
		y_a = LENGTH_Y;
	}
	if (y_b <= -LENGTH_Y) {
		y_b = LENGTH_Y;
	}
	// front tree
	draw_texture_uv(BG_C_TEXTURE, (v2i) {
			OFFSET_X, OFFSET_Y}
			, (v2i) {
			256, 256}
			, (v2i) {
			LENGTH_X, LENGTH_Y}
	);
}

static void (*callback)() = &nsc_bg_1_callback;

void tick_background()
{
	callback();
}

void set_background_style(int style)
{
	switch (style) {
	case NSC_BACKGROUND_1:{
			callback = nsc_bg_1_callback;
			break;
		}
	case NSC_BACKGROUND_2:{
			callback = nsc_bg_2_callback;
			break;
		}
	case SC_BACKGROUND:{
			callback = sc_bg_callback;
			break;
		}
	default:{
			ILLEGALPARAM("background style");
		}
	}
}
