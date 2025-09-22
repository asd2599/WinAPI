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
    Vector3 delta = mousePos - prevMousePos;
    prevMousePos = mousePos;

    if (Input::Get()->IsKeyPress(VK_RBUTTON))
    {
        if (Input::Get()->IsKeyPress('W'))
            Translate(Vector3::Forward() * moveSpeed * DELTA);
        if (Input::Get()->IsKeyPress('S'))
            Translate(Vector3::Back() * moveSpeed * DELTA);
        if (Input::Get()->IsKeyPress('Q'))
            Translate(Vector3::Up() * moveSpeed * DELTA);
        if (Input::Get()->IsKeyPress('E'))
            Translate(Vector3::Down() * moveSpeed * DELTA);
        if (Input::Get()->IsKeyPress('A'))
            Translate(Vector3::Left() * moveSpeed * DELTA);
        if (Input::Get()->IsKeyPress('D'))
            Translate(Vector3::Right() * moveSpeed * DELTA);

        Rotate(Vector3::Right(), -delta.y * rotSpeed * DELTA);
        Rotate(Vector3::Up(), delta.x * rotSpeed * DELTA);
    }
}

void Camera::FollowMode()
{
    //Vector2 targetPos = target->GetGlobalPosition() - targetOffset;
    //FixPosition(targetPos);
    //localPosition = GameMath::Lerp<Vector2>(localPosition, targetPos, speed * DELTA);
}
