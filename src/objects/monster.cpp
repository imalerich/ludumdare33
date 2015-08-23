#include "monster.h"
#include <cmath>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>

#include "camera.h"

#define MAX_JUMP_CHARGE 1300.0
#define GRAVITY_ACCEL 3000 
#define LANE_CHANGE_SPEED 200

#define DEFAULT_PLAYER_SPEED 15.0
#define MAX_SPEED 20.0
#define MIN_SPEED 10.0
#define PLAYER_ACCELERATION 8.0

MONSTER::MONSTER(const char * LEG_LEFT, const char * LEG_RIGHT, const char * ARM_LEFT, const char * ARM_RIGHT, const char * BODY, const char * HEAD) {
	body_parts[MONSTER_LEFT_LEG] = new IMAGE(LEG_LEFT);
	body_parts[MONSTER_RIGHT_LEG] = new IMAGE(LEG_RIGHT);

	body_parts[MONSTER_LEFT_ARM] = new IMAGE(ARM_LEFT);
	body_parts[MONSTER_RIGHT_ARM] = new IMAGE(ARM_RIGHT);

	body_parts[MONSTER_BODY] = new IMAGE(BODY);
	body_parts[MONSTER_HEAD] = new IMAGE(HEAD);

	shadow = new IMAGE("assets/player/shadow.png");

	IMAGE * head = body_parts[MONSTER_HEAD];
	size = head->size;

	health = 1.0;

	time = 0.0;
	was_jumping = false;
	jump_move_speed = 0.0;
	default_speed = 0.0;
	default_time = 0.0;
	found_default_speed = false;
	lane_offset = 0.0;
	speed = DEFAULT_PLAYER_SPEED;
	step_state = LEFT_STOMP;
}

MONSTER::~MONSTER() {
	for (int i=0; i<BODY_PART_COUNT; i++) {
		if (body_parts[i])
			delete body_parts[i];
	}

	delete shadow;
}

void MONSTER::reset() {
	health = 1.0;

	pos = VECTOR2(0, max_y_pos);
	vel = VECTOR2();

	time = 0.0;
	was_jumping = false;
	jump_move_speed = 0.0;
	default_speed = 0.0;
	default_time = 0.0;
	found_default_speed = false;
	lane_offset = 0.0;
	speed = DEFAULT_PLAYER_SPEED;
	step_state = LEFT_STOMP;
}

void MONSTER::checkInputDown(ALLEGRO_EVENT ev) {
	switch (ev.keyboard.keycode) {

	case ALLEGRO_KEY_UP:
		directions[KEY_UP] = true;
		break;

	case ALLEGRO_KEY_DOWN:
		directions[KEY_DOWN] = true;
		break;

	case ALLEGRO_KEY_LEFT:
		directions[KEY_LEFT] = true;
	break;

	case ALLEGRO_KEY_RIGHT:
		directions[KEY_RIGHT] = true;
		break;

	case ALLEGRO_KEY_SPACE:
		if (isOnGround()) {
			jump_move_speed = speed;
			vel.y = -MAX_JUMP_CHARGE;
			was_jumping = true;
		}
		
		break;
	}
}

void MONSTER::checkInputUp(ALLEGRO_EVENT ev) {
	switch (ev.keyboard.keycode) {

	case ALLEGRO_KEY_UP:
		directions[KEY_UP] = false;

		break;

	case ALLEGRO_KEY_DOWN:
		directions[KEY_DOWN] = false;
		break;

	case ALLEGRO_KEY_RIGHT:
		directions[KEY_RIGHT] = false;
		break;

	case ALLEGRO_KEY_LEFT:
		directions[KEY_LEFT] = false;
		break;

	case ALLEGRO_KEY_SPACE:
		if (isOnGround()) {
			jump_move_speed = speed;
			vel.y = -MAX_JUMP_CHARGE;
			was_jumping = true;
		}
		
		break;
	}
}

double MONSTER::getRenderedY() {
	return pos.y - lane_offset;
}

double MONSTER::getCurrentLane() {
	return round(std::abs(lane_offset / lane_height));
}

bool MONSTER::isOnGround() {
	return std::abs(vel.y) < 0.001;
}

bool MONSTER::canStompCar() {
	return !isOnGround() && (vel.y > 0) && (pos.y > (max_y_pos - 10));
}

double MONSTER::getDefaultSpeed() {
	if (!found_default_speed) {
		return 0.0;
	} else {
		return default_speed / default_time;
	}
}

void MONSTER::updatePos() {
	double radius = 10;

	if (directions[KEY_LEFT]) {
		speed -= PLAYER_ACCELERATION * (1.0 / FRAME_RATE);
		speed = std::max(speed, MIN_SPEED);

	} else if (directions[KEY_RIGHT]) {
		speed += PLAYER_ACCELERATION * (1.0 / FRAME_RATE);
		speed = std::min(speed, MAX_SPEED);

	} else {
		// if neither keys are pressed, reset the player to the default speed
		if (speed < DEFAULT_PLAYER_SPEED) {
			speed += PLAYER_ACCELERATION * (1.0 / FRAME_RATE);
			speed = std::min(speed, DEFAULT_PLAYER_SPEED);
		} else if (speed > DEFAULT_PLAYER_SPEED) {
			speed -= PLAYER_ACCELERATION * (1.0 / FRAME_RATE);
			speed = std::max(speed, DEFAULT_PLAYER_SPEED);
		}
	}

	if (directions[KEY_UP]) {
		lane_offset += (1.0 / FRAME_RATE) * LANE_CHANGE_SPEED;
		lane_offset = std::min(lane_offset, (num_lanes-1) * lane_height);

	} else if (directions[KEY_DOWN]) {
		lane_offset -= (1.0 / FRAME_RATE) * LANE_CHANGE_SPEED;
		lane_offset = std::max(lane_offset, 0.0);

	} else {
		// we need to snap the player to the nearest lane
		int lane = getCurrentLane();
		double lane_target = lane * lane_height;

		// update the lane offset for the player
		if (lane_offset < lane_target && (step_state == LEFT_STOMP || step_state == RIGHT_STOMP)) {
			lane_offset += (1.0 / FRAME_RATE) * 150;

			if (lane_offset > lane_target) {
				lane_offset = lane_target;
			}
		} else if (lane_offset > lane_target && (step_state == LEFT_STOMP || step_state == RIGHT_STOMP)) {
			lane_offset -= (1.0 / FRAME_RATE) * 150;

			if (lane_offset < lane_target) {
				lane_offset = lane_target;
			}
		}
	}

	double time_accel = 0.7 + (time/M_PI);
	time += (1.0 / FRAME_RATE) * (speed  * time_accel);

	// time for M_PI for a walk motion
	if (time > M_PI) {
		time = 0.0;
		step_state = (step_state + 1) % STOMP_COUNT;
	}

	// pause for M_PI / 2.0
	if (time > M_PI * 0.75 && step_state%2 == 1) {
		if (!found_default_speed && step_state + 1 == STOMP_COUNT) {
			found_default_speed = true;
		}

		time = 0.0;
		step_state = (step_state + 1) % STOMP_COUNT;

		if (step_state == RIGHT_STOMP || step_state == LEFT_STOMP) {
			camera.cam_shake += 1.0;
		}
	}

	if (!found_default_speed) {
		default_time += (1.0 / FRAME_RATE);
	}

	if (step_state == LEFT_STOMP) {
		leg_offset.x = cos(time) * radius;
		leg_offset.y = sin(time) * radius;

		body_offset.y = (1 + sin(time * 2)) * (radius/2.0);

		if (isOnGround()) {
			pos.x += (time * speed)/9.0;
		}

		if (!found_default_speed) {
			default_speed += (time * speed)/9.0;
		}

	} else if (step_state == RIGHT_STOMP) {
		leg_offset.x = -cos(time) * radius;
		leg_offset.y = -sin(time) * radius;

		body_offset.y = (1 + sin(time * 2)) * (radius/2.0);

		if (isOnGround()) {
			pos.x += (time * speed)/9.0;
		}

		if (!found_default_speed) {
			default_speed += (time * speed)/9.0;
		}

	}

	if (!isOnGround()) {
		pos.x += (default_speed / default_time) * (1.0 / FRAME_RATE);
	}

	if (step_state == LEFT_STOMP) {
		head_rot = time * 0.05;

	} else if (step_state == RIGHT_STOMP) {
		head_rot = (M_PI * 0.05) - time * 0.05;
	}

	// do shit with velocity and acceloration
	accel.y = GRAVITY_ACCEL;
	vel.y += accel.y * (1.0 / FRAME_RATE);
	pos.y += vel.y * (1.0 / FRAME_RATE);

	pos.x += vel.x * (1.0 / FRAME_RATE);
	if (vel.x > 0) {
		vel.x -= 3000.0  * (1.0 / FRAME_RATE);
		vel.x = std::max(0.0, vel.x);

	} else if (vel.x < 0) {
		vel.x += 3000.0  * (1.0 / FRAME_RATE);
		vel.x = std::min(0.0, vel.x);
	}

	if (pos.y >= max_y_pos) {
		if (was_jumping) {
			was_jumping = false;
			camera.cam_shake += 5.0;
		}

		vel.y = 0.0;
		pos.y = max_y_pos;
	}
}

void MONSTER::update() {
	updatePos();
}

void MONSTER::drawShadow() {
	shadow->draw(VECTOR2(pos.x, max_y_pos - lane_offset));
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
