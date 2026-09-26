#include "pch.h"
#include "Scene_Assignment4.h"
#include "EventFunc.h"
#include "Rect4.h"

void Scene_Assignment4::update()
{
	for (int key = 0; key <= (int)KEY::LAST; ++key)
	{
		processKeyInput((KEY)key);
	}

	Scene::update();
}

void Scene_Assignment4::enter()
{
	cout << "실습4" << endl;
	cout << "1: 사각형들은 각각 대각선으로 이동하고 벽에 닿으면 튕겨 다른 방향으로 이동한다/멈춘다." << endl;
	cout << "2: 사각형들이 가로 지그재그로 이동한다/멈춘다." << endl;
	cout << "3: 모든 사각형들이 윈도우의 가장자리를 따라 시계방향으로 순서대로 이동한다/멈춘다." << endl;
	cout << "4: 사각형의 크기가 커졌다 작아졌다를 반복한다/멈춘다." << endl;
	cout << "5: 사각형의 색상이 랜덤하게 변한다/변하지 않는다." << endl;
	cout << "s: 모든 애니메이션이 멈춘다." << endl;
	cout << "m: 원래 그린 위치로 사각형들이 이동한다" << endl;	//
	cout << "r: 사각형들을 삭제하고 다시 마우스 입력을 받을 수 있다." << endl;	//
	cout << "q: 프로그램을 종료한다." << endl;	//
}

void Scene_Assignment4::exit()
{
	reset();
}

void Scene_Assignment4::processKeyInput(KEY _key)
{
	vector<Object*> rects = Scene::getGroupObject(OBJECT_GROUP::RECT4);

	switch (_key)
	{
	case KEY::NUM1:
		if (KeyManager::getInstance().getKeyState(KEY::NUM1) == KEY_STATE::TAP)
		{
			if (Rect4::getState().movement != MOVEMENT::DIAGNAL)
				Rect4::setMovement(MOVEMENT::DIAGNAL);
			else Rect4::setMovement(MOVEMENT::NONE);
		}
		break;
	case KEY::NUM2:
		if (KeyManager::getInstance().getKeyState(KEY::NUM2) == KEY_STATE::TAP)
		{
			if (Rect4::getState().movement != MOVEMENT::ZIGZAG)
				Rect4::setMovement(MOVEMENT::ZIGZAG);
			else Rect4::setMovement(MOVEMENT::NONE);
		}
		break;
	case KEY::NUM3:
		if (KeyManager::getInstance().getKeyState(KEY::NUM3) == KEY_STATE::TAP)
		{
			if (Rect4::getState().movement != MOVEMENT::CLOCKWISE)
				Rect4::setMovement(MOVEMENT::CLOCKWISE);
			else Rect4::setMovement(MOVEMENT::NONE);
		}
		break;
	case KEY::NUM4:
		if (KeyManager::getInstance().getKeyState(KEY::NUM4) == KEY_STATE::TAP)
		{
			Rect4::toggleChangeScale();
			for (size_t i = 0; i < rects.size(); ++i)
			{
				rects[i]->setScale(static_cast<Rect4*>(rects[i])->getOrgScale());
			}
		}
		break;
	case KEY::NUM5:
		if (KeyManager::getInstance().getKeyState(KEY::NUM5) == KEY_STATE::TAP)
		{
			Rect4::toggleChangeColor();
		}
		break;
	case KEY::M:
		if (KeyManager::getInstance().getKeyState(KEY::M) == KEY_STATE::TAP)
		{
			for (size_t i = 0; i < rects.size(); ++i)
			{
				rects[i]->setPos(static_cast<Rect4*>(rects[i])->getOrgPos());
			}
		}
		break;
	case KEY::Q:
		if (KeyManager::getInstance().getKeyState(KEY::Q) == KEY_STATE::TAP)
		{
			changeScene(SCENE_TYPE::START);
		}
		break;
	case KEY::R:
		if (KeyManager::getInstance().getKeyState(KEY::R) == KEY_STATE::TAP)
		{
			reset();
		}
		break;
	case KEY::MOUSE_L:
		if (KeyManager::getInstance().getKeyState(KEY::MOUSE_L) == KEY_STATE::TAP)
		{
			if (Scene::getGroupObject(OBJECT_GROUP::RECT4).size() < 5)
			{
				Vector2 mousePos{ KeyManager::getInstance().getMousePos() };

				Rect4* rect = new Rect4;
				rect->setPos(mousePos);
				rect->setScale(Vector2(50, 50));
				rect->setOrgPos(rect->getPos());
				rect->setOrgScale(rect->getScale());

				createObject(rect, OBJECT_GROUP::RECT4);
			}
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
