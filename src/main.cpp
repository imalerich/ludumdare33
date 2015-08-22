#include <stdio.h>
#include "gameprefix.h"

void redraw_screen() {
	al_clear_to_color(al_map_rgb(0, 0, 0));

	// draw shit goes here

	al_flip_display();
}

int main(int argc, char **argv) {
	if (!init_allegro()) {
		fprintf(stderr, "Failed to setup Allegro.\n");
		return -1;
	}

	if (!setup_allegro_objects()) {
		fprintf(stderr, "Failed to setup Allegro Objects.\n");
		return -1;
	}

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();

	bool redraw = true;
	while (!GAME_OVER) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
		}

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			GAME_OVER = true;
		}

		if (redraw) {
			redraw = false;
			redraw_screen();
		}
	}

	release_allegro();
	return 0;
}