#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define SOIZE 300
int *SMOL_TABLE[SOIZE] = { NULL };

#define TURN_LEFT  (-2)
#define TURN_RIGHT (-1)

#define SOUTH	0
#define WEST	1
#define NORTH	2
#define EAST	3

typedef struct ivec {
	int x;
	int y;
	int d;
} ivec;

void update_table(int *entry, int h) {
	while (SMOL_TABLE[h] != NULL) {
			++h;
	}
	SMOL_TABLE[h] = entry;
}

int hash(int x, int y) {
	return ((x * 2) + y) % SOIZE;
}

ivec set_max_distance(ivec a, ivec b) {
	int da = (a.x * a.x) + (a.y * a.y);
	int db = (b.x * b.x) + (b.y * b.y);
	return (db > da)? b : a;
}


void move(ivec *p, int command) {
	switch (p->d)
	{
		case SOUTH:
			command = (-1) * command; break;
		case WEST:
			command = (-1) * command; break;
		case NORTH: case EAST: break;
	}

	int x = hash(p->x, p->y);
	if (SMOL_TABLE[x] == NULL) return;
	ivec obs = { .x = SMOL_TABLE[x][0], .y = SMOL_TABLE[x][1] };
	if (obs.y == p->y) {
		if (p->y + command > obs.y) {
			p->y = obs.y - 1;
		} else {
			p->y = command;
		}
	}
	if (obs.x == p->x) {
		if (p->x + command > obs.x) {
			p->x = obs.x - 1;
		} else {
			p->x = command;
		}
	}
}

int main(void) {
	ivec robot_pos = { .x = 0, .y = 0, .d = NORTH };
	ivec max_pos   = { .x = 0, .y = 0, .d = NORTH };

	int commands[] = {4, -1, 4, -2, 4}; int size = sizeof(commands) / sizeof(commands[0]);
	int obstacles[][2] = { {2, 4} };
	int obstaclesSize = 1;

	for (int i = 0; i < obstaclesSize; ++i) {
		int h = hash(obstacles[i][0], obstacles[i][1]);
		update_table(obstacles[i], h);
	}

	for (int i = 0; i < size; ++i) {
		if (commands[i] == TURN_LEFT) {
			robot_pos.d = (robot_pos.d == 0)? 3 : robot_pos.d - 1;
		} else if (commands[i] == TURN_RIGHT) {
			robot_pos.d = (robot_pos.d == 3)? 0 : robot_pos.d + 1;
		} else {
			move(&robot_pos, commands[i]);
		}
		max_pos = set_max_distance(max_pos, robot_pos);
	}
	printf("max_pos = (%d, %d) : with distance equal %d\n",
	max_pos.x, max_pos.y, (max_pos.x * max_pos.x) + (max_pos.y * max_pos.y));
}
