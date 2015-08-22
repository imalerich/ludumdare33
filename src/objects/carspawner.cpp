#include "carspawner.h"
#include <iostream>

CARSPAWNER::CARSPAWNER(const char * filename) {
	image = new IMAGE(filename);

	for (int y=0; y<SCREENH; y += image->size.y) {
		coords.push_back(VECTOR2(0, y));
		std::cout << "Added a vector to the array\n";
	}

	std::cout << "Created a vector of size: " + coords.size();
}

CARSPAWNER::~CARSPAWNER() {
	delete image;
}

void CARSPAWNER::draw() {
	for (std::vector<VECTOR2>::iterator it = coords.begin(); it != coords.end(); it++) {
		std::cout << "Drawing a car\n";
		image->draw(*it);
	}
}

void CARSPAWNER::update() {
	for (std::vector<VECTOR2>::iterator it = coords.begin(); it != coords.end(); it++) {
	}
}