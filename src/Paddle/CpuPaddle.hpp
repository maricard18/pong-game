#pragma once

#include <iostream>
#include "../../lib/lib.h"
#include "Paddle.hpp"

class CpuPaddle : public Paddle
{
public:
	using Paddle::Paddle;

	void update(int ball_y);
};