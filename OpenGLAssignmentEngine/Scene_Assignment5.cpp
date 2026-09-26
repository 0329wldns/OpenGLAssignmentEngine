#include "pch.h"
#include "Scene_Assignment5.h"
#include "KeyManager.h"
#include "CollisionManager.h"
#include "EventFunc.h"
#include "Rect5.h"

void Scene_Assignment5::update()
{
	processKeyInput();

	Scene::update();
}

void Scene_Assignment5::enter()
{
	init();

	cout << "실습5" << endl;
	cout << "좌클릭: 화면의 사각형의 2배의 크기의 검정색 사각형(지우개 사각형)이 그려진다" << endl;
	cout << "우클릭: 그 자리에 사각형이 새롭게 생긴다." << endl;
	cout << "r: 기존 사각형들 삭제되고 리셋하여 새로 시작하기" << endl;
	cout << "q: 프로그램을 종료한다." << endl;

	CollisionManager::getInstance().checkCollisionGroup(OBJECT_GROUP::RECT5, OBJECT_GROUP::ERASER_RECT);
}

void Scene_Assignment5::exit()
{
	reset();
}

void Scene_Assignment5::init()
{
	reset();

	for (int i = 0; i < 30; ++i)
	{
		Rect5* rect = new Rect5;
		rect->setPos(intDist(gen) % SCREEN_WIDTH, intDist(gen) % SCREEN_HEIGHT);
		rect->setScale(20, 20);
		rect->getCollider()->setPos(rect->getPos());
		rect->getCollider()->setScale(rect->getScale());

		createObject(rect, OBJECT_GROUP::RECT5);
	}
}

void Scene_Assignment5::processKeyInput()
{
	for (int key = 0; key <= (int)KEY::LAST; ++key)
	{
		switch ((KEY)key)
		{
		case KEY::MOUSE_L:
			if (KeyManager::getInstance().getKeyState(KEY::MOUSE_L) == KEY_STATE::TAP)
			{
				Vector2 mousePos{ KeyManager::getInstance().getMousePos() };


			}
			break;
		case KEY::R:
			if (KeyManager::getInstance().getKeyState(KEY::R) == KEY_STATE::TAP)
			{
				init();
			}
			break;
		case KEY::ESC:
			if (KeyManager::getInstance().getKeyState(KEY::ESC) == KEY_STATE::TAP)
			{
				changeScene(SCENE_TYPE::START);
			}
			break;
		}
	}
}
