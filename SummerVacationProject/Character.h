#pragma once
#include "AnimationObject.h"

enum CHARACTER_STATE
{
	IDLE_R,
	IDLE_L,
	WALK_L,
	WALK_R,
	RUN_L,
	RUN_R,
	UP,
	PUNCH_L,
	PUNCH_R,
	SWORD_L,
	SWORD_R,
	GETHIT_L,
	GETHIT_R,
	KNOCKDOWN_L,
	KNOCKDOWN_R,
	DEATH_L,
	DEATH_R

};

class Character : public AnimationObject
{
public:
	Character();
	virtual ~Character();

private:
	//포인터로 쓰는 이유 그때그때 동적할당 해놓고 캐릭터가 사라질 시 여기서 풀어주면 되니까
	vector<Texture*> idle_RAnimation;
	vector<Texture*> idle_LAnimation;
	vector<Texture*> walk_LAnimation;
	vector<Texture*> walk_RAnimation;
	vector<Texture*> run_LAnimation;
	vector<Texture*> run_RAnimation;
	vector<Texture*> up_Animation;
	vector<Texture*> punch_LAnimation;
	vector<Texture*> punch_RAnimation;
	vector<Texture*> sword_LAnimation;
	vector<Texture*> sword_RAnimation;
	vector<Texture*> gethit_LAnimation;
	vector<Texture*> gethit_RAnimation;
	vector<Texture*> knockdown_LAnimation;
	vector<Texture*> knockdown_RAnimation;
	vector<Texture*> death_LAnimation;
	vector<Texture*> death_RAnimation;


	int state = IDLE_R;

	//int자료형 하나랑 vector컨테이너 하나를 짝꿍시킴
	// ex) WALK하나 불렀다면 walkAnimation과 짝꿍
	// ex) RUN하나 불렀다면 runAnimation과 짝꿍
	map<int, vector<Texture*>> stateAnimation;
	// stateAnimation에서 키값(int자료형)을 불렀을때 해당 vector컨테이너가 튀어나오는것


private:
	virtual void Init();

public:
	virtual void Destroy();
	virtual void Update(const float& deltaTime);
};



