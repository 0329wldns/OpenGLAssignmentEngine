#include "pch.h"
#include "Scene_Assignment4.h"
#include "KeyManager.h"
#include "EventFunc.h"

void Scene_Assignment4::update()
{
	if (KeyManager::getInstance().getKeyState(KEY::ESC) == KEY_STATE::TAP)
	{
		changeScene(SCENE_TYPE::START);
		cout << "Tap" << endl;
	}

	Scene::update();
}

void Scene_Assignment4::enter()
{
	cout << "과제4" << endl;
}

void Scene_Assignment4::exit()
{
}
