#include "framework.h"
#include "TitleScene.h"

TitleScene::TitleScene()
{
	Init();
}

TitleScene::TitleScene(stack<Scene*>* scenes) : Scene(scenes)
{
	Init();
}

TitleScene::~TitleScene()
{

}

void TitleScene::Init()
{

	
}

void TitleScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void TitleScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}