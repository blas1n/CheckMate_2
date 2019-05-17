#pragma once

#include "IComponent.h"
#include "Vector2.h"

class IGui : public IComponent {
private:
	Utility::Vector2 m_size;

public:
	IGui(Object* entity)
		: IComponent(entity),
		m_size() {}

	virtual ~IGui() = default;

public:
	virtual void Init() override {}
	virtual void Update() override {}
	virtual void Clear() override {}

public:
	virtual void OnClick() = 0;

	const Utility::Vector2& GetSize() const noexcept {
		return m_size;
	}

	void SetSize(const Utility::Vector2& size) noexcept {
		m_size = size;
	}

	void SetSize(const float x, const float y) noexcept {
		m_size = Utility::Vector2(x, y);
	}
};