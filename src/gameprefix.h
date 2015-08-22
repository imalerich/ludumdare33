#ifndef GAMEPREFIX_H
#define GAMEPREFIX_H

#include "LudumDare33Config.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

#define FRAME_RATE 144
#define SCREENW 800
#define SCREENH 600

extern ALLEGRO_EVENT_QUEUE * event_queue;
extern ALLEGRO_TIMER * timer;
extern ALLEGRO_DISPLAY * display;
extern bool GAME_OVER;

bool init_allegro();
bool setup_allegro_objects();
void release_allegro();

#endif