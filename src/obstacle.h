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

};

Obstacle CreateObstacle();
void MoveObstacle(Obstacle& Obstacle);