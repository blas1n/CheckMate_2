#pragma once

#include "Math.h"

namespace Utility {

	struct Vector2 {
	public:
		float x, y;

	public:
		Vector2() = default;
		Vector2(const float, const float);

	public:
		void Set(const float, const float) noexcept;

	public:
		Vector2 operator+=(const Vector2&) noexcept;
		Vector2 operator-=(const Vector2&) noexcept;
		Vector2 operator*=(const float&) noexcept;
		Vector2 operator/=(const float&) noexcept;

	public:
		float GetLength() const noexcept;
		float GetSqrLength() const noexcept;

		Vector2 GetNormalize() const noexcept;
		Vector2& Normalize() noexcept;
	};

	Vector2 operator+(const Vector2&, const Vector2&);
	Vector2 operator-(const Vector2&, const Vector2&);
	Vector2 operator*(const Vector2&, const float&);
	Vector2 operator/(const Vector2&, const float&);

	bool operator==(const Vector2&, const Vector2&);
	bool operator!=(const Vector2&, const Vector2&);

	float Dot(const Vector2&, const Vector2&);

	Vector2 Max(const Vector2&, const Vector2&);
	Vector2 Min(const Vector2&, const Vector2&);

	float GetAngle(const Vector2&, const Vector2&);
	float GetDistance(const Vector2&, const Vector2&);
}