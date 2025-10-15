#include "Framework.h"
#include "ModelAnimaionScene.h"

ModelAnimationScene::ModelAnimationScene()
{
	model = new ModelAnimator("Test");
	model->SetVertexShader(L"Model/Model.hlsl");

	model->ReadClip("Idle", 0);
	model->ReadClip("Run", 0);
	model->ReadClip("Throwing", 0);
	model->CreateTexture();
}

ModelAnimationScene::~ModelAnimationScene()
{
	delete model;
}

void ModelAnimationScene::Update()
{
	model->Update();
}

void ModelAnimationScene::PreRender()
{
}

void ModelAnimationScene::Render()
{
	model->Render();
}

void ModelAnimationScene::PostRender()
{
}

void ModelAnimationScene::GUIRender()
{
	model->Edit();
}
