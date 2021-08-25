#pragma once
#include "Scene.h"
class GameScene : public Scene
{
public:
    GameScene();
    GameScene(stack<Scene*>* scenes);
    ~GameScene();
     
private:
    virtual void Init();

public:
    virtual void Update(const float& deltaTime);
    virtual void Render(RenderWindow* window);
        
};

