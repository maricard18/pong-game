#pragma once

#include <iostream>
#include <unistd.h>

#include "../lib/lib.h"
#include "./Ball/Ball.hpp"
#include "./Paddle/Paddle.hpp"
#include "./Paddle/CpuPaddle.hpp"

bool run_game(Ball &ball, Paddle &player, CpuPaddle &cpu);