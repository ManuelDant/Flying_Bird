#include "player.h"

Player CreatePlayer() {
	Player player{};
	player.height = static_cast<float>(GetScreenHeight() / 9);
	player.width = static_cast<float>(GetScreenWidth() / 16);

	player.position.x = static_cast<float>(GetScreenWidth() / 15);
	player.position.y = static_cast<float>(GetScreenHeight() - 150);

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
			if (Player.position.y > static_cast<float>(GetScreenHeight() - 150))
			{
				Player.position.y = static_cast<float>(GetScreenHeight() - 150);
			}		
	}
}
	
