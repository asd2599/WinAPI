cbuffer MateiralBuffer : register(b0)
{
    float4 mDiffuse;
    float4 mSpecular;
    float4 mAmbient;
    float4 mEmissive;
    
    float shininess;
}

cbuffer LightBuffer : register(b1)
{
    float4 ambient;
    float3 lightDirection;
}

Texture2D diffuseMap : register(t0);
Texture2D specularMap : register(t1);
Texture2D normalMap : register(t2);

SamplerState samplerState : register(s0);