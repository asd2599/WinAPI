#pragma once

class Bullet : public GameObject
{
private:
	const float SPEED = 200.0f;

public:
	Bullet();
	~Bullet();

	void Update();
	void Render();
	void SetPaddle(Plane* plane) { this->plane = plane; }
	void Fire();
	void IsScreenCollision();
	void IsPaddleCollision();
private:
	void MakeMesh() override;

private:
	Vector2 velocity = { 0, SPEED };	
	Plane* plane = nullptr;
};