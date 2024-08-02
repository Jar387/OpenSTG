#include <openstg.h>

bullet_manager buman_list[MAX_BUMAN_INSTANCE];

void init_buman()
{
	memset(buman_list, 0, sizeof(buman_list));
	for (int i = 0; i < MAX_BUMAN_INSTANCE; i++) {
		buman_list[i].id = i;
	}
}

static void style_default_task(int looptime, void *data)
{
	int buman_id = *(int *)data;
	bullet_manager *buman = buman_list + buman_id;
	if (buman->style != DEFAULT) {

	}

}
