#pragma once
#include "raylib.h"



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
static int betweenObstacles = 760;

Obstacle CreateObstacle();
void MoveObstacle(Obstacle Obstacle[]);
void StartPositionObstacle(Obstacle Obstacle[]);