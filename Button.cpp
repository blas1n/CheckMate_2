#include "Button.h"
#include "Transform.h"

Button::Button(Object* entity)
	: IGui(entity),
	m_transform(GetEntity().GetComponent<Transform>()) {

	GameDirector::GetGameDirector().GetUiManager().AddButton(this);
}

void Button::OnClick() {
	m_onClick();
}

bool Button::IsClick(const Utility::Vector2& pos) const noexcept {
	const auto& myPos = m_transform.GetPos();
	const auto halfSize = GetSize() / 2;

	return (pos.x > myPos.x - halfSize.x) && (pos.x < myPos.x + halfSize.x) &&
		(pos.y > myPos.y - halfSize.y) && (pos.y < myPos.y + halfSize.y);
}

void Button::SetOnClick(const ClickFunc& onClick) noexcept {
	m_onClick = onClick;
}