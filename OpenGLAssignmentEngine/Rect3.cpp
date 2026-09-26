#include "pch.h"
#include "Rect3.h"
#include "KeyManager.h"
#include "EventFunc.h"
#include "SceneManager.h"

Rect3::Rect3()
	: isHeld(false)
	, isUnioned(false)
{
	setColor(realDist(gen), realDist(gen), realDist(gen));
	createCollider();
}

Rect3::~Rect3()
{
}

void Rect3::update()
{
	Vector2 mousePos{ KeyManager::getInstance().getMousePos() };

	if (KeyManager::getInstance().getKeyState(KEY::MOUSE_L) == KEY_STATE::HOLD && isHeld)
		setPos(mousePos + dragOffset);
}

void Rect3::onMouseDownLeft()
{
	Vector2 mousePos{ KeyManager::getInstance().getMousePos() };

	Vector2 myPos{ getPos() };
	Vector2 myScale{ getScale() };

	isHeld = true;
	dragOffset = myPos - mousePos;
}

void Rect3::onMouseUpLeft()
{
	isHeld = false;
}

void Rect3::onMouseDownRight()
{
	if (SceneManager::getInstance().getCurScene()->getGroupObject(OBJECT_GROUP::RECT3).size() >= 20)
		return;

	Vector2 myPos{ getPos() };
	Vector2 myScale{ getScale() };

	Rect3* rect1 = new Rect3;
	Rect3* rect2 = new Rect3;

	rect1->setPos(Vector2(myPos.x - myScale.x / 2, myPos.y));
	rect1->setScale(Vector2(myScale.x / 2, myScale.y));
	rect1->getCollider()->setPos(rect1->getPos());
	rect1->getCollider()->setScale(rect1->getScale());

	rect2->setPos(Vector2(myPos.x + myScale.x / 2, myPos.y));
	rect2->setScale(Vector2(myScale.x / 2, myScale.y));
	rect2->getCollider()->setPos(rect2->getPos());
	rect2->getCollider()->setScale(rect2->getScale());

	createObject(rect1, OBJECT_GROUP::RECT3);
	createObject(rect2, OBJECT_GROUP::RECT3);
	
	deleteObject(this);
}

void Rect3::render() const
{
	glColor3f(color.r, color.g, color.b);

	Vector2 myPos = getPos();
	Vector2 myScale = getScale();

	glRectd(myPos.x - myScale.x, myPos.y - myScale.y, myPos.x + myScale.x, myPos.y + myScale.y);

	componantRender();
}

void Rect3::onCollision(Collider* other)
{
	if (isHeld || dynamic_cast<Rect3*>(other->getObj())->isHeld
		|| isUnioned || dynamic_cast<Rect3*>(other->getObj())->isUnioned)
		return;

	Vector2 myPos = getPos();
	Vector2 myScale = getScale();

	Vector2 otherPos = other->getPos();
	Vector2 otherScale = other->getScale();

	Vector2 minA{ myPos.x - myScale.x, myPos.y - myScale.y };
    Vector2 maxA{ myPos.x + myScale.x, myPos.y + myScale.y };

    Vector2 minB{ otherPos.x - otherScale.x, otherPos.y - otherScale.y };
    Vector2 maxB{ otherPos.x + otherScale.x, otherPos.y + otherScale.y };

    Vector2 minUnion{ (std::min)(minA.x, minB.x), (std::min)(minA.y, minB.y) };
    Vector2 maxUnion{ (std::max)(maxA.x, maxB.x), (std::max)(maxA.y, maxB.y) };

	Rect3* rect = new Rect3;
	rect->setPos(Vector2{ (minUnion.x + maxUnion.x) * 0.5f, (minUnion.y + maxUnion.y) * 0.5f });
	rect->setScale(Vector2{ (maxUnion.x - minUnion.x) * 0.5f, (maxUnion.y - minUnion.y) * 0.5f });
	rect->getCollider()->setPos(rect->getPos());
	rect->getCollider()->setScale(rect->getScale());
	createObject(rect, OBJECT_GROUP::RECT3);

	isUnioned = true;
	deleteObject(this);
	deleteObject(other->getObj());
}
