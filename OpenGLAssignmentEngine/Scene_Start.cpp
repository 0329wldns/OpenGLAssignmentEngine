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
	for (int i = (int)SCENE_TYPE::ASSIGNMENT3; i < (int)SCENE_TYPE::END; ++i)
	{
		UIButton* button = new UIButton();
		button->setPos(i * 300, SCREEN_HEIGHT / 2 - 100);
		button->setTargetScene((SCENE_TYPE)i);
		createObject(button, OBJECT_GROUP::UIBUTTON);
	}
}

void Scene_Start::exit()
{
	reset();
}