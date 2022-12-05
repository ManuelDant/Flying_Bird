#include "obstacle.h"

int betweenObstacles = 650;

Obstacle CreateObstacle() {
	Obstacle obstacle{};
	obstacle.heightUp = static_cast<float>(GetScreenHeight() / 2);
	obstacle.widthUp = static_cast<float>(GetScreenWidth() / 12);
	obstacle.heightDown = static_cast<float>(GetScreenHeight() / 2);
	obstacle.widthDown = static_cast<float>(GetScreenWidth() / 12);

	obstacle.positionUp.x = obstacle.positionDown.x;
	obstacle.positionUp.y = obstacle.positionDown.y + betweenObstacles;

	obstacle.positionDown.x = static_cast<float>(GetScreenWidth() / 4);
	obstacle.positionDown.y = static_cast<float>(GetScreenHeight() / 20);

	obstacle.speed = 1000;

	return obstacle;
}

void MoveObstacle(Obstacle& Obstacle) {
	int random;

	Obstacle.positionDown.x -= Obstacle.speed * GetFrameTime();
	Obstacle.positionUp.x -= Obstacle.speed * GetFrameTime();

	if (Obstacle.positionDown.x < 0 - Obstacle.widthDown)
	{
		Obstacle.positionDown.x = GetScreenWidth() + Obstacle.widthDown;
		Obstacle.positionUp.x = GetScreenWidth() + Obstacle.widthUp;

		random = GetRandomValue(static_cast<int>(0 - Obstacle.heightDown / 2), static_cast<int>(GetScreenHeight() / 2 - betweenObstacles / 2));

		Obstacle.positionDown.y = static_cast<float>(random);
		Obstacle.positionUp.y = Obstacle.positionDown.y + betweenObstacles;
	}

}