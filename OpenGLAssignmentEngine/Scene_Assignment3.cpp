#include "pch.h"
#include "Scene_Assignment3.h"
#include "KeyManager.h"
#include "EventFunc.h"

random_device rd{};
mt19937 gen(rd());
uniform_int_distribution<int> dis(1, 10000);

void Scene_Assignment3::update()
{
	if (KeyManager::getInstance().getKeyState(KEY::ESC) == KEY_STATE::TAP)
		changeScene(SCENE_TYPE::START);
	else if (KeyManager::getInstance().getKeyState(KEY::A) == KEY_STATE::TAP)
	{

	}

	Scene::update();
}

void Scene_Assignment3::enter()
{
	cout << "과제3" << endl;
}

void Scene_Assignment3::exit()
{
}
