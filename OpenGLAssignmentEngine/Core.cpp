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
    // GLFW 초기화[cite: 13]
    if (!glfwInit())
    {
        cerr << "GLFW 초기화 실패!\n";
        return -1;
    }

    // OpenGL 호환성 프로파일 설정 (glRectf, glColor3f 사용 위함)[cite: 13]
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);


    // 1600x1200 윈도우 생성[cite: 13]
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "OpenGL Game Engine", nullptr, nullptr);
    if (!window)
    {
        cerr << "윈도우 생성 실패!\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // GLEW 초기화[cite: 13]
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        cerr << "GLEW 초기화 실패!\n";
        return -1;
    }

    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    // 각 매니저 초기화
    KeyManager::getInstance().init();
    SceneManager::getInstance().init();

    return 0;
}

void Core::progress()
{
    // 입력 이벤트 폴링[cite: 13]
    glfwPollEvents();

    KeyManager::getInstance().update();
    SceneManager::getInstance().update();
    CollisionManager::getInstance().update();

    finalUpdate();
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
    // 초기 배경색 흰색 설정 (실습 1 요구사항)[cite: 13]
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    SceneManager::getInstance().render();

    // 버퍼 교체[cite: 13]
    glfwSwapBuffers(window);
}