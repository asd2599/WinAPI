#include "Framework.h"
#include "TextureScene.h"

TextureScene::TextureScene()
{	
	quad = new Quad(L"Resources/Textures/Background.png", Vector2(), Vector2(4, 1));
	quad->SetLocalPosition(CENTER);
	quad->UpdateWorld();		

	Vector2 size = quad->GetSize();

	bird = new Bird();
	bird->SetLocalPosition(CENTER);
}

TextureScene::~TextureScene()
{
	delete quad;	
	delete bird;
}

void TextureScene::Update()
{
	quad->Translate(Vector2::Left() * BG_SPEED * DELTA);

	if (quad->GetLocalPosition().x <= 0)
	{
		quad->Translate(Vector2::Right() * quad->GetSize().x * 0.5f);
	}

	quad->UpdateWorld();
	bird->Update();
}

void TextureScene::Render()
{
	quad->Render();
	bird->Render();
}
