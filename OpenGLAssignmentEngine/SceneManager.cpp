#include "pch.h"
#include "SceneManager.h"

#include "Scene_Start.h"
#include "Scene_Assignment3.h"
#include "Scene_Assignment4.h"
#include "Scene_Assignment5.h"

SceneManager::SceneManager()
	: scene()
	, curScene(nullptr)
{
}

void SceneManager::init()
{
	scene[(int)SCENE_TYPE::START] = new Scene_Start;
	scene[(int)SCENE_TYPE::ASSIGNMENT3] = new Scene_Assignment3;
	scene[(int)SCENE_TYPE::ASSIGNMENT4] = new Scene_Assignment4;
	scene[(int)SCENE_TYPE::ASSIGNMENT5] = new Scene_Assignment5;

	curScene = scene[(int)SCENE_TYPE::START];
	curScene->enter();
}

void SceneManager::update()
{
	curScene->update();
}

void SceneManager::finalUpdate()
{
	curScene->finalUpdate();
}

void SceneManager::render() const
{
	curScene->render();
}

void SceneManager::changeScene(SCENE_TYPE nextScene)
{
	curScene->exit();
	curScene = scene[(int)nextScene];
	curScene->enter();
}
