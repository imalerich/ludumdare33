#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "../gameprefix.h"
#include "image.h"

class BACKGROUND {
public:
	BACKGROUND(const char * filename);
	~BACKGROUND();

	IMAGE * image;
	double parallax;
	double yPos;

	void update();
	void draw();
};

#endif