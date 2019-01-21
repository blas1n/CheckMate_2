#include "SettingValue.h"

SettingValue::SettingValue(WNDPROC wndProc, HINSTANCE hIn)
	: cbSize(sizeof(WNDCLASSEX)),
	style(CS_HREDRAW | CS_VREDRAW),
	lpfnWndProc(wndProc),
	cbClsExtra(0),
	cbWndExtra(0),
	hInstance(hIn),
	hbrBackground(reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH))),
	hCursor(LoadCursor(nullptr, IDC_ARROW)),
	hIcon(LoadIcon(nullptr, IDI_APPLICATION)),
	lpszMenuName(TEXT("CheckMate")),
	lpszClassName(TEXT("CheckMate")),
	dwStyle(WS_OVERLAPPEDWINDOW),
	x(CW_USEDEFAULT),
	y(CW_USEDEFAULT),
	width(800),
	height(600),
	hWndParent(nullptr),
	hMenu(nullptr),
	lpParam(nullptr),
	nCmdShow(SW_SHOWMAXIMIZED) {}