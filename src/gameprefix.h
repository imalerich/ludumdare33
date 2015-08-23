#ifndef GAMEPREFIX_H
#define GAMEPREFIX_H

// include all of the necessary allegro files
#include <stdio.h>
#include "LudumDare33Config.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

#define FRAME_RATE 144
#define SCREENW 1280
#define SCREENH 720

extern ALLEGRO_EVENT_QUEUE * event_queue;
extern ALLEGRO_TIMER * timer;
extern ALLEGRO_DISPLAY * display;
extern ALLEGRO_DISPLAY_MODE disp_data;
extern bool GAME_OVER;

extern int score;
extern double GAME_TIME;

bool init_allegro();
bool setup_allegro_objects();
void release_allegro();

#endif