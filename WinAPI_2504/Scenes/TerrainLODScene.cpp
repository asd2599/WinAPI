#include "Framework.h"
#include "TerrainLODScene.h"

TerrainLODScene::TerrainLODScene()
{
	terrainLOD = new TerrainLOD(L"Resources/Textures/HeightMaps/HeightMap.png");
}

TerrainLODScene::~TerrainLODScene()
{
	delete terrainLOD;
}

void TerrainLODScene::Update()
{
}

void TerrainLODScene::PreRender()
{
}

void TerrainLODScene::Render()
{
	terrainLOD->Render();
}

void TerrainLODScene::PostRender()
{
}

void TerrainLODScene::GUIRender()
{
	terrainLOD->GUIRender();
}
