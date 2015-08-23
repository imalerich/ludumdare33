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

	default_speed = 400;
	height = (max_y - min_y)/3;

	next_spawn = rand() % 2 + 1;
	follow = NULL;
}

CARSPAWNER::~CARSPAWNER() {
	delete image;
}

void CARSPAWNER::reset() {
	cars.clear();
	next_spawn = rand() % 2 + 1;
}

void CARSPAWNER::draw(int lane) {
	for (std::vector<CAR>::iterator it = cars.begin(); it != cars.end(); it++) {
		VECTOR2 pos = it->pos;

		if ((int)it->getCurrentLane() == lane) {
			pos.y += it->y_offset;
			image->draw(pos, it->rotation, it->scale);
		}
	}
}

void CARSPAWNER::update() {
	time += (1.0 / FRAME_RATE);
	if (time > next_spawn) {
		time = 0.0;

		double base = std::max(2.0 - (GAME_TIME)/60.0, 0.0);
		double variance = std::max(3.0 - (GAME_TIME)/60.0, 1.0);
		next_spawn = variance * (rand() % 1000)/1000.0 + base;

		int lane = rand() % 3;
		double y = max_y - (lane * height) - image->size.y;

		MONSTER * monster = NULL;
		if (GAME_TIME > 15.0 && rand()%4 == 0) {
			monster = follow;
		}

		cars.push_back(CAR( VECTOR2(SCREENW + camera.pos.x, y), default_speed, height, max_y, image->size.y, monster ));
	}


	for (std::vector<CAR>::iterator it = cars.begin(); it != cars.end(); it++) {
		it->update();
		if (!it->is_falling) {
			it->pos.x -= (1.0 / FRAME_RATE) * it->speed;
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
			(int)it->getCurrentLane() == monster->getCurrentLane() &&
			!it->is_falling) {
			double speed = 1500;
			double r = ((rand() % 1000)/1000.0) * (2 * M_PI);

			double x = cos(r);
			double y = sin(r);

			it->fall_direction = VECTOR2(x * speed, y * speed);
			it->is_falling = true;

			score += 10;
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
			(int)it->getCurrentLane() == monster->getCurrentLane() && 
			!(monster->max_y_pos - monster->pos.y > 100)) {

			it->pos.y += SCREENH;
			monster->health = std::max(monster->health - 0.2, 0.0);
			monster->vel.x = -1000;
			it->follow = NULL;

		}
	}
}