#include "framework.h"
#include "GameScene2.h"
#include "Character.h"


GameScene2::GameScene2()
{
	Init();

}

GameScene2::GameScene2(stack<Scene*>* scenes) : Scene(scenes)
{
	Init();
}

GameScene2::~GameScene2()
{

}

void GameScene2::Init()
{

	vObjects.push_back(new Character);
	
}

void GameScene2::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void GameScene2::Render(RenderWindow* window)
{
	Scene::Render(window);
}