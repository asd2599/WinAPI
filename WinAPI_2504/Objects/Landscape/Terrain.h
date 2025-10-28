#pragma once

class Terrain : public Plane
{
private:
	

public:
	Terrain();
	~Terrain();

	void Render();

private:
	Texture* alphaMap;
	Texture* secondMap;
};