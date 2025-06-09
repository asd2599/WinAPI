#pragma once

class TileMap : public Transform
{
public:
	TileMap(string file);
	~TileMap();
	
	void Render();
	
	void UpdateWorld();

	void PushCollision(RectCollider* tank);	

private:
	void LoadTiles(string file);
	void CreateTiles();

private:
	int cols = 0;
	int rows = 0;
	Vector2 tileSize;
	Vector2 imageSize;

	vector<Quad*> bgTiles;
	vector<GameTile*> objTiles;
};