#include "Framework.h"

TerrainEditor::TerrainEditor() : width(100), height(100)
{
	material->SetShader(L"Landscape/TerrainEditor.hlsl");
	material->SetDiffuseMap(L"Resources/Textures/Landscape/Dirt2.png");

	mesh = new Mesh<VertexType>();
	MakeMesh();
	MakeNormal(mesh);
    MakeComputeData();
	mesh->CreateMesh();

    brushBuffer = new BrushBuffer();

    //Compute
    computeShader = Shader::AddCS(L"Compute/ComputePicking.hlsl");
    structuredBuffer = new StructuredBuffer(
        inputs.data(), sizeof(InputDesc), triangleSize,
        sizeof(OutputDesc), triangleSize);
    rayBuffer = new RayBuffer();
}

TerrainEditor::~TerrainEditor()
{
	delete mesh;
	delete brushBuffer;
	delete structuredBuffer;
	delete rayBuffer;
}

void TerrainEditor::Update()
{
    //Picking();
    //brushBuffer->Get().pickingPos = pickingPos;
	if (ComputePicking(pickingPos))
		brushBuffer->Get().pickingPos = pickingPos;
}

void TerrainEditor::Render()
{
	brushBuffer->SetPS(10);

	SetRender();
	mesh->Draw();
}

void TerrainEditor::GUIRender()
{
    ImGui::Text("PickingPos : %f, %f, %f", pickingPos.x, pickingPos.y, pickingPos.z);

    ImGui::DragFloat("BrushRange", &brushBuffer->Get().range);
    ImGui::ColorEdit3("BrushColor", (float*)&brushBuffer->Get().color);
}

void TerrainEditor::Picking()
{
    Ray ray = CAM->ScreenPointToRay(mousePos);

    for (UINT z = 0; z < height - 1; z++)
    {
        for (UINT x = 0; x < width - 1; x++)
        {
            UINT index[4];
            index[0] = width * z + x;
            index[1] = width * z + x + 1;
            index[2] = width * (z + 1) + x;
            index[3] = width * (z + 1) + x + 1;

            vector<VertexType>& vertices = mesh->GetVertices();

            Vector3 p[4];
            FOR(4)
                p[i] = vertices[index[i]].pos;

            float distance = 0.0f;

            if (Intersects(ray.origin, ray.direction, p[0], p[1], p[2], distance))
            {
                pickingPos = ray.origin + ray.direction * distance;
                return;
            }
            if (Intersects(ray.origin, ray.direction, p[3], p[1], p[2], distance))
            {
                pickingPos = ray.origin + ray.direction * distance;
                return;
            }
        }
    }
}

bool TerrainEditor::ComputePicking(Vector3& pos)
{
    Ray ray = CAM->ScreenPointToRay(mousePos);

    rayBuffer->Get().pos = ray.origin;
    rayBuffer->Get().dir = ray.direction;
    rayBuffer->Get().triangleSize = triangleSize;

    rayBuffer->SetCS(0);

    DC->CSSetShaderResources(0, 1, &structuredBuffer->GetSRV());
    DC->CSSetUnorderedAccessViews(0, 1, &structuredBuffer->GetUAV(), nullptr);

    computeShader->Set();

    UINT x = ceil((float)triangleSize / 64.0f);

    DC->Dispatch(x, 1, 1);

    structuredBuffer->Copy(outputs.data(), sizeof(OutputDesc) * triangleSize);

    float minDistance = FLT_MAX;
    int minIndex = -1;

    UINT index = 0;
    for (OutputDesc output : outputs)
    {
        if (output.picked)
        {
            if (minDistance > output.distance)
            {
                minDistance = output.distance;
                minIndex = index;
            }
        }
        index++;
    }

    if (minIndex >= 0)
    {
        pos = ray.origin + ray.direction * minDistance;
        return true;
    }

    return false;
}

void TerrainEditor::MakeMesh()
{
    vector<VertexType>& vertices = mesh->GetVertices();
    vertices.clear();

    vertices.reserve(width * height);
    for (UINT z = 0; z < height; z++)
    {
        for (UINT x = 0; x < width; x++)
        {
            VertexType vertex;
            vertex.pos = { (float)x, 0.0f, (float)z };
            vertex.uv.x = x / (float)(width - 1);
            vertex.uv.y = z / (float)(height - 1);

            UINT index = width * z + x;            

            vertices.push_back(vertex);
        }
    }

    //Indices
    vector<UINT>& indices = mesh->GetIndices();
    indices.clear();

    indices.reserve((width - 1) * (height - 1) * 6);

    for (UINT z = 0; z < height - 1; z++)
    {
        for (UINT x = 0; x < width - 1; x++)
        {
            indices.push_back(width * z + x);//0
            indices.push_back(width * (z + 1) + x);//1
            indices.push_back(width * z + x + 1);//2

            indices.push_back(width * z + x + 1);//2
            indices.push_back(width * (z + 1) + x);//1
            indices.push_back(width * (z + 1) + x + 1);//3
        }
    }
}

void TerrainEditor::MakeComputeData()
{
    vector<VertexType> vertices = mesh->GetVertices();
    vector<UINT> indices = mesh->GetIndices();

    triangleSize = indices.size() / 3;

    inputs.resize(triangleSize);
    outputs.resize(triangleSize);

    for (UINT i = 0; i < triangleSize; i++)
    {
        UINT index0 = indices[i * 3 + 0];
        UINT index1 = indices[i * 3 + 1];
        UINT index2 = indices[i * 3 + 2];

        inputs[i].v0 = vertices[index0].pos;
        inputs[i].v1 = vertices[index1].pos;
        inputs[i].v2 = vertices[index2].pos;
    }
}
