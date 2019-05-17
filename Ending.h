#pragma once

#include "IComponent.h"
#include "Object.h"

class InputManager;

class Ending : public IComponent {
private:
	const InputManager& m_inputManager;

public:
	Ending(Object* entity);

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Clear() override;
};

