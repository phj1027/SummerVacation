#include "framework.h" // framework�� �׻� ������
#include "Scene.h"
#include "Object.h" // vector<Object*> vObjects;�� Object����ϱ� ���� 



Scene::Scene()
{
	Init();
}

Scene::Scene(stack<Scene*>* scene) : scenes(scenes)
{
	Init();
}

Scene::~Scene()
{

}

void Scene::Init()
{
}

bool Scene::GetQuit() const
{
	return quit;
}

void Scene::EndScene()
{
	quit = true;
}

void Scene::Update(const float& deltaTime)
{


	for (auto& obj : vObjects)
	{
		obj->Update(deltaTime);
	}
}

void Scene::Render(RenderWindow* window)
{
	for (auto& obj : vObjects)
	{
		window->draw(*obj);
	}
}