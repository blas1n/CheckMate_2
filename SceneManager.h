#pragma once

#include "stdafx.h"
#include "Scene.h"
#include <memory>
#include <string>
#include <map>

using std::string;

class SceneManager {
private:
	using PScene = std::shared_ptr<Scene>;

	std::map<string, PScene> m_sceneContainer;
	
	PScene m_reservedScene;
	PScene m_currentScene;

public:
	void RegisterScene(const string& sceneName) noexcept;
	void ReserveChangeScene(const string& sceneName);
	Scene& GetScene(const string& sceneName = "");

public:
	void Update();
};

