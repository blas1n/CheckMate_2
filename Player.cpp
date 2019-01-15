#include "Player.h"
#include "InputManager.h"
#include "Transform.h"

Player::Player(Object* entity)
	: IComponent(entity),
	m_inputManager(GameDirector::GetGameDirector().GetInputManager()),
	m_transform(GetEntity().GetComponent<Transform>()) {}

void Player::Init() {}

void Player::Update() {
	m_transform.SetAngle(m_transform.GetAngle() + (100 * Time::GetDeltaTime()));

	if (m_inputManager.GetKey(InputManager::Key::LButton))
		m_transform.SetPos(m_inputManager.GetMousePos());

	if (m_inputManager.GetKey(InputManager::Key::Left))
		m_transform.SetPos(m_transform.GetPos().x - (300.0f * Time::GetDeltaTime()), m_transform.GetPos().y);

	if (m_inputManager.GetKey(InputManager::Key::Right))
		m_transform.SetPos(m_transform.GetPos().x + (300.0f * Time::GetDeltaTime()), m_transform.GetPos().y);

	if (m_inputManager.GetKey(InputManager::Key::Up))
		m_transform.SetPos(m_transform.GetPos().x, m_transform.GetPos().y - (300.0f * Time::GetDeltaTime()));

	if (m_inputManager.GetKey(InputManager::Key::Down))
		m_transform.SetPos(m_transform.GetPos().x, m_transform.GetPos().y + (300.0f * Time::GetDeltaTime()));
}

void Player::Clear() {}