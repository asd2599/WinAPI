#pragma once

class BoxCollider : public Collider
{
public:
	BoxCollider(Vector3 size = Vector3(1, 1, 1));
	~BoxCollider();

	bool IsRayCollision(const Ray& ray, RayHit* hitInfo) override;
	bool IsBoxCollision(BoxCollider* collider) override;
	bool IsSphereCollision(SphereCollider* collider) override;
	bool IsCapsuleCollision(CapsuleCollider* collider) override;

private:
	void MakeMesh() override;

private:
	Vector3 size;
};
