#include "Framework.h"
#include "DijkstraScene.h"

DijkstraScene::DijkstraScene()
{
	dijkstra = new Dijkstra();
	tank = new Tank();
	tank->SetLocalPosition(CENTER);

	CAM->SetRightTop(SCREEN_WIDTH * 2, SCREEN_HEIGHT);
}

DijkstraScene::~DijkstraScene()
{
	delete dijkstra;
	delete tank;
}

void DijkstraScene::Update()
{
	if (Input::Get()->IsKeyDown(VK_LBUTTON))
	{
		int start = dijkstra->FindCloseNode(tank->GetLocalPosition());
		int end = dijkstra->FindCloseNode(mousePos);

		tank->SetPath(dijkstra->GetPath(start, end));
	}	

	dijkstra->Update();
	tank->Update();
}

void DijkstraScene::Render()
{
	dijkstra->Render();
	tank->Render();
}
