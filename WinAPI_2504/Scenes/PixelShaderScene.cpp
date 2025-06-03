#include "Framework.h"
#include "PixelShaderScene.h"

PixelShaderScene::PixelShaderScene()
{
	quad = new Quad(L"Resources/Textures/Test.jfif");
	quad->SetLocalPosition(CENTER);	
	quad->GetMaterial()->SetShader(L"Filter.hlsl");

	valueBuffer = new FloatValueBuffer();
	addColorBuffer = new ColorBuffer();

	secondMap = Texture::Add(L"Resources/Textures/Background.png");
}

PixelShaderScene::~PixelShaderScene()
{
	delete quad;
	delete valueBuffer;
	delete addColorBuffer;
}

void PixelShaderScene::Update()
{
	quad->UpdateWorld();
}

void PixelShaderScene::Render()
{
	valueBuffer->SetPS(1);
	secondMap->PSSet(1);
	addColorBuffer->SetPS(2);
	quad->Render();
}

void PixelShaderScene::GUIRender()
{
	quad->Edit();
	//ImGui::SliderFloat("Value 1", &valueBuffer->GetValues()[0], -PI, PI);
	ImGui::DragFloat("Value 1", &valueBuffer->GetValues()[0]);
	ImGui::ColorEdit4("Add Color", (float*)addColorBuffer->GetColor());
}
