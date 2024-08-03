#include <openstg.h>

bullet_manager buman_list[MAX_BUMAN_INSTANCE];

void init_buman()
{
	memset(buman_list, 0, sizeof(buman_list));
}

static void style_default_task(int looptime, void *data)
{
	bullet_manager *buman = (bullet_manager *) data;

}
