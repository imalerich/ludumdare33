#include "monster.h"
#include <cmath>
#include <math.h>

MONSTER::MONSTER(const char * LEG_LEFT, const char * LEG_RIGHT, const char * ARM_LEFT, const char * ARM_RIGHT, const char * BODY, const char * HEAD) {
	body_parts[MONSTER_LEFT_LEG] = new IMAGE(LEG_LEFT);
	body_parts[MONSTER_RIGHT_LEG] = new IMAGE(LEG_RIGHT);

	body_parts[MONSTER_LEFT_ARM] = new IMAGE(ARM_LEFT);
	body_parts[MONSTER_RIGHT_ARM] = new IMAGE(ARM_RIGHT);

	body_parts[MONSTER_BODY] = new IMAGE(BODY);
	body_parts[MONSTER_HEAD] = new IMAGE(HEAD);

	IMAGE * head = body_parts[MONSTER_HEAD];
	size = head->size;

	time = 0.0;
	step_state = LEFT_STOMP;
}

MONSTER::~MONSTER() {
	for (int i=0; i<BODY_PART_COUNT; i++) {
		if (body_parts[i])
			delete body_parts[i];
	}
}

void MONSTER::update() {
	double radius = 10;
	double speed = 9.0;

	double accel = 0.7 + (time/M_PI);
	time += (1.0 / FRAME_RATE) * (speed  * accel);

	// time for M_PI for a walk motion
	if (time > M_PI) {
		time = 0.0;
		step_state = (step_state + 1) % STOMP_COUNT;
	}

	// pause for M_PI / 2.0
	if (time > M_PI * 0.75 && step_state%2 == 1) {
		time = 0.0;
		step_state = (step_state + 1) % STOMP_COUNT;
	}

	if (step_state == LEFT_STOMP) {
		leg_offset.x = cos(time) * radius;
		leg_offset.y = sin(time) * radius;

		body_offset.y = (1 + sin(time * 2)) * (radius/2.0);

	} else if (step_state == RIGHT_STOMP) {
		leg_offset.x = -cos(time) * radius;
		leg_offset.y = -sin(time) * radius;

		body_offset.y = (1 + sin(time * 2)) * (radius/2.0);

	}

	if (step_state == LEFT_STOMP) {
		head_rot = time * 0.05;

	} else if (step_state == RIGHT_STOMP) {
		head_rot = (M_PI * 0.05) - time * 0.05;
	}
}

void MONSTER::draw() {
	for (int i=0; i<BODY_PART_COUNT; i++) {
		IMAGE * img = body_parts[i];

		double xOff = 0.0;
		double yOff = 0.0;

		switch(i) {
		case MONSTER_LEFT_LEG:
			xOff = leg_offset.x;
			yOff = leg_offset.y;
			img->draw(VECTOR2(pos.x + xOff, pos.y + yOff));
			break;

		case MONSTER_RIGHT_LEG:
			xOff = -leg_offset.x;
			yOff = -leg_offset.y;
			img->draw(VECTOR2(pos.x + xOff, pos.y + yOff));
			break;

		case MONSTER_LEFT_ARM:
			yOff = -leg_offset.y;
			img->draw(VECTOR2(pos.x + xOff, pos.y + yOff));
			break;

		case MONSTER_RIGHT_ARM:
			yOff = leg_offset.y;
			img->draw(VECTOR2(pos.x + xOff, pos.y + yOff));
			break;

		case MONSTER_BODY:
			yOff = body_offset.y;
			img->draw(VECTOR2(pos.x + xOff, pos.y + yOff));
			break;

		case MONSTER_HEAD:
			yOff = body_offset.y;
			img->draw(VECTOR2(pos.x + xOff, pos.y + yOff), VECTOR2(241, 210), head_rot);
			break;

		default:
			img->draw(VECTOR2(pos.x + xOff, pos.y + yOff));
			break;
		}

	}
}
