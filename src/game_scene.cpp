#include "game_scene.h"

#include <string>

#include "raylib.h"

#include "game.h"
#include "score.h"
#include "parallax_background.h"

namespace flying {
	static void MenuScene();
	static void GameplayScene();
	static void CreditsScene();
	static void DrawMenu();
	static void DrawCredits();
	static void DrawButtons();

	static GameScene gamescene;

	void ScreenScene() {
		switch (gamescene)
		{
		case Menu:
			SetExitKey(KEY_ESCAPE);
			MenuScene();
			break;
		case Gameplay:
			SetExitKey(NULL);
			GameplayScene();
			break;
		case Credits:
			SetExitKey(NULL);
			CreditsScene();
			break;
		default:
			break;
		}
	}
	void MenuScene() {
		DrawMenu();
	}

	void CreditsScene() {
		DrawCredits();
	}

	void GameplayScene() {
		Update();
		DrawGame();

		if (IsKeyPressed(KEY_ESCAPE))
		{
			ActivatePause();
		}

	}

	void DrawMenu() {
		BeginDrawing();
		ClearBackground(BLACK);
		RestartGame();
		RestartParallax();

		DrawBackgroundGame();
		DrawButtons();

		DrawText("Flying Bird", GetScreenWidth() / 2 - 162, GetScreenHeight() / 2 - 251, 70, BLACK);
		DrawText("Flying Bird", GetScreenWidth() / 2 - 160, GetScreenHeight() / 2 - 250, 70, WHITE);
		DrawText("Flying Bird", GetScreenWidth() / 2 - 158, GetScreenHeight() / 2 - 249, 70, RED);

		DrawText("Play", GetScreenWidth() / 2 - 30, GetScreenHeight() / 2 - 30, 50, BLACK);
		DrawText("Credits", GetScreenWidth() / 2 - 60, GetScreenHeight() / 2 + 175, 50, BLACK);
		DrawMaxScore();
		DrawVersion();

		EndDrawing();
	}

	void CheckDefeat(bool isDefeat) {
		if (isDefeat)
		{
			gamescene = GameScene::Menu;
		}
	}


	void DrawCredits() {
		BeginDrawing();
		ClearBackground(BLACK);

		DrawBackgroundGame();
		DrawText("Flying Bird Credits", GetScreenWidth() / 2 - 220, GetScreenHeight() / 2 - 200, 50, RED);
		DrawText("Flying Bird Credits", GetScreenWidth() / 2 - 219, GetScreenHeight() / 2 - 199, 50, BLACK);
		DrawText("Textures Made by Manuel Dantuono", GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 - 50, 40, BLACK);
		DrawText("Bird and Obstacles inspired by the game Flappy Bird", GetScreenWidth() / 2 - 500, GetScreenHeight() / 2 + 50, 40, BLACK);
		DrawText("Created with Raylib by Ray", GetScreenWidth() / 2 - 250, GetScreenHeight() / 2 + 280, 40, BLACK);


		if (IsKeyPressed(KEY_ESCAPE))
		{
			gamescene = GameScene::Menu;
		}

		DrawVersion();

		Rectangle mousePosition = { GetMousePosition().x, GetMousePosition().y, 1,1 };
		Rectangle back = { 50, static_cast<float>(GetScreenHeight() - 100), static_cast<float>(GetScreenWidth() / 16), static_cast<float>(GetScreenHeight() / 16) };
		Rectangle audio = { static_cast<float>(GetScreenWidth() / 2 - 100), static_cast<float>(GetScreenHeight() / 2 + 150), 200, 100 };

		std::string audioScore = " start https://www.epidemicsound.com/es/track/IPtGqTMW05/";

		DrawRectangleRec(back, WHITE);
		DrawRectangleRec(audio, WHITE);
		DrawText("Back", 60, GetScreenHeight() - 80, 25, BLACK);

		if (CheckCollisionRecs(mousePosition, back))
		{
			DrawRectangleRec(back, BLACK);
			DrawText("Back", 60, GetScreenHeight() - 80, 25, WHITE);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				gamescene = GameScene::Menu;
			}
		}

		if (CheckCollisionRecs(mousePosition, audio))
		{
			DrawRectangleRec(audio, BLACK);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				system(audioScore.c_str());
			}
		}
		DrawText("Audio", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 180, 40, BLACK);
		DrawText("Audio", GetScreenWidth() / 2 - 51, GetScreenHeight() / 2 + 181, 40, RED);

		EndDrawing();
	}

	void DrawButtons() {
		Rectangle mousePosition = { GetMousePosition().x, GetMousePosition().y, 1,1 };
		Rectangle play = { static_cast<float>(GetScreenWidth() / 2 - 100), static_cast<float>(GetScreenHeight() / 2 - 50), static_cast<float>(GetScreenWidth() / 5), static_cast<float>(GetScreenHeight() / 8) };
		Rectangle credits = { static_cast<float>(GetScreenWidth() / 2 - 100), static_cast<float>(GetScreenHeight() / 2 + 150), static_cast<float>(GetScreenWidth() / 5), static_cast<float>(GetScreenHeight() / 8) };

		DrawRectangleRec(play, WHITE);
		DrawRectangleRec(credits, WHITE);

		if (CheckCollisionRecs(mousePosition, play))
		{
			DrawRectangleRec(play, RED);
			DrawText("Play", GetScreenWidth() / 2 - 28, GetScreenHeight() / 2 - 30, 48, WHITE);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				gamescene = GameScene::Gameplay;
			}
		}

		if (CheckCollisionRecs(mousePosition, credits))
		{
			DrawRectangleRec(credits, RED);
			DrawText("Credits", GetScreenWidth() / 2 - 54, GetScreenHeight() / 2 + 175, 48, WHITE);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				gamescene = GameScene::Credits;
			}
		}
	}
}
