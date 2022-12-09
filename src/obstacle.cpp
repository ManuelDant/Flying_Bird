#include "obstacle.h"

Obstacle CreateObstacle() {
	int random;

	Obstacle obstacle{};
	obstacle.heightUp = static_cast<float>(GetScreenHeight() / 2 + 100);
	obstacle.widthUp = static_cast<float>(GetScreenWidth() / 12);
	obstacle.heightDown = static_cast<float>(GetScreenHeight() / 2 + 100);
	obstacle.widthDown = static_cast<float>(GetScreenWidth() / 12);

	random = GetRandomValue(static_cast<int>(0 - obstacle.heightDown), static_cast<int>(GetScreenHeight() / 2 - GetScreenHeight() / 2));

	obstacle.positionDown.y = static_cast<float>(random);
	obstacle.positionUp.y = obstacle.positionDown.y + GetScreenHeight();

	obstacle.positionUp.x = GetScreenWidth() / 2  - obstacle.widthUp;
	obstacle.positionDown.x = GetScreenWidth() / 2- obstacle.widthDown;

	obstacle.speed = 300;

	return obstacle;
}

void MoveObstacle(Obstacle Obstacle[]) {
	int random;

	for (int i = 0; i < maxObstacles; i++)
	{
		Obstacle[i].positionDown.x -= Obstacle[i].speed * GetFrameTime();
		Obstacle[i].positionUp.x -= Obstacle[i].speed * GetFrameTime();

		if (Obstacle[i].positionDown.x < 0 - Obstacle[i].widthDown)
		{
			Obstacle[i].positionDown.x = GetScreenWidth() + Obstacle[i].widthDown;
			Obstacle[i].positionUp.x = GetScreenWidth() + Obstacle[i].widthUp;

			random = GetRandomValue(static_cast<int>(0 - Obstacle[i].heightDown), static_cast<int>(GetScreenHeight() / 2 - GetScreenHeight() / 2));

			Obstacle[i].positionDown.y = static_cast<float>(random);
			Obstacle[i].positionUp.y = Obstacle[i].positionDown.y + GetScreenHeight();
		}
	}
	

}

void StartPositionObstacle(Obstacle Obstacle[]) {
	int startDistance = 650;

	for (int i = 0; i < maxObstacles; i++)
	{
		Obstacle[i].positionDown.x = static_cast<float>((i  * GetScreenWidth() / 3.5f) + startDistance);
		Obstacle[i].positionUp.x = static_cast<float>((i  * GetScreenWidth() / 3.5f) + startDistance);
	}

}