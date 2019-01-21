#pragma once

#include "stdafx.h"

struct SettingValue {
private:
	static const LPCTSTR fileName;
	static const int maxNameLen = 30;

public:
	SettingValue(WNDPROC, HINSTANCE);

	UINT					cbSize;
	UINT					style;
	WNDPROC					lpfnWndProc;
	int						cbClsExtra;
	int						cbWndExtra;
	HINSTANCE				hInstance;
	HICON					hIcon;
	HCURSOR					hCursor;
	HBRUSH					hbrBackground;
	LPCTSTR					lpszMenuName;
	TCHAR					lpszClassName[maxNameLen + 1];

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