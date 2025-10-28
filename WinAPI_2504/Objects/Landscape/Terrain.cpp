#include "Framework.h"

Terrain::Terrain() : Plane(L"Resources/Textures/HeightMaps/HeightMap.png")
{
	material->SetShader(L"Landscape/Terrain.hlsl");
	material->SetDiffuseMap(L"Resources/Textures/Landscape/Dirt2.png");

	alphaMap = Texture::Add(L"Resources/Textures/HeightMaps/AlphaMap.png");
	secondMap = Texture::Add(L"Resources/Textures/Landscape/Dirt.png");
}

Terrain::~Terrain()
{
}

void Terrain::Render()
{
	alphaMap->PSSet(10);
	secondMap->PSSet(11);

	Plane::Render();
}
