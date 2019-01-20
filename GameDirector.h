#pragma once

#include "stdafx.h"
#include "WindowWrapper.h"

class SceneManager;
class Time;

class GameDirector : public WindowWrapper {
private:
	std::unique_ptr<SceneManager> m_pSceneManager;
	std::unique_ptr<Time> m_pTime;

private:
	GameDirector();

public:
	virtual void Process() override;

public:
	static const GameDirector& GetGameDirector();
	SceneManager& GetSceneManager() const noexcept;
	const Time& GetTime() const noexcept;
};