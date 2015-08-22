#include "background.h"

BACKGROUND::BACKGROUND(const char * filename) {
	image = new IMAGE(filename);
}

BACKGROUND::~BACKGROUND() {
	delete image;
}

void BACKGROUND::draw() {
	for (int x=0; x<(SCREENW/image->size.x) + 2; x++) {
		image->draw(VECTOR2(x * image->size.x, 0));
	}
}
