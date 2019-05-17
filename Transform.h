#pragma once

#include "IComponent.h"
#include "Vector2.h"

class Transform : public IComponent {
	using Vector2 = Utility::Vector2;

private:
	Vector2 m_pos;
	Vector2 m_scale;
	float m_angle;

public:
	Transform(Object*, const Vector2& pos = Vector2(), const Vector2& scale = Vector2(), float angle = 0.0f);
	Transform(const Transform& transform);

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Clear() override;

public:
	const Utility::Vector2& GetPos() const noexcept;
	void SetPos(const Vector2& pos) noexcept;
	void SetPos(const float x, const float y) noexcept;

	const Utility::Vector2& GetScale() const noexcept;
	void SetScale(const Utility::Vector2& scale) noexcept;
	void SetScale(const float x, const float y) noexcept;

	const float& GetAngle() const noexcept;
	void SetAngle(const float angle) noexcept;
};