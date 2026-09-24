#include "pch.h"
#include "Scene_Assignment3.h"
#include "KeyManager.h"
#include "EventFunc.h"
#include "Rect.h"
#include "CollisionManager.h"

void Scene_Assignment3::update()
{
	static const int g_sizeLimit{ 100 };

	if (KeyManager::getInstance().getKeyState(KEY::ESC) == KEY_STATE::TAP)
		changeScene(SCENE_TYPE::START);
	if (KeyManager::getInstance().getKeyState(KEY::A) == KEY_STATE::TAP)
	{
		if (Scene::getGroupObject(OBJECT_GROUP::RECT).size() < 10)
		{
			Vector2 pos{ intDist(gen) % SCREEN_WIDTH, intDist(gen) % SCREEN_HEIGHT };
			Vector2 scale{ 10 + intDist(gen) % g_sizeLimit, 10 + intDist(gen) % g_sizeLimit };
			Color col{ realDist(gen), realDist(gen), realDist(gen) };

			Rect* rect = new Rect();
			rect->setPos(pos);
			rect->setScale(scale);
			rect->getCollider()->setPos(rect->getPos());
			rect->getCollider()->setScale(rect->getScale());

			createObject(rect, OBJECT_GROUP::RECT);
		}
		else cout << "더 이상 추가할 수 없음" << endl;
	}
	if (KeyManager::getInstance().getKeyState(KEY::R) == KEY_STATE::TAP) 
		reset();

	Scene::update();
}

void Scene_Assignment3::enter()
{
	cout << "과제3" << endl;

	CollisionManager::getInstance().checkCollisionGroup(OBJECT_GROUP::RECT, OBJECT_GROUP::RECT);
}

void Scene_Assignment3::exit()
{
	CollisionManager::getInstance().reset();
	reset();
}
