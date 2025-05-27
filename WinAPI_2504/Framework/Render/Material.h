#pragma once

class Material
{
public:
	Material(wstring shaderFile = L"Texture.hlsl");
	~Material();	

	void SetColor(float r, float g, float b, float a = 1.0f);

	void SetVertexShader(wstring file);
	void SetPixelShader(wstring file);

	void Set();
	
	void SetBaseMap(wstring file);
	Texture* GetBaseMap() { return baseMap; }

private:
	VertexShader* vertexShader;
	PixelShader* pixelShader;

	ColorBuffer* colorBuffer;

	Texture* baseMap;
};