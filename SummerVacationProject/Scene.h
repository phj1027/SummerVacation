#pragma once

#include "Button.h"

class Object; // vector<Object*> vObjects;�� �������� 

class Scene // Scene�� ��ӹ޴� �ֵ��� ���� _ ���� ���� Ŭ������ ����°�
{
public:
	Scene();
	Scene(stack<Scene*>* scenes, RenderWindow* window); //Scene*�� ����ִ� ������ ������
	virtual ~Scene();

protected:

	// ������ ������Ʈ���� ���� 
	vector<Object*> animationObjects;
	vector<Object*>staticObjects;
	// ��> ���Ϳ� ���õǾ������ϱ� v�ٿ��ذ� 

	map<string, Text*> mTexts;
	map<string, Button*> mButtons;
	stack<Scene*>* scenes = nullptr;
	RenderWindow* window = nullptr;
	Vector2f mousePosition{ 0.f,0.f };
	bool quit = false;

private:

	virtual void Init();

public:

	bool GetQuit() const;
	void EndScene();

	virtual void Input(Event* e);
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);
	// ��> �׷��� ���� ���� 

};