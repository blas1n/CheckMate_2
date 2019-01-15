#include "Renderer.h"
#include "Transform.h"
#include "Object.h"

Renderer::Renderer(Object* entity)
	: IComponent(entity),
	m_transform(GetEntity().GetComponent<Transform>()),
	m_sprite() {}

void Renderer::Init() {}

void Renderer::Update() {
	m_sprite.Draw(m_transform.GetPos(), m_transform.GetScale(), m_transform.GetAngle());
}

void Renderer::Clear() {}

const Sprite& Renderer::GetSprite() const noexcept {
	return m_sprite;
}

bool Renderer::SetSprite(LPWSTR id) noexcept {
	return m_sprite.LoadSprite(id);
}