#include "Sprite.h"

Sprite::Sprite(const std::tstring& name)
	: m_pImage(nullptr),
	m_name(name) {}

Sprite::Sprite(const Sprite& other)
	: m_pImage(nullptr),
	m_name(other.m_name) {}

void Sprite::Draw(const Utility::Vector2& pos, const Utility::Vector2& scale, const float& angle) const {
	if (m_pImage != nullptr)
		GameDirector::GetGameDirector().GetRenderManager().RenderImage(m_pImage.get(), pos, scale, angle);
}

void Sprite::ReserveSprite(const std::tstring& name) noexcept {
	m_name = name;
}

void Sprite::LoadSprite() noexcept {
	if (m_name.compare(TEXT("")))
		m_pImage.reset(Gdiplus::Image::FromFile(m_name.c_str()));
}

void Sprite::UnloadSprite() noexcept {
	m_pImage.reset();
}