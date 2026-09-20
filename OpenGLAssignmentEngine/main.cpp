#include "pch.h"
#include "Core.h"
#include "KeyManager.h"

int main()
{
    // 1. 엔진 초기화
    if (Core::getInstance().init() != 0)
    {
        return -1;
    }

    // 2. 메인 게임 루프[cite: 13]
    while (Core::getInstance().isRunning())
    {
        Core::getInstance().progress();

        // ESC 누르면 프로그램 종료 처리[cite: 13]
        if (KeyManager::getInstance().getKeyState(KEY::ESC) == KEY_STATE::TAP)
        {
            glfwSetWindowShouldClose(Core::getInstance().getWindow(), true);
        }
    }

    return 0;
}