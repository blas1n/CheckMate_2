#include "InputManager.h"

bool InputManager::GetKey(Key key) const noexcept {
	return GetAsyncKeyState(static_cast<int>(key)) & 0x8000;
}

Utility::Vector2 InputManager::GetMousePos() const noexcept {
	return m_mousePos;
}

void InputManager::SetMousePos(Utility::Vector2 pos) noexcept {
	m_mousePos = pos;
}