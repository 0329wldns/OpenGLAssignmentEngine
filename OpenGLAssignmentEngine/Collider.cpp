#include "pch.h"
#include "collider.h"

#include "KeyManager.h"

#include "SceneManager.h"

static unsigned int g_Id{ 0 };

Collider::Collider()
	: owner(nullptr)
	, pos()
	, scale()
	, offset()
	, id(g_Id++)
	, isCol(false)
{
}

void Collider::finalUpdate()
{
	pos.x = owner->getPos().x + offset.x;
	pos.y = owner->getPos().y + offset.y;
}

void Collider::render()
{
    // 디버그용 테두리 출력이 꺼져있으면 무시
    // if (!SceneManager::getInstance().getCurScene()->showBorder()) return;

    if (isCol)
    {
        glColor3f(1.0f, 0.0f, 0.0f); // 충돌 중이면 빨간색
    }
    else
    {
        glColor3f(1.0f, 1.0f, 0.0f); // 평소엔 노란색
    }

    // OpenGL로 속이 빈 사각형 그리기 (선 연결)
    glBegin(GL_LINE_LOOP);
    glVertex2f(GLfloat(pos.x - scale.x), GLfloat(pos.y - scale.y)); // 좌하단
    glVertex2f(GLfloat(pos.x + scale.x), GLfloat(pos.y - scale.y)); // 우하단
    glVertex2f(GLfloat(pos.x + scale.x), GLfloat(pos.y + scale.y)); // 우상단
    glVertex2f(GLfloat(pos.x - scale.x), GLfloat(pos.y + scale.y)); // 좌상단
    glEnd();
}

void Collider::onCollision(Collider* other)
{
	owner->onCollision(other);
	isCol = true;
}

void Collider::onCollisionEnter(Collider* other)
{
	owner->onCollisionEnter(other);
	isCol = true;
}

void Collider::onCollisionExit(Collider* other)
{
	owner->onCollisionExit(other);
	isCol = false;
}
