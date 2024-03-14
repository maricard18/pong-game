#pragma once

#include <iostream>
#include "../../lib/lib.hpp"

class Paddle
{
private:
	Paddle();

public:
	float x;
	float y;
	float width;
	float height;
	int speed;
	Color color;

	Paddle(float x, float y, float width, float height, int speed, Color color);
	Rectangle getRectangle();

	void draw();
	void update();
};