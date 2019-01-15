#pragma once

#include "IComponent.h"
#include "Text.h"

class Transform;

class TextRenderer : public IComponent {
private:
	Text m_text;
	const Transform& m_transform;

public:
	TextRenderer(Object*);

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Clear() override;

public:
	const Text& GetText() const noexcept;

	template <class Str>
	void SetStr(Str&& str) {
		m_text.SetStr(std::forward<Str>(str));
	}

	void SetFont(const std::shared_ptr<Gdiplus::Font>&);
	void SetColor(const Gdiplus::Color&);
	void SetFormat(const std::shared_ptr<Gdiplus::StringFormat>&);
};

