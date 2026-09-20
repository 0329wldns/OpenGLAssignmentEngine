#include "pch.h"
#include "EventManager.h"
#include "SceneManager.h"

EventManager::~EventManager()
{

}

void EventManager::update()
{
	for (size_t i = 0; i < vecDead.size(); ++i) 
		delete vecDead[i];
	vecDead.clear();

	for (size_t i = 0; i < vecEvent.size(); ++i) 
		excute(vecEvent[i]);
	vecEvent.clear();
}

void EventManager::excute(const Event& _event)
{
	switch (_event.event)
	{
	case EVENT_TYPE::CREATE_OBJECT:
	{
		// lParam : object address
		// wParam : group type
		SceneManager::getInstance().getCurScene()->addObject((Object*)_event.lParam, (OBJECT_GROUP)_event.wParam);
	}
		break;
	case EVENT_TYPE::DELETE_OBJECT:
	{
		// lParam : object address
		Object* deadObject = (Object*)_event.lParam;
		if (!deadObject->isDead())
		{
			vecDead.push_back(deadObject);
			deadObject->setDead();
		}
	}
		break;
	}
}
