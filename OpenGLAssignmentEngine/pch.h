#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <random>

// OpenGL 관련 라이브러리 (GLEW가 GLFW보다 먼저 include 되어야 함)
#include <GL/glew.h>
#include <GL/glfw3.h>

using namespace std;

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 1200;

enum class SCENE_TYPE
{
	START,
	ASSIGNMENT4,

	END
};

enum class OBJECT_GROUP
{
	DEFAULT,
	PLAYER,

	END
};