#include "pch.h"
#include "UIButton.h"
#include "KeyManager.h"
#include "EventFunc.h"
#include "TimeManager.h"

UIButton::UIButton()
	: targetScene(SCENE_TYPE::START)
	, isHover(false)
{
	setScale(100, 60);
	setColor(0.5f, 0.5f, 0.5f);
}

void UIButton::update()
{
	Vector2 myPos{ getPos() };
	Vector2 myScale{ getScale() };

	float dt = TimeManager::getInstance().getDeltaTime();

	if (isHover)
	{
		if (myScale.x < 100 * 1.2f && myScale.y < 60 * 1.2f)
			setScale(myScale.x + 100 * 1.4f * dt, myScale.y + 60 * 1.4f * dt);
	}
	else
	{
		if (myScale.x > 100 && myScale.y > 60)
			setScale(myScale.x - 100 * 1.2f * dt, myScale.y - 60 * 1.2f * dt);
	}
}

void UIButton::onMouseEnter()
{
	isHover = true;
}

void UIButton::onMouseLeave()
{
	isHover = false;
}

void UIButton::onMouseDownLeft()
{
	changeScene(targetScene);
}

void UIButton::render() const
{
	glColor3f(color.r, color.g, color.b);   // 원래 설정한 색상

	Vector2 myPos = getPos();
	Vector2 myScale = getScale();

	glRectd(myPos.x - myScale.x, myPos.y - myScale.y, myPos.x + myScale.x, myPos.y + myScale.y);

	if (isHover)
	{
		glColor3f(1.0f, 0.0f, 0.0f);

		glBegin(GL_LINE_LOOP);
		glVertex2f(GLfloat(myPos.x - myScale.x), GLfloat(myPos.y - myScale.y));
		glVertex2f(GLfloat(myPos.x + myScale.x), GLfloat(myPos.y - myScale.y));
		glVertex2f(GLfloat(myPos.x + myScale.x), GLfloat(myPos.y + myScale.y));
		glVertex2f(GLfloat(myPos.x - myScale.x), GLfloat(myPos.y + myScale.y));
		glEnd();
	}
}