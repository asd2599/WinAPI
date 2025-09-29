#include "Framework.h"
#include "LightScene.h"

LightScene::LightScene()
{
	sphere = new Sphere();
	sphere->GetMaterial()->SetBaseMap(L"Resources/Textures/Landscape/Box.png");
	sphere->GetMaterial()->SetShader(L"Light/DiffuseLight.hlsl");
	sphere->SetLocalScale(5, 5, 5);
	sphere->UpdateWorld();
}

LightScene::~LightScene()
{
	delete sphere;
}

void LightScene::Update()
{
	sphere->UpdateWorld();
}

void LightScene::PreRender()
{
}

void LightScene::Render()
{
	sphere->Render();
}

void LightScene::PostRender()
{
}

void LightScene::GUIRender()
{
	sphere->Edit();
}
