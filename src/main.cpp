#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "gameprefix.h"

#include "objects/monster.h"
#include "objects/background.h"
#include "objects/camera.h"
#include "objects/carspawner.h"
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

	srand(time(NULL));

	al_clear_to_color(al_map_rgb(139, 217, 252));
	al_flip_display();

	MONSTER * player = new MONSTER("assets/player/legl.png", "assets/player/legr.png", "assets/player/arml.png", "assets/player/armr.png", "assets/player/body.png", "assets/player/head.png");
	BACKGROUND * bg_0 = new BACKGROUND("assets/map/background_0.png");
	BACKGROUND * bg_1 = new BACKGROUND("assets/map/background_1.png");
	BACKGROUND * street = new BACKGROUND("assets/map/street.png");

	double min_y = SCREENH - street->image->size.y;
	double max_y = SCREENH - 63;
	double lane_height = (max_y - min_y)/3;
	CARSPAWNER * spawner = new CARSPAWNER("assets/objects/car.png", min_y, max_y);

	// set the players position to the center of the screen
	player->pos.y = SCREENH - player->size.y - 63;
	player->max_y_pos = player->pos.y;
	player->num_lanes = 3;
	player->lane_height = lane_height;
	
	street->yPos = SCREENH - street->image->size.y;
	bg_0->parallax = 1;
	bg_1->parallax = 2;

	bool redraw = true;
	while (!GAME_OVER) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
			GAME_TIME += (1.0 / FRAME_RATE);

			spawner->update();
			player->update();
			camera.pos.x = player->pos.x;

			spawner->checkCarStomps(player);
		}

		if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			player->checkInput(ev);

			if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				GAME_OVER = true;
			}
		}

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			GAME_OVER = true;
		}

		if (redraw) {
			redraw = false;
			al_clear_to_color(al_map_rgb(139, 217, 252));

			// draw shit goes here
			street->draw();
			bg_1->draw();
			bg_0->draw();


			for (int i=2; i>=0; i--) {
				if (i == player->current_lane)
					player->draw_background();

				spawner->draw(i);

				if (i == player->current_lane)
					player->draw();
			}

			al_flip_display();
		}
	}

	delete player;
	delete bg_0;
	delete bg_1;
	delete street;
	delete spawner;

	release_allegro();
	return 0;
}