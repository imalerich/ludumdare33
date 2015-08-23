#ifndef SCORE_H
#define SCORE_H

#include "../gameprefix.h"
#include "../objects/image.h"

class SCORE {
public:
	SCORE();
	~SCORE();

	void draw();

private:
	IMAGE * font;
};

#endif