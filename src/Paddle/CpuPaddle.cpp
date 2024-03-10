#include "CpuPaddle.hpp"

void CpuPaddle::update(int ball_y)
{
	if (y + height / 2 > ball_y && y > 0)
	{
		y -= speed;
	}
	if (y + height / 2 < ball_y && y + height < GetScreenHeight())
	{
		y += speed;
	}
}
