#pragma once

#include "Vector2.h"
#include <mutex>
#include <queue>
#include <list>

class Button;

class UiManager {
private:
	std::queue<Utility::Vector2> m_waitingQueue;
	std::list<Button*> m_buttons;
	bool m_isEnd;

	std::condition_variable cv;
	std::mutex m_uiMutex;
	std::mutex m_buttonMutex;

public:
	void UiLoop() noexcept;

public:
	void OnClick(const Utility::Vector2&);
	void AddButton(Button*);

public:
	void End();
};

