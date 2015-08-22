#include "healthbar.h"
#include "../objects/camera.h"

HEALTHBAR::HEALTHBAR() {
	health_top = new IMAGE("assets/ui/health_top.png");
	health_bar = new IMAGE("assets/ui/health_bar.png");
	health_bottom = new IMAGE("assets/ui/health_bottom.png");

	current_health = 1.0;
}

HEALTHBAR::~HEALTHBAR() {
	delete health_top;
	delete health_bar;
	delete health_bottom;
}

void HEALTHBAR::draw() {
	double x = (SCREENW - health_bar->size.x);
	health_bottom->draw(VECTOR2(camera.pos.x + x, camera.pos.y));
	health_bar->draw(VECTOR2(camera.pos.x + x, camera.pos.y), VECTOR2(88, 0) , 0, current_health, 1.0);
	health_top->draw(VECTOR2(camera.pos.x + x, camera.pos.y));
}
