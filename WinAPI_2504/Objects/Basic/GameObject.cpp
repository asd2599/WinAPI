#include "Framework.h"

GameObject::GameObject()
{
    vertexShader = Shader::AddVS(L"Tutorial.hlsl");
    pixelShader = Shader::AddPS(L"Tutorial.hlsl");    

    worldBuffer = new MatrixBuffer();
    colorBuffer = new ColorBuffer();
}

GameObject::GameObject(wstring shaderFile)
{
    vertexShader = Shader::AddVS(shaderFile);
    pixelShader = Shader::AddPS(shaderFile);

    worldBuffer = new MatrixBuffer();
    colorBuffer = new ColorBuffer();
}

GameObject::~GameObject()
{
    delete vertexBuffer;

    if(indexBuffer)
        delete indexBuffer;

    delete worldBuffer;
    delete colorBuffer;
}

void GameObject::Render()
{
    if (!isActive) return;

    worldBuffer->Set(world);
    worldBuffer->SetVS(0);

    colorBuffer->SetPS(0);

    vertexBuffer->Set();
    if(indexBuffer)
        indexBuffer->Set();

    vertexShader->Set();
    pixelShader->Set();

    DC->DrawIndexed(indices.size(), 0, 0);
}

void GameObject::SetColor(float r, float g, float b, float a)
{
    colorBuffer->Set(r, g, b, a);
}

void GameObject::Init()
{
    MakeMesh();
        
    vertexBuffer = new VertexBuffer(vertices.data(), sizeof(VertexColor), vertices.size());    

    if(!indices.empty())
        indexBuffer = new IndexBuffer(indices.data(), indices.size());
}
