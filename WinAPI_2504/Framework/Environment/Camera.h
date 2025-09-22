#pragma once

class Camera : public Transform
{
public:
	Camera();
	~Camera();

	void Update();

	void SetTarget(Transform* target) { this->target = target; }

private:
	void FreeMode();
	void FollowMode();

private:
	float moveSpeed = 10.0f;
	float rotSpeed = 10.0f;
	Vector3 prevMousePos;

	Matrix view;
	MatrixBuffer* viewBuffer;	

	Transform* target = nullptr;	
};