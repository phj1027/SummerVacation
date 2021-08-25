#pragma once
#include "Scene.h"
class GameScene2 : public Scene
{
public:
    GameScene2(); 
    GameScene2(stack<Scene*>* scenes);
    virtual ~GameScene2();

private:
    virtual void Init();

public:
    virtual void Update(const float& deltaTime);
    virtual void Render(RenderWindow* window);

};

