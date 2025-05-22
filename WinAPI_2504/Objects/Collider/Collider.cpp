#include "Framework.h"

Collider::Collider()
{
    colorBuffer->Set(0, 1, 0);
}

bool Collider::IsCollision(Collider* collider, Vector2* overlap)
{
    if (!IsActive()) return false;
    if (!collider->IsActive()) return false;

    switch (collider->type)
    {
    case Collider::Type::Rect:
        return IsRectCollision((RectCollider*)collider, overlap);
    case Collider::Type::Circle:
        return IsCircleCollision((CircleCollider*)collider);    
    }

    return false;
}

void Collider::Render()
{
    if (!isActive) return;

    worldBuffer->Set(world);
    worldBuffer->SetVS(0);

    colorBuffer->SetPS(0);

    vertexBuffer->Set(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);    

    vertexShader->Set();
    pixelShader->Set();

    DC->Draw(vertices.size(), 0);
}

void Collider::MakeMesh()
{
}
