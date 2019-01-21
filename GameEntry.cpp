#include <memory>
#include "GameDirector.h"
#include "SceneManager.h"
#include "SettingValue.h"
#include "Object.h"
#include "Sprite.h"
#include "Transform.h"
#include "Renderer.h"
#include "TextRenderer.h"
#include "Button.h"
#include "Player.h"
#include "Ending.h"

void GameEntry() {
	const auto& wndRect = GameDirector::GetGameDirector().GetRenderManager().GetWndRect();
	auto& sceneManager = GameDirector::GetGameDirector().GetSceneManager();

	sceneManager.RegisterScene("Home");
	sceneManager.RegisterScene("Stage");
	sceneManager.RegisterScene("Ending");

	sceneManager.ReserveScene("Home");

	auto& homeScene = sceneManager.GetScene("Home");
	auto& endScene = sceneManager.GetScene("Ending");

	{
		homeScene.AddObject("Background").AddComponent<Renderer>(TEXT("D:\\CheckMate\\Background.png")).GetEntity().GetComponent<Transform>().SetPos(wndRect.right * 0.5f, wndRect.bottom * 0.5f);

		auto& title = homeScene.AddObject("Title").AddComponent<TextRenderer>();
		title.SetStr(TEXT("CheckMate!"));
		title.SetFont(std::make_shared<Gdiplus::Font>(TEXT("Linden Hill"), 270, Gdiplus::FontStyle::FontStyleBold, Gdiplus::Unit::UnitPixel));

		auto& startButton = homeScene.AddObject("Button").AddComponent<Button>();
		startButton.SetSize(650, 170);
		startButton.SetOnClick([]() {GameDirector::GetGameDirector().GetSceneManager().ReserveScene("Stage"); });
		startButton.GetEntity().AddComponent<Renderer>().SetSprite(TEXT("D:\\CheckMate\\Start.png"));

		title.GetEntity().GetComponent<Transform>().SetPos(wndRect.right * 0.5f, wndRect.bottom * 0.5f - 120);
		startButton.GetEntity().GetComponent<Transform>().SetPos(wndRect.right * 0.5f, wndRect.bottom * 0.5f + 150);
	}

	{
		endScene.AddObject("Background").AddComponent<Renderer>(TEXT("D:\\CheckMate\\Background.png")).GetEntity().AddComponent<Ending>().GetEntity().GetComponent<Transform>().SetPos(wndRect.right * 0.5f, wndRect.bottom * 0.5f);

		auto& clearCaption = endScene.AddObject("Clear Caption").AddComponent<TextRenderer>();
		clearCaption.SetStr(TEXT("0 Stage Clear!!"));
		clearCaption.SetFont(std::make_shared<Gdiplus::Font>(TEXT("Linden Hill"), 160, Gdiplus::FontStyle::FontStyleBold, Gdiplus::Unit::UnitPixel));
		clearCaption.GetEntity().GetComponent<Transform>().SetPos(wndRect.right * 0.5f, wndRect.bottom * 0.5f - 40);

		auto& pressCaption = endScene.AddObject("Press Caption").AddComponent<TextRenderer>();
		pressCaption.SetStr(TEXT("Press Any Key"));
		pressCaption.SetColor(Gdiplus::Color(50, 50, 50));
		pressCaption.SetFont(std::make_shared<Gdiplus::Font>(TEXT("Linden Hill"), 60, Gdiplus::FontStyle::FontStyleBold, Gdiplus::Unit::UnitPixel));
		pressCaption.GetEntity().GetComponent<Transform>().SetPos(wndRect.right * 0.5f, wndRect.bottom * 0.5f + 150);
	}
}