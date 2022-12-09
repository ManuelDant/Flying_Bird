#include "parallax_background.h"

void LoadParallax() {
	floorTexture = LoadTexture("rsc/floorParallax.png");
	mountain = LoadTexture("rsc/mountainParallax.png");
	background = LoadTexture("rsc/backgroundParallax.png");

	floorTexture.width = GetScreenWidth();
	floorTexture.height = GetScreenWidth() / 16;
	mountain.width = GetScreenWidth() / 2;
	mountain.height = GetScreenHeight() / 2;
	background.width = GetScreenWidth();
	background.height = GetScreenHeight();
}

void UnloadParallax() {
	UnloadTexture(floorTexture);
	UnloadTexture(mountain);
	UnloadTexture(background);
}

void DrawBackgroundGame() {
	DrawBackgroundParallax();
	DrawMountainParallax();
	DrawFloorParallax();
}

void DrawFloorParallax() {
	DrawTextureEx(floorTexture, { scrollback, static_cast<float>(GetScreenHeight() - 50) }, 0, 2, WHITE);
	DrawTextureEx(floorTexture, { floorTexture.width * 2 + scrollback, static_cast<float>(GetScreenHeight() - 50) }, 0, 2, WHITE);
}

void DrawMountainParallax() {
	DrawTextureEx(mountain, { scrollbackMountain, 200 }, 0, 2, WHITE);
	DrawTextureEx(mountain, { mountain.width * 2 + scrollbackMountain, 200 }, 0, 2, WHITE);
}

void DrawBackgroundParallax() {
	DrawTextureEx(background, { scrollbackground, 0 }, 0, 2, WHITE);
	DrawTextureEx(background, { background.width * 2 + scrollbackground, 0 }, 0, 2, WHITE);
}

void UpdateParallax() {
	scrollback -= speedFloor * GetFrameTime();

	if (scrollback <= -floorTexture.width * 2) scrollback = 0;

	scrollbackMountain -= speedMountain * GetFrameTime();

	if (scrollbackMountain <= -mountain.width * 2) scrollbackMountain = 0;

	scrollbackground -= speedCity * GetFrameTime();

	if (scrollbackground <= -background.width * 2) scrollbackground = 0;
}

void RestartParallax() {
	scrollback = 0;
	scrollbackMountain = 0;
	scrollbackground = 0;
}