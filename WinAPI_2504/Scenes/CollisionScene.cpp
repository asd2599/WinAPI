#include "Framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	colliders.push_back(new BoxCollider());
	colliders.back()->SetTag("BoxCollider1");
}

CollisionScene::~CollisionScene()
{
	for (Collider* collider : colliders)
		delete collider;
}

void CollisionScene::Update()
{
	for (Collider* collider : colliders)
		collider->UpdateWorld();	
}

void CollisionScene::PreRender()
{
}

void CollisionScene::Render()
{
	for (Collider* collider : colliders)
		collider->Render();
}

void CollisionScene::PostRender()
{
}

void CollisionScene::GUIRender()
{
	for (Collider* collider : colliders)
		collider->Edit();
}
