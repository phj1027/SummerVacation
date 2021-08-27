#pragma once

class Object; // vector<Object*> vObjects;�� �������� 

class Scene // Scene�� ��ӹ޴� �ֵ��� ���� _ ���� ���� Ŭ������ ����°�
{
public:
	Scene();
	Scene(stack<Scene*>* scenes); //Scene*�� ����ִ� ������ ������
	virtual ~Scene();

protected:

	// ������ ������Ʈ���� ���� 
	vector<Object*> vObjects;
	// ��> ���Ϳ� ���õǾ������ϱ� v�ٿ��ذ� 

	map<string, Text*> mTexts;
	stack<Scene*>* scenes;
	bool quit = false;

private:

	virtual void Init();

public:

	bool GetQuit() const;
	void EndScene();

	virtual void Update(const float& deltaTime);

	virtual void Render(RenderWindow* window);
	// ��> �׷��� ���� ���� 

};