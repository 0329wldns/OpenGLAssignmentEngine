#include "pch.h"
#include "Rect.h"
#include "KeyManager.h"
#include "EventFunc.h"
#include "SceneManager.h"

Rect::Rect()
	: isHeld(false)
{
	setColor(realDist(gen), realDist(gen), realDist(gen));
	createCollider();
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

void Rect::onMouseDownRight()
{
	if (SceneManager::getInstance().getCurScene()->getGroupObject(OBJECT_GROUP::RECT).size() >= 20)
		return;

	Vector2 myPos{ getPos() };
	Vector2 myScale{ getScale() };

	Rect* rect1 = new Rect;
	Rect* rect2 = new Rect;

	rect1->setPos(Vector2(myPos.x - myScale.x / 2, myPos.y));
	rect1->setScale(Vector2(myScale.x / 2, myScale.y));
	rect1->getCollider()->setPos(rect1->getPos());
	rect1->getCollider()->setScale(rect1->getScale());

	rect2->setPos(Vector2(myPos.x + myScale.x / 2, myPos.y));
	rect2->setScale(Vector2(myScale.x / 2, myScale.y));
	rect2->getCollider()->setPos(rect2->getPos());
	rect2->getCollider()->setScale(rect2->getScale());

	createObject(rect1, OBJECT_GROUP::RECT);
	createObject(rect2, OBJECT_GROUP::RECT);
	
	deleteObject(this);
}

void Rect::render() const
{
	glColor3f(color.r, color.g, color.b);

	Vector2 myPos = getPos();
	Vector2 myScale = getScale();

	glRectd(myPos.x - myScale.x, myPos.y - myScale.y, myPos.x + myScale.x, myPos.y + myScale.y);

	componantRender();
}

void Rect::onCollision(Collider* other)
{
	Vector2 myPos = getPos();
	Vector2 myScale = getScale();

	Vector2 otherPos = other->getPos();
	Vector2 otherScale = other->getScale();

	Rect* rect = new Rect;
	if (myPos.x > otherPos.x)
	{

	}
}
