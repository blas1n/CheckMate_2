#pragma once

#include "GameDirector.h"

class Time {
private:
	float m_deltaTime;
	
public:
	float GetDeltaTime() const noexcept;
	void UpdateDeltaTime() noexcept;
};

