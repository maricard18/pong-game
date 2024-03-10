#include "main.hpp"

void CheckPlayerCollision(Ball &ball, Paddle &player)
{
	if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, player.getRectangle()))
	{
		if (ball.speed_x < 0)
		{
			ball.speed_x *= -1.05;
			ball.speed_y = (ball.y - player.y) / (player.height / 2) * ball.speed_x;
		}
	}
}

void CheckCpuCollision(Ball &ball, CpuPaddle &cpu)
{
	if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, cpu.getRectangle()))
	{
		if (ball.speed_x > 0)
		{
			ball.speed_x *= -1.05;
			ball.speed_y = (ball.y - cpu.y) / (cpu.height / 2) * (-ball.speed_x);
		}
	}
}

bool run_game(Ball &ball, Paddle &player, CpuPaddle &cpu)
{
	ClearBackground(BLACK);
	DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), YELLOW);

	ball.update();
	player.update();
	cpu.update(ball.y);

	CheckPlayerCollision(ball, player);
	CheckCpuCollision(ball, cpu);

	ball.draw();
	player.draw();
	cpu.draw();

	DrawText(TextFormat("%i", ball.player_score), GetScreenWidth() / 2 - 100, 25, 80, WHITE);
	DrawText(TextFormat("%i", ball.cpu_score), GetScreenWidth() / 2 + 60, 25, 80, WHITE);

	if (ball.player_score == MAX_SCORE)
	{
		DrawText("GAME OVER", GetScreenWidth() / 2 + 170, GetScreenHeight() / 2 - 20, 50, RED);
		EndDrawing();

		return false;
	}
	else if (ball.cpu_score == MAX_SCORE)
	{
		DrawText("GAME OVER", 170, GetScreenHeight() / 2 - 20, 50, RED);
		EndDrawing();

		return false;
	}

	return true;
}