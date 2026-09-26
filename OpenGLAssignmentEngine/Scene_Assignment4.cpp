#include "pch.h"
#include "Scene_Assignment4.h"
#include "KeyManager.h"
#include "EventFunc.h"
#include "Rect4.h"

void Scene_Assignment4::update()
{
	if (KeyManager::getInstance().getKeyState(KEY::Q) == KEY_STATE::TAP)
	{
		changeScene(SCENE_TYPE::START);
	}

	if (KeyManager::getInstance().getKeyState(KEY::MOUSE_L) == KEY_STATE::TAP)
	{
		if (Scene::getGroupObject(OBJECT_GROUP::RECT4).size() < 5)
		{
			Vector2 mousePos{ KeyManager::getInstance().getMousePos() };

			Rect4* rect = new Rect4;
			rect->setPos(mousePos);
			rect->setScale(Vector2(50, 50));

			createObject(rect, OBJECT_GROUP::RECT4);
		}
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
