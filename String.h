#pragma once

#include "stdafx.h"
#include <gdiplus.h>
#include <string>

namespace std {
	using tstring = std::basic_string<TCHAR>;
}

struct TextInfo {
	std::tstring str;
	Gdiplus::Color color;
	std::shared_ptr<Gdiplus::Font> font;
	std::shared_ptr<Gdiplus::StringFormat> format;

	TextInfo()
		: str(TEXT("")),
		color(0, 0, 0),
		font(nullptr),
		format(nullptr) {}
};