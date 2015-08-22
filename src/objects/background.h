#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "../gameprefix.h"
#include "image.h"

class BACKGROUND {
public:
	BACKGROUND(const char * filename);
	~BACKGROUND();

	void update();
	void draw();

private:
	IMAGE * image;
};

#endif