#include "score.h"
#include <iostream>

SCORE::SCORE() {
	font = new IMAGE("assets/ui/font.png");
}

SCORE::~SCORE() {
	delete font;
}

void SCORE::draw() {
	int width = font->size.x / 10;
	int height = font->size.y;

	if (score == 0) {
		font->drawRegion(VECTOR2(SCREENW - 12 - width, 12), VECTOR2(0, 0), VECTOR2(width, height));

		return;
	}

	int current_digit = 1;
	int render_score = score;
	while (render_score > 0) {
		int digit = render_score % 10;
		render_score /= 10;

		font->drawRegion(VECTOR2(SCREENW - 12 - current_digit * width * (4/5.0), 12), VECTOR2(width * digit, 0), VECTOR2(width, height));
		current_digit++;
	}
}
