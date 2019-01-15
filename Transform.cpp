#include "Transform.h"
#include "GameDirector.h"

Transform::Transform(const Object* entity, const Utility::Vector2 pos, const Utility::Vector2 scale, const float angle)
	: IComponent(entity),
	m_pos(pos),
	m_scale(scale),
	m_angle(angle) {}

void Transform::Init() {}

void Transform::Update() {}

void Transform::Clear() {}

const Utility::Vector2 Transform::GetPos() const noexcept {
	return m_pos;
}

void Transform::SetPos(const Utility::Vector2 pos) noexcept {
	m_pos = pos;
}

void Transform::SetPos(const float x, const float y) noexcept {
	m_pos.Set(x, y);
}

const Utility::Vector2 Transform::GetScale() const noexcept {
	return m_scale;
}

void Transform::SetScale(const Utility::Vector2 scale) noexcept {
	m_scale = scale;
}

void Transform::SetScale(const float x , const float y) noexcept {
	m_scale.Set(x, y);
}

const float Transform::GetAngle() const noexcept {
	return m_angle;
}

void Transform::SetAngle(const float angle) noexcept {
	m_angle = angle;
}