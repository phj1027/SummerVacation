#define _CRT_SECURE_NO_WARNINGS
#include "framework.h"
#include "AnimationObject.h"

AnimationObject::AnimationObject()
{
	Init();
}

AnimationObject::~AnimationObject()
{
}

void AnimationObject::Init()
{
	Texture* tx = nullptr;

	char filePath[150];
	for (int i = 0; i < 15; ++i)
	{
		sprintf(filePath, "Textures/Finn&Jake/Walk/Left(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->vAnimation.push_back(tx);
	}

	setScale(2.f, 2.f);
	setPosition(Vector2f(250.f, 250.f));
	setOrigin(tx->getSize().x / 2.f, tx->getSize().y); //�Ǻ� �߾Ʒ�
}

void AnimationObject::Destroy()
{
}

void AnimationObject::Update(const float& deltaTime)
{
	elapsedTime += deltaTime;

	if (elapsedTime > 0.1f)
	{
		setTexture(*vAnimation.data()[keyFrame % vAnimation.size()]);
		// ��>Texture�� *�� �޾ұ⶧���� �������ؾ���
		++keyFrame;
		elapsedTime = 0.f;
		// ���� ��� clock.restart();�� ���� elapsedTime
	}
}