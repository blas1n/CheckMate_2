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
	void SetWndRect(const RECT rect) noexcept;

public:
	void RenderOnScreen(HDC hDC);

public:
	void RenderImage(Gdiplus::Image* image, const Utility::Vector2& pos, const Utility::Vector2& scale, const float angle) const;
	void RenderText(const TextInfo& text, const Utility::Vector2& pos, const Utility::Vector2& scale, const float angle) const;

private:
	void GetConversionMatrix(Gdiplus::Matrix& matrix, const Utility::Vector2& pos,
		const Utility::Vector2& scale, const Utility::Vector2& area, const float angle) const;

public:
	void BeginRender();
	void EndRender();
};