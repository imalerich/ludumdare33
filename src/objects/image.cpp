#include "image.h"
#include "camera.h"

IMAGE::IMAGE(const char * filename) {
	image = al_load_bitmap(filename);

	if (image) {
		unsigned width = al_get_bitmap_width(image);
		unsigned height = al_get_bitmap_height(image);
		size = VECTOR2(width, height);

	} else {
		fprintf(stderr, "Failed to create bitmap.%s");

	}
}

IMAGE::~IMAGE() {
	al_destroy_bitmap(image);
}

void IMAGE::draw(VECTOR2 pos) {
	al_draw_bitmap(image, pos.x - camera.pos.x, pos.y - camera.pos.y, 0);
}

void IMAGE::draw(VECTOR2 pos, double rot) {
	al_draw_rotated_bitmap(image, size.x/2.0, size.y/2.0, pos.x + size.x/2.0 - camera.pos.x, pos.y + size.y/2.0 - camera.pos.y, rot, 0);
}

void IMAGE::draw(VECTOR2 pos, VECTOR2 center, double rot) {
	al_draw_rotated_bitmap(image, center.x, center.y, pos.x + center.x - camera.pos.x, pos.y + center.y - camera.pos.y, rot, 0);
}