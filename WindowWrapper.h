#pragma once

#include "stdafx.h"
#include "InputManager.h"
#include "RenderManager.h"

struct SettingValue;

class WindowWrapper {
private:
	HINSTANCE m_hInstance;
	HWND m_hWnd;

	std::unique_ptr<InputManager> m_pInputManager;
	std::unique_ptr<RenderManager> m_pRenderManager;

protected:
	WindowWrapper() = default;
	virtual ~WindowWrapper() = default;

public:
	int Run(HINSTANCE);

private:
	void Init(HINSTANCE);
	void Release() noexcept;

private:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK RealWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

protected:
	virtual void Process() = 0;

private:
	void RegisterWndClass(const SettingValue& value);
	void CreateWnd(const SettingValue& value);
	void ShowWnd(const SettingValue& value);

public:
	const HINSTANCE GetHInstance() const noexcept;
	const HWND GetHWnd() const noexcept;

	const InputManager& GetInputManager() const noexcept;
	const RenderManager& GetRenderManager() const noexcept;

protected:
	void BeginRender();
	void EndRender();
};