#include "camera.h"

CAMERA::CAMERA() {
	pos = VECTOR2();
}

VECTOR2 CAMERA::getPosRelativeToCam(VECTOR2 in) {
	return VECTOR2(in.x - pos.x, in.y - pos.y);
}

CAMERA camera;