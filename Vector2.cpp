#include "Vector2.h"

namespace Utility {

	Vector2::Vector2(const float& _x, const float& _y)
		: x(_x), y(_y) {}

	void Vector2::Set(const float& x, const float& y) noexcept {
		this->x = x;
		this->y = y;
	}

	Vector2 Vector2::operator+=(const Vector2& rhs) noexcept {
		return (*this = *this + rhs);
	}

	Vector2 Vector2::operator-=(const Vector2& rhs) noexcept {
		return (*this = *this - rhs);
	}

	Vector2 Vector2::operator*=(const float& rhs) noexcept {
		return (*this = *this * rhs);
	}

	Vector2 Vector2::operator/=(const float& rhs) noexcept {
		return (*this = *this / rhs);
	}

	float Vector2::GetLength() const noexcept {
		return std::sqrtf(x * x + y * y);
	}

	float Vector2::GetSqrLength() const noexcept {
		return x * x + y * y;
	}

	Vector2 Vector2::GetNormalize() const noexcept {
		return (*this / GetLength());
	}

	Vector2& Vector2::Normalize() noexcept {
		*this /= GetLength();
		return *this;
	}

	Vector2 operator+(const Vector2& lhs, const Vector2& rhs) {
		return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
	}

	Vector2 operator-(const Vector2& lhs, const Vector2& rhs) {
		return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
	}

	Vector2 operator*(const Vector2& lhs, const float& rhs) {
		return Vector2(lhs.x * rhs, lhs.x * rhs);
	}

	Vector2 operator/(const Vector2& lhs, const float& rhs) {
		return Vector2(lhs.x / rhs, lhs.y / rhs);
	}

	bool operator==(const Vector2& lhs, const Vector2& rhs) {
		return (lhs.x == rhs.x) && (lhs.y == rhs.y);
	}

	bool operator!=(const Vector2& lhs, const Vector2& rhs) {
		return !(lhs == rhs);
	}

	float Dot(const Vector2& lhs, const Vector2& rhs) {
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}

	Vector2 Max(const Vector2& lhs, const Vector2& rhs) {
		return (lhs.x - rhs.x) + (lhs.y - rhs.y) > 0 ? lhs : rhs;
	}

	Vector2 Min(const Vector2& lhs, const Vector2& rhs) {
		return Max(lhs, rhs) == rhs ? lhs : rhs;
	}

	float GetAngle(const Vector2& lhs, const Vector2& rhs) {
		return std::Rad2Deg(std::acosf(Dot(lhs.GetNormalize(), rhs.GetNormalize())));
	}

	float GetDistance(const Vector2& lhs, const Vector2& rhs) {
		return (lhs - rhs).GetLength();
	}

}