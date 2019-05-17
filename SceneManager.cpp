#include "stdafx.h"
#include "SceneManager.h"

void SceneManager::RegisterScene(const string& sceneName) noexcept {
	if (sceneName.compare("") && m_sceneContainer.find(sceneName) == m_sceneContainer.end())
		m_sceneContainer.emplace(std::make_pair(sceneName, std::make_shared<Scene>()));
}

void SceneManager::ReserveScene(const string& sceneName) {
	auto iter = m_sceneContainer.find(sceneName);

	if (iter != m_sceneContainer.end())
		m_reservedScene = iter->second;

	else throw;
}

Scene& SceneManager::GetScene() {
	return *m_currentScene;
}

Scene& SceneManager::GetScene(const string& sceneName) {
	auto iter = m_sceneContainer.find(sceneName);

	if (iter == m_sceneContainer.end())
		throw;

	return *(iter->second);
}

void SceneManager::Update() {
	if (m_reservedScene) {
		if (m_currentScene)
			m_currentScene->Clear();

		m_reservedScene->Init();
		m_currentScene = std::move(m_reservedScene);
	}

	if (m_currentScene)
		m_currentScene->Update();
}
