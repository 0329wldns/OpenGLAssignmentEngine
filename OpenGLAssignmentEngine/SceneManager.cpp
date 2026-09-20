#include "pch.h"
#include "SceneManager.h"

#include "Scene_Start.h"

SceneManager::SceneManager()
	: scene()
	, curScene(nullptr)
{
}

void SceneManager::init()
{
	scene[(int)SCENE_TYPE::START] = new Scene_Start;

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
