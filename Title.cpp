#include "Title.h"
#include "GameDirector.h"
#include "SceneManager.h"

Title::Title(Object* entity)
	: IComponent(entity),
	m_inputManager(GameDirector::GetGameDirector().GetInputManager()) {}

void Title::Init() {}

void Title::Update() {
	if (m_inputManager.GetAnyKey())
		GameDirector::GetGameDirector().GetSceneManager().ReserveChangeScene("Home");
}

void Title::Clear() {}