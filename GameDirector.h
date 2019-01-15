#pragma once

#include "stdafx.h"
#include "WindowWrapper.h"

class SceneManager;

class GameDirector : public WindowWrapper {
private:
	std::unique_ptr<SceneManager> m_pSceneManager;
	DWORD m_frameInterval;

private:
	GameDirector();

public:
	virtual void Process() override;

public:
	static const GameDirector& GetGameDirector();
	SceneManager& GetSceneManager() const noexcept;

	DWORD GetFrameInterval() const noexcept;
	void SetFrameInterval(DWORD) noexcept;
};