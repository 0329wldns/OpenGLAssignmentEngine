#include "pch.h"
#include "Rect.h"
#include "KeyManager.h"

Rect::Rect()
	: isHeld(false)
{
}

Rect::~Rect()
{
}

void Rect::update()
{
	Vector2 mousePos{ KeyManager::getInstance().getMousePos() };

	if (KeyManager::getInstance().getKeyState(KEY::MOUSE_L) == KEY_STATE::HOLD && isHeld)
		setPos(mousePos + dragOffset);
}

void Rect::onMouseDownLeft()
{
	Vector2 mousePos{ KeyManager::getInstance().getMousePos() };

	Vector2 myPos{ getPos() };
	Vector2 myScale{ getScale() };

	isHeld = true;
	dragOffset = myPos - mousePos;
}

void Rect::onMouseUpLeft()
{
	isHeld = false;
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
