#pragma once

#include "stdafx.h"
#include "WindowWrapper.h"

class SceneManager;
class Time;

class GameDirector : public WindowWrapper {
private:
	std::unique_ptr<SceneManager> m_pSceneManager;
	std::unique_ptr<Time> m_pTime;
	DWORD m_frameInterval;

private:
	GameDirector();

public:
	virtual void Process() override;

public:
	static const GameDirector& GetGameDirector();
	SceneManager& GetSceneManager() const noexcept;
	const Time& GetTime() const noexcept;

	DWORD GetFrameInterval() const noexcept;
	void SetFrameInterval(DWORD) noexcept;
};