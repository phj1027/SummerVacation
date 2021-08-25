#include "framework.h"
#include "GameScene.h"
#include "Character.h"
#include "BigZombie.h"

GameScene::GameScene()
{
	Init();
}

GameScene::GameScene(stack<Scene*>* scenes) : Scene(scenes)
{
	Init();
}

GameScene::~GameScene()
{

}

void GameScene::Init()
{

	vObjects.push_back(new Character);
	vObjects.push_back(new BigZombie);
}

void GameScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void GameScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}