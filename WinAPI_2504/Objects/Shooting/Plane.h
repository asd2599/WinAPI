#pragma once

class Plane : public GameObject
{
private:
	const float SPEED = 100.0f;

public:
	Plane();
	~Plane();

	void Update();

private:
	void MakeMesh() override;
};