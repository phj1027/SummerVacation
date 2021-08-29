#include "framework.h"
#include "GameScene.h"
#include "PauseScene.h"
#include "ResultScene.h"
#include "Character.h"
#include "BigZombie.h"

GameScene::GameScene()
{
	Init();
}

GameScene::GameScene(stack<Scene*>* scene, RenderWindow* window) : Scene(scenes, window)
{
	Init();
}

GameScene::~GameScene()
{

}

void GameScene::Init()
{

	animationObjects.push_back(new Character);
	animationObjects.push_back(new BigZombie);
}

void GameScene::Input(Event* e)
{
	switch (e->key.code)
	{

	case Keyboard::Space:
	{
		scenes->push(new ResultScene(scenes,window));
		cout << "ResultScene Scene\n";
		break;
	}
	case Keyboard::P:
	{
		scenes->push(new PauseScene(scenes, window));
		cout << "Pause Scene\n";
		break;
	}
	default:
		break;
	}
}

void GameScene::Destroy()
{

}

void GameScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void GameScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}