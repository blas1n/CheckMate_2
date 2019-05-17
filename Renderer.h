#pragma once

#include "IComponent.h"
#include "Sprite.h"

class Transform;

class Renderer : public IComponent {
private:
	Sprite m_sprite;
	const Transform& m_transform;

public:
	Renderer(Object* entity);
	Renderer(Object* entity, const std::tstring& id);

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Clear() override;

public:
	const Sprite& GetSprite() const noexcept;
	void SetSprite(const std::tstring& id) noexcept;
};