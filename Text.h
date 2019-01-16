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
	void Draw(const Utility::Vector2&, const Utility::Vector2&, const float&) const;

public:
	const std::tstring& GetStr() const noexcept;
	const Gdiplus::Font& GetFont() const noexcept;
	const Gdiplus::Color& GetColor() const noexcept;
	const Gdiplus::StringFormat& GetFormat() const noexcept;

	template <class Str>
	void SetStr(Str&& str) noexcept {
		static_assert(std::is_constructible_v<std::tstring, Str>, "Unable to generate string with parameter.");
		m_text.str = std::forward<Str>(str);
	}

	void SetFont(const std::shared_ptr<Gdiplus::Font>&) noexcept;
	void SetColor(const Gdiplus::Color&) noexcept;
	void SetFormat(const std::shared_ptr<Gdiplus::StringFormat>&) noexcept;
};

