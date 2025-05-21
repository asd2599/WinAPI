#pragma once

class Environment : public Singleton<Environment>
{
	friend class Singleton;

private:
	Environment();
	~Environment();

	void CreateProjection();

private:
	MatrixBuffer* viewBuffer;
	MatrixBuffer* projectionBuffer;
};