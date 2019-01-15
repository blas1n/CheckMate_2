#include <memory>
#include "GameDirector.h"
#include "SceneManager.h"
#include "SettingValue.h"
#include "Object.h"
#include "Sprite.h"
#include "resource.h"
#include "Transform.h"
#include "Renderer.h"
#include "TextRenderer.h"
#include "Player.h"
#include "Title.h"

void SettingWindow(SettingValue& value) {
	value.lpszClassName = value.lpszMenuName = TEXT("CheckMate");

	value.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	value.hCursor = LoadCursor(nullptr, IDC_ARROW);
	value.hIcon = LoadIcon(value.hInstance, MAKEINTRESOURCE(IDI_ICON1));
}

void SettingGame() {
	auto& sceneManager = GameDirector::GetGameDirector().GetSceneManager();

	sceneManager.RegisterScene("Title");
	sceneManager.RegisterScene("Home");
	sceneManager.RegisterScene("Stage");
	sceneManager.RegisterScene("Ending");

	sceneManager.ReserveChangeScene("Title");

	auto& player = sceneManager.GetScene("Title").AddObject("Player", Utility::Vector2(500, 200), Utility::Vector2(0.3f, 0.3f));
	player.AddComponent<Renderer>().SetSprite(MAKEINTRESOURCE(IDB_PNG1));
	player.AddComponent<Player>();

	auto& title = sceneManager.GetScene("Title").AddObject("Title");

	auto& titleRenderer = title.AddComponent<TextRenderer>();
	titleRenderer.SetStr(TEXT("CheckMate!"));
	titleRenderer.SetFont(std::make_shared<Gdiplus::Font>(TEXT("Arial"), 80, Gdiplus::FontStyle::FontStyleBold, Gdiplus::Unit::UnitPixel));

	auto wndRect = GameDirector::GetGameDirector().GetRenderManager().GetWndRect();
	auto area = titleRenderer.GetText().GetTextArea();
	title.GetComponent<Transform>().SetPos((wndRect.right / 2) - (area.x / 2), (wndRect.bottom / 2) - (area.y / 2));

	title.AddComponent<Title>();
}