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
	std::mutex m_mutex;
	bool isEnd;

public:
	void UiLoop() noexcept;

public:
	void OnClick(const Utility::Vector2&);
	void AddButton(Button*);

public:
	void End();

private:
	void Enqueue(const Utility::Vector2&);
	void Dequeue();
	bool IsEmpty();
	Utility::Vector2& Peak();
};

