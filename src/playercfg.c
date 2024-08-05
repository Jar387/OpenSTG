#include <openstg.h>

void create_player_config()
{				// manual configurator
	FILE *fp = fopen("../data/pl00.dat", "wb");
	player_cfg_data *data =
	    (player_cfg_data *) malloc(sizeof(player_cfg_data));
	memset(data, 0, sizeof(*data));
	data->sig = 0x4754534f;
	data->bomb_per_life = 3;
	data->deathbomb_frame = 15;
	data->hitbox = HITBOX;
	data->grazebox = GRAZEBOX;
	data->itembox = 20;
	data->speed = SPEED;
	data->padding = 0xeeeeeeee;

	data->shooters[0][0].fire_rate = 5;
	data->shooters[0][0].position = (v2c) {
	0, 0};
	data->shooters[0][0].start_dalay = 0;
	data->shooters[0][0].dmg = 48;
	data->shooters[0][0].hitbox = (v2c) {
	12, 12};
	data->shooters[0][0].speed = 12;
	data->shooters[0][0].flags = 0;
	data->shooters[0][0].padding1 = -1;

	data->shooters[0][1].fire_rate = 30;
	data->shooters[0][1].position = (v2c) {
	0, 0};
	data->shooters[0][1].start_dalay = 0;
	data->shooters[0][1].dmg = 14;
	data->shooters[0][1].hitbox = (v2c) {
	12, 12};
	data->shooters[0][1].speed = 10;
	data->shooters[0][1].flags = 1;
	data->shooters[0][1].padding1 = -1;

	data->shooters[0][2].fire_rate = 30;
	data->shooters[0][2].position = (v2c) {
	0, 0};
	data->shooters[0][2].start_dalay = 0;
	data->shooters[0][2].dmg = 14;
	data->shooters[0][2].hitbox = (v2c) {
	12, 12};
	data->shooters[0][2].speed = 10;
	data->shooters[0][2].flags = 1;
	data->shooters[0][2].padding1 = -1;

	data->shooters[1][0].fire_rate = 5;
	data->shooters[1][0].position = (v2c) {
	-4, 0};
	data->shooters[1][0].start_dalay = 0;
	data->shooters[1][0].dmg = 30;
	data->shooters[1][0].hitbox = (v2c) {
	12, 12};
	data->shooters[1][0].speed = 12;
	data->shooters[1][0].flags = 0;
	data->shooters[1][0].padding1 = -1;

	data->shooters[1][1].fire_rate = 5;
	data->shooters[1][1].position = (v2c) {
	4, 0};
	data->shooters[1][1].start_dalay = 0;
	data->shooters[1][1].dmg = 30;
	data->shooters[1][1].hitbox = (v2c) {
	12, 12};
	data->shooters[1][1].speed = 12;
	data->shooters[1][1].flags = 0;
	data->shooters[1][1].padding1 = -1;

	data->shooters[1][2].fire_rate = 30;
	data->shooters[1][2].position = (v2c) {
	0, 0};
	data->shooters[1][2].start_dalay = 0;
	data->shooters[1][2].dmg = 14;
	data->shooters[1][2].hitbox = (v2c) {
	12, 12};
	data->shooters[1][2].speed = 10;
	data->shooters[1][2].flags = 1;
	data->shooters[1][2].padding1 = -1;

	data->shooters[1][3].fire_rate = 30;
	data->shooters[1][3].position = (v2c) {
	0, 0};
	data->shooters[1][3].start_dalay = 0;
	data->shooters[1][3].dmg = 14;
	data->shooters[1][3].hitbox = (v2c) {
	12, 12};
	data->shooters[1][3].speed = 10;
	data->shooters[1][3].flags = 1;
	data->shooters[1][3].padding1 = -1;

	data->shooters[2][0].fire_rate = 5;
	data->shooters[2][0].position = (v2c) {
	-4, 0};
	data->shooters[2][0].start_dalay = 0;
	data->shooters[2][0].dmg = 30;
	data->shooters[2][0].hitbox = (v2c) {
	12, 12};
	data->shooters[2][0].speed = 12;
	data->shooters[2][0].flags = 0;
	data->shooters[2][0].padding1 = -1;

	data->shooters[2][1].fire_rate = 5;
	data->shooters[2][1].position = (v2c) {
	4, 0};
	data->shooters[2][1].start_dalay = 0;
	data->shooters[2][1].dmg = 30;
	data->shooters[2][1].hitbox = (v2c) {
	12, 12};
	data->shooters[2][1].speed = 12;
	data->shooters[2][1].flags = 0;
	data->shooters[2][1].padding1 = -1;

	data->shooters[2][2].fire_rate = 15;
	data->shooters[2][2].position = (v2c) {
	0, 0};
	data->shooters[2][2].start_dalay = 0;
	data->shooters[2][2].dmg = 14;
	data->shooters[2][2].hitbox = (v2c) {
	12, 12};
	data->shooters[2][2].speed = 10;
	data->shooters[2][2].flags = 1;
	data->shooters[2][2].padding1 = -1;

	data->shooters[2][3].fire_rate = 15;
	data->shooters[2][3].position = (v2c) {
	0, 0};
	data->shooters[2][3].start_dalay = 0;
	data->shooters[2][3].dmg = 14;
	data->shooters[2][3].hitbox = (v2c) {
	12, 12};
	data->shooters[2][3].speed = 10;
	data->shooters[2][3].flags = 1;
	data->shooters[2][3].padding1 = -1;

	data->shooters[3][0].fire_rate = 5;
	data->shooters[3][0].position = (v2c) {
	0, 0};
	data->shooters[3][0].start_dalay = 0;
	data->shooters[3][0].dmg = 28;
	data->shooters[3][0].hitbox = (v2c) {
	12, 12};
	data->shooters[3][0].speed = 12;
	data->shooters[3][0].flags = 0;
	data->shooters[3][0].padding1 = -1;

	data->shooters[3][1].fire_rate = 5;
	data->shooters[3][1].position = (v2c) {
	0, 0};
	data->shooters[3][1].start_dalay = 0;
	data->shooters[3][1].dmg = 30;
	data->shooters[3][1].hitbox = (v2c) {
	12, 12};
	data->shooters[3][1].speed = 12;
	data->shooters[3][1].flags = 0;
	data->shooters[3][1].padding1 = -1;

	data->shooters[3][2].fire_rate = 5;
	data->shooters[3][2].position = (v2c) {
	0, 0};
	data->shooters[3][2].start_dalay = 0;
	data->shooters[3][2].dmg = 28;
	data->shooters[3][2].hitbox = (v2c) {
	12, 12};
	data->shooters[3][2].speed = 12;
	data->shooters[3][2].flags = 0;
	data->shooters[3][2].padding1 = -1;

	data->shooters[3][3].fire_rate = 15;
	data->shooters[3][3].position = (v2c) {
	0, 0};
	data->shooters[3][3].start_dalay = 0;
	data->shooters[3][3].dmg = 14;
	data->shooters[3][3].hitbox = (v2c) {
	12, 12};
	data->shooters[3][3].speed = 10;
	data->shooters[3][3].flags = 1;
	data->shooters[3][3].padding1 = -1;

	data->shooters[3][4].fire_rate = 15;
	data->shooters[3][4].position = (v2c) {
	0, 0};
	data->shooters[3][4].start_dalay = 0;
	data->shooters[3][4].dmg = 14;
	data->shooters[3][4].hitbox = (v2c) {
	12, 12};
	data->shooters[3][4].speed = 10;
	data->shooters[3][4].flags = 1;
	data->shooters[3][4].padding1 = -1;

	data->shooters[4][0].fire_rate = 5;
	data->shooters[4][0].position = (v2c) {
	0, 0};
	data->shooters[4][0].start_dalay = 0;
	data->shooters[4][0].dmg = 28;
	data->shooters[4][0].hitbox = (v2c) {
	12, 12};
	data->shooters[4][0].speed = 12;
	data->shooters[4][0].flags = 0;
	data->shooters[4][0].padding1 = -1;

	data->shooters[4][1].fire_rate = 5;
	data->shooters[4][1].position = (v2c) {
	0, 0};
	data->shooters[4][1].start_dalay = 0;
	data->shooters[4][1].dmg = 30;
	data->shooters[4][1].hitbox = (v2c) {
	12, 12};
	data->shooters[4][1].speed = 12;
	data->shooters[4][1].flags = 0;
	data->shooters[4][1].padding1 = -1;

	data->shooters[4][2].fire_rate = 5;
	data->shooters[4][2].position = (v2c) {
	0, 0};
	data->shooters[4][2].start_dalay = 0;
	data->shooters[4][2].dmg = 28;
	data->shooters[4][2].hitbox = (v2c) {
	12, 12};
	data->shooters[4][2].speed = 12;
	data->shooters[4][2].flags = 0;
	data->shooters[4][2].padding1 = -1;

	data->shooters[4][3].fire_rate = 15;
	data->shooters[4][3].position = (v2c) {
	0, 0};
	data->shooters[4][3].start_dalay = 0;
	data->shooters[4][3].dmg = 7;
	data->shooters[4][3].hitbox = (v2c) {
	12, 12};
	data->shooters[4][3].speed = 10;
	data->shooters[4][3].flags = 1;
	data->shooters[4][3].padding1 = -1;

	data->shooters[4][4].fire_rate = 15;
	data->shooters[4][4].position = (v2c) {
	0, 0};
	data->shooters[4][4].start_dalay = 0;
	data->shooters[4][4].dmg = 7;
	data->shooters[4][4].hitbox = (v2c) {
	12, 12};
	data->shooters[4][4].speed = 10;
	data->shooters[4][4].flags = 1;
	data->shooters[4][4].padding1 = -1;

	data->shooters[4][5].fire_rate = 30;
	data->shooters[4][5].position = (v2c) {
	0, 0};
	data->shooters[4][5].start_dalay = 0;
	data->shooters[4][5].dmg = 9;
	data->shooters[4][5].hitbox = (v2c) {
	12, 12};
	data->shooters[4][5].speed = 10;
	data->shooters[4][5].flags = 1;
	data->shooters[4][5].padding1 = -1;

	data->shooters[4][6].fire_rate = 30;
	data->shooters[4][6].position = (v2c) {
	0, 0};
	data->shooters[4][6].start_dalay = 0;
	data->shooters[4][6].dmg = 9;
	data->shooters[4][6].hitbox = (v2c) {
	12, 12};
	data->shooters[4][6].speed = 10;
	data->shooters[4][6].flags = 1;
	data->shooters[4][6].padding1 = -1;

	data->shooters[5][0].fire_rate = 5;
	data->shooters[5][0].position = (v2c) {
	0, 0};
	data->shooters[5][0].start_dalay = 0;
	data->shooters[5][0].dmg = 28;
	data->shooters[5][0].hitbox = (v2c) {
	12, 12};
	data->shooters[5][0].speed = 12;
	data->shooters[5][0].flags = 0;
	data->shooters[5][0].padding1 = -1;

	data->shooters[5][1].fire_rate = 5;
	data->shooters[5][1].position = (v2c) {
	0, 0};
	data->shooters[5][1].start_dalay = 0;
	data->shooters[5][1].dmg = 29;
	data->shooters[5][1].hitbox = (v2c) {
	12, 12};
	data->shooters[5][1].speed = 12;
	data->shooters[5][1].flags = 0;
	data->shooters[5][1].padding1 = -1;

	data->shooters[5][2].fire_rate = 5;
	data->shooters[5][2].position = (v2c) {
	0, 0};
	data->shooters[5][2].start_dalay = 0;
	data->shooters[5][2].dmg = 28;
	data->shooters[5][2].hitbox = (v2c) {
	12, 12};
	data->shooters[5][2].speed = 12;
	data->shooters[5][2].flags = 0;
	data->shooters[5][2].padding1 = -1;

	data->shooters[5][3].fire_rate = 15;
	data->shooters[5][3].position = (v2c) {
	0, 0};
	data->shooters[5][3].start_dalay = 0;
	data->shooters[5][3].dmg = 7;
	data->shooters[5][3].hitbox = (v2c) {
	12, 12};
	data->shooters[5][3].speed = 10;
	data->shooters[5][3].flags = 1;
	data->shooters[5][3].padding1 = -1;

	data->shooters[5][4].fire_rate = 15;
	data->shooters[5][4].position = (v2c) {
	0, 0};
	data->shooters[5][4].start_dalay = 0;
	data->shooters[5][4].dmg = 7;
	data->shooters[5][4].hitbox = (v2c) {
	12, 12};
	data->shooters[5][4].speed = 10;
	data->shooters[5][4].flags = 1;
	data->shooters[5][4].padding1 = -1;

	data->shooters[5][5].fire_rate = 15;
	data->shooters[5][5].position = (v2c) {
	0, 0};
	data->shooters[5][5].start_dalay = 0;
	data->shooters[5][5].dmg = 8;
	data->shooters[5][5].hitbox = (v2c) {
	12, 12};
	data->shooters[5][5].speed = 10;
	data->shooters[5][5].flags = 1;
	data->shooters[5][5].padding1 = -1;

	data->shooters[5][6].fire_rate = 15;
	data->shooters[5][6].position = (v2c) {
	0, 0};
	data->shooters[5][6].start_dalay = 0;
	data->shooters[5][6].dmg = 8;
	data->shooters[5][6].hitbox = (v2c) {
	12, 12};
	data->shooters[5][6].speed = 10;
	data->shooters[5][6].flags = 1;
	data->shooters[5][6].padding1 = -1;

	data->shooters[6][0].fire_rate = 5;
	data->shooters[6][0].position = (v2c) {
	0, 0};
	data->shooters[6][0].start_dalay = 0;
	data->shooters[6][0].dmg = 28;
	data->shooters[6][0].hitbox = (v2c) {
	12, 12};
	data->shooters[6][0].speed = 12;
	data->shooters[6][0].flags = 0;
	data->shooters[6][0].padding1 = -1;

	data->shooters[6][1].fire_rate = 5;
	data->shooters[6][1].position = (v2c) {
	0, 0};
	data->shooters[6][1].start_dalay = 0;
	data->shooters[6][1].dmg = 30;
	data->shooters[6][1].hitbox = (v2c) {
	12, 12};
	data->shooters[6][1].speed = 12;
	data->shooters[6][1].flags = 0;
	data->shooters[6][1].padding1 = -1;

	data->shooters[6][2].fire_rate = 5;
	data->shooters[6][2].position = (v2c) {
	0, 0};
	data->shooters[6][2].start_dalay = 0;
	data->shooters[6][2].dmg = 28;
	data->shooters[6][2].hitbox = (v2c) {
	12, 12};
	data->shooters[6][2].speed = 12;
	data->shooters[6][2].flags = 0;
	data->shooters[6][2].padding1 = -1;

	data->shooters[6][3].fire_rate = 15;
	data->shooters[6][3].position = (v2c) {
	0, 0};
	data->shooters[6][3].start_dalay = 0;
	data->shooters[6][3].dmg = 7;
	data->shooters[6][3].hitbox = (v2c) {
	12, 12};
	data->shooters[6][3].speed = 10;
	data->shooters[6][3].flags = 1;
	data->shooters[6][3].padding1 = -1;

	data->shooters[6][4].fire_rate = 15;
	data->shooters[6][4].position = (v2c) {
	0, 0};
	data->shooters[6][4].start_dalay = 0;
	data->shooters[6][4].dmg = 7;
	data->shooters[6][4].hitbox = (v2c) {
	12, 12};
	data->shooters[6][4].speed = 10;
	data->shooters[6][4].flags = 1;
	data->shooters[6][4].padding1 = -1;

	data->shooters[6][5].fire_rate = 15;
	data->shooters[6][5].position = (v2c) {
	0, 0};
	data->shooters[6][5].start_dalay = 10;
	data->shooters[6][5].dmg = 8;
	data->shooters[6][5].hitbox = (v2c) {
	12, 12};
	data->shooters[6][5].speed = 10;
	data->shooters[6][5].flags = 1;
	data->shooters[6][5].padding1 = -1;

	data->shooters[6][6].fire_rate = 15;
	data->shooters[6][6].position = (v2c) {
	0, 0};
	data->shooters[6][6].start_dalay = 10;
	data->shooters[6][6].dmg = 8;
	data->shooters[6][6].hitbox = (v2c) {
	12, 12};
	data->shooters[6][6].speed = 10;
	data->shooters[6][6].flags = 1;
	data->shooters[6][6].padding1 = -1;

	data->shooters[6][7].fire_rate = 30;
	data->shooters[6][7].position = (v2c) {
	0, 0};
	data->shooters[6][7].start_dalay = 20;
	data->shooters[6][7].dmg = 7;
	data->shooters[6][7].hitbox = (v2c) {
	12, 12};
	data->shooters[6][7].speed = 10;
	data->shooters[6][7].flags = 1;
	data->shooters[6][7].padding1 = -1;

	data->shooters[6][8].fire_rate = 30;
	data->shooters[6][8].position = (v2c) {
	0, 0};
	data->shooters[6][8].start_dalay = 20;
	data->shooters[6][8].dmg = 7;
	data->shooters[6][8].hitbox = (v2c) {
	12, 12};
	data->shooters[6][8].speed = 10;
	data->shooters[6][8].flags = 1;
	data->shooters[6][8].padding1 = -1;

	data->shooters[7][0].fire_rate = 5;
	data->shooters[7][0].position = (v2c) {
	0, 0};
	data->shooters[7][0].start_dalay = 0;
	data->shooters[7][0].dmg = 28;
	data->shooters[7][0].hitbox = (v2c) {
	12, 12};
	data->shooters[7][0].speed = 12;
	data->shooters[7][0].flags = 0;
	data->shooters[7][0].padding1 = -1;

	data->shooters[7][1].fire_rate = 5;
	data->shooters[7][1].position = (v2c) {
	0, 0};
	data->shooters[7][1].start_dalay = 0;
	data->shooters[7][1].dmg = 30;
	data->shooters[7][1].hitbox = (v2c) {
	12, 12};
	data->shooters[7][1].speed = 12;
	data->shooters[7][1].flags = 0;
	data->shooters[7][1].padding1 = -1;

	data->shooters[7][2].fire_rate = 5;
	data->shooters[7][2].position = (v2c) {
	0, 0};
	data->shooters[7][2].start_dalay = 0;
	data->shooters[7][2].dmg = 28;
	data->shooters[7][2].hitbox = (v2c) {
	12, 12};
	data->shooters[7][2].speed = 12;
	data->shooters[7][2].flags = 0;
	data->shooters[7][2].padding1 = -1;

	data->shooters[7][3].fire_rate = 15;
	data->shooters[7][3].position = (v2c) {
	0, 0};
	data->shooters[7][3].start_dalay = 0;
	data->shooters[7][3].dmg = 6;
	data->shooters[7][3].hitbox = (v2c) {
	12, 12};
	data->shooters[7][3].speed = 10;
	data->shooters[7][3].flags = 1;
	data->shooters[7][3].padding1 = -1;

	data->shooters[7][4].fire_rate = 15;
	data->shooters[7][4].position = (v2c) {
	0, 0};
	data->shooters[7][4].start_dalay = 0;
	data->shooters[7][4].dmg = 6;
	data->shooters[7][4].hitbox = (v2c) {
	12, 12};
	data->shooters[7][4].speed = 10;
	data->shooters[7][4].flags = 1;
	data->shooters[7][4].padding1 = -1;

	data->shooters[7][5].fire_rate = 15;
	data->shooters[7][5].position = (v2c) {
	0, 0};
	data->shooters[7][5].start_dalay = 5;
	data->shooters[7][5].dmg = 5;
	data->shooters[7][5].hitbox = (v2c) {
	12, 12};
	data->shooters[7][5].speed = 10;
	data->shooters[7][5].flags = 1;
	data->shooters[7][5].padding1 = -1;

	data->shooters[7][6].fire_rate = 15;
	data->shooters[7][6].position = (v2c) {
	0, 0};
	data->shooters[7][6].start_dalay = 5;
	data->shooters[7][6].dmg = 5;
	data->shooters[7][6].hitbox = (v2c) {
	12, 12};
	data->shooters[7][6].speed = 10;
	data->shooters[7][6].flags = 1;
	data->shooters[7][6].padding1 = -1;

	data->shooters[7][7].fire_rate = 15;
	data->shooters[7][7].position = (v2c) {
	0, 0};
	data->shooters[7][7].start_dalay = 10;
	data->shooters[7][7].dmg = 6;
	data->shooters[7][7].hitbox = (v2c) {
	12, 12};
	data->shooters[7][7].speed = 10;
	data->shooters[7][7].flags = 1;
	data->shooters[7][7].padding1 = -1;

	data->shooters[7][8].fire_rate = 15;
	data->shooters[7][8].position = (v2c) {
	0, 0};
	data->shooters[7][8].start_dalay = 10;
	data->shooters[7][8].dmg = 6;
	data->shooters[7][8].hitbox = (v2c) {
	12, 12};
	data->shooters[7][8].speed = 10;
	data->shooters[7][8].flags = 1;
	data->shooters[7][8].padding1 = -1;

	data->shooters[8][0].fire_rate = 5;
	data->shooters[8][0].position = (v2c) {
	-8, 0};
	data->shooters[8][0].start_dalay = 0;
	data->shooters[8][0].dmg = 28;
	data->shooters[8][0].hitbox = (v2c) {
	12, 12};
	data->shooters[8][0].speed = 12;
	data->shooters[8][0].flags = 0;
	data->shooters[8][0].padding1 = -1;

	data->shooters[8][1].fire_rate = 5;
	data->shooters[8][1].position = (v2c) {
	-8, 0};
	data->shooters[8][1].start_dalay = 0;
	data->shooters[8][1].dmg = 30;
	data->shooters[8][1].hitbox = (v2c) {
	12, 12};
	data->shooters[8][1].speed = 12;
	data->shooters[8][1].flags = 0;
	data->shooters[8][1].padding1 = -1;

	data->shooters[8][2].fire_rate = 5;
	data->shooters[8][2].position = (v2c) {
	8, 0};
	data->shooters[8][2].start_dalay = 0;
	data->shooters[8][2].dmg = 30;
	data->shooters[8][2].hitbox = (v2c) {
	12, 12};
	data->shooters[8][2].speed = 12;
	data->shooters[8][2].flags = 0;
	data->shooters[8][2].padding1 = -1;

	data->shooters[8][3].fire_rate = 5;
	data->shooters[8][3].position = (v2c) {
	8, 0};
	data->shooters[8][3].start_dalay = 0;
	data->shooters[8][3].dmg = 28;
	data->shooters[8][3].hitbox = (v2c) {
	12, 12};
	data->shooters[8][3].speed = 12;
	data->shooters[8][3].flags = 0;
	data->shooters[8][3].padding1 = -1;

	data->shooters[8][4].fire_rate = 15;
	data->shooters[8][4].position = (v2c) {
	0, 0};
	data->shooters[8][4].start_dalay = 0;
	data->shooters[8][4].dmg = 5;
	data->shooters[8][4].hitbox = (v2c) {
	12, 12};
	data->shooters[8][4].speed = 10;
	data->shooters[8][4].flags = 1;
	data->shooters[8][4].padding1 = -1;

	data->shooters[8][5].fire_rate = 15;
	data->shooters[8][5].position = (v2c) {
	0, 0};
	data->shooters[8][5].start_dalay = 5;
	data->shooters[8][5].dmg = 5;
	data->shooters[8][5].hitbox = (v2c) {
	12, 12};
	data->shooters[8][5].speed = 10;
	data->shooters[8][5].flags = 1;
	data->shooters[8][5].padding1 = -1;

	data->shooters[8][6].fire_rate = 15;
	data->shooters[8][6].position = (v2c) {
	0, 0};
	data->shooters[8][6].start_dalay = 4;
	data->shooters[8][6].dmg = 5;
	data->shooters[8][6].hitbox = (v2c) {
	12, 12};
	data->shooters[8][6].speed = 10;
	data->shooters[8][6].flags = 1;
	data->shooters[8][6].padding1 = -1;

	data->shooters[8][7].fire_rate = 15;
	data->shooters[8][7].position = (v2c) {
	0, 0};
	data->shooters[8][7].start_dalay = 4;
	data->shooters[8][7].dmg = 5;
	data->shooters[8][7].hitbox = (v2c) {
	12, 12};
	data->shooters[8][7].speed = 10;
	data->shooters[8][7].flags = 1;
	data->shooters[8][7].padding1 = -1;

	data->shooters[8][8].fire_rate = 15;
	data->shooters[8][8].position = (v2c) {
	0, 0};
	data->shooters[8][8].start_dalay = 8;
	data->shooters[8][8].dmg = 5;
	data->shooters[8][8].hitbox = (v2c) {
	12, 12};
	data->shooters[8][8].speed = 10;
	data->shooters[8][8].flags = 1;
	data->shooters[8][8].padding1 = -1;

	data->shooters[8][9].fire_rate = 15;
	data->shooters[8][9].position = (v2c) {
	0, 0};
	data->shooters[8][9].start_dalay = 8;
	data->shooters[8][9].dmg = 5;
	data->shooters[8][9].hitbox = (v2c) {
	12, 12};
	data->shooters[8][9].speed = 10;
	data->shooters[8][9].flags = 1;
	data->shooters[8][9].padding1 = -1;

	data->shooters[8][10].fire_rate = 15;
	data->shooters[8][10].position = (v2c) {
	0, 0};
	data->shooters[8][10].start_dalay = 12;
	data->shooters[8][10].dmg = 5;
	data->shooters[8][10].hitbox = (v2c) {
	12, 12};
	data->shooters[8][10].speed = 10;
	data->shooters[8][10].flags = 1;
	data->shooters[8][10].padding1 = -1;

	data->shooters[8][11].fire_rate = 15;
	data->shooters[8][11].position = (v2c) {
	0, 0};
	data->shooters[8][11].start_dalay = 12;
	data->shooters[8][11].dmg = 5;
	data->shooters[8][11].hitbox = (v2c) {
	12, 12};
	data->shooters[8][11].speed = 10;
	data->shooters[8][11].flags = 1;
	data->shooters[8][11].padding1 = -1;

	fwrite(data, sizeof(player_cfg_data), 1, fp);
	fclose(fp);
}
