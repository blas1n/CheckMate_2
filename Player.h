#pragma once

#include "IComponent.h"
#include "Object.h"

class InputManager;
class Transform;

class Player : public IComponent {
private:
	const InputManager& m_inputManager;
	Transform& m_transform;
	
	float m_time;
	bool m_isClick;

public:
	Player(Object* entity);

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Clear() override;
};

