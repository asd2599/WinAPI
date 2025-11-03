#pragma once

class TerrainLOD : public GameObject
{
private:
    typedef VertexUV VertexType;

public:
    TerrainLOD(wstring heightFile);
    ~TerrainLOD();

    void Render();
    void GUIRender();

private:
    void MakeMesh();

private:
	Mesh<VertexType>* mesh;

    FloatValueBuffer* terrainBuffer;
    FloatValueBuffer* heightBuffer;

    HullShader* hullShader;
    DomainShader* domainShader;

    Texture* heightMap;

    UINT cellsPerPatch = 32;
    float cellSpacing = 5;
    Vector2 cellUV;

    UINT width, height;
    UINT patchWidth, patchHeight;
};