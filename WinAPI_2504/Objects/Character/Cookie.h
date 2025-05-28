#pragma once

class Cookie : public RectCollider
{
private:
	enum ActionState
	{
		Run, Roll, Idle, Dead
	};

public:
	Cookie();
	~Cookie();

	void Update();
	void Render();
	void Edit();

private:
	void CreateClips();
	void LoadClip(string path, string file, bool isLoop, float speed = 1.0f);

private:
	ActionState curState = Run;

	Transform* clipTransform;
	MatrixBuffer* worldBuffer;

	vector<Clip*> clips;	
};