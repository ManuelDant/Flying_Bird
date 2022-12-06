#include "score.h"

void DrawScore() {
	DrawText(TextFormat("Score: %02i", score), 10, 15, 40, RED);
}

void DrawMaxScore() {
	if (maxScore > 0)
	{
		DrawText(TextFormat("Max. Score: %02i", maxScore), GetScreenWidth() / 2 - 270, 30, 50, RED);
	}
}

void UpdateMaxScore() {
	if (score > maxScore)
	{
		maxScore = score;
	}
}

void RestartScore() {
	score = 0;
}

void AddScore(int Score) {
	score += Score;
}