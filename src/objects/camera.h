#ifndef CAMERA_H
#define CAMERA_H

#include "../gameprefix.h"
#include "../math/vector2.h"

class CAMERA {
public:
	CAMERA();

	double cam_shake;
	VECTOR2 pos;

	VECTOR2 renderPos();
	void update();

private:
	double time;
	VECTOR2 shake;
};

extern CAMERA camera;

#endif