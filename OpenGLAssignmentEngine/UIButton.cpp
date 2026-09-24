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
	// 마우스가 버튼 위에 있으면 색을 살짝 밝게(노란색 등) 바꿔서 선택된 느낌 주기
	if (isHover) glColor3f(1.0f, 1.0f, 0.0f); // 노란색
	else glColor3f(color.r, color.g, color.b);   // 원래 설정한 색상

	Vector2 myPos = getPos();
	Vector2 myScale = getScale();

	glRectd(myPos.x - myScale.x, myPos.y - myScale.y, myPos.x + myScale.x, myPos.y + myScale.y);
}