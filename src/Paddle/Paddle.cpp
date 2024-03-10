#include "Paddle.hpp"

Paddle::Paddle()
{
}

Paddle::Paddle(float x, float y, float width, float height, int speed, Color color)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->speed = speed;
	this->color = color;
}

Rectangle Paddle::getRectangle()
{
	return Rectangle{x, y, width, height};
}

void Paddle::draw()
{
	DrawRectangle(x, y, width, height, color);
}

void Paddle::update()
{
	if (IsKeyDown(KEY_UP) && y >= 0)
	{
		y -= speed;
	}
	if (IsKeyDown(KEY_DOWN) && y + height <= GetScreenHeight())
	{
		y += speed;
	}
}
