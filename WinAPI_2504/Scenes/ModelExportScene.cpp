#include "Framework.h"
#include "ModelExportScene.h"

ModelExportScene::ModelExportScene()
{
	string name = "Test";
	string file = "Resources/Models/FBX/" + name + ".fbx";
	ModelExporter* exporter;

	//exporter = new ModelExporter(name, file);
	//exporter->ExportMaterial();
	//exporter->ExportMesh();

	string clipName = "Idle";
	//file = "Resources/Models/Animations/" + name + "/" + clipName + ".fbx";
	//
	//exporter = new ModelExporter(name, file);
	//exporter->ExportClip(clipName);	

	clipName = "Run";
	file = "Resources/Models/Animations/" + name + "/" + clipName + ".fbx";

	exporter = new ModelExporter(name, file);
	exporter->ExportClip(clipName);
	delete exporter;

	clipName = "Throwing";
	file = "Resources/Models/Animations/" + name + "/" + clipName + ".fbx";

	exporter = new ModelExporter(name, file);
	exporter->ExportClip(clipName);
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
