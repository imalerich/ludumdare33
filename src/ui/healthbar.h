#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include "../gameprefix.h"
#include "../objects/image.h"

class HEALTHBAR {
public:
	HEALTHBAR();
	~HEALTHBAR();

	void draw();

	double current_health;

private:
	IMAGE * health_top;
	IMAGE * health_bar;
	IMAGE * health_bottom;
};

#endif