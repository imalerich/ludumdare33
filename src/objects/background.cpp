#include "background.h"
#include "camera.h"

BACKGROUND::BACKGROUND(const char * filename) {
	image = new IMAGE(filename);

	parallax = 1;
	yPos = 0.0;
}

BACKGROUND::~BACKGROUND() {
	delete image;
}

void BACKGROUND::draw() {
	double oldCamX = camera.pos.x;
	int camX = (int)(oldCamX / parallax) % (int)image->size.x;
	camera.pos.x = camX;

	for (int x=0; x<(SCREENW/image->size.x) + 2; x++) {
		image->draw(VECTOR2(x * image->size.x, yPos));
	}

	camera.pos.x = oldCamX;
}
