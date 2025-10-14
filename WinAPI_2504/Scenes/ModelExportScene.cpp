#include "Framework.h"
#include "ModelExportScene.h"

ModelExportScene::ModelExportScene()
{
	string name = "Test";
	string file = "Resources/Models/FBX/" + name + ".fbx";
	ModelExporter* exporter = new ModelExporter(name, file);
	//exporter->ExportMaterial();
	exporter->ExportMesh();
	delete exporter;
}

ModelExportScene::~ModelExportScene()
{
}

void ModelExportScene::Update()
{
}

void ModelExportScene::PreRender()
{
}

void ModelExportScene::Render()
{
}

void ModelExportScene::PostRender()
{
}

void ModelExportScene::GUIRender()
{
}
