#pragma once

class TerrainScene : public Scene
{
public:
	TerrainScene();
	~TerrainScene();	

	void Update() override;
	void PreRender() override;
	void Render() override;
	void PostRender() override;
	void GUIRender() override;

private:
	Terrain* terrain;
	Skybox* skybox;
};