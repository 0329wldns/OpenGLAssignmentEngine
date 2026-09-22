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
	int buttonPresetX{ SCREEN_WIDTH / 2 };
	int buttonPresetY{ SCREEN_HEIGHT / 2};

	// === 1번 과제 시작 버튼 만들기 ===
	UIButton* btn1 = new UIButton();
	btn1->setPos(buttonPresetX, buttonPresetY);
	btn1->setScale(200, 80);  // 가로 200, 세로 80 크기의 네모
	btn1->setColor(1.0f, 0.5f, 0.0f); // 주황색

	btn1->setTargetScene(SCENE_TYPE::ASSIGNMENT3);

	// 씬의 UI 그룹에 버튼 객체 추가
	createObject(btn1, OBJECT_GROUP::UIBUTTON);

	cout << "================================\n";
	cout << "주황 버튼: 3번 실습 과제\n";
	cout << "================================\n";
}

void Scene_Start::exit()
{
	reset();
}
