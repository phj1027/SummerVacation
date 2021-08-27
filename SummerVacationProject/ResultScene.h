#pragma once
#include "Scene.h"
class ResultScene : public Scene
{
public:
    ResultScene();
    ResultScene(stack<Scene*>* scenes);
    virtual ~ResultScene();

private:
    virtual void Init();

public:
    virtual void Update(const float& deltaTime);
    virtual void Render(RenderWindow* window);

};
