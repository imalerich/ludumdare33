#include "monster.h"
#include <cmath>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define MAX_JUMP_CHARGE 800.0
#define GRAVITY_ACCEL 3000 

MONSTER::MONSTER(const char * LEG_LEFT, const char * LEG_RIGHT, const char * ARM_LEFT, const char * ARM_RIGHT, const char * BODY, const char * HEAD) {
	body_parts[MONSTER_LEFT_LEG] = new IMAGE(LEG_LEFT);
	body_parts[MONSTER_RIGHT_LEG] = new IMAGE(LEG_RIGHT);

	body_parts[MONSTER_LEFT_ARM] = new IMAGE(ARM_LEFT);
	body_parts[MONSTER_RIGHT_ARM] = new IMAGE(ARM_RIGHT);

	body_parts[MONSTER_BODY] = new IMAGE(BODY);
	body_parts[MONSTER_HEAD] = new IMAGE(HEAD);

	IMAGE * head = body_parts[MONSTER_HEAD];
	size = head->size;

	lane_offset = 0.0;
	time = 0.0;
	step_state = LEFT_STOMP;
	max_y_pos;
}

MONSTER::~MONSTER() {
	for (int i=0; i<BODY_PART_COUNT; i++) {
		if (body_parts[i])
			delete body_parts[i];
	}
}

void MONSTER::checkInput(ALLEGRO_EVENT ev) {
	switch (ev.keyboard.keycode) {

	case ALLEGRO_KEY_UP:
		if (current_lane < num_lanes-1) {
			current_lane++;
			target_lane_offset += lane_height;
		}

		break;

	case ALLEGRO_KEY_DOWN:
		if (current_lane > 0) {
			current_lane--;
			target_lane_offset -= lane_height;
		}
		break;

	case ALLEGRO_KEY_SPACE:
		if (isOnGround()) {
			vel.y = -MAX_JUMP_CHARGE;
		}
		
		break;
	}
}

bool MONSTER::isOnGround() {
	return std::abs(vel.y) < 0.001;
}

bool MONSTER::canStompCar() {
	return !isOnGround() && (vel.y > 100);
}

void MONSTER::updatePos() {
	double radius = 10;
	double speed = 5.0;

	double time_accel = 0.7 + (time/M_PI);
	time += (1.0 / FRAME_RATE) * (speed  * time_accel);

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
		pos.x += (time * speed)/9.0;

	} else if (step_state == RIGHT_STOMP) {
		leg_offset.x = -cos(time) * radius;
		leg_offset.y = -sin(time) * radius;

		body_offset.y = (1 + sin(time * 2)) * (radius/2.0);
		pos.x += (time * speed)/9.0;

	}

	if (step_state == LEFT_STOMP) {
		head_rot = time * 0.05;

	} else if (step_state == RIGHT_STOMP) {
		head_rot = (M_PI * 0.05) - time * 0.05;
	}

	// update the lane offset for the player
	if (lane_offset < target_lane_offset && (step_state == LEFT_STOMP || step_state == RIGHT_STOMP)) {
		lane_offset += (1.0 / FRAME_RATE) * 150;

		if (lane_offset > target_lane_offset) {
			lane_offset = target_lane_offset;
		}
	} else if (lane_offset > target_lane_offset && (step_state == LEFT_STOMP || step_state == RIGHT_STOMP)) {
		lane_offset -= (1.0 / FRAME_RATE) * 150;

		if (lane_offset < target_lane_offset) {
			lane_offset = target_lane_offset;
		}
	}

	// do shit with velocity and acceloration
	accel.y = GRAVITY_ACCEL;
	vel.y += accel.y * (1.0 / FRAME_RATE);
	pos.y += vel.y * (1.0 / FRAME_RATE);

	if (pos.y >= max_y_pos) {
		vel.y = 0.0;
		pos.y = max_y_pos;
	}
}

void MONSTER::update() {
	updatePos();
}

void MONSTER::draw_background() {
	for (int i=0; i<BODY_PART_COUNT; i++) {
		IMAGE * img = body_parts[i];

		double xOff = 0.0;
		double yOff = 0.0;

		switch(i) {
		case MONSTER_RIGHT_LEG:
			xOff = -leg_offset.x;
			yOff = -leg_offset.y;
			img->draw(VECTOR2(pos.x + xOff, pos.y + yOff - lane_offset));
			break;

		case MONSTER_RIGHT_ARM:
			yOff = leg_offset.y;
			img->draw(VECTOR2(pos.x + xOff, pos.y + yOff - lane_offset));
			break;

		default:
			break;
		}

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
			img->draw(VECTOR2(pos.x + xOff, pos.y + yOff + 16 - lane_offset));
			break;

		case MONSTER_LEFT_ARM:
			yOff = -leg_offset.y;
			img->draw(VECTOR2(pos.x + xOff, pos.y + yOff - lane_offset));
			break;

		case MONSTER_BODY:
			yOff = body_offset.y;
			img->draw(VECTOR2(pos.x + xOff, pos.y + yOff - lane_offset));
			break;

		case MONSTER_HEAD:
			yOff = body_offset.y;
			img->draw(VECTOR2(pos.x + xOff, pos.y + yOff - lane_offset), VECTOR2(241, 210), head_rot);
			break;

		default:
			break;
		}

	}
}
