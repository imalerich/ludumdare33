#ifndef CARSPAWNER_H
#define CARSPAWNER_H

#include <vector>
#include "../gameprefix.h"
#include "../math/vector2.h"
#include "image.h"

class CARSPAWNER {
public:
	CARSPAWNER(const char * filename);
	~CARSPAWNER();

	void draw();
	void update();

private:
	IMAGE * image;

	std::vector<VECTOR2> coords;
};

#endif