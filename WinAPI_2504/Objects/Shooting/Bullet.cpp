#include "Framework.h"

Bullet::Bullet()
{
	Init();
    isActive = false;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
    if (!isActive)
    {
        if (plane)
        {
            plane->UpdateWorld();
            localPosition = plane->GetGlobalPosition();
            localPosition.y += 20.0f;

            if (Input::Get()->IsKeyDown(VK_SPACE))
            {
                isActive = true;
                velocity = { 0, SPEED };
            }
        }
    }
    else
    {
        // 공이 발사되어 움직이는 상태
        Fire();
        IsScreenCollision();
        IsPaddleCollision();
    }

    UpdateWorld();
}

void Bullet::Render()
{
    GameObject::Render();
}

void Bullet::Fire()
{

    localPosition += velocity * DELTA;
}

void Bullet::IsScreenCollision()
{
    if (localPosition.x < 0.0f)
    {
        localPosition.x = 0.0f;
        velocity.x *= -1.0f;
    }

    if (localPosition.x > SCREEN_WIDTH)
    {
        localPosition.x = SCREEN_WIDTH;
        velocity.x *= -1.0f;
    }
    if (localPosition.y > SCREEN_HEIGHT)
    {
        localPosition.y = SCREEN_HEIGHT;
        velocity.y *= -1.0f;
    }
    if (localPosition.y < 0.0f)
    {
        isActive = false;
    }
}

void Bullet::IsPaddleCollision()
{
    if (!plane) return;

    Vector2 paddlePos = plane->GetGlobalPosition();
    Vector2 halfSize = plane->GetHalfSize();
    Vector2 ballPos = localPosition;

    if (ballPos.x > paddlePos.x - halfSize.x &&
        ballPos.x < paddlePos.x + halfSize.x &&
        ballPos.y > paddlePos.y - halfSize.y &&
        ballPos.y < paddlePos.y + halfSize.y)
    {
       
        velocity.y *= -1.0f;

        float offset = (ballPos.x - paddlePos.x) / halfSize.x;
        velocity.x = offset * SPEED;

        localPosition.y = paddlePos.y + halfSize.y + 1.0f;
    }
}

void Bullet::MakeMesh()
{
    const int segments = 36;     
    const float radius = 10.0f;  

    vertices.emplace_back(0.0f, 0.0f, 1, 1, 1);

    for (int i = 0; i <= segments; i++)
    {
        float angle = XM_2PI * i / segments;
        float x = cosf(angle) * radius;
        float y = sinf(angle) * radius;

        vertices.emplace_back(x, y, 1, 1, 1); 
    }

    for (int i = 1; i <= segments; i++)
    {
        indices.push_back(0);                  
        indices.push_back((i % segments) + 1); 
        indices.push_back(i);                  
    }
}
