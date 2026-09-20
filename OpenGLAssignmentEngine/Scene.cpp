#include "pch.h"
#include "Scene.h"
#include "KeyManager.h"
#include "Core.h"

Scene::Scene()
{

}

Scene::~Scene()
{
}

void Scene::update()
{
	for (int i = 0; i < (int)OBJECT_GROUP::END; ++i)
	{
		for (size_t j = 0; j < object[i].size(); ++j)
		{
			if (!object[i][j]->isDead())
				object[i][j]->update();
		}
	}
}

void Scene::finalUpdate()
{
	for (int i = 0; i < (int)OBJECT_GROUP::END; ++i)
	{
		for (size_t j = 0; j < object[i].size(); ++j)
		{
			object[i][j]->finalUpdate();
		}
	}
}

void Scene::render()
{
	drawBG();
	drawUI();

	for (int i{}; i < static_cast<int>(OBJECT_GROUP::END); ++i)
	{
		for (size_t j{}; j < object[i].size(); ++j)
		{
			if (!object[i][j]->isDead())
			{
				object[i][j]->render();
			}
		}
	}
	drawClear();
}

void Scene::reset()
{
	for (int i = 0; i < (int)OBJECT_GROUP::END; ++i)
	{
		for (size_t j = 0; j < object[i].size(); ++j) {
			delete object[i][j];
		}
		object[i].clear();
	}
}

void Scene::addObject(Object* obj, OBJECT_GROUP group)
{
	object[(int)group].push_back(obj);
}
