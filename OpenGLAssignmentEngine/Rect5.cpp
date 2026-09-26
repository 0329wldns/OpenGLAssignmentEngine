#include "pch.h"
#include "Rect5.h"

Rect5::Rect5()
{
	setColor(realDist(gen), realDist(gen), realDist(gen));
	createCollider();
}

void Rect5::update()
{
}

void Rect5::render() const
{
	glColor3f(color.r, color.g, color.b);

	Vector2 myPos = getPos();
	Vector2 myScale = getScale();

	glRectd(myPos.x - myScale.x, myPos.y - myScale.y, myPos.x + myScale.x, myPos.y + myScale.y);

	componantRender();
}

void Rect5::onCollision(Collider*)
{
}
