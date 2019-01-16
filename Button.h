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
	Button(Object*);

public:
	virtual void OnClick() override;
	bool IsClick(const Utility::Vector2&) const noexcept;
	void SetOnClick(const ClickFunc&) noexcept;
};

