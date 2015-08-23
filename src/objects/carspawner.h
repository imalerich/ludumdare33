#ifndef CARSPAWNER_H
#define CARSPAWNER_H

#include <vector>
#include "../gameprefix.h"
#include "../math/vector2.h"
#include "car.h"
#include "monster.h"
#include "image.h"

class CARSPAWNER {
public:
	CARSPAWNER(const char * filename, double MINY, double MAXY);
	~CARSPAWNER();

	void reset();

	double default_speed;

	void draw(int lane);
	void update();

	void checkCarStomps(MONSTER * monster);
	void checkBulletHits(MONSTER * monster);

	MONSTER * follow;

private:
	double time;
	double next_spawn;

	IMAGE * image;
	double min_y;
	double max_y;
	double height;

	std::vector<CAR> cars;
};

#endif