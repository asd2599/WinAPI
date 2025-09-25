#include "Framework.h"

BoxCollider::BoxCollider(Vector3 size) : size(size)
{
    type = Type::Box;

    MakeMesh();
    mesh->CreateMesh();
}

BoxCollider::~BoxCollider()
{
	delete mesh;
}

bool BoxCollider::IsRayCollision(const Ray& ray, RayHit* hitInfo)
{
	UpdateWorld();

	ObbDesc box;
	GetOBB(box);

	Vector3 min = box.halfSize * -1.0f;
	Vector3 max = box.halfSize;

	Vector3 delta = box.center - ray.origin;

	Vector3 D = ray.direction.GetNormalized();

	float tMin = 0.0f;
	float tMax = FLT_MAX;

	for (int i = 0; i < 3; i++)
	{
		Vector3 axis = box.axis[i];
		float e = Vector3::Dot(axis, delta);
		float f = Vector3::Dot(D, axis);

		if (GameMath::NearlyEqual(f, 0.0f))
		{
			if (min[i] > e || e > max[i])
				return false;
		}
		else
		{
			float t1 = (e + min[i]) / f;
			float t2 = (e + max[i]) / f;

			if (t1 > t2)
				swap(t1, t2);

			if (t2 < tMax)
				tMax = t2;
			if (t1 > tMin)
				tMin = t1;

			if (tMax < tMin)
				return false;
		}
	}

	if (hitInfo)
	{
		hitInfo->isHit = true;
		hitInfo->distance = tMin;
		hitInfo->position = ray.origin + D * hitInfo->distance;
		hitInfo->normal = (hitInfo->position - box.center).GetNormalized();
	}

    return true;
}

bool BoxCollider::IsBoxCollision(BoxCollider* collider)
{
    return false;
}

bool BoxCollider::IsSphereCollision(SphereCollider* collider)
{
    return false;
}

bool BoxCollider::IsCapsuleCollision(CapsuleCollider* collider)
{
    return false;
}

void BoxCollider::GetOBB(ObbDesc& desc)
{	
	desc.center = GetGlobalPosition();
	desc.axis[0] = GetRight();
	desc.axis[1] = GetUp();
	desc.axis[2] = GetForward();
	desc.halfSize = size * 0.5f * GetGlobalScale();
}

void BoxCollider::MakeMesh()
{
	Vector3 halfSize = size * 0.5f;
	vector<Vertex>& vertices = mesh->GetVertices();
	
	vertices.emplace_back(-halfSize.x, +halfSize.y, -halfSize.z);
	vertices.emplace_back(+halfSize.x, +halfSize.y, -halfSize.z);
	vertices.emplace_back(+halfSize.x, -halfSize.y, -halfSize.z);
	vertices.emplace_back(-halfSize.x, -halfSize.y, -halfSize.z);
    
	vertices.emplace_back(-halfSize.x, +halfSize.y, +halfSize.z);
	vertices.emplace_back(+halfSize.x, +halfSize.y, +halfSize.z);
	vertices.emplace_back(+halfSize.x, -halfSize.y, +halfSize.z);
	vertices.emplace_back(-halfSize.x, -halfSize.y, +halfSize.z);

	vector<UINT>& indices = mesh->GetIndices();
	indices = {
		0, 1, 3, 2, 4, 5, 7, 6,
		0, 3, 1, 2, 4, 7, 5, 6,
		0, 4, 1, 5, 3, 7, 2, 6
	};
}
