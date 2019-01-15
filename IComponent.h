#pragma once

#include "GameDirector.h"
#include "Time.h"

class Object;

class IComponent {
private:
	Object* m_pEntity;

public:
	Object& GetEntity() const noexcept {
		return *m_pEntity;
	}

public:
	IComponent(Object* entity)
		: m_pEntity(entity) {}

	virtual ~IComponent() = default;

public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Clear() = 0;
};