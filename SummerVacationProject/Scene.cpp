#include "framework.h" // framework�� �׻� ������
#include "Scene.h"
#include "Object.h" // vector<Object*> vObjects;�� Object����ϱ� ���� 


Scene::Scene()
{
	Init();
}

Scene::Scene(stack<Scene*>* scene,RenderWindow* window) : scenes(scenes),window(window)
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

void Scene::Input(Event* e)
{

}

void Scene::Update(const float& deltaTime)
{

	mousePosition = window->mapPixelToCoords(Mouse::getPosition(*window));

	for (auto& obj : animationObjects)
	{
		obj->Update(deltaTime);
	}

	for (auto& btn : mButtons)
	{
		btn.second->Update(mousePosition);
	}
}

void Scene::Render(RenderWindow* window)
{
	for (auto& obj : animationObjects)
	{
		if (obj->IsActive() == true)
		{
			window->draw(*obj);
		}
	
	}

	for (auto& btn : mButtons)
	{
		window->draw(*btn.second);
	}

	for (auto& txt : mTexts)
	{
		window->draw(*txt.second);
	}
}