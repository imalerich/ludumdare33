#ifndef CAMERA_H
#define CAMERA_H

#include "../gameprefix.h"
#include "../math/vector2.h"

class CAMERA {
public:
	CAMERA();

	VECTOR2 pos;
	VECTOR2 getPosRelativeToCam(VECTOR2 in);
};

extern CAMERA camera;

#endif