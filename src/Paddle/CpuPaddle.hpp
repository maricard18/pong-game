#pragma once

#include <iostream>
#include "../../lib/lib.hpp"
#include "Paddle.hpp"

class CpuPaddle : public Paddle
{
public:
	using Paddle::Paddle;

	void update(int ball_y);
};