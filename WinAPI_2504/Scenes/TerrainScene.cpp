#include "Framework.h"
#include "TerrainScene.h"

TerrainScene::TerrainScene()
{
	skybox = new Skybox(L"Resources/Textures/Landscape/Snow_ENV.dds");
	terrain = new Terrain();
}

TerrainScene::~TerrainScene()
{
	delete skybox;
	delete terrain;
}

void TerrainScene::Update()
{
}

void TerrainScene::PreRender()
{
}

void TerrainScene::Render()
{
	//skybox->Render();
	terrain->Render();	
}

void TerrainScene::PostRender()
{
}

void TerrainScene::GUIRender()
{
}
