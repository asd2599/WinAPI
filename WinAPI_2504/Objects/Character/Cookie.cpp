#include "Framework.h"

Cookie::Cookie() : RectCollider(Vector2(200, 200))
{
	CreateClips();
	clipTransform = new Transform();
	clipTransform->SetTag("CookieClip");
	clipTransform->SetParent(this);

	worldBuffer = new MatrixBuffer();
}

Cookie::~Cookie()
{
	for (Clip* clip : clips)
		delete clip;

	delete clipTransform;
	delete worldBuffer;
}

void Cookie::Update()
{
	if (Input::Get()->IsKeyDown('1'))
		curState = Run;

	if (Input::Get()->IsKeyDown('2'))
		curState = Roll;

	if (Input::Get()->IsKeyDown('3'))
		curState = Idle;

	if (Input::Get()->IsKeyDown('4'))
	{
		curState = Dead;
		clips[curState]->Play();
	}

	clips[curState]->Update();

	clipTransform->UpdateWorld();
	UpdateWorld();
}

void Cookie::Render()
{
	Collider::Render();

	worldBuffer->Set(clipTransform->GetWorld());
	worldBuffer->SetVS(0);
	clips[curState]->Render();
}

void Cookie::Edit()
{
	clipTransform->Edit();
	Transform::Edit();
}

void Cookie::CreateClips()
{
	vector<Frame*> frames;	
	frames.push_back(new Frame(L"Resources/Textures/Cookie/cookie0034z03_run01.png"));
	frames.push_back(new Frame(L"Resources/Textures/Cookie/cookie0034z03_run02.png"));
	frames.push_back(new Frame(L"Resources/Textures/Cookie/cookie0034z03_run03.png"));
	frames.push_back(new Frame(L"Resources/Textures/Cookie/cookie0034z03_run04.png"));

	clips.push_back(new Clip(frames, true));

	frames.clear();
	for (int i = 0; i < 7; i++)
	{
		wstring file = L"Resources/Textures/Cookie/cookie0034z03x2_000" + to_wstring(i + 1);
		file += L".png";

		frames.push_back(new Frame(file));
	}	

	clips.push_back(new Clip(frames, true));

	LoadClip("Resources/Textures/RedHat/", "RedHat_Idle.xml", true);
	LoadClip("Resources/Textures/RedHat/", "RedHat_Dead.xml", false);
}

void Cookie::LoadClip(string path, string file, bool isLoop, float speed)
{
	tinyxml2::XMLDocument* document = new tinyxml2::XMLDocument();
	document->LoadFile((path + file).c_str());

	tinyxml2::XMLElement* atlas = document->FirstChildElement();
	string textureFile = path + atlas->Attribute("imagePath");

	vector<Frame*> frames;
	tinyxml2::XMLElement* sprite = atlas->FirstChildElement();

	while (sprite != nullptr)
	{
		float x, y, w, h;
		x = sprite->FloatAttribute("x");
		y = sprite->FloatAttribute("y");
		w = sprite->FloatAttribute("w");
		h = sprite->FloatAttribute("h");

		wstring file = Utility::ToWString(textureFile);
		frames.push_back(new Frame(file, x, y, w, h));

		sprite = sprite->NextSiblingElement();
	}

	clips.push_back(new Clip(frames, isLoop, speed));

	delete document;
}
