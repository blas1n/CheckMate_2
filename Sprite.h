#pragma once

#include "stdafx.h"
#include "GameDirector.h"
#include "RenderManager.h"
#include "Vector2.h"

class Sprite {
private:
	std::unique_ptr<Gdiplus::Bitmap> m_pBitmap;
	LPWSTR m_name;

public:
	Sprite() = default;
	Sprite(const LPWSTR&);
	Sprite(const Sprite&);

public:
	void Draw(const Utility::Vector2&, const Utility::Vector2&, const float&) const;

public:
	void ReserveSprite(const LPWSTR& name) noexcept;
	bool LoadSprite() noexcept;
	void UnloadSprite() noexcept;

	LPWSTR GetName() const noexcept;
	bool Empty() const noexcept;
};