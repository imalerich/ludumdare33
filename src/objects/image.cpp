#include "image.h"

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
	al_draw_bitmap(image, pos.x, pos.y, 0);
}

void IMAGE::draw(VECTOR2 pos, double rot) {
	fprintf(stdout, "Deleting the Image\n");
	al_draw_rotated_bitmap(image, size.x/2.0, size.y/2.0, pos.x + size.x/2.0, pos.y + size.y/2.0, rot, 0);
}