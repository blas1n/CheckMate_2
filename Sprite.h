#pragma once

#include "stdafx.h"
#include "GameDirector.h"
#include "RenderManager.h"
#include "Vector2.h"
#include "String.h"

class Sprite {
private:
	std::unique_ptr<Gdiplus::Image> m_pImage;
	std::tstring m_name;

public:
	explicit Sprite(const std::tstring& = TEXT(""));
	Sprite(const Sprite&);

public:
	void Draw(const Utility::Vector2& pos, const Utility::Vector2& scale, const float angle) const;

public:
	void ReserveSprite(const std::tstring& name) noexcept;
	void LoadSprite() noexcept;
	void UnloadSprite() noexcept;
};