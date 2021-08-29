#include "framework.h"
#include "Character.h"

Character::Character()
{
	Init();
}
Character::~Character()
{
}

void Character::Init()
{
	Texture* tx = nullptr;

	

	char filePath[150];
	for (int i = 0; i < 9; ++i)
	{
		sprintf(filePath, "Textures/Finn&Jake/Idle/Left(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->idle_LAnimation.push_back(tx);
	}
	for (int i = 0; i < 9; ++i)
	{
		sprintf(filePath, "Textures/Finn&Jake/Idle/Right(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->idle_RAnimation.push_back(tx);
	}


	for (int i = 0; i < 15; ++i)
	{
		sprintf(filePath, "Textures/Finn&Jake/Walk/Left(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->walk_LAnimation.push_back(tx);
	}
	for (int i = 0; i < 15; ++i)
	{
		sprintf(filePath, "Textures/Finn&Jake/Walk/Right(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->walk_RAnimation.push_back(tx);
	}


	for (int i = 0; i < 11; ++i)
	{
		sprintf(filePath, "Textures/Finn&Jake/Run/Left(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->run_LAnimation.push_back(tx);
	}
	for (int i = 0; i < 11; ++i)
	{
		sprintf(filePath, "Textures/Finn&Jake/Run/Right(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->run_RAnimation.push_back(tx);
	}


	for (int i = 0; i < 9; ++i)
	{
		sprintf(filePath, "Textures/Finn&Jake/Up/(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->up_Animation.push_back(tx);
	}
	

	for (int i = 0; i < 9; ++i)
	{
		sprintf(filePath, "Textures/Finn&Jake/Punch/Left(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->punch_LAnimation.push_back(tx);
	}
	for (int i = 0; i < 9; ++i)
	{
		sprintf(filePath, "Textures/Finn&Jake/Punch/Right(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->punch_RAnimation.push_back(tx);
	}


	for (int i = 0; i < 13; ++i)
	{
		sprintf(filePath, "Textures/Finn&Jake/Sword/Left(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->sword_LAnimation.push_back(tx);
	}
	for (int i = 0; i < 13; ++i)
	{
		sprintf(filePath, "Textures/Finn&Jake/Sword/Right(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->sword_RAnimation.push_back(tx);
	}


	for (int i = 0; i < 3; ++i)
	{
		sprintf(filePath, "Textures/Finn&Jake/GetHit/Left(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->gethit_LAnimation.push_back(tx);
	}
	for (int i = 0; i < 3; ++i)
	{
		sprintf(filePath, "Textures/Finn&Jake/GetHit/Right(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->gethit_RAnimation.push_back(tx);
	}


	for (int i = 0; i < 11; ++i)
	{
		sprintf(filePath, "Textures/Finn&Jake/KnockDown/Left(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->knockdown_LAnimation.push_back(tx);
	}
	for (int i = 0; i < 11; ++i)
	{
		sprintf(filePath, "Textures/Finn&Jake/KnockDown/Right(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->knockdown_RAnimation.push_back(tx);
	}


	for (int i = 0; i < 19; ++i)
	{
		sprintf(filePath, "Textures/Finn&Jake/Death/Left(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->death_LAnimation.push_back(tx);
	}
	for (int i = 0; i < 19; ++i)
	{
		sprintf(filePath, "Textures/Finn&Jake/Death/Right(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->death_RAnimation.push_back(tx);
	}

	stateAnimation[IDLE_R] = idle_RAnimation;
	stateAnimation[IDLE_L] = idle_LAnimation;
	stateAnimation[WALK_L] = walk_LAnimation;
	stateAnimation[WALK_R] = walk_RAnimation;
	stateAnimation[RUN_L] = run_LAnimation;
	stateAnimation[RUN_R] = run_RAnimation;
	stateAnimation[UP] = up_Animation;
	stateAnimation[PUNCH_L] = punch_LAnimation;
	stateAnimation[PUNCH_R] = punch_RAnimation;
	stateAnimation[SWORD_L] = sword_LAnimation;
	stateAnimation[SWORD_R] = sword_RAnimation;
	stateAnimation[GETHIT_L] = gethit_LAnimation;
	stateAnimation[GETHIT_R] = gethit_RAnimation;
	stateAnimation[KNOCKDOWN_L] = knockdown_LAnimation;
	stateAnimation[KNOCKDOWN_R] = knockdown_RAnimation;
	stateAnimation[DEATH_L] = death_LAnimation;
	stateAnimation[DEATH_R] = death_RAnimation;

	setScale(2.f, 2.f);
	setPosition(Vector2f(250.f, 250.f));
	setOrigin(tx->getSize().x / 2.f, tx->getSize().y);
	
}

void Character::Destroy()
{
	AnimationObject::Destroy();
}

void Character::Update(const float& deltaTime)
{
	//state = IDLE_L;

	// if- else if�� �ϸ� �ΰ� ���ÿ� �Է������� �ϳ��� Ű�� �Է¹��� 

	if (Keyboard::isKeyPressed(Keyboard::Right)) //Ű���� �����ʹ���Ű
	{
		state = WALK_R;
		move(0.07f, 0.f);
		if (Keyboard::isKeyPressed(Keyboard::LControl))
		{
			state = RUN_R;
			move(0.1f, 0.f);
		}
	}
	
	else if (Keyboard::isKeyPressed(Keyboard::Left)) // Ű���� ���ʹ���Ű 
	{
		state = WALK_L;
		move(-0.07f, 0.f);
		if (Keyboard::isKeyPressed(Keyboard::LControl))
		{
			state = RUN_L;
			move(-0.1f, 0.f);
		}
	}

	else if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		state = UP;
		move(0.f, -0.05f);
	}

	else if (Keyboard::isKeyPressed(Keyboard::Z))
	{
		keyFrame = 0;
		state = PUNCH_R;
	}
		
	else if (Keyboard::isKeyPressed(Keyboard::X))
	{
		keyFrame = 0;
		state = SWORD_R;
	}


	elapsedTime += deltaTime;

	if (elapsedTime > 0.1f)
	{
		//������� for��
		// stateAnimation�ȿ��ִ� ��ü���� animation�ϳ��� �ϳ��� �ҷ��ü����� 
		for (auto& animation : stateAnimation)
		{
			//first : ���� ������Ʈ  -> IDLE�̳� RUN�̳� JUMP�� PUNCH�� WALK�� �׼Ҹ� 
			// animation -> <state(first), animationVector(second)>
			// <key,value> == <first,second> == <RUN,runanimation> ...
			if (animation.first == state) // first�� ���� state�� ���ٸ� 
			{
				setTexture(*animation.second.data()[keyFrame % animation.second.size()]);
				

				if (animation.first == PUNCH_L)
				{
					if (keyFrame % animation.second.size() >= animation.second.size() - 1)
					{
						state = IDLE_L;
					}
				}
				else if (animation.first == PUNCH_R)
				{
					if (keyFrame % animation.second.size() >= animation.second.size() - 1)
					{
						state = IDLE_R;
					}
				}
				else if (animation.first != PUNCH_L && animation.first != PUNCH_R)
				{
					if (keyFrame % animation.second.size() >= animation.second.size() - 1)
					{
					
						state = IDLE_R;
						//punch�� �ƴϸ� �� �����߸� �ִϸ��̼��� ���ѹݺ�
						// �׷��ٰ� punch�� �ڵ尡 �Ȱ����� �ڴ����� ���ѹݺ������ʰ� �Ѿִϸ��̼���鿡 �������� ����?��
					}
				}
			}
		}

		++keyFrame;
		elapsedTime = 0.f;

	}
}