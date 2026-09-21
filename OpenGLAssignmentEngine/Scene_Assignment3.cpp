#include "pch.h"
#include "Scene_Assignment3.h"
#include "KeyManager.h"
#include "EventFunc.h"

void Scene_Assignment3::update()
{
	if (KeyManager::getInstance().getKeyState(KEY::ESC) == KEY_STATE::TAP)
	{
		changeScene(SCENE_TYPE::START);
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
