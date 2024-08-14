#ifndef ITEM_H
#define ITEM_H

extern list_head *item_list;

enum ITEM_TYPE {
	POWER,
	POINT,
	BIG_P,
	BOMB,
	FULL,
	PLAYER,
	STAR
};

#define ITEM_DV 0.01		// (pixels/frame^2)
#define INITIAL_ITEM_V -1

typedef struct item_t {
	v2d pos;
	double speed;
	enum ITEM_TYPE type;
	v2i uv;
	v2i sign_uv;

	list_node node;
} item;

item *create_item(v2d pos, enum ITEM_TYPE type);
void delete_all_item();

void tick_items();

#endif
