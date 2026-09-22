#include "pch.h"
#include "Scene_Assignment3.h"
#include "KeyManager.h"
#include "EventFunc.h"
#include "Rect.h"

random_device rd{};
mt19937 gen(rd());
uniform_int_distribution<int> intDist(1, 10000);
uniform_real_distribution<float> realDist(0.0f, 1.0f);

static const int g_sizeLimit{ 100 };

void Scene_Assignment3::update()
{
	if (KeyManager::getInstance().getKeyState(KEY::ESC) == KEY_STATE::TAP)
		changeScene(SCENE_TYPE::START);
	if (KeyManager::getInstance().getKeyState(KEY::A) == KEY_STATE::TAP)
	{
		Rect* rect = new Rect();
		rect->setPos(intDist(gen) % SCREEN_WIDTH, intDist(gen) % SCREEN_HEIGHT);
		rect->setScale(10 + intDist(gen) % g_sizeLimit, 10 + intDist(gen) % g_sizeLimit);
		rect->setColor(realDist(gen), realDist(gen), realDist(gen));

		createObject(rect, OBJECT_GROUP::RECT);
	}

	Scene::update();
}

void Scene_Assignment3::enter()
{
	cout << "과제3" << endl;
}

void Scene_Assignment3::exit()
{
	reset();
}
