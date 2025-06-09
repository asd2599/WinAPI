#pragma once

class TileGameScene : public Scene
{
public:
	TileGameScene();
	~TileGameScene();	

	void Update() override;
	void Render() override;
	void GUIRender() override;

private:
	TileMap* tileMap = nullptr;
	Tank* tank;
};