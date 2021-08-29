#include "framework.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "PauseScene.h"

TitleScene::TitleScene()
{
	Init();
}

TitleScene::TitleScene(stack<Scene*>* scene, RenderWindow* window) :Scene(scenes,window)
{
	Init();
}

TitleScene::~TitleScene()
{

}

void TitleScene::Init()
{
//Font* font = new Font;
//font->loadFromFile("Font/CookieRun_Bold.ttf");
//Text* text = new Text("Press \"Space\" Key!!", *font);
//text->setFillColor(Color::White);
//text->setOrigin(text->getGlobalBounds().width / 2.f, text->getGlobalBounds().height / 2.f);
//text->setPosition(Vector2f(500 / 2.f, 450));
//mTexts["START"] = text;



	mButtons["PLAY"] = new Button("Textures/Button/start.png",
		"Textures/Button/start.png",
		Vector2f(500 / 2.f, 400.f));
	
}

void TitleScene::Input(Event* e)
{
	switch (e->key.code)
	{
	case Keyboard::Escape:
	{
		scenes->top()->EndScene();
		break;
	}
	case Keyboard::Space:
	{
		scenes->push(new GameScene(scenes,window));
		break;
	}
	default:
		break;
	}
}

void TitleScene::Destroy()
{

}
void TitleScene::Update(const float& deltaTime)
{

	if (mButtons["PLAY"]->IsPressed())
	{
		scenes->push(new GameScene(scenes, window));
	}
	Scene::Update(deltaTime);
	
}

void TitleScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}