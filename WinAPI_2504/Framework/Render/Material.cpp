#include "Framework.h"

Material::Material(wstring shaderFile)
{
    vertexShader = Shader::AddVS(shaderFile);
    pixelShader = Shader::AddPS(shaderFile);

    materialBuffer = new MaterialBuffer();
}

Material::~Material()
{
	delete materialBuffer;
}

void Material::Edit()
{
	ImGui::ColorEdit4("mDiffuse", (float*)&materialBuffer->GetData()->diffuse);
	ImGui::ColorEdit4("mSpecular", (float*)&materialBuffer->GetData()->specular);
	ImGui::ColorEdit4("mAmbient", (float*)&materialBuffer->GetData()->ambient);
	ImGui::SliderFloat("Shininess", &materialBuffer->GetData()->shininess, 1, 30);
}

void Material::SetColor(float r, float g, float b, float a)
{
	materialBuffer->GetData()->diffuse = { r, g, b, a };
}

void Material::SetShader(wstring file)
{
	vertexShader = Shader::AddVS(file);
	pixelShader = Shader::AddPS(file);
}

void Material::SetVertexShader(wstring file)
{
	vertexShader = Shader::AddVS(file);
}

void Material::SetPixelShader(wstring file)
{
	pixelShader = Shader::AddPS(file);
}

void Material::Set()
{
	if (diffuseMap)
		diffuseMap->PSSet(0);

	if (specularMap)
		specularMap->PSSet(1);

	if (normalMap)
		normalMap->PSSet(2);

	materialBuffer->SetPS(0);

	vertexShader->Set();
	pixelShader->Set();
}

void Material::SetDiffuseMap(wstring file)
{
	diffuseMap = Texture::Add(file);
}

void Material::SetSpecularMap(wstring file)
{
	specularMap = Texture::Add(file);
}

void Material::SetNormalMap(wstring file)
{
	normalMap = Texture::Add(file);
}
