#pragma once

class Tank : public RectCollider
{
private:
	enum AnimState
	{
		Idle, Move
	};

	const float SPEED = 200.0f;

public:
	Tank();
	~Tank();
	
	void Update();
	void Render();

	void SetTileMap(TileMap* tileMap) { this->tileMap = tileMap; }

private:
	void Control();
	void CollisionTileMap();

private:
	void CreateClips();

private:
	AnimState curState = Move;

	vector<Clip*> clips;	

	TileMap* tileMap = nullptr;
};