#pragma once

#include "Button.h"

class Object; // vector<Object*> vObjects;를 쓰기위해 

class Scene // Scene은 상속받는 애들이 많음 _ 지금 마더 클래스를 만드는것
{
public:
	Scene();
	Scene(stack<Scene*>* scenes, RenderWindow* window); //Scene*를 담고있는 스택의 포인터
	virtual ~Scene();

protected:

	// 씬에서 오브젝트들을 관리 
	vector<Object*> animationObjects;
	vector<Object*>staticObjects;
	// ㄴ> 백터와 관련되어있으니까 v붙여준것 

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
	// ㄴ> 그려줄 곳을 말함 

};