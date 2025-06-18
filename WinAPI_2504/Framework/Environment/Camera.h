#pragma once

class Camera : public Transform
{
public:
	Camera();
	~Camera();

	void Update();

	void SetTarget(Transform* target) { this->target = target; }

	void SetLeftBottom(float x, float y) { leftBottom = { x, y }; }
	void SetLeftBottom(Vector2 pos) { leftBottom = pos; }
	void SetRightTop(float x, float y) { rightTop = { x, y }; }
	void SetRightTop(Vector2 pos) { rightTop = pos; }

private:
	void FreeMode();
	void FollowMode();

	void FixPosition(Vector2& pos);

private:
	float speed = 10.0f;
	Matrix view;

	MatrixBuffer* viewBuffer;	

	Vector2 leftBottom;
	Vector2 rightTop = { SCREEN_WIDTH, SCREEN_HEIGHT };

	Transform* target = nullptr;
	Vector2 targetOffset = { CENTER_X, CENTER_Y };

	bool isFix = true;
};