#pragma once

#include "stdafx.h"
#include "GameDirector.h"
#include "RenderManager.h"
#include "String.h"
#include "Vector2.h"

class Text {
private:
	TextInfo m_text;

public:
	void Draw(const Utility::Vector2& pos, const Utility::Vector2& scale, const float angle) const;

public:
	const std::tstring& GetStr() const noexcept;
	const Gdiplus::Font& GetFont() const noexcept;
	const Gdiplus::Color& GetColor() const noexcept;
	const Gdiplus::StringFormat& GetFormat() const noexcept;

	void SetStr(const std::tstring& str) noexcept;
	void SetStr(std::tstring&& str) noexcept;
	void SetFont(const std::shared_ptr<Gdiplus::Font>&) noexcept;
	void SetColor(const Gdiplus::Color&) noexcept;
	void SetFormat(const std::shared_ptr<Gdiplus::StringFormat>&) noexcept;
};

