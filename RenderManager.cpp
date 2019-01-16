#include "RenderManager.h"

RenderManager::RenderManager(const HWND hWnd)
	: m_hWnd(hWnd),
	m_gdiplusToken(0),
	m_pGraphics(nullptr),
	m_pMemGraphics(nullptr),
	m_pBitmap(nullptr),
	m_pCachedBitmap(nullptr) {

	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	Gdiplus::GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, nullptr);
}

RenderManager::~RenderManager() {
	m_pCachedBitmap.reset();
	Gdiplus::GdiplusShutdown(m_gdiplusToken);
}

void RenderManager::RenderOnScreen(HDC hDC) {
	if (!m_pCachedBitmap) return;
	
	Gdiplus::Graphics(hDC).DrawCachedBitmap(m_pCachedBitmap.get(), 0, 0);
	m_pCachedBitmap.reset();
}

void RenderManager::RenderImage(Gdiplus::Image* image, const Utility::Vector2& pos, const Utility::Vector2& scale, const float& angle) const {
	Gdiplus::Matrix matrix;
	GetConversionMatrix(matrix, pos, scale, Utility::Vector2(image->GetWidth(), image->GetHeight()), angle);

	m_pMemGraphics->SetTransform(&matrix);
	m_pMemGraphics->DrawImage(image, 0, 0, image->GetWidth(), image->GetHeight());
	m_pMemGraphics->ResetTransform();
}

void RenderManager::RenderText(const TextInfo& text, const Utility::Vector2& pos, const Utility::Vector2& scale, const float& angle) const {
	Gdiplus::RectF rect;
	m_pMemGraphics->MeasureString(text.str.c_str(), static_cast<INT>(text.str.length()), text.font.get(), Gdiplus::PointF(0, 0), text.format.get(), &rect);
	
	Gdiplus::Matrix matrix;
	GetConversionMatrix(matrix, pos, scale, Utility::Vector2(rect.Width, rect.Height), angle);
	
	m_pMemGraphics->SetTransform(&matrix);
	m_pMemGraphics->DrawString(text.str.c_str(), static_cast<INT>(text.str.length()), text.font.get(), Gdiplus::PointF(0, 0), text.format.get(), &Gdiplus::SolidBrush(text.color));
	m_pMemGraphics->ResetTransform();
}

void RenderManager::GetConversionMatrix(Gdiplus::Matrix& matrix, const Utility::Vector2& pos,
	const Utility::Vector2& scale, const Utility::Vector2& area, const float& angle) const {

	matrix.Scale(scale.x, scale.y);
	matrix.Translate(pos.x / scale.x - area.x * 0.5f, pos.y / scale.y - area.y * 0.5f);
	matrix.RotateAt(-angle, Gdiplus::PointF(area.x * 0.5f, area.y * 0.5f));
}

void RenderManager::BeginRender() {
	m_pGraphics.reset(Gdiplus::Graphics::FromHWND(m_hWnd));
	m_pBitmap.reset(new Gdiplus::Bitmap(m_wndRect.right, m_wndRect.bottom, m_pGraphics.get()));
	m_pMemGraphics.reset(new Gdiplus::Graphics(m_pBitmap.get()));
	
	m_pMemGraphics->FillRectangle(&Gdiplus::SolidBrush(Gdiplus::Color::White), 0, 0, m_wndRect.right, m_wndRect.bottom);
}

void RenderManager::EndRender() {
	m_pCachedBitmap.reset(new Gdiplus::CachedBitmap(m_pBitmap.get(), m_pGraphics.get()));
	
	m_pGraphics.reset();
	m_pMemGraphics.reset();
	m_pBitmap.reset();

	InvalidateRect(m_hWnd, nullptr, false);
}

const RECT RenderManager::GetWndRect() const noexcept {
	return m_wndRect;
}

void RenderManager::SetWndRect(const RECT rect) noexcept {
	m_wndRect = rect;
}