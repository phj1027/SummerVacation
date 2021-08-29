#include "framework.h"
#include "ResultScene.h"
#include "TitleScene.h"

ResultScene::ResultScene()
{
	Init();
}

ResultScene::ResultScene(stack<Scene*>* scene, RenderWindow* window) : Scene(scenes, window)
{
	Init();
}

ResultScene::~ResultScene()
{

}

void ResultScene::Init()
{


}

void ResultScene::Input(Event* e)
{

}

void ResultScene::Destroy()
{
}


void ResultScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void ResultScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}