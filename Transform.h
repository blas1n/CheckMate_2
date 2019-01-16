#pragma once

#include "IComponent.h"
#include "Vector2.h"

class Transform : public IComponent {
private:
	Utility::Vector2 m_pos;
	Utility::Vector2 m_scale;
	float m_angle;

public:
	Transform(Object*, const Utility::Vector2 = Utility::Vector2(), const Utility::Vector2 = Utility::Vector2(1.0f, 1.0f), const float = 0.0f);

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Clear() override;

public:
	const Utility::Vector2& GetPos() const noexcept;
	void SetPos(const Utility::Vector2&) noexcept;
	void SetPos(const float&, const float&) noexcept;

	const Utility::Vector2& GetScale() const noexcept;
	void SetScale(const Utility::Vector2&) noexcept;
	void SetScale(const float&, const float&) noexcept;

	const float& GetAngle() const noexcept;
	void SetAngle(const float&) noexcept;
};