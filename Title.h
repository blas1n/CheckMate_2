#pragma once

#include "IComponent.h"

class InputManager;

class Title : public IComponent {
private:
	const InputManager& m_inputManager;

public:
	Title(Object*);

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Clear() override;
};

