#include "Framework.h"
#include "TileGameScene.h"

TileGameScene::TileGameScene()
{
	tileMap = new TileMap("Resources/TextData/Stage1.map");
	tileMap->SetLocalPosition(0, SCREEN_HEIGHT);
	tileMap->UpdateWorld();
	tileMap->SetTag("TileMap");
	tileMap->Load();

	tank = new Tank();
	tank->SetTileMap(tileMap);
}

TileGameScene::~TileGameScene()
{
	delete tileMap;
	delete tank;
}

void TileGameScene::Update()
{
	//tileMap->UpdateWorld();
	tank->Update();
}

void TileGameScene::Render()
{
	tileMap->Render();
	tank->Render();
}

void TileGameScene::GUIRender()
{
	tileMap->Edit();
}
