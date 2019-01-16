#pragma once

#include "stdafx.h"
#include <list>

class InputManager;
class Button;

class UiManager {
private:
	const InputManager& m_InputManager;
	mutable std::list<Button*> m_buttons;

public:
	UiManager();

public:
	void OnClick() const;
	void AddButton(Button*) const;
};

