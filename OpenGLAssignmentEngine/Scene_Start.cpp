#include "pch.h"
#include "Scene_Start.h"
#include "UIButton.h"

#include "Core.h"
#include "EventFunc.h"

Scene_Start::Scene_Start()
{
}

void Scene_Start::drawBG() const
{
	
}

void Scene_Start::enter()
{
    // === 1번 과제 시작 버튼 만들기 ===
    UIButton* btn1 = new UIButton();
    btn1->setPos(0.0f, 0.0f);   // 윈도우 중앙 위쪽 (800x600 기준)
    btn1->setScale(0.5f, 0.5f);  // 가로 200, 세로 80 크기의 네모
    btn1->setColor(1.0f, 0.5f, 0.0f); // 주황색


    // 이 버튼을 누르면 ASSIGNMENT4 씬으로 넘어가게 설정
    btn1->setTargetScene(SCENE_TYPE::ASSIGNMENT4);

    // 씬의 UI 그룹에 버튼 객체 추가
    addObject(btn1, OBJECT_GROUP::DEFAULT);


    // === 2번 과제 시작 버튼 만들기 (선택사항) ===
    UIButton* btn2 = new UIButton();
    btn2->setPos(400.0f, 350.0f);   // 1번 버튼 아래쪽
    btn2->setScale(100.0f, 40.0f);
    btn2->setColor(0.0f, 0.5f, 1.0f); // 파란색

    // 만약 나중에 SCENE_TYPE::ASSIGNMENT_2 같은 걸 만들면 여기 연결
    // btn2->setTargetScene(SCENE_TYPE::ASSIGNMENT_2); 

    addObject(btn2, OBJECT_GROUP::DEFAULT);

    // 참고: 텍스트(글자)를 화면에 그리는 건 OpenGL에서 조금 복잡한 작업입니다.
    // 일단 콘솔창(검은창)에 안내 문구를 띄워주는 것으로 대체하면 편합니다!
    cout << "================================\n";
    cout << "위쪽 주황 버튼: 1번 실습 과제\n";
    cout << "아래 파랑 버튼: 2번 실습 과제\n";
    cout << "================================\n";
}

void Scene_Start::exit()
{
	reset();
}
