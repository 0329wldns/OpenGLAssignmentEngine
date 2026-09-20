#include "pch.h"
#include "UIButton.h"
#include "KeyManager.h"

UIButton::UIButton()
    : targetScene(SCENE_TYPE::START)
    , colorR(0.5f), colorG(0.5f), colorB(0.5f) // 기본 회색
    , isHover(false)
{
}

void UIButton::update()
{
    // 1. 현재 마우스 위치 가져오기
    Vector2 mousePos = KeyManager::getInstance().getMousePos();

    // 2. 내 버튼의 위치와 크기 가져오기
    Vector2 myPos = getPos();
    Vector2 myScale = getScale();

    // 3. 마우스가 내 버튼 네모 상자 안에 있는지 검사 (충돌 체크)
    if (mousePos.x > myPos.x - myScale.x && mousePos.x < myPos.x + myScale.x &&
        mousePos.y > myPos.y - myScale.y && mousePos.y < myPos.y + myScale.y)
    {
        isHover = true; // 마우스가 올라와 있음!

        // 4. 마우스가 올라와 있는데, 왼쪽 마우스 버튼을 '막 눌렀다(TAP)'면?
        if (KeyManager::getInstance().getKeyState(KEY::MOUSE_L) == KEY_STATE::TAP)
        {
            // 원하는 과제 씬으로 이동하라고 이벤트 매니저에게 명령!
            changeScene(targetScene);
        }
    }
    else
    {
        isHover = false; // 마우스가 벗어남
    }
}

void UIButton::render() const
{
    // 마우스가 버튼 위에 있으면 색을 살짝 밝게(노란색 등) 바꿔서 선택된 느낌 주기
    if (isHover) glColor3f(1.0f, 1.0f, 0.0f); // 노란색
    else glColor3f(colorR, colorG, colorB);   // 원래 설정한 색상

    Vector2 myPos = getPos();
    Vector2 myScale = getScale();

    glRectd(myPos.x - myScale.x, myPos.y - myScale.y, myPos.x + myScale.x, myPos.y + myScale.y);

	// cout << "UIButton::render() called. Position: (" << myPos.x << ", " << myPos.y << "), Scale: (" << myScale.x << ", " << myScale.y << ")\n";

    // OpenGL로 속이 꽉 찬 사각형(버튼) 그리기
    glBegin(GL_QUADS);
    glVertex2f(myPos.x - myScale.x, myPos.y - myScale.y); // 좌하단
    glVertex2f(myPos.x + myScale.x, myPos.y - myScale.y); // 우하단
    glVertex2f(myPos.x + myScale.x, myPos.y + myScale.y); // 우상단
    glVertex2f(myPos.x - myScale.x, myPos.y + myScale.y); // 좌상단
    glEnd();
}