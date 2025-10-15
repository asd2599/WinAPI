cbuffer WorldBuffer : register(b0)
{
    matrix world;
}
cbuffer ViewBuffer : register(b1)
{
    matrix view;
    matrix invView;
}
cbuffer ProjectionBuffer : register(b2)
{
    matrix projection;
}

cbuffer FrameBuffer : register(b3)
{
    int clip;
    int curFrame;
    float time;
    float scale;
}

Texture2DArray transformMap : register(t0);

//Functions

matrix LoadTransform(int index, int frame, int clip)
{
    float4 f0 = transformMap.Load(int4(index * 4 + 0, frame, clip, 0));
    float4 f1 = transformMap.Load(int4(index * 4 + 1, frame, clip, 0));
    float4 f2 = transformMap.Load(int4(index * 4 + 2, frame, clip, 0));
    float4 f3 = transformMap.Load(int4(index * 4 + 3, frame, clip, 0));
	
    return matrix(f0, f1, f2, f3);
}

matrix SkinWorld(float4 indices, float4 weights)
{
    matrix transform = 0;
    
    [unroll(4)]
    for (int i = 0; i < 4; i++)
    {
        if(weights[i] == 0.0f)
            continue;
        
        transform += weights[i] * LoadTransform(indices[i], curFrame, clip);
    }

    return transform;
}

//VertexLayouts

struct Vertex
{
    float4 pos : POSITION;
};

struct VertexUV
{
    float4 pos : POSITION;
    float2 uv : UV;
};

struct VertexColor
{
    float4 pos : POSITION;
    float4 color : COLOR;
};

struct VertexUVNormal
{
    float4 pos : POSITION;
    float2 uv : UV;
    float3 normal : NORMAL;
};

struct VertexUVNormalTangent
{
    float4 pos : POSITION;
    float2 uv : UV;
    float3 normal : NORMAL;
    float3 tangent : TANGENT;
};

struct VertexUVNormalTangentBlend
{
    float4 pos : POSITION;
    float2 uv : UV;
    float3 normal : NORMAL;
    float3 tangent : TANGENT;
    float4 indices : INDICES;
    float4 weights : WEIGHTS;
};

