#include "Framework.h"

Plane::Plane()
{
    pos = CENTER;

    Init();
}

Plane::~Plane()
{
    
}

void Plane::Update()
{
    if (Input::Get()->IsKeyPress('D'))
    {        
        //pos.x += SPEED * DELTA;
        Translate(Vector2::Right() * SPEED * DELTA);
    }

    if (Input::Get()->IsKeyPress('A'))
    {
        //pos.x -= SPEED * DELTA;
        Translate(Vector2::Left() * SPEED * DELTA);
    }

    if (Input::Get()->IsKeyPress('W'))
    {
        //pos.y += SPEED * DELTA;
        Translate(Vector2::Up() * SPEED * DELTA);
    }
    if (Input::Get()->IsKeyPress('S'))
    {
        //pos.y -= SPEED * DELTA;
        Translate(Vector2::Down() * SPEED * DELTA);
    }

    if (Input::Get()->IsKeyPress('L'))
    {
        scale.x += DELTA;
    }
    if (Input::Get()->IsKeyPress('J'))
    {
        scale.x -= DELTA;
    }
    if (Input::Get()->IsKeyPress('I'))
    {
        scale.y += DELTA;
    }
    if (Input::Get()->IsKeyPress('K'))
    {
        scale.y -= DELTA;
    }

    if (Input::Get()->IsKeyPress(VK_UP))
    {
        rot.z += DELTA;
    }
    if (Input::Get()->IsKeyPress(VK_DOWN))
    {
        rot.z -= DELTA;
    }

    //matWorld._11 = scale.x;
    //matWorld._22 = scale.y;

    //matWorld._11 = cos(angle);
    //matWorld._12 = sin(angle);
    //matWorld._21 = -sin(angle);
    //matWorld._22 = cos(angle);

    if (Input::Get()->IsKeyDown('1'))
        colorBuffer->Set(1, 0, 0);

    if (Input::Get()->IsKeyDown('2'))
        colorBuffer->Set(0, 1, 0);

    if (Input::Get()->IsKeyDown('3'))
        colorBuffer->Set(0, 0, 1);

    UpdateWorld();
}

void Plane::MakeMesh()
{
    vertices.emplace_back(0, 50, 1, 0, 0);
    vertices.emplace_back(0, -20, 1, 1, 0);
    vertices.emplace_back(-50, -50, 0, 1, 0);
    vertices.emplace_back(+50, -50, 0, 1, 0);

    indices = { 0, 1, 2, 1, 0, 3};
}
