#include "player.h"

Player CreatePlayer() {
	Player player{};
	player.height = static_cast<float>(GetScreenHeight() / 14);
	player.width = static_cast<float>(GetScreenWidth() / 17);

	player.position.x = static_cast<float>(GetScreenWidth() / 15);
	player.position.y = static_cast<float>(GetScreenHeight() / 2);

	player.isJump = false;

	player.jumpTimer = 0.15f;
	player.speedJump = 700;


	return player;
}

void PlayerInput(Player& Player) {
	
	if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) && !Player.isJump)
	{
		Player.isJump = true;
		StartTimer(&Player.jump, Player.jumpTimer);
	}	
	UpdateTimer(&Player.jump);
}

void MovePlayer(Player& Player) {	
	if (Player.isJump)
	{	
		if (!TimerDone(&Player.jump))
		{
			Player.position.y -= Player.speedJump * GetFrameTime();
		}

		if (TimerDone(&Player.jump))
		{
			Player.isJump = false;
		}
	
	}
	else
	{
			Player.position.y += Player.speedJump * GetFrameTime();
			if (Player.position.y > static_cast<float>(GetScreenHeight() - 100))
			{
				Player.position.y = static_cast<float>(GetScreenHeight() - 100);
			}		
	}
}

void StartPositionPlayer(Player& Player) {
	Player.position.x = static_cast<float>(GetScreenWidth() / 15);
	Player.position.y = static_cast<float>(GetScreenHeight() / 2);
}
	
