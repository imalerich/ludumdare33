#include "car.h"

CAR::CAR(VECTOR2 POS) {
	pos = POS;
	is_falling = false;
	y_offset = 0;
}

void CAR::update() {
	pos.x += (fall_direction.x * (1.0 / FRAME_RATE));
	y_offset += (fall_direction.y * (1.0 / FRAME_RATE));
}