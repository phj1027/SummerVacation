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
	//�����ͷ� ���� ���� �׶��׶� �����Ҵ� �س��� ĳ���Ͱ� ����� �� ���⼭ Ǯ���ָ� �Ǵϱ�
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

	//int�ڷ��� �ϳ��� vector�����̳� �ϳ��� ¦���Ŵ
	// ex) WALK�ϳ� �ҷ��ٸ� walkAnimation�� ¦��
	// ex) RUN�ϳ� �ҷ��ٸ� runAnimation�� ¦��
	map<int, vector<Texture*>> stateAnimation;
	// stateAnimation���� Ű��(int�ڷ���)�� �ҷ����� �ش� vector�����̳ʰ� Ƣ����°�


private:
	virtual void Init();

public:
	virtual void Destroy();
	virtual void Update(const float& deltaTime);
};



