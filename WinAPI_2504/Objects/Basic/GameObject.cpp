#include "Framework.h"

GameObject::GameObject()
{
    vertexShader = Shader::AddVS(L"Tutorial.hlsl");
    pixelShader = Shader::AddPS(L"Tutorial.hlsl");    

    worldBuffer = new MatrixBuffer();
    colorBuffer = new ColorBuffer();
}

GameObject::~GameObject()
{
    delete vertexBuffer;
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
    indexBuffer->Set();

    vertexShader->Set();
    pixelShader->Set();

    DC->DrawIndexed(indices.size(), 0, 0);
}

void GameObject::Init()
{
    MakeMesh();
        
    vertexBuffer = new VertexBuffer(vertices.data(), sizeof(VertexColor), vertices.size());    
    indexBuffer = new IndexBuffer(indices.data(), indices.size());
}
