#include "InputManager.h"

bool InputManager::GetKey(Key key) const noexcept {
	return GetAsyncKeyState(static_cast<int>(key)) & 0x8000;
}

bool InputManager::GetAnyKey() const noexcept {
	return m_inputKeyNum > 0;
}

Utility::Vector2 InputManager::GetMousePos() const noexcept {
	return m_mousePos;
}

void InputManager::OnKeyDown() noexcept {
	m_inputKeyNum++;
}

void InputManager::OnKeyUp() noexcept {
	m_inputKeyNum--;
}

void InputManager::SetMousePos(Utility::Vector2 pos) noexcept {
	m_mousePos = pos;
}