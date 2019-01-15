#include "Title.h"
#include "GameDirector.h"
#include "SceneManager.h"

Title::Title(Object* entity)
	: IComponent(entity),
	m_inputManager(GameDirector::GetGameDirector().GetInputManager()) {}

void Title::Init() {}

void Title::Update() {
	using Key = InputManager::Key;

	if (m_inputManager.GetKey(Key::Space))
		GameDirector::GetGameDirector().GetSceneManager().ReserveChangeScene("Home");
}

void Title::Clear() {}