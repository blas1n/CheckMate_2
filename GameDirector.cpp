#include "GameDirector.h"
#include "SceneManager.h"
#include "Time.h"

GameDirector::GameDirector()
	: WindowWrapper(),
	m_pSceneManager(std::make_unique<SceneManager>()),
	m_pTime(std::make_unique<Time>()) {}

void GameDirector::Process() {
	m_pTime->UpdateDeltaTime();

	BeginRender();
	m_pSceneManager->Update();
	EndRender();
}

const GameDirector& GameDirector::GetGameDirector() {
	static GameDirector director;
	return director;
}

SceneManager& GameDirector::GetSceneManager() const noexcept {
	return *m_pSceneManager;
}

const Time& GameDirector::GetTime() const noexcept {
	return *m_pTime;
}