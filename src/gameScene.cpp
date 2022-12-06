#include "gameScene.h"
#include "score.h"

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
	DrawGame();
	Update();
	if (IsKeyPressed(KEY_ESCAPE))
	{
		gamescene = GameScene::Menu;
	}
}

void DrawMenu() {
	BeginDrawing();
	ClearBackground(BLACK);
	RestartGame();
	DrawMaxScore();

	DrawText("Flying Bird Menu", GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 - 50, 50, WHITE);
	DrawText("(Space) to Start", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2, 20, WHITE);
	DrawText("(Enter) to Credits", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 + 50, 20, WHITE);
	

	if (IsKeyPressed(KEY_SPACE))
	{
		gamescene = GameScene::Gameplay;
	}

	if (IsKeyPressed(KEY_ENTER))
	{
		gamescene = GameScene::Credits;
	}
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

	DrawText("Flying Bird Credits", GetScreenWidth() / 2 - 250, GetScreenHeight() / 2 - 200, 50, WHITE);
	DrawText("Made by Manuel Dantuono", GetScreenWidth() / 2 - 130, GetScreenHeight() / 2 - 50, 20, WHITE);
	DrawText("Created with Raylib by Ray", GetScreenWidth() / 2 - 130, GetScreenHeight() / 2, 20, WHITE);
	DrawText("(Space) to back Menu", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 + 150, 20, WHITE);
	if (IsKeyPressed(KEY_SPACE))
	{
		gamescene = GameScene::Menu;
	}
	DrawVersion();

	EndDrawing();
}