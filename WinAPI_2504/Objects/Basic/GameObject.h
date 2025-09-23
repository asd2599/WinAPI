#pragma once

class GameObject : public Transform
{
public:
	GameObject();
	GameObject(wstring shaderFile);
	~GameObject();	

	virtual void Render() {}
	virtual void SetRender();

	void SetWorld();
	
	Material* GetMaterial() { return material; }

	void SetColor(float r, float g, float b, float a = 1.0f);

	void SetActive(bool isActive) { this->isActive = isActive; }
	bool IsActive() { return isActive; }

protected:
	bool isActive = true;

	Material* material;
	MatrixBuffer* worldBuffer;	
};