#pragma once

#include <list>
#include <string>
#include <memory>
#include "IComponent.h"
#include "Vector2.h"

class Object {
private:
	using ComponentList = std::list<std::shared_ptr<IComponent>>;

	std::string m_name;
	ComponentList m_components;

public:
	Object(std::string, const Utility::Vector2 = Utility::Vector2(), const Utility::Vector2 = Utility::Vector2(1, 1), const float = 0);
	virtual ~Object() = default;

public:
	void Init();
	void Update();
	void Clear();

public:
	const std::string& GetName() const noexcept;

	template <class ComponentType>
	ComponentType& GetComponent() const {
		static_assert(std::is_base_of<IComponent, ComponentType>::value, "ComponentType is not Component");

		for (auto& iter : m_components)
			if (dynamic_cast<ComponentType*>(iter.get()))
				return *(static_cast<ComponentType*>(iter.get()));

		throw;
	}

	template <class ComponentType>
	ComponentType& AddComponent() {
		static_assert(std::is_base_of<IComponent, ComponentType>::value, "ComponentType is not Component");

		m_components.emplace_back(std::unique_ptr<ComponentType>(new ComponentType(this)));
		return *(static_cast<ComponentType*>(m_components.back().get()));
	}
};