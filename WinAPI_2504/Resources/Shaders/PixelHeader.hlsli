cbuffer ColorBuffer : register(b0)
{
    float4 color;
}

cbuffer LightBuffer : register(b1)
{
    float3 lightDirection;
}

Texture2D diffuseMap : register(t0);
SamplerState samplerState : register(s0);