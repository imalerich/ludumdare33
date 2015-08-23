#include "gameover.h"
#include "../objects/camera.h"
#include <iostream>

GAMEOVER::GAMEOVER() {
	background = new IMAGE("assets/ui/gameover_background.png");
	text = new IMAGE("assets/ui/gameover.png");

	retry_inactive = new IMAGE("assets/ui/retry_inactive.png");
	quit_inactive = new IMAGE("assets/ui/quit_inactive.png");

	retry = new IMAGE("assets/ui/retry.png");
	quit  = new IMAGE("assets/ui/quit.png");

	is_game_over = false;
	restart_game = false;
	is_mouse_over_retry = false;
	is_mouse_over_quit = false;
}

GAMEOVER::~GAMEOVER() {
	delete background;
	delete text;
}

void GAMEOVER::draw() {
	background->draw(camera.pos);
	text->draw(VECTOR2(camera.pos.x + (SCREENW - text->size.x)/2.0, camera.pos.y + (SCREENH - text->size.y)/2.0));

	if (!is_mouse_over_retry) {
		retry_inactive->draw(VECTOR2(camera.pos.x + (SCREENW - retry_inactive->size.x)/2.0, camera.pos.y + (SCREENH - retry_inactive->size.y)/2.0));
	} else {
		retry->draw(VECTOR2(camera.pos.x + (SCREENW - retry->size.x)/2.0, camera.pos.y + (SCREENH - retry->size.y)/2.0));
	}

	if (!is_mouse_over_quit) {
		quit_inactive->draw(VECTOR2(camera.pos.x + (SCREENW - quit_inactive->size.x)/2.0, camera.pos.y + (SCREENH - quit_inactive->size.y)/2.0));
	} else {
		quit->draw(VECTOR2(camera.pos.x + (SCREENW - quit->size.x)/2.0, camera.pos.y + (SCREENH - quit->size.y)/2.0));
	}
}

void GAMEOVER::update(ALLEGRO_EVENT ev) {
	if (ev.type == ALLEGRO_EVENT_MOUSE_AXES || ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
		double mouse_x = ev.mouse.x;
		double mouse_y = ev.mouse.y;

		double width = text->size.x;
		double height = text->size.y;

		double xPos = (SCREENW - width)/2.0;
		double yPos = (SCREENH - height)/2.0 + 200;

		if (mouse_x > 0 && mouse_y > 0) {
			is_mouse_over_retry = false;
			is_mouse_over_quit = false;

			if (mouse_y > yPos && mouse_y < yPos + height) {
				if (mouse_x > xPos && mouse_x < xPos + width/2.0) {
					is_mouse_over_retry = true;

				} else if (mouse_x > xPos + width/2.0 && mouse_x < xPos + width) {
					is_mouse_over_quit = true;
				}
			}
		}
	}

	if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
		if (is_mouse_over_quit) {
			is_game_over = true;
		}

		if (is_mouse_over_retry) {
			restart_game = true;
		}
	}
}