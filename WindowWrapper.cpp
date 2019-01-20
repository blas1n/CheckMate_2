#include "WindowWrapper.h"
#include "SettingValue.h"
#include "GameEntry.h"

WindowWrapper* WindowWrapper::self = nullptr;

void WindowWrapper::Init(HINSTANCE hInstance) {
	m_hInstance = hInstance;

	SettingValue value(WndProc, hInstance);

	RegisterWndClass(value);
	CreateWnd(value);
	ShowWnd(value);

	m_pInputManager = std::make_unique<InputManager>();
	m_pRenderManager = std::make_unique<RenderManager>(m_hWnd);
	m_pUiManager = std::make_unique<UiManager>();

	RECT wndRect;
	GetClientRect(m_hWnd, &wndRect);
	m_pRenderManager->SetWndRect(wndRect);

	self = this;

	m_uiThread = std::thread(&UiManager::UiLoop, m_pUiManager.get());
}

void WindowWrapper::Release() noexcept {
	m_pUiManager->End();
	m_uiThread.join();
	DestroyWindow(m_hWnd);
}

int WindowWrapper::Run(HINSTANCE hInstance) {
	Init(hInstance);
	
	MSG msg;
	memset(&msg, 0, sizeof(msg));

	GameEntry();

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

	case WM_KEYDOWN:
		m_pInputManager->OnKeyDown();
		return 0;

	case WM_KEYUP:
		m_pInputManager->OnKeyUp();
		return 0;

	case WM_MOUSEMOVE:
		m_pInputManager->SetMousePos(Utility::Vector2(LOWORD(lParam), HIWORD(lParam)));
		return 0;

	case WM_LBUTTONDOWN:
		m_pUiManager->OnClick(m_pInputManager->GetMousePos());
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

UiManager& WindowWrapper::GetUiManager() const noexcept {
	return *m_pUiManager;
}

void WindowWrapper::BeginRender() {
	m_pRenderManager->BeginRender();
}

void WindowWrapper::EndRender() {
	m_pRenderManager->EndRender();
}