#include <openstg.h>

// global game data
int player_count;
int bomb_count;
int hiscore;
int score;
int power;
int graze;
int point;
int invulnerable_frame;

item *create_item(v2d pos, enum ITEM_TYPE type)
{
	item *itm = (item *) malloc(sizeof(*itm));
	itm->pos = pos;
	itm->type = type;
	itm->uv = (v2i) {
	type *16, 0};
	itm->sign_uv = (v2i) {
	type *16 + 128, 0};
	itm->node.data = itm;
	itm->speed = INITIAL_ITEM_V;
	insert_tail(item_list, &itm->node);
	return itm;
}

static void delete_callback(void *data, int id)
{
	delete_object(item_list, data);
}

static void tick_item(void *data, int id)
{
	item *itm = (item *) data;
	itm->pos.y += itm->speed;
	itm->speed += ITEM_DV;
	if (itm->pos.y < 0) {
		draw_game_object(ITEM_TEX, (v2i) {
				 itm->pos.x, 10}
				 , itm->sign_uv, ITEM_SZ, 0.0f, 1.0f);
		return;
	} else if (itm->pos.y > LENGTH_Y) {
		delete_object(item_list, &itm->node);
		return;
	} else {
		draw_game_object(ITEM_TEX, d2i(itm->pos), itm->uv, ITEM_SZ,
				 0.0f, 1.0f);
		if (check_collision(player_position, (v2d) {
				    curr_cfg->itembox, curr_cfg->itembox}
				    , itm->pos, i2d(ITEM_SZ))) {
			delete_object(item_list, &itm->node);
			switch (itm->type) {
			case POWER:{
					if (power < MAX_POWER) {
						power++;
					}
					break;
				}
			case POINT:{
					if (point < MAX_POINT) {
						point++;
					}
					break;
				}
			case BIG_P:{
					power += BIG_P_CONTAIN_POWER;
					if (power > MAX_POWER) {
						power = MAX_POWER;
					}
					break;
				}
			case BOMB:{
					if (bomb_count < MAX_BOMB) {
						bomb_count++;
					}
					break;
				}
			case FULL:{
					power = MAX_POWER;
					break;
				}
			case PLAYER:{
					if (player_count < MAX_PLAYER) {
						player_count++;
					}
					break;
				}
			case STAR:{
					// score aligo
					break;
				}
			default:{
					ILLEGALPARAM("item type");
					break;
				}
			}
		}
	}

}

void delete_all_item()
{
	list_foreach(item_list, &delete_all_item);
}

void tick_items()
{
	if (item_list->head == NULL) {
		return;
	}
	list_foreach(item_list, &tick_item);
}
