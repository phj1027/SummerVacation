#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode(500, 500), "Window");

	vector<Texture> txVector;

	Texture tx;
	char name[150];

	for (int i = 0; i <= 9; ++i)
	{
		sprintf(name, "Textures/Finn&Jake/Idle/Left(%d).png", i);
		// cout << name << endl; // 관찰위한 코드 
		tx.loadFromFile(name);
		txVector.push_back(tx);
	}

	Sprite sp;
	sp.setScale(3.f, 3.f); // 사이즈
	sp.setOrigin(tx.getSize().x / 2.f, tx.getSize().y); // 피봇 발아래로 설정함
	sp.setPosition(Vector2f(250.f, 500.f)); // 좌상단이 0,0 기준으로 위치설정

	Clock clock;

	size_t keyFrameTime = 0;

	while (window.isOpen())
	{
		window.clear();

		Event e;
		while (window.pollEvent(e))
		{
			switch (e.type)
			{
			case Event::Closed:
			{
				window.close();
				break;
			}
			default:
				break;
			}
		}

		if (clock.getElapsedTime().asSeconds() > 0.2f)
		{
			sp.setTexture(txVector.data()[++keyFrameTime % txVector.size()]);
			clock.restart();
		}

		window.draw(sp);
		window.display();
	}
}