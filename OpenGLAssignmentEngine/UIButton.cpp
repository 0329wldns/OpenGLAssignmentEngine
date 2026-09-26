#include "pch.h"
#include "UIButton.h"
#include "KeyManager.h"
#include "EventFunc.h"

UIButton::UIButton()
	: targetScene(SCENE_TYPE::START)
	, isHover(false)
{
	color.r = 0.5f;
	color.g = 0.5f;
	color.b = 0.5f;
}

void UIButton::update()
{
	
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
		glColor3f(1.0f - color.r, 1.0f - color.g, 1.0f - color.b); // 노란색

		glBegin(GL_LINE_LOOP);
		glVertex2f(GLfloat(myPos.x - myScale.x), GLfloat(myPos.y - myScale.y)); // 좌하단
		glVertex2f(GLfloat(myPos.x + myScale.x), GLfloat(myPos.y - myScale.y)); // 우하단
		glVertex2f(GLfloat(myPos.x + myScale.x), GLfloat(myPos.y + myScale.y)); // 우상단
		glVertex2f(GLfloat(myPos.x - myScale.x), GLfloat(myPos.y + myScale.y)); // 좌상단
		glEnd();
	}
}