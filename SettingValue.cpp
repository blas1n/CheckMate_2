#include "SettingValue.h"

SettingValue::SettingValue()
	: cbSize(sizeof(WNDCLASSEX)),
	style(CS_HREDRAW | CS_VREDRAW),
	lpfnWndProc(nullptr),
	cbClsExtra(0),
	cbWndExtra(0),
	hIcon(nullptr),
	hCursor(nullptr),
	hbrBackground(nullptr),
	lpszMenuName(TEXT("")),
	lpszClassName(TEXT("")),
	dwStyle(WS_OVERLAPPEDWINDOW),
	x(CW_USEDEFAULT),
	y(CW_USEDEFAULT),
	width(800),
	height(600),
	hWndParent(nullptr),
	hMenu(nullptr),
	lpParam(nullptr),
	nCmdShow(SW_SHOW) {}