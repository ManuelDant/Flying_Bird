#pragma once
#include "timer.h"

#include "raylib.h"

namespace flying {
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
	void StartPositionPlayer(Player& Player);
}
