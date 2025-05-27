#include "Framework.h"

RectCollider::RectCollider(Vector2 size) : size(size)
{
    type = Type::Rect;

    Init();
}

//AABB
//bool RectCollider::IsPointCollision(const Vector2& point)
//{
//    if (point.x > Left() && point.x < Right())
//    {
//        if (point.y > Bottom() && point.y < Top())
//            return true;
//    }
//
//    return false;
//}

//¿ªÇà·Ä
bool RectCollider::IsPointCollision(const Vector2& point)
{
    Vector2 coord = point * XMMatrixInverse(nullptr, world);

    if (abs(coord.x) < size.x * 0.5f && abs(coord.y) < size.y * 0.5f)
        return true;

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

Vector2 RectCollider::LeftTop()
{
    Vector2 edge = Vector2(-size.x, +size.y) * 0.5f;

    return edge * world;
}

Vector2 RectCollider::LeftBottom()
{
    Vector2 edge = Vector2(-size.x, -size.y) * 0.5f;

    return edge * world;
}

Vector2 RectCollider::RightTop()
{
    Vector2 edge = Vector2(+size.x, +size.y) * 0.5f;

    return edge * world;
}

Vector2 RectCollider::RightBottom()
{
    Vector2 edge = Vector2(+size.x, -size.y) * 0.5f;

    return edge * world;
}

float RectCollider::Left()
{
    float minLeft = min(LeftTop().x, LeftBottom().x);
    float minRight = min(RightTop().x, RightBottom().x);

    return min(minLeft, minRight);
}

float RectCollider::Right()
{
    float maxLeft = max(LeftTop().x, LeftBottom().x);
    float maxRight = max(RightTop().x, RightBottom().x);

    return max(maxLeft, maxRight);
}

float RectCollider::Top()
{
    float maxTop = max(LeftTop().y, LeftBottom().y);
    float maxBottom = max(RightTop().y, RightBottom().y);

    return max(maxTop, maxBottom);
}

float RectCollider::Bottom()
{
    float minTop = min(LeftTop().y, LeftBottom().y);
    float minBottom = min(RightTop().y, RightBottom().y);

    return min(minTop, minBottom);
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
