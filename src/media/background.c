#include <openstg.h>

static void nsc_bg_callback()
{
}

static void sc_bg_callback()
{
}

static void (*callback) () = &nsc_bg_callback;

void tick_background()
{
	callback();
}

void set_background_style(int style)
{
	switch (style) {
	case NSC_BACKGROUND:{
			callback = nsc_bg_callback;
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
