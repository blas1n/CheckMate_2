#include "GameDirector.h"
#include "SceneManager.h"
#include "Time.h"

GameDirector::GameDirector()
	: m_pSceneManager(std::make_unique<SceneManager>()),
	m_frameInterval(10) {}

void GameDirector::Process() {
	static auto prevFrameTime = static_cast<DWORD>(0);

	if (GetTickCount() - prevFrameTime <= m_frameInterval) return;

	Time::SetDeltaTime(static_cast<float>(GetTickCount() - prevFrameTime) * 0.001f);

	BeginRender();
	m_pSceneManager->Update();
	EndRender();

	prevFrameTime = GetTickCount();
}

const GameDirector& GameDirector::GetGameDirector() {
	static GameDirector director;
	return director;
}

SceneManager& GameDirector::GetSceneManager() const noexcept {
	return *m_pSceneManager;
}

DWORD GameDirector::GetFrameInterval() const noexcept {
	return m_frameInterval;
}

void GameDirector::SetFrameInterval(DWORD frameInterval) noexcept {
	m_frameInterval = frameInterval;
}