#include "TextRenderer.h"
#include "Transform.h"
#include "Object.h"

TextRenderer::TextRenderer(Object* entity)
	: IComponent(entity),
	m_transform(GetEntity().GetComponent<Transform>()),
	m_text() {}

void TextRenderer::Init() {}

void TextRenderer::Update() {
	m_text.Draw(m_transform.GetPos());
}

void TextRenderer::Clear() {}

const Text& TextRenderer::GetText() const noexcept {
	return m_text;
}

void TextRenderer::SetFont(const std::shared_ptr<Gdiplus::Font>& font) {
	m_text.SetFont(font);
}
void TextRenderer::SetColor(const Gdiplus::Color& color) {
	m_text.SetColor(color);
}

void TextRenderer::SetFormat(const std::shared_ptr<Gdiplus::StringFormat>& format) {
	m_text.SetFormat(format);
}