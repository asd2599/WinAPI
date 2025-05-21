#include "Framework.h"

Transform::Transform()
{
}

Transform::~Transform()
{
}

void Transform::UpdateWorld()
{
    S = XMMatrixScaling(scale.x, scale.y, 1.0f);
    R = XMMatrixRotationRollPitchYaw(rot.x, rot.y, rot.z);
    T = XMMatrixTranslation(pos.x, pos.y, 0.0f);

    world = S * R * T;
}
