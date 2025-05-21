#include "Framework.h"
#include "Environment.h"

Environment::Environment()
{
	CreateProjection();
}

Environment::~Environment()
{
	delete viewBuffer;
	delete projectionBuffer;
}

void Environment::CreateProjection()
{
    viewBuffer = new MatrixBuffer();
    projectionBuffer = new MatrixBuffer();

    //Orthographic : 원근감이 없는 직육면체의 절두체를 형성하는 투영변환
    Matrix projection = XMMatrixOrthographicOffCenterLH(0.0f, SCREEN_WIDTH, 0.0f, SCREEN_HEIGHT, -1.0f, 1.0f);

    viewBuffer->SetVS(1);

    projectionBuffer->Set(projection);
    projectionBuffer->SetVS(2);
}
