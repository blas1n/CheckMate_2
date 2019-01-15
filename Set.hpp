#include "GameDirector.h"
#include "SceneManager.h"
#include "SettingValue.h"
#include "Object.h"
#include "Sprite.h"
#include "resource.h"
#include "Renderer.h"
#include "Player.h"
#include <memory>

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
}