#include "UiManager.h"
#include "Button.h"

void UiManager::UiLoop() noexcept {
	Utility::Vector2 pos;

	while (true) {
		{
			std::unique_lock<std::mutex> lock(m_uiMutex);
			cv.wait(lock, [this] { return (m_isEnd || !m_waitingQueue.empty()); });

			if (m_isEnd) return;

			pos = m_waitingQueue.front();
			m_waitingQueue.pop();
		}

		std::lock_guard<std::mutex> lock(m_buttonMutex);

		for (auto& button : m_buttons) {
			if (!button->IsClick(pos)) continue;

			button->OnClick();
			break;
		}
	}
}

void UiManager::OnClick(const Utility::Vector2& pos) {
	{
		std::lock_guard<std::mutex> lock(m_uiMutex);
		m_waitingQueue.push(pos);
	}

	cv.notify_one();
}

void UiManager::AddButton(Button* pButton) {
	std::lock_guard<std::mutex> lock(m_buttonMutex);
	m_buttons.emplace_back(pButton);
}

void UiManager::End() {
	{
		std::lock_guard<std::mutex> lock(m_uiMutex);
		m_isEnd = true;
	}

	cv.notify_all();
}