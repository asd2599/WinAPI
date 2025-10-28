#pragma once

class TerrainEditor : public GameObject
{
private:
	typedef VertexUVNormal VertexType;

	const UINT MAX_SIZE = 256;
	const UINT MAX_HEIGHT = 20.0f;

	enum EditType
	{
		HEIGHT, ALPHA
	};

	struct InputDesc
	{
		Float3 v0, v1, v2;
	};

	struct OutputDesc
	{
		int picked;
		float distance;
	};

public:
	TerrainEditor();
	~TerrainEditor();
	
	void Update();
	void Render();
	void GUIRender();

	void Picking();
	bool ComputePicking(Vector3& pos);

private:
	void MakeMesh();
	void MakeComputeData();

private:
	UINT width, height, triangleSize;
	Vector3 pickingPos;

	Mesh<VertexType>* mesh;

	BrushBuffer* brushBuffer;

	//Compute
	RayBuffer* rayBuffer;
	StructuredBuffer* structuredBuffer;

	vector<InputDesc> inputs;
	vector<OutputDesc> outputs;

	ComputeShader* computeShader;
};