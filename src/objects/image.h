#ifndef IMAGE_H
#define IMAGE_H

#include "../gameprefix.h"
#include "../math/vector2.h"

class IMAGE {
public:
	IMAGE(const char * filename);
	~IMAGE();

	void draw(VECTOR2 pos);
	void draw(VECTOR2 pos, double rot);
	VECTOR2 size;

private:
	ALLEGRO_BITMAP * image;
};

#endif