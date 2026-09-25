#include "pch.h"
#include "Scene_Start.h"
#include "KeyManager.h"
#include "UIButton.h"
#include "EventFunc.h"

void Scene_Start::update()
{
	// ESC 누르면 프로그램 종료 처리
	if (KeyManager::getInstance().getKeyState(KEY::ESC) == KEY_STATE::TAP)
		glfwSetWindowShouldClose(Core::getInstance().getWindow(), true);

	Scene::update();
}

void Scene_Start::enter()
{
	// === 1번 과제 시작 버튼 만들기 ===
	UIButton* btn3 = new UIButton();
	btn3->setPos(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 100);
	btn3->setScale(150, 80);
	btn3->setColor(1.0f, 0.5f, 0.0f);
	btn3->setTargetScene(SCENE_TYPE::ASSIGNMENT3);

	UIButton* btn4 = new UIButton();
	btn4->setPos(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 100);
	btn4->setScale(150, 80);
	btn4->setColor(1.0f, 0.0f, 0.0f);
	btn4->setTargetScene(SCENE_TYPE::ASSIGNMENT4);

	// 씬의 UI 그룹에 버튼 객체 추가
	createObject(btn3, OBJECT_GROUP::UIBUTTON);
	createObject(btn4, OBJECT_GROUP::UIBUTTON);

	cout << "================================\n";
	cout << "주황 버튼: 3번 실습 과제\n";
	cout << "================================\n";
}

void Scene_Start::exit()
{
	reset();
}
