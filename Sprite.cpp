#include "Sprite.h"

Sprite::Sprite(const LPWSTR& name) : Sprite() {
	ReserveSprite(name);
}

Sprite::Sprite(const Sprite& other) : Sprite() {
	ReserveSprite(other.GetName());
}

void Sprite::Draw(const Utility::Vector2& pos, const Utility::Vector2& scale, const float& angle) const {
	GameDirector::GetGameDirector().GetRenderManager().RenderImage(m_pBitmap.get(), pos, scale, angle);
}

void Sprite::ReserveSprite(const LPWSTR& name) noexcept {
	m_name = name;
}

bool Sprite::LoadSprite() noexcept {
	auto hInstance = GameDirector::GetGameDirector().GetHInstance();

	auto hResource = FindResource(hInstance, m_name, TEXT("PNG"));
	if (!hResource) return false;

	auto size = SizeofResource(hInstance, hResource);
	auto hGlobal = LoadResource(hInstance, hResource);
	auto pData = LockResource(hGlobal);

	auto hBuffer = GlobalAlloc(GMEM_MOVEABLE, size);
	auto pBuffer = GlobalLock(hBuffer);
	CopyMemory(pBuffer, pData, size);
	GlobalUnlock(hBuffer);

	IStream* pStream;
	CreateStreamOnHGlobal(hBuffer, TRUE, &pStream);
	m_pBitmap.reset(Gdiplus::Bitmap::FromStream(pStream));
	pStream->Release();

	return m_pBitmap->GetLastStatus() == Gdiplus::Ok;
}

void Sprite::UnloadSprite() noexcept {
	m_pBitmap.reset();
}

LPWSTR Sprite::GetName() const noexcept {
	return m_name;
}

bool Sprite::Empty() const noexcept {
	return m_pBitmap == nullptr;
}