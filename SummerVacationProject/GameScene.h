#pragma once
#include "Scene.h"
class GameScene : public Scene
{
public:
    GameScene();
    GameScene(stack<Scene*>* scenes, RenderWindow* window);
    ~GameScene();
     
private:
    virtual void Init();

public:
    virtual void Input(Event* e);
    virtual void Destroy();
    virtual void Update(const float& deltaTime);
    virtual void Render(RenderWindow* window);
        
};

