#pragma once

class Plane : public GameObject
{
private:
	const float SPEED = 200.0f;

public:
	Plane();
	~Plane();

	void Update();
	void Render();
	Vector2 GetHalfSize();
private:
	void ControlKeyboard();
	void ControlMouse();

private:
	void MakeMesh() override;

private:
	Collider* collider;
};