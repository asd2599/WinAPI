#pragma once

class GameObject : public Transform
{
public:
	GameObject();
	~GameObject();	

	void Render();
	
	void SetActive(bool isActive) { this->isActive = isActive; }
	bool IsActive() { return isActive; }	

protected:
	void Init();

private:
	virtual void MakeMesh() = 0;

protected:
	bool isActive = true;

	vector<VertexColor> vertices;
	vector<UINT> indices;

	VertexShader* vertexShader;
	PixelShader* pixelShader;

	VertexBuffer* vertexBuffer;
	IndexBuffer* indexBuffer;

	MatrixBuffer* worldBuffer;

	ColorBuffer* colorBuffer;
};