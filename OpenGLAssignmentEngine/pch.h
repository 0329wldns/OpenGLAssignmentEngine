#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <random>
#include <windows.h>

// OpenGL 관련 라이브러리 (GLEW가 GLFW보다 먼저 include 되어야 함)
#include <GL/glew.h>
#include <GL/glfw3.h>

using namespace std;

inline const int SCREEN_WIDTH = 1600;
inline const int SCREEN_HEIGHT = 1200;

enum class SCENE_TYPE
{
	START,
	ASSIGNMENT3,
	ASSIGNMENT4,

	END
};

enum class OBJECT_GROUP
{
	DEFAULT,
	UIButton,

	END
};