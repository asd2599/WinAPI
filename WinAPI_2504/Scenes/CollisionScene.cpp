#include "Framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	colliders.push_back(new CircleCollider());
	colliders.back()->SetLocalPosition(CENTER);
	colliders.back()->SetTag("Circle1");
	//
	//colliders.push_back(new CircleCollider());
	//colliders.back()->SetLocalPosition(CENTER);

	colliders.push_back(new RectCollider());
	colliders.back()->SetLocalPosition(CENTER);
	colliders.back()->SetTag("Rect1");
	
	//colliders.push_back(new RectCollider());
	//colliders.back()->SetLocalPosition(CENTER);
	//colliders.back()->SetTag("Rect2");
}

CollisionScene::~CollisionScene()
{
	for (Collider* collider : colliders)
		delete collider;
}

void CollisionScene::Update()
{
	if (Input::Get()->IsKeyPress(VK_RIGHT))
	{
		//colliders[0]->GetLocalPosition() += DELTA;
		Vector2 pos = colliders[0]->GetLocalPosition();
		pos.x += DELTA * 100;
		colliders[0]->SetLocalPosition(pos);
	}

	//if (colliders[0]->IsCollision(colliders[1], &overlap))
	if (colliders[0]->IsCollision(colliders[1]))
	//if(colliders[0]->IsPointCollision(mousePos))
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

void CollisionScene::GUIRender()
{
	for (Collider* collider : colliders)
		collider->Edit();

	ImGui::DragFloat2("Overlap", (float*)&overlap);
}
