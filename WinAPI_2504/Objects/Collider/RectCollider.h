#pragma once

class RectCollider : public Collider
{
public:
	RectCollider(Vector2 size = Vector2(50, 50));
	~RectCollider() = default;
	
	bool IsPointCollision(const Vector2& point) override;
	bool IsRectCollision(RectCollider* rect, Vector2* overlap) override;
	bool IsCircleCollision(CircleCollider* circle) override;	

	Vector2 LeftTop();
	Vector2 LeftBottom();
	Vector2 RightTop();
	Vector2 RightBottom();

	float Left();
	float Right();
	float Top();
	float Bottom();

private:
	void MakeMesh() override;

private:
	Vector2 size;
};