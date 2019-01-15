#include "Time.h"

float Time::GetDeltaTime() {
	return m_deltaTime;
}

void Time::SetDeltaTime(float deltaTime){
	m_deltaTime = deltaTime;
}

float Time::m_deltaTime = 0.0f;