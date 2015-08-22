#include "car.h"
#include <cmath>
#include <iostream>

#define ROTATION_SPEED 8*M_PI
#define SCALE_SPEED -1.0

CAR::CAR(VECTOR2 POS) {
	pos = POS;
	is_falling = false;
	y_offset = 0;
	scale = 1.0;
	rotation = 0.0;
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
}