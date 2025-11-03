#pragma once

class TerrainLODScene : public Scene
{
public:
	TerrainLODScene();
	~TerrainLODScene();	

	// Scene을(를) 통해 상속됨
	void Update() override;
	void PreRender() override;
	void Render() override;
	void PostRender() override;
	void GUIRender() override;

private:
	TerrainLOD* terrainLOD;
};