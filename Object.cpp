#include "stdafx.h"
#include "Object.h"
#include "Transform.h"

Object::Object(std::tstring name, const Utility::Vector2 pos, const Utility::Vector2 scale, const float angle)
	: m_name(name),
	m_components() {

	m_transform = std::make_unique<Transform>(this);
	m_transform->SetPos(pos);
	m_transform->SetScale(scale);
	m_transform->SetAngle(angle);
}

Object::Object(const Object& object)
	: m_name(object.m_name),
	m_transform(new Transform(*object.m_transform)),
	m_components(object.m_components) {}

void Object::Init() {
	for (auto iter : m_components)
		iter->Init();
}

void Object::Update() {
	for (auto iter : m_components)
		iter->Update();
}

void Object::Clear() {
	for (auto iter : m_components)
		iter->Clear();
}

const std::tstring& Object::GetName() const noexcept {
	return m_name;
}