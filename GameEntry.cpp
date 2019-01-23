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
	auto& stageScene = sceneManager.GetScene("Stage");
	auto& endScene = sceneManager.GetScene("Ending");

	{
		homeScene.AddObject(TEXT("Background")).AddComponent<Renderer>(TEXT("D:\\CheckMate\\Background.png")).GetEntity().GetComponent<Transform>().SetPos(wndRect.right * 0.5f, wndRect.bottom * 0.5f);

		auto& title = homeScene.AddObject(TEXT("Title")).AddComponent<TextRenderer>();
		title.SetStr(TEXT("CheckMate!"));
		title.SetFont(std::make_shared<Gdiplus::Font>(TEXT("Linden Hill"), 270, Gdiplus::FontStyle::FontStyleBold, Gdiplus::Unit::UnitPixel));

		auto& startButton = homeScene.AddObject(TEXT("Button")).AddComponent<Button>();
		startButton.SetSize(650, 170);
		startButton.SetOnClick([] {GameDirector::GetGameDirector().GetSceneManager().ReserveScene("Stage"); });
		startButton.GetEntity().AddComponent<Renderer>().SetSprite(TEXT("D:\\CheckMate\\Start.png"));

		title.GetEntity().GetComponent<Transform>().SetPos(wndRect.right * 0.5f, wndRect.bottom * 0.5f - 120);
		startButton.GetEntity().GetComponent<Transform>().SetPos(wndRect.right * 0.5f, wndRect.bottom * 0.5f + 150);
	}

	{
		{
			LPCTSTR path[2] = { TEXT("D:\\CheckMate\\WhiteTile.png"), TEXT("D:\\CheckMate\\BlackTile.png") };
			TCHAR nameBuffer[11];
			int tile = 0;

			for (int i = 0; i < wndRect.right / 100 + 1; i++) {
				for (int j = 0; j < wndRect.bottom / 100 + 1; j++) {
					_sntprintf_s(nameBuffer, 10, TEXT("Tile %d %d"), i, j);

					stageScene.AddObject(nameBuffer).AddComponent<Renderer>(path[tile % 2]).GetEntity().GetComponent<Transform>().SetPos(i * 100 + 50, j * 100 + 50);
					tile++;
				}

				if ((wndRect.bottom / 100) & 1)
					tile++;
			}
		}
	
		auto& player = stageScene.AddObject(TEXT("Player")).AddComponent<Player>().GetEntity().AddComponent<Renderer>(TEXT("D:\\CheckMate\\Player.png")).GetEntity();
		player.GetComponent<Transform>().SetScale(0.4f, 0.4f);
		player.GetComponent<Transform>().SetPos(50.0f, 50.0f);
	}

	{
		endScene.AddObject(TEXT("Background")).AddComponent<Renderer>(TEXT("D:\\CheckMate\\Background.png")).GetEntity().AddComponent<Ending>().GetEntity().GetComponent<Transform>().SetPos(wndRect.right * 0.5f, wndRect.bottom * 0.5f);

		auto& clearCaption = endScene.AddObject(TEXT("Clear Caption")).AddComponent<TextRenderer>();
		clearCaption.SetStr(TEXT("0 Stage Clear!!"));
		clearCaption.SetFont(std::make_shared<Gdiplus::Font>(TEXT("Linden Hill"), 160, Gdiplus::FontStyle::FontStyleBold, Gdiplus::Unit::UnitPixel));
		clearCaption.GetEntity().GetComponent<Transform>().SetPos(wndRect.right * 0.5f, wndRect.bottom * 0.5f - 40);

		auto& pressCaption = endScene.AddObject(TEXT("Press Caption")).AddComponent<TextRenderer>();
		pressCaption.SetStr(TEXT("Press Any Key"));
		pressCaption.SetColor(Gdiplus::Color(50, 50, 50));
		pressCaption.SetFont(std::make_shared<Gdiplus::Font>(TEXT("Linden Hill"), 60, Gdiplus::FontStyle::FontStyleBold, Gdiplus::Unit::UnitPixel));
		pressCaption.GetEntity().GetComponent<Transform>().SetPos(wndRect.right * 0.5f, wndRect.bottom * 0.5f + 150);
	}
}