#pragma once

#include "GameDirector.h"
#include "Time.h"

class Object;

class IComponent {
private:
	const Object* m_pEntity;

protected:
	const Object& GetEntity() const noexcept {
		return *m_pEntity;
	}

public:
	IComponent(const Object* entity)
		: m_pEntity(entity) {}

	virtual ~IComponent() = default;

public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Clear() = 0;
};