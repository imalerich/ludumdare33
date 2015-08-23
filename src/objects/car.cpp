#include "car.h"
#include <cmath>
#include <iostream>

#define ROTATION_SPEED 8*M_PI
#define SCALE_SPEED 0.0

CAR::CAR(VECTOR2 POS, double SPEED, double LANE_HEIGHT, double MAX_Y, double IMAGE_HEIGHT, MONSTER * FOLLOW) {
	pos = POS;
	is_falling = false;
	y_offset = 0;
	scale = 1.0;
	rotation = 0.0;
	image_height = IMAGE_HEIGHT;
	lane_height = LANE_HEIGHT;
	speed = SPEED;
	max_y = MAX_Y;
	follow = FOLLOW;
}

void CAR::update() {
	pos.x += (fall_direction.x * (1.0 / FRAME_RATE));
	y_offset += (fall_direction.y * (1.0 / FRAME_RATE));

	if (is_falling) {
		rotation += (ROTATION_SPEED * (1.0 / FRAME_RATE));
		scale += (SCALE_SPEED * (1.0 / FRAME_RATE));

		if (scale < 0) {
			scale = 0.0;
		}
	}

	if (follow != NULL) {
		pos.y = max_y - follow->lane_offset - image_height;
	}
}

double CAR::getCurrentLane() {
	double lane = -((pos.y + image_height) - max_y)/lane_height;
	return round(std::abs(lane));
}