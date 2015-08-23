#ifndef CAR_H
#define CAR_H

#include "../gameprefix.h"
#include "../math/vector2.h"
#include "monster.h"

class CAR {
public:
	CAR(VECTOR2 POS, double SPEED, double LANE_HEIGHT, double MAX_Y, double IMAGE_HEIGHT, MONSTER * FOLLOW);

	double y_offset;
	VECTOR2 pos;
	VECTOR2 fall_direction;
	bool is_falling;

	double rotation;
	double scale;

	double image_height;
	double max_y;
	double speed;

	MONSTER * follow;

	void update();

	double lane_height;
	double getCurrentLane();
};

#endif