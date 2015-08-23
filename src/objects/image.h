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
	void draw(VECTOR2 pos, VECTOR2 center, double rot);
	void draw(VECTOR2 pos, double rot, double scale);
	void draw(VECTOR2 pos, double rot, double scaleX, double scaleY);
	void draw(VECTOR2 pos, VECTOR2 center, double rot, double scale);
	void draw(VECTOR2 pos, VECTOR2 center, double rot, double scaleX, double scaleY);

	void drawRegion(VECTOR2 pos, VECTOR2 source, VECTOR2 size);
	void drawScaled(VECTOR2 source, VECTOR2 source_size, VECTOR2 destination, VECTOR2 destination_width);

	VECTOR2 size;

private:
	ALLEGRO_BITMAP * image;
};

#endif