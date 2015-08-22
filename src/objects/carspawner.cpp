#include <iostream>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <iostream>

#include "carspawner.h"
#include "camera.h"

CARSPAWNER::CARSPAWNER(const char * filename, double MINY, double MAXY) {
	image = new IMAGE(filename);

	min_y = MINY;
	max_y = MAXY;

	height = (max_y - min_y)/3;

	int lane = rand() % 3;
	cars.push_back(CAR( VECTOR2(SCREENW + camera.pos.x, lane) ));

	next_spawn = rand() % 3 + 2;
}

CARSPAWNER::~CARSPAWNER() {
	delete image;
}

void CARSPAWNER::draw(int lane) {
	for (std::vector<CAR>::iterator it = cars.begin(); it != cars.end(); it++) {
		VECTOR2 pos = it->pos;

		if (pos.y == lane) {
			pos.y = max_y - (pos.y * height) - height;
			pos.y += it->y_offset;
			image->draw(pos);
		}
	}
}

void CARSPAWNER::update() {
	time += (1.0 / FRAME_RATE);
	if (time > next_spawn) {
		time = 0.0;
		next_spawn = (rand() % 300)/300.0 + 2;

		int lane = rand() % 3;
		cars.push_back(CAR( VECTOR2(SCREENW + camera.pos.x, lane) ));
	}


	for (std::vector<CAR>::iterator it = cars.begin(); it != cars.end(); it++) {
		if (it->is_falling) {
			it->update();
		} else {
			it->pos.x -= (1.0 / FRAME_RATE) * 200;
		}
	}
}

void CARSPAWNER::checkCarStomps(MONSTER * monster) {
	if (!monster->canStompCar()) {
		return;
	}

	for (std::vector<CAR>::iterator it = cars.begin(); it != cars.end(); it++) {
		if (it->pos.x < monster->pos.x + monster->size.x && !it->is_falling) {
			double speed = 1500;
			double r = ((rand() % 1000)/1000.0) * (2 * M_PI);

			double x = cos(r);
			double y = sin(r);

			it->fall_direction = VECTOR2(x * speed, y * speed);
			it->is_falling = true;
		}
	}
}