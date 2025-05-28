#include "Framework.h"

Clip::Clip(vector<Frame*> frames, bool isLoop, float speed)
    : frames(frames), isLoop(isLoop), speed(speed)
{
    intervalTime = 1.0f / FPS;
}

Clip::~Clip()
{
    for (Frame* frame : frames)
        delete frame;
}

void Clip::Update()
{
    if (!isPlay) return;

    frameTime += speed * DELTA;

    if (frameTime < intervalTime) return;

    frameTime -= intervalTime;

    curFrameNum++;

    if (isLoop)
    {
        curFrameNum %= frames.size();
    }
    else
    {
        if (curFrameNum >= frames.size())
        {
            curFrameNum--;
            Stop();
        }
    }
}

void Clip::Render()
{
    frames[curFrameNum]->Render();
}

void Clip::Play()
{
    isPlay = true;
    frameTime = 0.0f;
    curFrameNum = 0;
}

void Clip::SetShader(wstring shaderFile)
{
    for (Frame* frame : frames)
        frame->GetMaterial()->SetShader(shaderFile);
}
