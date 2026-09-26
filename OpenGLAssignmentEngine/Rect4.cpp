#include "pch.h"
#include "Rect4.h"
#include "TimeManager.h"

Rect4::Rect4()
	: orgPos(), changeColorCD()
{
	setColor(realDist(gen), realDist(gen), realDist(gen));
}

void Rect4::update()
{
	Vector2 myPos{ getPos() };
	Vector2 myScale{ getScale() };

	float dt = TimeManager::getInstance().getDeltaTime();

	if (state.changeColor)
	{
		changeColorCD += dt;
		if (changeColorCD >= 2.0f)
		{
			setColor(realDist(gen), realDist(gen), realDist(gen));
			changeColorCD -= 2.0f;
		}
	}
}

void Rect4::render() const
{
	glColor3f(color.r, color.g, color.b);

	Vector2 myPos{ getPos() };
	Vector2 myScale{ getScale() };

	glRectd(myPos.x - myScale.x, myPos.y - myScale.y, myPos.x + myScale.x, myPos.y + myScale.y);
}
