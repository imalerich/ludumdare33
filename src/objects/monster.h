#ifndef MONSTER_H
#define MONSTER_H

#include "../gameprefix.h"
#include "../math/vector2.h"
#include "image.h"

#define MONSTER_RIGHT_LEG 0
#define MONSTER_RIGHT_ARM 1
#define MONSTER_BODY 2
#define MONSTER_LEFT_LEG 3
#define MONSTER_LEFT_ARM 4
#define MONSTER_HEAD 5

#define LEFT_STOMP 0
#define LEFT_STOMP_HOLD 1
#define RIGHT_STOMP 2
#define RIGHT_STOMP_HOLD 3
#define STOMP_COUNT 4

#define BODY_PART_COUNT 6

class MONSTER {
public:
	MONSTER(const char * leg_left, const char * leg_right, const char * arm_left, const char *arm_right, const char * body, const char * head);
	~MONSTER();

	VECTOR2 pos;
	VECTOR2 size;
	void draw();
	void update();

private:
	IMAGE * body_parts[BODY_PART_COUNT];

	unsigned step_state;

	double time;
	double stall;
	double head_rot;
	
	VECTOR2 leg_offset;
	VECTOR2 body_offset;

	VECTOR2 vel;
	VECTOR2 accel;
};

#endif