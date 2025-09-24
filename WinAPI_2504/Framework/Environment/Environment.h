#pragma once

class Environment : public Singleton<Environment>
{
	friend class Singleton;

private:
	Environment();
	~Environment();

public:
	void Update();
	void Edit();

	void SetViewport(UINT width = SCREEN_WIDTH, UINT height = SCREEN_HEIGHT);
	void SetUIViewBuffer();

	Camera* GetMainCamera() { return mainCamera; }
	Matrix GetPerspective() { return perspective; }

private:
	void CreateProjection();
	void CreateSamplerState();
	void CreateBlendState();
	void CreateStats();

private:
	bool isWireFrame = false;

	Matrix perspective;

	Camera* mainCamera;
	MatrixBuffer* projectionBuffer;
	MatrixBuffer* uiViewBuffer;

	ID3D11SamplerState* samplerState;
	ID3D11BlendState* alphaBlendState;	

	RasterizerState* rasterizerState[2];
};