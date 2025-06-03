cbuffer WorldBuffer : register(b0)
{
    matrix world;
}
cbuffer ViewBuffer : register(b1)
{
    matrix view;
}
cbuffer ProjectionBuffer : register(b2)
{
    matrix projection;
}

struct Input
{
    float4 pos : POSITION;
    float2 uv : UV;
};

struct Output
{
    float4 pos : SV_POSITION;
    float2 uv : UV;
};

Output VS(Input input)
{
    Output output;
    output.pos = mul(input.pos, world);
    output.pos = mul(output.pos, view);
    output.pos = mul(output.pos, projection);
    
    output.uv = input.uv;
    
    return output;
}

cbuffer ColorBuffer : register(b0)
{
    float4 color;
}

Texture2D baseMap : register(t0);
SamplerState samplerState : register(s0);

cbuffer FilterBuffer : register(b1)
{
    float filterType; // 0 for Grayscale, 1 for Sepia, etc.
    float filterValue;
    
    float2 imageSize;
}

float4 Grayscale(float4 color)
{
    float scale = (color.r + color.g + color.b) / 3;
    
    //return float4(scale, scale, scale, color.a);
    return float4(scale.xxx, color.a);
}

float4 Grayscale2(float4 color)
{
    //float3 grayColor;
    //grayColor.r = color.r * 0.3f;
    //grayColor.g = color.g * 0.59f;
    //grayColor.b = color.b * 0.11f;
    //
    //float scale = grayColor.r + grayColor.g + grayColor.b;
    
    float scale = dot(color.rgb, float3(0.3f, 0.59f, 0.11f));
    
    return float4(scale.xxx, color.a);
}

float4 Sepia(float4 color)
{
    float3 sepiaColor;
    sepiaColor.r = dot(color.rgb, float3(0.393f, 0.769f, 0.189f));
    sepiaColor.g = dot(color.rgb, float3(0.349f, 0.686f, 0.168f));
    sepiaColor.b = dot(color.rgb, float3(0.272f, 0.534f, 0.131f));
    
    return float4(sepiaColor, color.a);
}

float4 Mosaic(float2 uv)
{
    float2 temp = floor(uv * filterValue) / filterValue;
    
    return baseMap.Sample(samplerState, temp);
}

float4 Blur(float2 uv)
{
    
    return baseMap.Sample(samplerState, uv);
}

float4 PS(Output output) : SV_TARGET
{
    float4 baseColor = baseMap.Sample(samplerState, output.uv);
    
    if(filterType == 1)
        return Grayscale(baseColor);
    else if (filterType == 2)
        return Grayscale2(baseColor);
    else if (filterType == 3)
        return Sepia(baseColor);
    else if (filterType == 4)
        return Mosaic(output.uv);
    
    return baseColor * color;
}