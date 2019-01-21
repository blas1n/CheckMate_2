#include "SettingValue.h"

const LPCTSTR SettingValue::fileName = TEXT("C:\\Users\\user\\Documents\\BS Engine\\Set.ini");

SettingValue::SettingValue(WNDPROC wndProc, HINSTANCE hIn)
	: cbSize(sizeof(WNDCLASSEX)),
	style(CS_HREDRAW | CS_VREDRAW),
	lpfnWndProc(wndProc),
	cbClsExtra(0),
	cbWndExtra(0),
	hInstance(hIn),
	lpszMenuName(nullptr),
	hWndParent(nullptr),
	hMenu(nullptr),
	lpParam(nullptr) {

	TCHAR name[128];

	GetPrivateProfileString(TEXT("Resource"), TEXT("Icon"), nullptr, name, 127, fileName);

	if (lstrcmp(name, TEXT("")))
		hIcon = reinterpret_cast<HICON>(LoadImage(nullptr, name, IMAGE_ICON, 0, 0, LR_LOADFROMFILE));
	else
		hIcon = LoadIcon(nullptr, IDI_APPLICATION);

	GetPrivateProfileString(TEXT("Resource"), TEXT("Cursor"), nullptr, name, 127, fileName);
	
	if (lstrcmp(name, TEXT("")))
		hCursor = reinterpret_cast<HCURSOR>(LoadImage(nullptr, name, IMAGE_CURSOR, 0, 0, LR_LOADFROMFILE));
	else
		hCursor = LoadCursor(nullptr, IDC_ARROW);

	hbrBackground = CreateSolidBrush(RGB(
		GetPrivateProfileInt(TEXT("Background"), TEXT("R"), 255, fileName),
		GetPrivateProfileInt(TEXT("Background"), TEXT("G"), 255, fileName),
		GetPrivateProfileInt(TEXT("Background"), TEXT("B"), 255, fileName)
	));

	GetPrivateProfileString(TEXT("Window"), TEXT("Name"), nullptr, lpszClassName, maxNameLen, fileName);
	
	if (GetPrivateProfileInt(TEXT("Window"), TEXT("Caption"), 1, fileName))
		dwStyle = WS_OVERLAPPEDWINDOW;
		
	else
		dwStyle = WS_OVERLAPPED;
	
	x = GetPrivateProfileInt(TEXT("Position"), TEXT("X"), CW_USEDEFAULT, fileName);
	y = GetPrivateProfileInt(TEXT("Position"), TEXT("Y"), CW_USEDEFAULT, fileName);
	width = GetPrivateProfileInt(TEXT("Position"), TEXT("Width"), CW_USEDEFAULT, fileName);
	height = GetPrivateProfileInt(TEXT("Position"), TEXT("Height"), CW_USEDEFAULT, fileName);

	if (GetPrivateProfileInt(TEXT("Window"), TEXT("Caption"), 1, fileName))
		nCmdShow = SW_SHOWMAXIMIZED;

	else
		nCmdShow = SW_SHOW;
}