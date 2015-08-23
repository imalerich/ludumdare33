#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "../gameprefix.h"
#include "../objects/image.h"

class GAMEOVER {
public:
	GAMEOVER();
	~GAMEOVER();

	void draw();
	void update(ALLEGRO_EVENT ev);

	bool is_game_over;
	bool restart_game;

private:
	bool is_mouse_over_retry;
	bool is_mouse_over_quit;

	IMAGE * background;
	IMAGE * text;

	IMAGE * retry_inactive;
	IMAGE * quit_inactive;

	IMAGE * retry;
	IMAGE * quit;
};

#endif