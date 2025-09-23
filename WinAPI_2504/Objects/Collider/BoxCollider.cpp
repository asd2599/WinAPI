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
    return false;
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
