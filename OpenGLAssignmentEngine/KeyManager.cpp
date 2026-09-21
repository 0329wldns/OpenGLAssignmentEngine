#include "pch.h"
#include "KeyManager.h"
#include "Core.h"

// GLFW 키 매핑 배열
int arrVK[(int)KEY::LAST]
{
	GLFW_KEY_UP, GLFW_KEY_DOWN, GLFW_KEY_LEFT, GLFW_KEY_RIGHT,
	GLFW_KEY_W, GLFW_KEY_A, GLFW_KEY_S, GLFW_KEY_D,
	GLFW_MOUSE_BUTTON_LEFT, GLFW_MOUSE_BUTTON_RIGHT, // 마우스
	GLFW_KEY_C, GLFW_KEY_M, GLFW_KEY_Y, GLFW_KEY_G, GLFW_KEY_K, GLFW_KEY_T,
	GLFW_KEY_1, GLFW_KEY_2, GLFW_KEY_3, GLFW_KEY_4,
	GLFW_KEY_ESCAPE // 프로그램 종료 키
};

void KeyManager::init()
{
	for (int i{}; i < (int)KEY::LAST; ++i)
	{
		keyInfo.push_back(KeyInfo{ KEY_STATE::NONE, false });
	}
}

void KeyManager::update()
{
	GLFWwindow* window{ Core::getInstance().getWindow() };
	if (!window) return;

	for (int i{}; i < (int)KEY::LAST; ++i)
	{
		bool isPressed{};

		// 마우스와 키보드는 GLFW 검사 함수가 서로 다름
		if (arrVK[i] == GLFW_MOUSE_BUTTON_LEFT || arrVK[i] == GLFW_MOUSE_BUTTON_RIGHT)
		{
			isPressed = (glfwGetMouseButton(window, arrVK[i]) == GLFW_PRESS);
		}
		else
		{
			isPressed = (glfwGetKey(window, arrVK[i]) == GLFW_PRESS);
		}

		if (isPressed)
		{
			if (keyInfo[i].prevPush) keyInfo[i].keyState = KEY_STATE::HOLD;
			else
			{
				keyInfo[i].keyState = KEY_STATE::TAP;

				cout << "Key Pressed: " << i << endl;
			}

			keyInfo[i].prevPush = true;
		}
		else
		{
			if (keyInfo[i].prevPush) keyInfo[i].keyState = KEY_STATE::AWAY;
			else keyInfo[i].keyState = KEY_STATE::NONE;

			keyInfo[i].prevPush = false;
		}
	}

	// 마우스 좌표 업데이트[cite: 13]
	glfwGetCursorPos(window, &curMousePos.x, &curMousePos.y);
}