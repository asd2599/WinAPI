#include "Framework.h"

RectCollider::RectCollider(Vector2 size) : size(size)
{
    type = Type::Rect;

    Init();
}

bool RectCollider::IsPointCollision(const Vector2& point)
{
    return false;
}

bool RectCollider::IsRectCollision(RectCollider* rect, Vector2* overlap)
{
    return false;
}

bool RectCollider::IsCircleCollision(CircleCollider* circle)
{
    return false;
}

void RectCollider::MakeMesh()
{
    Vector2 halfSize = size * 0.5f;

    vertices.emplace_back(-halfSize.x, +halfSize.y);
    vertices.emplace_back(+halfSize.x, +halfSize.y);
    vertices.emplace_back(+halfSize.x, -halfSize.y);
    vertices.emplace_back(-halfSize.x, -halfSize.y);
    vertices.emplace_back(-halfSize.x, +halfSize.y);
}
