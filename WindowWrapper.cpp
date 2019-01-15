#include "WindowWrapper.h"
#include "SettingValue.h"
#include "Set.hpp"

void WindowWrapper::Init(HINSTANCE hInstance) {
	m_hInstance = hInstance;

	SettingValue value{};
	value.lpfnWndProc = WndProc;
	value.hInstance = hInstance;

	SettingWindow(value);

	RegisterWndClass(value);
	CreateWnd(value);
	ShowWnd(value);

	m_pInputManager = std::make_unique<InputManager>();
	m_pRenderManager = std::make_unique<RenderManager>(m_hWnd);

	RECT wndRect;
	GetClientRect(m_hWnd, &wndRect);
	m_pRenderManager->SetWndRect(wndRect);

	SetWindowLongPtr(m_hWnd, GWLP_USERDATA, reinterpret_cast<LONG>(this));
}

void WindowWrapper::Release() noexcept {
	DestroyWindow(m_hWnd);
}

int WindowWrapper::Run(HINSTANCE hInstance) {
	Init(hInstance);
	
	MSG msg;
	memset(&msg, 0, sizeof(msg));

	SettingGame();

	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
		}

		else Process();
	}

	Release();
	return static_cast<int>(msg.wParam);
}

LRESULT CALLBACK WindowWrapper::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	auto self = reinterpret_cast<WindowWrapper*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
	return (self) ? (self->RealWndProc(hWnd, msg, wParam, lParam)) : DefWindowProc(hWnd, msg, wParam, lParam);
}

LRESULT CALLBACK WindowWrapper::RealWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	HDC hDC;
	PAINTSTRUCT ps;
	RECT wndRect;
	
	switch (msg) {
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		m_pRenderManager->RenderOnScreen(hDC);
		EndPaint(hWnd, &ps);
		return 0;

	case WM_MOVE: case WM_SIZE:
		GetClientRect(hWnd, &wndRect);
		m_pRenderManager->SetWndRect(wndRect);
		return 0;

	case WM_MOUSEMOVE:
		m_pInputManager->SetMousePos(Utility::Vector2(LOWORD(lParam), HIWORD(lParam)));
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void WindowWrapper::RegisterWndClass(const SettingValue& value) {
	WNDCLASSEX wndClass;
	memset(&wndClass, 0, sizeof(wndClass));
	
	wndClass.cbSize = value.cbSize;
	wndClass.lpszClassName = value.lpszClassName;
	wndClass.lpszMenuName = value.lpszMenuName;
	wndClass.lpfnWndProc = value.lpfnWndProc;
	wndClass.hInstance = value.hInstance;
	wndClass.style = value.style;
	wndClass.hbrBackground = value.hbrBackground;
	wndClass.hCursor = value.hCursor;
	wndClass.hIcon = value.hIcon;
	wndClass.hIconSm = value.hIcon;

	RegisterClassEx(&wndClass);
}

void WindowWrapper::CreateWnd(const SettingValue& value) {
	m_hWnd = CreateWindow(value.lpszClassName, value.lpszMenuName, value.dwStyle,
		value.x, value.y, value.width, value.height, value.hWndParent, value.hMenu, value.hInstance, value.lpParam);
}

void WindowWrapper::ShowWnd(const SettingValue& value) {
	ShowWindow(m_hWnd, value.nCmdShow);
	UpdateWindow(m_hWnd);
}

const HINSTANCE WindowWrapper::GetHInstance() const noexcept {
	return m_hInstance;
}

const HWND WindowWrapper::GetHWnd() const noexcept {
	return m_hWnd;
}

const InputManager& WindowWrapper::GetInputManager() const noexcept {
	return *m_pInputManager;
}

const RenderManager& WindowWrapper::GetRenderManager() const noexcept {
	return *m_pRenderManager;
}

void WindowWrapper::BeginRender() {
	m_pRenderManager->BeginRender();
}

void WindowWrapper::EndRender() {
	m_pRenderManager->EndRender();
}