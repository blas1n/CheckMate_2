#include "stdafx.h"
#include "Object.h"
#include "Transform.h"

Object::Object(std::string name, const Utility::Vector2 pos, const Utility::Vector2 scale, const float angle)
	: m_name(name),
	m_components() {

	auto& transform = AddComponent<Transform>();
	transform.SetPos(pos);
	transform.SetScale(scale);
	transform.SetAngle(angle);
}

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

const std::string& Object::GetName() const noexcept {
	return m_name;
}