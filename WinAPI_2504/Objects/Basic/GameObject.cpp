#include "Framework.h"

GameObject::GameObject()
{
	material = new Material();

    worldBuffer = new MatrixBuffer();
    
}

GameObject::GameObject(wstring shaderFile)
{
    material = new Material(shaderFile);

    worldBuffer = new MatrixBuffer();
}

GameObject::~GameObject()
{
    delete worldBuffer;
	delete material;
}

void GameObject::SetRender()
{
    worldBuffer->Set(world);
    worldBuffer->SetVS(0);

    material->Set();
}

void GameObject::SetWorld()
{
    worldBuffer->Set(world);
    worldBuffer->SetVS(0);
}

void GameObject::SetColor(float r, float g, float b, float a)
{
	material->SetColor(r, g, b, a);
}