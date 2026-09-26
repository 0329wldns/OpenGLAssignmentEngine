#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <random>
#include <windows.h>
#include <cmath>

// OpenGL 관련 라이브러리 (GLEW가 GLFW보다 먼저 include 되어야 함)
#include <GL/glew.h>
#include <GL/glfw3.h>

using namespace std;

static random_device rd{};
static mt19937 gen(rd());
static uniform_int_distribution<int> intDist(1, 10000);
static uniform_real_distribution<float> realDist(0.0f, 1.0f);

static const int SCREEN_WIDTH = 1600;
static const int SCREEN_HEIGHT = 1200;

enum class SCENE_TYPE
{
	START,
	ASSIGNMENT3,
	ASSIGNMENT4,
	ASSIGNMENT5,
	// ASSIGNMENT6,

	END
};

enum class OBJECT_GROUP
{
	DEFAULT,
	UIBUTTON,
	RECT3,
	RECT4,
	RECT5,
	RECT6,
	ERASER_RECT,

	END
};