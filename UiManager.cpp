#include "UiManager.h"
#include "GameDirector.h"
#include "InputManager.h"
#include "Button.h"
#include "Vector2.h"

UiManager::UiManager()
	: m_InputManager(GameDirector::GetGameDirector().GetInputManager()) {}

void UiManager::OnClick() const {
	auto pos = m_InputManager.GetMousePos();

	for (auto& button : m_buttons) {
		if (!button->IsClick(pos)) continue;

		button->OnClick();
		break;
	}
}

void UiManager::AddButton(Button* pButton) const {
	m_buttons.emplace_back(pButton);
}