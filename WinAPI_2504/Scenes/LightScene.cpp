#include "Framework.h"
#include "LightScene.h"

LightScene::LightScene()
{
	sphere = new Sphere();
	sphere->Load();
	//sphere->GetMaterial()->SetBaseMap(L"Resources/Textures/Landscape/Box.png");
	sphere->GetMaterial()->SetDiffuseMap(L"Resources/Textures/Landscape/Fieldstone_DM.tga");
	sphere->GetMaterial()->SetSpecularMap(L"Resources/Textures/Landscape/Fieldstone_SM.tga");
	sphere->GetMaterial()->SetNormalMap(L"Resources/Textures/Landscape/Fieldstone_NM.tga");
	sphere->GetMaterial()->SetShader(L"Light/Light.hlsl");
	sphere->SetLocalScale(5, 5, 5);
	sphere->UpdateWorld();

	plane = new Plane();
	plane->Load();
	//plane->GetMaterial()->Load("Resources/Materials/Wall.mat");
}

LightScene::~LightScene()
{
	delete sphere;
	delete plane;
}

void LightScene::Update()
{
	sphere->UpdateWorld();
	plane->UpdateWorld();
}

void LightScene::PreRender()
{
}

void LightScene::Render()
{
	sphere->Render();
	plane->Render();
}

void LightScene::PostRender()
{
}

void LightScene::GUIRender()
{
	sphere->Edit();
	sphere->GetMaterial()->Edit();
	plane->Edit();
	//plane->GetMaterial()->Edit();
}
