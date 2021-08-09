#include "framework.h"
#include "BigZombie.h"

BigZombie::BigZombie()
{
	Init();
}

BigZombie::~BigZombie()
{

}

void BigZombie::Init()
{
	Texture* tx = nullptr;

	char filePath[150];
	for (int i = 0; i < 9; ++i)
	{
		sprintf(filePath, "Textures/Enemies/BigZombie/Walk/Right(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->vAnimation.push_back(tx);
	}
	setScale(2.f, 2.f);
	setPosition(Vector2f(100.f, 250.f));
	setOrigin(tx->getSize().x / 2.f, tx->getSize().y );
}

void BigZombie::Destroy()
{
	Enemies::Destroy();
}

void BigZombie::Update(const float& deltaTime)
{
	Enemies::Update(deltaTime);
}