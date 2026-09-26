#include "pch.h"
#include "Rect4.h"

Rect4::Rect4()
{
	setColor(realDist(gen), realDist(gen), realDist(gen));
}

void Rect4::update()
{
}

void Rect4::render() const
{
	glColor3f(color.r, color.g, color.b);

	Vector2 myPos = getPos();
	Vector2 myScale = getScale();

	glRectd(myPos.x - myScale.x, myPos.y - myScale.y, myPos.x + myScale.x, myPos.y + myScale.y);
}
