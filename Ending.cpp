#include "Ending.h"
#include "GameDirector.h"
#include "InputManager.h"
#include "SceneManager.h"

Ending::Ending(Object* entity)
	: IComponent(entity),
	m_inputManager(GameDirector::GetGameDirector().GetInputManager()) {}

void Ending::Init() {}

void Ending::Update() {
	if (m_inputManager.GetAnyKey())
		GameDirector::GetGameDirector().GetSceneManager().ReserveScene("Home");
}

void Ending::Clear() {}