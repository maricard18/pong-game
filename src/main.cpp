#include "main.hpp"

const int screenWidth = 1280;
const int screenHeight = 800;

int main(void)
{
	InitWindow(screenWidth, screenHeight, "Pong Game");
	SetTargetFPS(60);

	Ball ball(screenWidth / 2, screenHeight / 2, BALL_SPEED_X, BALL_SPEED_Y, 10, YELLOW);
	Paddle player(25, screenHeight / 2 - 60, 25, 120, 7, WHITE);
	CpuPaddle cpu(screenWidth - 50, screenHeight / 2 - 60, 25, 120, 7, WHITE);

	while (!WindowShouldClose())
	{
		BeginDrawing();

		if (!run_game(ball, player, cpu))
		{
			WaitTime(3);
			break;
		}

		EndDrawing();
	}

	CloseWindow();
	return 0;
}