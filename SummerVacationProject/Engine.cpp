#include "framework.h"
#include "Engine.h"
#include "TitleScene.h"


Engine::Engine()
{
	Init(); // 생성되었을때 바로 초기화 
}

Engine::~Engine()
{

}

void Engine::Init()
{
	// 현재 window 변수는 포인터로 존재함
	this->window = new RenderWindow(VideoMode(500, 500), "Adventure Time with Finn and Jake");
	// this는 현재 작성하고있는 Engine을 의미함 == Engine의 window

	window->setMouseCursorVisible(true); // 마우스 커서 보이게 설정

	// 윈도우창 아이콘 꾸미기
	Image icon;
	icon.loadFromFile("Textures/1.jpg");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	this->scenes.push(new TitleScene(&scenes,window)); // 아무것도 없는 장면 
	cout << "TitleScene!!\n";
	
}

void Engine::Destroy()
{
	// Init에서 window는 new로 동적할당을 받았기 때문에 풀어줘야함
	// window가 nullptr이 아니라면
	if (window)
	{
		delete window;
	}
}

void Engine::Input()
{
	// 이벤트는 외부로부터 이벤트를 받는거니까 input 
	while (window->pollEvent(evt))
	{
		switch (evt.type)
		{
		case Event::Closed:
		{
			window->close();
			break;
		}
		// 키보드 이벤트
		case Event::KeyPressed: // 한번입력할때 한번실행 -> 스킬쓸때 활용
		{
			if (!scenes.empty())
			{
				scenes.top()->Input(&evt);
			}
		}
		default:
			break;
		}
	}


	//// Mouse Input
	//if (Mouse::isButtonPressed(Mouse::Left))
	//{
	//	window->setTitle("Left Click");
	//}
	//else if (Mouse::isButtonPressed(Mouse::Right))
	//{
	//	window->setTitle("Right Click");
	//}
	//else
	//{
	//	window->setTitle("Adventure Time with Finn and Jake");
	//}
}

void Engine::Update()
{
	// 시간도 update해야함
	deltaTime = timer.getElapsedTime().asSeconds();

	timer.restart();

	// input은 매프레임 실행되기때문에 update의 일부분
	Input();

	if (!scenes.empty())
	{
		scenes.top()->Update(deltaTime);
		if (this-> scenes.top()->GetQuit())
		{
			//현재 실행중인 scene을 종료 
			delete this->scenes.top();
			this->scenes.pop();
			cout << "Pop Scene\n";
		}
	}
	else
	{
		window->close(); //scene이 없으면 게임 끄기
	}
}

void Engine::Render()
{

	while (window->isOpen())
	{
		window->clear();
		Update();
		
		if (!scenes.empty())
		{
			scenes.top()->Render(window);
		}
	


		window->display();
	}
}