#pragma once

#include "GameDirector.h"

class Time {
	friend void GameDirector::Process();

private:
	static float m_deltaTime;
	static void SetDeltaTime(float);

public:
	static float GetDeltaTime();
};

