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

	DrawButtons();

	DrawText("Flying Bird", GetScreenWidth() / 2 - 160, GetScreenHeight() / 2 - 250, 70, WHITE);
	DrawText("Flying Bird", GetScreenWidth() / 2 - 158, GetScreenHeight() / 2 - 249, 70, GREEN);
	DrawText("Play", GetScreenWidth() / 2 - 30, GetScreenHeight() / 2 - 30, 50, BLACK);
	DrawText("Credits", GetScreenWidth() / 2 - 60, GetScreenHeight() / 2 + 175, 50, BLACK);
	
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

	DrawText("Flying Bird Credits", GetScreenWidth() / 2 - 220, GetScreenHeight() / 2 - 200, 50, WHITE);
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