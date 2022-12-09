#pragma once
#include "raylib.h"

enum GameScene {
	Menu,
	Gameplay,
	Credits,
}static gamescene;

void StartGame();
void ScreenScene();
void GameplayScene();
void MenuScene();
void DrawMenu();
void CheckDefeat(bool isDefeat);
void DrawGame();
void Update();
void DrawVersion();
void RestartGame();
void CreditsScene();
void DrawCredits();
void DrawButtons();
void ActivatePause();




