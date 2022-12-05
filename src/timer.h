#pragma once
#include "raylib.h"

struct Timer {
	float lifeTime;
};

void StartTimer(Timer* Timer, float lifetime);
void UpdateTimer(Timer* Timer);
bool TimerDone(Timer* Timer);