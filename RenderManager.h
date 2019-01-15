#pragma once

#include "stdafx.h"
#include "String.h"
#include "Vector2.h"
#include <gdiplus.h>

class RenderManager {
private:
	const HWND m_hWnd;
	RECT m_wndRect;
	ULONG_PTR m_gdiplusToken;

	std::unique_ptr<Gdiplus::Graphics> m_pGraphics;
	std::unique_ptr<Gdiplus::Graphics> m_pMemGraphics;
	std::unique_ptr<Gdiplus::Bitmap> m_pBitmap;
	std::unique_ptr<Gdiplus::CachedBitmap> m_pCachedBitmap;

public:
	RenderManager(const HWND);
	~RenderManager();

public:
	const RECT GetWndRect() const noexcept;
	void SetWndRect(const RECT) noexcept;

public:
	void RenderOnScreen(HDC);

public:
	void RenderImage(Gdiplus::Image*, const Utility::Vector2&, const Utility::Vector2&, const float&) const;
	void RenderText(const TextInfo&, const Utility::Vector2&) const;
	Utility::Vector2 GetTextArea(const TextInfo&) const;

public:
	void BeginRender();
	void EndRender();
};