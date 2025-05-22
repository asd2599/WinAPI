#pragma once

class GameObject : public Transform
{
public:
	GameObject();
	GameObject(wstring shaderFile);
	~GameObject();	

	virtual void Render();
	
	void SetColor(float r, float g, float b, float a = 1.0f);

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
	IndexBuffer* indexBuffer = nullptr;

	MatrixBuffer* worldBuffer;

	ColorBuffer* colorBuffer;
};