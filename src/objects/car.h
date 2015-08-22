#ifndef CAR_H
#define CAR_H

#include "../gameprefix.h"
#include "../math/vector2.h"

class CAR {
public:
	CAR(VECTOR2 POS);

	double y_offset;
	VECTOR2 pos;
	VECTOR2 fall_direction;
	bool is_falling;

	double rotation;
	double scale;

	void update();
};

#endif