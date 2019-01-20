#pragma once

#include <functional>

class Object;

class IComponent {
private:
	Object* m_pEntity;

public:
	IComponent(Object* entity);
	virtual ~IComponent() = default;

public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Clear() = 0;

public:
	Object& GetEntity() const noexcept;

protected:
	float GetDeltaTime();
};