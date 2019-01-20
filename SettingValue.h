#pragma once

#include "stdafx.h"

struct SettingValue {
	SettingValue(WNDPROC, HINSTANCE);

	UINT					cbSize;
	UINT					style;
	WNDPROC					lpfnWndProc;
	int						cbClsExtra;
	int						cbWndExtra;
	HINSTANCE				hInstance;
	HBRUSH					hbrBackground;
	HCURSOR					hCursor;
	HICON					hIcon;
	LPCTSTR					lpszMenuName;
	LPCTSTR					lpszClassName;

	DWORD					dwStyle;
	int						x;
	int						y;
	int						width;
	int						height;
	HWND					hWndParent;
	HMENU					hMenu;
	LPVOID					lpParam;

	int						nCmdShow;
};