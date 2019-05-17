#pragma once

#include "stdafx.h"
#include "Vector2.h"

class InputManager {
public:
	enum class Key {
		Backspace = 0x08, Tab, Enter = 0x0D, Escape = 0x1B, Space = 0x20,
		Left = 0x25, Up, Right, Down, LButton = 0x01, RButton, MButton = 0x04,
		Zero = 0x30, One, Two, Three, Four, Five, Six, Seven, Eight, Nine,
		A = 0x41, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
		LShift = 0xA0, RShift, LCtrl, RCtrl, LAlt, RAlt,
		Numpad0 = 0x60, Numpad1, Numpad2, Numpad3, Numpad4, Numpad5, Numpad6, Numpad7, Numpad8, Numpad9,
		F0 = 0x70, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12
	};

private:
	Utility::Vector2 m_mousePos;
	int m_inputKeyNum;

public:
	bool GetKey(Key key) const noexcept;
	bool GetAnyKey() const noexcept;
	Utility::Vector2 GetMousePos() const noexcept;
	
	void OnKeyDown() noexcept;
	void OnKeyUp() noexcept;

	void SetMousePos(Utility::Vector2 pos) noexcept;
};