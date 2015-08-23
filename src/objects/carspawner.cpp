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
			pos.y = max_y - (pos.y * height) - image->size.y;
			pos.y += it->y_offset;
			image->draw(pos, it->rotation, it->scale);
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
			it->pos.x -= (1.0 / FRAME_RATE) * 400;
		}
	}
}

void CARSPAWNER::checkCarStomps(MONSTER * monster) {
	if (!monster->canStompCar()) {
		return;
	}

	for (std::vector<CAR>::iterator it = cars.begin(); it != cars.end(); it++) {
		double carX = it->pos.x;
		double carWidth = image->size.x;

		double monsterX = monster->pos.x;
		double monsterWidth = monster->size.x;

		if (carX < monsterX + (monsterWidth * 7/8.0) && 
			carX + carWidth > monsterX + (monsterWidth * 1/8.0) &&
			(int)it->pos.y == monster->getCurrentLane() &&
			!it->is_falling) {
			double speed = 1500;
			double r = ((rand() % 1000)/1000.0) * (2 * M_PI);

			double x = cos(r);
			double y = sin(r);

			it->fall_direction = VECTOR2(x * speed, y * speed);
			it->is_falling = true;
		}
	}
}

void CARSPAWNER::checkBulletHits(MONSTER * monster) {
	for (std::vector<CAR>::iterator it = cars.begin(); it != cars.end(); it++) {
		double carX = it->pos.x;
		double carWidth = image->size.x;

		double monsterX = monster->pos.x;
		double monsterWidth = monster->size.x;

		if (carX < monsterX + (monsterWidth * 2/3.0) && 
			carX + carWidth > monsterX + (monsterWidth * 1/3.0) &&
			(int)it->pos.y == monster->getCurrentLane() && 
			!(monster->max_y_pos - monster->pos.y > 100)) {

			it->pos.y += SCREENH;
			monster->health = std::max(monster->health - 0.1, 0.0);

		}
	}
}