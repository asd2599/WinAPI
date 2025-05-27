#pragma once

class TextureScene : public Scene
{
public:
	TextureScene();
	~TextureScene();

	void Update() override;
	void Render() override;

private:
	Bird* bird;
};