#include "Framework.h"

#include "Scenes/TutorialScene.h"
#include "Scenes/ShootingScene.h"
#include "Scenes/CollisionScene.h"

GameManager::GameManager()
{
	Create();
		
	//SCENE->AddScene("Game", new TutorialScene());	
	//SCENE->AddScene("Game", new ShootingScene());
	SCENE->AddScene("Game", new CollisionScene());

	SCENE->ChangeScene("Game");
}

GameManager::~GameManager()
{
	Release();
}

void GameManager::Update()
{
	Timer::Get()->Update();
	Input::Get()->Update();

	SCENE->Update();

	InvalidateRect(hWnd, nullptr, false);
}

void GameManager::Render()
{
	Device::Get()->Clear();

	SCENE->Render();	

	Device::Get()->Present();
}

void GameManager::Create()
{
	Timer::Get();
	Input::Get();

	Device::Get();

	SceneManager::Get();

	Environment::Get();
}

void GameManager::Release()
{
	Timer::Delete();
	Input::Delete();

	Device::Delete();
	Shader::Delete();

	SceneManager::Delete();

	Environment::Delete();
}
