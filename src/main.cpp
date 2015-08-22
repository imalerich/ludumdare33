#include <stdio.h>
#include "gameprefix.h"

#include "objects/monster.h"
#include "objects/background.h"
#include "objects/camera.h"
#include "math/vector2.h"

int main(int argc, char **argv) {
	if (!init_allegro()) {
		fprintf(stderr, "Failed to setup Allegro.\n");
		return -1;
	}

	if (!setup_allegro_objects()) {
		fprintf(stderr, "Failed to setup Allegro Objects.\n");
		return -1;
	}

	al_clear_to_color(al_map_rgb(139, 217, 252));
	al_flip_display();

	MONSTER * player = new MONSTER("assets/player/legl.png", "assets/player/legr.png", "assets/player/arml.png", "assets/player/armr.png", "assets/player/body.png", "assets/player/head.png");
	BACKGROUND * bg = new BACKGROUND("assets/map/background.png");

	bool redraw = true;
	while (!GAME_OVER) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
			GAME_TIME += (1.0 / FRAME_RATE);

			player->update();
			camera.pos.x = player->pos.x;
		}

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			GAME_OVER = true;
		}

		if (redraw) {
			redraw = false;
			al_clear_to_color(al_map_rgb(139, 217, 252));

			// draw shit goes here
			bg->draw();
			player->draw();

			al_flip_display();
		}
	}

	delete player;
	delete bg;

	release_allegro();
	return 0;
}