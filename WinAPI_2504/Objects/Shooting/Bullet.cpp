#include "Framework.h"

Bullet::Bullet()
{
	localPosition = plane->GetLocalPosition();

	Init();
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	if (!isActive) return;

	//Translate(direction * SPEED * DELTA);


	if (localPosition.y > SCREEN_HEIGHT)
		isActive = false;

	UpdateWorld();
}

void Bullet::MakeMesh()
{
	vertices.emplace_back(0, 20, 1, 0, 0);
	vertices.emplace_back(20, -20, 1, 0, 0);
	vertices.emplace_back(-20, -20, 1, 0, 0);

	indices = { 0, 1, 2 };
}
