#pragma once

class Transform
{
public:
	Transform();
	~Transform();

	void Translate(const Vector2& velocity)
	{
		pos += velocity;
	}

	void UpdateWorld();

protected:
	Vector2 pos;
	Vector2 scale = { 1, 1 };
	Float3 rot;

	Matrix world;

private:
	Matrix S, R, T;
};