#pragma once

#include <iostream>
#include <unistd.h>

#include "./lib/lib.h"
#include "./src/Ball/Ball.hpp"
#include "./src/Paddle/Paddle.hpp"
#include "./src/Paddle/CpuPaddle.hpp"

bool run_game(Ball &ball, Paddle &player, CpuPaddle &cpu);