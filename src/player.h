#pragma once
#include "raylib.h"
#include "timer.h"

struct Player {
	Vector2 position;
	float width;
	float height;

	bool isJump;
	Timer jump;
	float jumpTimer;
	float speedJump;
};

Player CreatePlayer();
void PlayerInput(Player& Player);
void MovePlayer(Player& Player);