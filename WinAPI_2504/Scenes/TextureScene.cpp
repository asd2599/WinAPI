#include "Framework.h"
#include "TextureScene.h"

TextureScene::TextureScene()
{
	//quad = new Quad(Vector2(200, 200));
	//quad = new Quad(L"Resources/Textures/Test.jfif");
	//quad->SetLocalPosition(CENTER);
	//quad->UpdateWorld();
	//quad->SetColor(0, 1, 0);
	//quad->GetMaterial()->SetBaseMap(L"Resources/Textures/Test.jfif");

	bird = new Bird();
	bird->SetLocalPosition(CENTER);
}

TextureScene::~TextureScene()
{
	//delete quad;	
	delete bird;
}

void TextureScene::Update()
{
	bird->Update();
}

void TextureScene::Render()
{
	//quad->Render();
	bird->Render();
}
