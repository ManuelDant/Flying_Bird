#pragma once
#include "raylib.h"

namespace flying {
	struct Obstacle {
		Vector2 positionUp;
		Vector2 positionDown;
		float widthUp;
		float widthDown;

		float heightDown;
		float heightUp;

		float speed;

		int checkAddScore = 0;
	};

	static const int maxObstacles = 4;

	Obstacle CreateObstacle();
	void MoveObstacle(Obstacle Obstacle[]);
	void StartPositionObstacle(Obstacle Obstacle[]);
}

