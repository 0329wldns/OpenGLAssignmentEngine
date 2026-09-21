#include "pch.h"
#include "Core.h"
#include "KeyManager.h"
#include "SceneManager.h"
#include "EventManager.h"
#include "CollisionManager.h"

Core::~Core()
{
	if (window)
	{
		glfwDestroyWindow(window);
	}
	glfwTerminate();
}

int Core::init()
{
	// GLFW 초기화
	if (!glfwInit())
	{
		cerr << "GLFW 초기화 실패!\n";
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	// 윈도우 생성
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "OpenGL Game Engine", nullptr, nullptr);
	if (!window)
	{
		cerr << "윈도우 생성 실패!\n";
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	// GLEW 초기화
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		cerr << "GLEW 초기화 실패!\n";
		return -1;
	}

	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	// 카메라 행렬(투영) 설정 모드로 변경
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0.0, (double)SCREEN_WIDTH, (double)SCREEN_HEIGHT, 0.0, -1.0, 1.0);

	// 다시 모델(그리기) 행렬 모드로 복구
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// 각 매니저 초기화
	KeyManager::getInstance().init();
	SceneManager::getInstance().init();

	// 배경색 설정
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	return 0;
}

void Core::progress()
{
	// 입력 이벤트 폴링
	glfwPollEvents();

	KeyManager::getInstance().update();
	SceneManager::getInstance().update();
	
	finalUpdate();
	CollisionManager::getInstance().update();
	render();

	EventManager::getInstance().update();
}

bool Core::isRunning() const
{
	return !glfwWindowShouldClose(window);
}

void Core::update()
{
}

void Core::finalUpdate()
{
	SceneManager::getInstance().finalUpdate();
}

void Core::render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	SceneManager::getInstance().render();

	// 버퍼 교체
	glfwSwapBuffers(window);
}