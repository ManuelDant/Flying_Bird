#pragma once
namespace flying {
	struct Timer {
		float lifeTime;
	};

	void StartTimer(Timer* Timer, float lifetime);
	void UpdateTimer(Timer* Timer);
	bool TimerDone(Timer* Timer);
}
