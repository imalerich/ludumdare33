#include "camera.h"
#include <algorithm>
#include <math.h>

CAMERA::CAMERA() {
	cam_shake = 0.0;
}

void CAMERA::reset() {
	cam_shake = 0.0;
	pos = VECTOR2();
}

void CAMERA::update() {
	time += (1.0 / FRAME_RATE);
	cam_shake = std::max(cam_shake - 10.0 * (1.0 / FRAME_RATE), 0.0);

	shake.x = cam_shake * cos(52 * time);
	shake.y = cam_shake * sin(38 *time);
}

VECTOR2 CAMERA::renderPos() {
	return VECTOR2(pos.x + shake.x, pos.y + shake.y);
}

CAMERA camera;