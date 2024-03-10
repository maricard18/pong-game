#include "Ball.hpp"

Ball::Ball()
{
}

Ball::Ball(float x, float y, int speed_x, int speed_y, int radius, Color color)
{
	this->x = x;
	this->y = y;
	this->speed_x = speed_x;
	this->speed_y = speed_y;
	this->radius = radius;
	this->color = color;
}

void Ball::draw()
{
	DrawCircle(x, y, radius, color);
}

void Ball::update()
{
	x += speed_x;
	y += speed_y;

	if (x + radius >= GetScreenWidth() || x - radius <= 0)
	{
		speed_x *= -1;
	}
	if (y + radius >= GetScreenHeight() || y - radius <= 0)
	{
		speed_y *= -1;
	}

	if (x - radius <= 0)
	{
		cpu_score++;
		resetBall();
	}
	if (x + radius >= GetScreenWidth())
	{
		player_score++;
		resetBall();
	}
}

void Ball::resetBall()
{
	x = GetScreenWidth() / 2;
	y = GetScreenHeight() / 2;

	int speed_choices[2] = {-1, 1};
	speed_x = BALL_SPEED_X * speed_choices[GetRandomValue(0, 1)];
	speed_y = BALL_SPEED_Y * speed_choices[GetRandomValue(0, 1)];
}
