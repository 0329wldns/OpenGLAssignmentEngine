#pragma once
#include "Object.h"
#include "EventFunc.h" // 씬 변경(changeScene) 이벤트를 쓰기 위해 포함

class UIButton : public Object
{
public:
    UIButton();
    ~UIButton() = default;

    void update() override;
    void render() const override;

    // 이 버튼이 어떤 씬으로 넘어갈지 설정하는 함수
    void setTargetScene(SCENE_TYPE nextScene) { targetScene = nextScene; }

    // 버튼의 색상을 지정하는 함수 (R, G, B)
    void setColor(float r, float g, float b) { colorR = r; colorG = g; colorB = b; }

private:
    SCENE_TYPE targetScene; // 클릭 시 넘어갈 씬
    float colorR, colorG, colorB; // 버튼 색상
    bool isHover; // 마우스가 버튼 위에 올라와 있는지 상태
};
