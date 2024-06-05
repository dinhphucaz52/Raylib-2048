#include "Game.h"

int main()
{

	InitWindow(SCREEN_WITH, SCREEN_HEIGHT, "2048 With Raylib");
	SetTargetFPS(60);

	Game game;

	Font font = LoadFontEx("utm_bebas.ttf", 150, 0, 0);

	while (!WindowShouldClose())
	{
		game.handleInput();
		BeginDrawing();
		ClearBackground(GAME_BACKGROUND);
		//Start Drawing

		if (game.gameOver == true)
		{
			DrawTextEx(
				font,
				"GAME OVER",
				{ 100, 100 },
				font.baseSize + 0.0f, 2, LIME
			);
		}
		else {
			game.start();
		}
		game.checkContinue();
		//End Drawing
		EndDrawing();
	}
	return 0;
}