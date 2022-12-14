#pragma once

namespace flying {
	enum GameScene {
		Menu,
		Gameplay,
		Credits,
	}static gamescene;

	void ScreenScene();
	void CheckDefeat(bool isDefeat);
	void DrawGame();
	void Update();
	void DrawVersion();
	void RestartGame();
	void ActivatePause();

}




