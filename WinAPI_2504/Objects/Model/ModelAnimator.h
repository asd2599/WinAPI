#pragma once

class ModelAnimator : public Model
{
protected:
    struct ClipTransform
    {
        Matrix transform[MAX_FRAME][MAX_BONE];

        ClipTransform()
        {
            for (int i = 0; i < MAX_FRAME; i++)
            {
                for (int j = 0; j < MAX_BONE; j++)
                {
                    transform[i][j] = XMMatrixIdentity();
                }
            }
        }
    };

    struct Frame
    {
        int clip = 0;
        int curFrame = 0;
        float time = 0.0f;
        float scale = 1.0f;
    };

    class FrameBuffer : public ConstBuffer
    {
    public:
        FrameBuffer() : ConstBuffer(&motion, sizeof(Frame))
        {
        }

        Frame* GetData() { return &motion; }

    private:
        Frame motion;
    };

public:
    ModelAnimator(string name);
    ~ModelAnimator();

    void Update();
    void Render();

    void Edit();

    void ReadClip(string clipName, UINT clipNum = 0);

    void CreateTexture();

protected:
    void CreateClipTransform(UINT index);

    UINT GetMaxFrameNum();

protected:
    vector<ModelClip*> clips;

    ClipTransform* clipTransforms;
    ClipTransform* nodeTransforms;

    ID3D11Texture2D* texture = nullptr;
    ID3D11ShaderResourceView* srv;

    FrameBuffer* frameBuffer;

    bool isPlay = true;
};