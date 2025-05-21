#pragma once

struct Vertex//정점 : 3차원 공간에서의 한 점
{
    float x, y, z;

    Vertex(float x = 0, float y = 0)
        : x(x), y(y), z(0)
    {
    }
};

struct VertexColor
{
    float x, y, z;
    float r, g, b, a;

    VertexColor(float x = 0, float y = 0, float r = 1, float g = 1, float b = 1)
        : x(x), y(y), z(0), r(r), g(g), b(b), a(1)
    {
    }
};