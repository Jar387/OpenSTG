#ifndef SHOOTER_H
#define SHOOTER_H

typedef struct player_bullet_t {
	v2d xy;
	v2d dxy;
	v2i uv;
	v2i wh;
	v2i hitbox;
	float angle;
	list_node node;
} player_bullet;

static inline int get_power_level()
{
	if (power < 8) {
		return 0;
	}
	if (power < 16) {
		return 1;
	}
	if (power < 32) {
		return 2;
	}
	if (power < 48) {
		return 3;
	}
	if (power < 64) {
		return 4;
	}
	if (power < 80) {
		return 5;
	}
	if (power < 96) {
		return 6;
	}
	if (power < 128) {
		return 7;
	}
	return 8;
}

void tick_shooter();

player_bullet *create_player_bullet(int id, v2d xy, v2i hitbox, int angle,
				    int speed);

#endif
