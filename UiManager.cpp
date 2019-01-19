#include "UiManager.h"
#include "Button.h"

void UiManager::UiLoop() noexcept {
	while (true) {
		while (IsEmpty()) {
			if (isEnd) return;
		}

		auto pos = Peak();
		Dequeue();

		for (auto& button : m_buttons) {
			if (!button->IsClick(pos)) continue;

			button->OnClick();
			break;
		}
	}
}

void UiManager::OnClick(const Utility::Vector2& pos) {
	Enqueue(pos);
}

void UiManager::AddButton(Button* pButton) {
	m_buttons.emplace_back(pButton);
}

void UiManager::End() {
	isEnd = true;
}

void UiManager::Enqueue(const Utility::Vector2& elem) {
	std::lock_guard<std::mutex> lock(m_mutex);
	m_waitingQueue.push(elem);
}

void UiManager::Dequeue() {
	std::lock_guard<std::mutex> lock(m_mutex);
	m_waitingQueue.pop();
}

bool UiManager::IsEmpty() {
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_waitingQueue.empty();
}

Utility::Vector2& UiManager::Peak() {
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_waitingQueue.front();
}