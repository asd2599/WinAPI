#include "Framework.h"
#include "ModelRenderScene.h"

ModelRenderScene::ModelRenderScene()
{
	model = new Model("Test");
}

ModelRenderScene::~ModelRenderScene()
{
	delete model;
}

void ModelRenderScene::Update()
{
}

void ModelRenderScene::PreRender()
{
}

void ModelRenderScene::Render()
{
}

void ModelRenderScene::PostRender()
{
}

void ModelRenderScene::GUIRender()
{
}
