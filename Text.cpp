#include "Text.h"

void Text::Draw(const Utility::Vector2& pos, const Utility::Vector2& scale, const float& angle) const {
	GameDirector::GetGameDirector().GetRenderManager().RenderText(m_text, pos, scale, angle);
}

const std::tstring& Text::GetStr() const noexcept {
	return m_text.str;
}

const Gdiplus::Font& Text::GetFont() const noexcept {
	return *m_text.font;
}

const Gdiplus::Color& Text::GetColor() const noexcept {
	return m_text.color;
}

const Gdiplus::StringFormat& Text::GetFormat() const noexcept {
	return *m_text.format;
}

void Text::SetFont(const std::shared_ptr<Gdiplus::Font>& font) noexcept {
	m_text.font = font;
}

void Text::SetColor(const Gdiplus::Color& color) noexcept {
	m_text.color = color;
}

void Text::SetFormat(const std::shared_ptr<Gdiplus::StringFormat>& format) noexcept {
	m_text.format = format;
}