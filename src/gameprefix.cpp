#include "gameprefix.h"

ALLEGRO_EVENT_QUEUE * event_queue = NULL;
ALLEGRO_TIMER * timer = NULL;
ALLEGRO_DISPLAY * display;
ALLEGRO_DISPLAY_MODE disp_data;
bool GAME_OVER = false;

int score = 0;
double GAME_TIME = 0.0;

bool init_allegro() {
	// call all allegro setup functions
	if (!al_init()) {
		return false;
	}

	if (!al_init_image_addon()) {
		return false;
	}

	if (!al_install_keyboard()) {
		return false;
	}

	if (!al_install_mouse()) {
		return false;
	}

	if (!al_install_joystick()) {
		return false;
	}

	return true;
}

bool setup_allegro_objects() {
	timer = al_create_timer(1.0 / FRAME_RATE);
	if (!timer) {
		release_allegro();
		return false;
	}

	// al_get_display_mode(al_get_num_display_modes() - 1, &disp_data);
	// al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	// display = al_create_display(disp_data.width, disp_data.height);
	display = al_create_display(SCREENW, SCREENH);
	if (!display) {
		release_allegro();
		return false;
	}

	event_queue = al_create_event_queue();
	if (!event_queue) {
		release_allegro();
		return false;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_start_timer(timer);

	return true;
}

void release_allegro() {
	if (timer) {
		al_destroy_timer(timer);
	}

	if (display) {
		al_destroy_display(display);
	}

	if (event_queue) {
		al_destroy_event_queue(event_queue);
	}
}