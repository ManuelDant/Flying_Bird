#pragma once
#include "raylib.h"

static int score = 0;
static int maxScore = 0;



void DrawScore();
void DrawMaxScore();
void RestartScore();
void UpdateMaxScore();
void AddScore(int Score);


