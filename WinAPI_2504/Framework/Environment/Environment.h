#pragma once

class Environment : public Singleton<Environment>
{
	friend class Singleton;

private:
	Environment();
	~Environment();

	void CreateProjection();
	void CreateSamplerState();
	void CreateBlendState();

private:
	MatrixBuffer* viewBuffer;
	MatrixBuffer* projectionBuffer;

	ID3D11SamplerState* samplerState;
	ID3D11BlendState* alphaBlendState;
};