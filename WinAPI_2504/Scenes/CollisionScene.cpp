#include "Framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	//colliders.push_back(new CircleCollider());
	//colliders.back()->SetLocalPosition(CENTER);
	//
	//colliders.push_back(new CircleCollider());
	//colliders.back()->SetLocalPosition(CENTER);

	colliders.push_back(new RectCollider());
	colliders.back()->SetLocalPosition(CENTER);
	
	colliders.push_back(new CircleCollider());
	colliders.back()->SetLocalPosition(CENTER);
}

CollisionScene::~CollisionScene()
{
	for (Collider* collider : colliders)
		delete collider;
}

void CollisionScene::Update()
{
	colliders[1]->SetLocalPosition(mousePos);

	if (colliders[0]->IsCollision(colliders[1]))
	{
		colliders[0]->SetColor(1, 0, 0);
	}
	else
	{
		colliders[0]->SetColor(0, 1, 0);
	}

	for (Collider* collider : colliders)
		collider->UpdateWorld();
}

void CollisionScene::Render()
{
	for (Collider* collider : colliders)
		collider->Render();
}
