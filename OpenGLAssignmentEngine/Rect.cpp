#include "pch.h"
#include "Rect.h"

Rect::Rect()
{
}

Rect::~Rect()
{
}

void Rect::update()
{
}

void Rect::render() const
{
	glColor3f(color.r, color.g, color.b);

	Vector2 myPos = getPos();
	Vector2 myScale = getScale();

	glRectd(myPos.x - myScale.x, myPos.y - myScale.y, myPos.x + myScale.x, myPos.y + myScale.y);
}

void Rect::onCollision(Collider* other)
{
}
