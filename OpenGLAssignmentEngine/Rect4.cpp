#include "pch.h"
#include "Rect4.h"
#include "TimeManager.h"

Rect4::Rect4()
	: orgPos()
	, orgScale()
	, changeColorCD()
	, changeScaleCD()
	, flag(true)
{
	setColor(realDist(gen), realDist(gen), realDist(gen));
}

void Rect4::update()
{
	Vector2 myPos{ getPos() };
	Vector2 myScale{ getScale() };

	float dt = TimeManager::getInstance().getDeltaTime();

	// 1. 이동(Movement) 로직 처리
	switch (state.movement)
	{
	case MOVEMENT::DIAGNAL:
	{
		// 이동 적용
		myPos.x += moveDir.x * moveSpeed * dt;
		myPos.y += moveDir.y * moveSpeed * dt;

		// X축 벽 충돌 튕기기
		if (myPos.x - myScale.x <= 0.0f || myPos.x + myScale.x >= SCREEN_WIDTH)
		{
			moveDir.x *= -1.0f; // 방향 반전
		}
		// Y축 벽 충돌 튕기기
		if (myPos.y - myScale.y <= 0.0f || myPos.y + myScale.y >= SCREEN_HEIGHT)
		{
			moveDir.y *= -1.0f;
		}
		break;
	}
	case MOVEMENT::CLOCKWISE:
	{
		// 윈도우 가장자리 시계방향 스냅(Snap) 및 이동
		if (myPos.y - myScale.y <= 0.0f && myPos.x + myScale.x < SCREEN_WIDTH)
		{
			// 상단 벽에 붙어서 우측으로
			myPos.y = myScale.y;
			myPos.x += moveSpeed * dt;
		}
		else if (myPos.x + myScale.x >= SCREEN_WIDTH && myPos.y + myScale.y < SCREEN_HEIGHT)
		{
			// 우측 벽에 붙어서 하단으로
			myPos.x = SCREEN_WIDTH - myScale.x;
			myPos.y += moveSpeed * dt;
		}
		else if (myPos.y + myScale.y >= SCREEN_HEIGHT && myPos.x - myScale.x > 0.0f)
		{
			// 하단 벽에 붙어서 좌측으로
			myPos.y = SCREEN_HEIGHT - myScale.y;
			myPos.x -= moveSpeed * dt;
		}
		else if (myPos.x - myScale.x <= 0.0f && myPos.y - myScale.y > 0.0f)
		{
			// 좌측 벽에 붙어서 상단으로
			myPos.x = myScale.x;
			myPos.y -= moveSpeed * dt;
		}
		else
		{
			// 허공에 있을 경우 가장 가까운 위쪽 가장자리로 강제 유도
			myPos.y -= moveSpeed * dt;
		}
		break;
	}
	}
	setPos(myPos);

	if (state.changeColor)
	{
		changeColorCD += dt;
		if (changeColorCD >= 2.0f)
		{
			setColor(realDist(gen), realDist(gen), realDist(gen));
			changeColorCD -= 2.0f;
		}
	}
	if (state.changeScale)
	{
		if (flag) setScale(myScale.x + orgScale.x * 1.5f * dt, myScale.y + orgScale.y * 1.5f * dt);
		else setScale(myScale.x - orgScale.x * 1.5f * dt, myScale.y - orgScale.y * 1.5f * dt);

		if (myScale.x > orgScale.x * 1.5f && myScale.y > orgScale.y * 1.5f)
			flag = false;
		else if(myScale.x < orgScale.x * 0.5f && myScale.y < orgScale.y * 0.5f)
			flag = true;
	}
}

void Rect4::render() const
{
	glColor3f(color.r, color.g, color.b);

	Vector2 myPos{ getPos() };
	Vector2 myScale{ getScale() };

	glRectd(myPos.x - myScale.x, myPos.y - myScale.y, myPos.x + myScale.x, myPos.y + myScale.y);
}
