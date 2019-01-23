#include "Player.h"
#include "GameDirector.h"
#include "InputManager.h"
#include "Transform.h"

Player::Player(Object* entity)
	: IComponent(entity),
	m_inputManager(GameDirector::GetGameDirector().GetInputManager()),
	m_transform(GetEntity().GetComponent<Transform>()),
	m_time(0.0f),
	m_isClick(false) {}

void Player::Init() {}

void Player::Update() {
	if (m_isClick && m_time < 0.2f) {
		m_time += GetDeltaTime();
		return;
	}

	else if (m_isClick) {
		m_time = 0.0f;
		m_isClick = false;
	}

	if (m_inputManager.GetKey(InputManager::Key::Left)) {
		m_transform.SetPos(m_transform.GetPos().x - 100.0f, m_transform.GetPos().y);
		m_transform.SetAngle(90);
		m_isClick = true;
	}

	if (m_inputManager.GetKey(InputManager::Key::Right)) {
		m_transform.SetPos(m_transform.GetPos().x + 100.0f, m_transform.GetPos().y);
		m_transform.SetAngle(-90);
		m_isClick = true;
	}

	if (m_inputManager.GetKey(InputManager::Key::Up)) {
		m_transform.SetPos(m_transform.GetPos().x, m_transform.GetPos().y - 100.0f);
		m_transform.SetAngle(0);
		m_isClick = true;
	}

	if (m_inputManager.GetKey(InputManager::Key::Down)) {
		m_transform.SetPos(m_transform.GetPos().x, m_transform.GetPos().y + 100.0f);
		m_transform.SetAngle(180);
		m_isClick = true;
	}
}

void Player::Clear() {}