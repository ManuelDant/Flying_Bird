#include "timer.h"

void StartTimer(Timer* Timer, float lifetime)
{
    if (Timer != NULL)
        Timer->lifeTime = lifetime;
}

void UpdateTimer(Timer* Timer)
{
    if (Timer != NULL && Timer->lifeTime > 0)
        Timer->lifeTime -= GetFrameTime();
}

bool TimerDone(Timer* Timer)
{
    if (Timer != NULL)
        return Timer->lifeTime <= 0;

    return false;
}