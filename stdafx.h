#pragma once

#define SHOWCONSOLE 1

#if SHOWCONSOLE
#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console") 
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console") 
#endif
#endif

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <tchar.h>
#include <Ole2.h>
#include <memory>
#include <string>

namespace std {
	using tstring = std::basic_string<TCHAR>;
}