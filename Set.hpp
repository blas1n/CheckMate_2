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
#include "Button.h"
#include "Title.h"

void SettingWindow(SettingValue& value) {
	value.lpszClassName = value.lpszMenuName = TEXT("CheckMate");

	value.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	value.hCursor = LoadCursor(nullptr, IDC_ARROW);
	value.hIcon = LoadIcon(value.hInstance, MAKEINTRESOURCE(IDI_ICON1));
}

void SettingGame() {
	const auto& wndRect = GameDirector::GetGameDirector().GetRenderManager().GetWndRect();
	auto& sceneManager = GameDirector::GetGameDirector().GetSceneManager();

	sceneManager.RegisterScene("Title");
	sceneManager.RegisterScene("Home");
	sceneManager.RegisterScene("Stage");
	sceneManager.RegisterScene("Ending");

	sceneManager.ReserveScene("Title");

	auto& title = sceneManager.GetScene("Title").AddObject("Title");
	title.GetComponent<Transform>().SetPos(wndRect.right * 0.5f, wndRect.bottom * 0.5f);
	title.AddComponent<Title>();

	auto& titleRenderer = title.AddComponent<TextRenderer>();
	titleRenderer.SetStr(TEXT("CheckMate!"));
	titleRenderer.SetFont(std::make_shared<Gdiplus::Font>(TEXT("Arial"), 120, Gdiplus::FontStyle::FontStyleBold, Gdiplus::Unit::UnitPixel));

	auto& startButtonObj = sceneManager.GetScene("Home").AddObject("Button");
	startButtonObj.GetComponent<Transform>().SetPos(wndRect.right * 0.5f, wndRect.bottom * 0.5f);

	auto& startButton = startButtonObj.AddComponent<Button>();
	startButton.SetSize(800, 600);
	startButton.SetOnClick([]() {GameDirector::GetGameDirector().GetSceneManager().ReserveScene("Stage"); });

	startButtonObj.AddComponent<Renderer>().SetSprite(MAKEINTRESOURCE(IDB_PNG2));
}