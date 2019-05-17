#pragma once

#include "IGui.h"
#include "Object.h"
#include <functional>

class Transform;

class Button : public IGui {
public:
	using ClickFunc = std::function<void()>;

private:
	Transform& m_transform;
	ClickFunc m_onClick;

public:
	Button(Object* entity);

public:
	virtual void OnClick() override;
	bool IsClick(const Utility::Vector2& pos) const noexcept;
	void SetOnClick(const ClickFunc& onClick) noexcept;
};

