#pragma once

#include <iostream>
#include "../../lib/lib.h"

class Ball
{
private:
	Ball();

public:
	int player_score = 0;
	int cpu_score = 0;
	float x;
	float y;
	int speed_x;
	int speed_y;
	int radius;
	Color color;

	Ball(float x, float y, int speed_x, int speed_y, int radius, Color color);

	void draw();
	void update();
	void resetBall();
};
