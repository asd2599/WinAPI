#pragma once

class TextureScene : public Scene
{
private:
	const float BG_SPEED = 200.0f;

public:
	TextureScene();
	~TextureScene();

	void Update() override;
	void Render() override;
	void PostRender() override;

private:
	Bird* bird;
	Quad* quad;

	Quad* ui;
};