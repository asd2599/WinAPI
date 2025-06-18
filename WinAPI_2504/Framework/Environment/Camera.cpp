#include "Framework.h"

Camera::Camera()
{
	tag = "Camera";

	viewBuffer = new MatrixBuffer();
}

Camera::~Camera()
{
	delete viewBuffer;
}

void Camera::Update()
{
    if (target)
        FollowMode();
    else
	    FreeMode();

	UpdateWorld();	

	view = XMMatrixInverse(nullptr, world);
	viewBuffer->Set(view);
	viewBuffer->SetVS(1);
}

void Camera::FreeMode()
{
    if (Input::Get()->IsKeyPress(VK_RBUTTON))
    {
        if (Input::Get()->IsKeyPress('W'))
            Translate(Vector2::Up() * speed * DELTA);
        if (Input::Get()->IsKeyPress('S'))
            Translate(Vector2::Down() * speed * DELTA);
        if (Input::Get()->IsKeyPress('A'))
            Translate(Vector2::Left() * speed * DELTA);
        if (Input::Get()->IsKeyPress('D'))
            Translate(Vector2::Right() * speed * DELTA);
    }
}

void Camera::FollowMode()
{
    Vector2 targetPos = target->GetGlobalPosition() - targetOffset;

    FixPosition(targetPos);

    localPosition = GameMath::Lerp<Vector2>(localPosition, targetPos, speed * DELTA);
}

void Camera::FixPosition(Vector2& pos)
{
    if (!isFix) return;

    if (pos.x < leftBottom.x)
        pos.x = leftBottom.x;

    if (pos.x > rightTop.x - SCREEN_WIDTH)
        pos.x = rightTop.x - SCREEN_WIDTH;

    if (pos.y < leftBottom.y)
        pos.y = leftBottom.y;

    if (pos.y > rightTop.y - SCREEN_HEIGHT)
        pos.y = rightTop.y - SCREEN_HEIGHT;
}
