#include "Framework.h"

Model::Model(string name) : name(name)
{
	ReadMaterial();
	ReadMesh();
}

Model::~Model()
{
}

void Model::ReadMaterial()
{
}

void Model::ReadMesh()
{
	string file = "Resources/Models/Meshes/" + name + ".mesh";

	BinaryReader* reader = new BinaryReader(file);
	if (reader->IsFailed())
		assert(false);

	UINT size = reader->UInt();

	for (UINT i = 0; i < size; i++)
	{
		string name = reader->String();
		UINT materialIndex = reader->UInt();

		vector<ModelVertex> vertices;		
		UINT vertexCount = reader->UInt();
		vertices.resize(vertexCount);		
		reader->Byte(vertices.data(), sizeof(ModelVertex) * vertexCount);

		vector<UINT> indices;
		UINT indexCount = reader->UInt();
		indices.resize(indexCount);				
		reader->Byte(indices.data(), sizeof(UINT) * indexCount);

		reader->Int();
	}
}
