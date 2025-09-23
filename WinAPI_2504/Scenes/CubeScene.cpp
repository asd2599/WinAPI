#include "Framework.h"
#include "CubeScene.h"

CubeScene::CubeScene()
{
	quad = new Quad();
	quad->Load();
	quad->GetMaterial()->SetBaseMap(L"Resources/Textures/Test.jfif");
	//quad->GetMaterial()->SetShader(L"Tutorial.hlsl");

	cube = new Cube();
	cube->GetMaterial()->SetBaseMap(L"Resources/Textures/Landscape/Box.png");

	quad->SetParent(cube);
}

CubeScene::~CubeScene()
{
	delete quad;
	delete cube;
}

void CubeScene::Update()
{
	cube->Rotate(Vector3::Up(), 1.0f * DELTA);

	quad->UpdateWorld();
	cube->UpdateWorld();
}

void CubeScene::PreRender()
{
}

void CubeScene::Render()
{
	quad->Render();
	cube->Render();
}

void CubeScene::PostRender()
{
}

void CubeScene::GUIRender()
{
	quad->Edit();
	cube->Edit();
}
