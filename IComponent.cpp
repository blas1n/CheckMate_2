#include "IComponent.h"
#include "GameDirector.h"
#include "Time.h"

IComponent::IComponent(Object* entity)
	: m_pEntity(entity) {}

Object& IComponent::GetEntity() const noexcept {
	return *m_pEntity;
}

float IComponent::GetDeltaTime() {
	return GameDirector::GetGameDirector().GetTime().GetDeltaTime();
}