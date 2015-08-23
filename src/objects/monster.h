#ifndef MONSTER_H
#define MONSTER_H

#include "../gameprefix.h"
#include "../math/vector2.h"
#include "image.h"

#define BODY_PART_COUNT 6
#define STOMP_COUNT 4

enum BODY_PARTS {
	MONSTER_RIGHT_LEG, MONSTER_RIGHT_ARM, MONSTER_BODY, 
	MONSTER_LEFT_LEG, MONSTER_LEFT_ARM, MONSTER_HEAD
};

enum ANIMATION_STAGE {
	LEFT_STOMP, LEFT_STOMP_HOLD, RIGHT_STOMP, RIGHT_STOMP_HOLD
};

enum DIRECTION_KEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

class MONSTER {
public:
	MONSTER(const char * leg_left, const char * leg_right, const char * arm_left, const char *arm_right, const char * body, const char * head);
	~MONSTER();

	void reset();

	VECTOR2 pos;
	VECTOR2 size;

	double health;

	double max_y_pos;
	double lane_height;

	double getDefaultSpeed();
	double getCurrentLane();
	int num_lanes;

	double lane_offset;

	bool canStompCar();
	double getRenderedY();

	void drawShadow();
	void draw();
	void draw_background();
	void update();

	void checkInputDown(ALLEGRO_EVENT ev);
	void checkInputUp(ALLEGRO_EVENT ev);

	VECTOR2 vel;

private:
	bool directions[4] = { false, false, false, false };

	bool isOnGround();
	void updatePos();

	bool was_jumping;
	double jump_move_speed;
	double default_speed;
	double default_time;
	bool found_default_speed;

	IMAGE * shadow;
	IMAGE * body_parts[BODY_PART_COUNT];

	unsigned step_state;

	double speed;
	double time;
	double stall;
	double head_rot;
	
	VECTOR2 leg_offset;
	VECTOR2 body_offset;

	VECTOR2 accel;
};

#endif