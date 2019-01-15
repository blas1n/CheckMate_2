#pragma once

#include "Object.h"
#include "Sprite.h"
#include "Renderer.h"
#include "IComponent.h"

class InputManager;
class Transform;

class Player : public IComponent {
private:
	const InputManager& m_inputManager;
	Transform& m_transform;

public:
	Player(Object*);

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Clear() override;
};

