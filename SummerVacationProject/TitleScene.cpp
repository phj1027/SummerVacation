#include "framework.h"
#include "TitleScene.h"

TitleScene::TitleScene()
{
	Init();
}

TitleScene::TitleScene(stack<Scene*>* scenes) : Scene(scenes)
{
	Init();
}

TitleScene::~TitleScene()
{

}

void TitleScene::Init()
{
	Font* font = new Font;
	font->loadFromFile("Font/CookieRun_Bold.ttf");
	Text* text = new Text("Press \"Space\" Key!!", *font);
	text->setFillColor(Color::White);
	text->setOrigin(text->getGlobalBounds().width / 2.f, text->getGlobalBounds().height / 2.f);
	text->setPosition(Vector2f(500 / 2.f, 450));
	mTexts["START"] = text;

	
}

void TitleScene::Update(const float& deltaTime)
{
	static float elapsedTime = 0.f;
	static float txtScale = 1.f;
	static int frame = 0;
	static int div = 1;
	if ((elapsedTime += deltaTime) >= 0.02f)
	{
		mTexts["START"]->setScale(Vector2f(txtScale, txtScale));
		if ((++frame%30) == 0)
		{
			div *= -1;
		}
		txtScale += (0.01f * div);
		mTexts["START"]->setScale(Vector2f(txtScale, txtScale));
		elapsedTime = 0.f;
	}
	Scene::Update(deltaTime);
	
}

void TitleScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}