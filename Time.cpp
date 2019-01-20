#include "Time.h"
#include <chrono>

float Time::GetDeltaTime() const noexcept {
	return m_deltaTime;
}

void Time::UpdateDeltaTime() noexcept {
	using namespace std::chrono;

	static auto prevTick = system_clock::now();

	duration<float> sec = system_clock::now() - prevTick;
	m_deltaTime = sec.count();

	prevTick = system_clock::now();
}