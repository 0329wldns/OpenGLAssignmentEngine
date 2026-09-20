#pragma once

// 2차원 좌표나 크기를 표현할 때 쓰는 가장 기본 구조체
struct Vector2
{
	double x{};
	double y{};
};

// 실습 과제의 사각형 등을 편하게 다루기 위한 구조체
struct Rect
{
	Vector2 pos{};   // 중심점 좌표 (x, y)
	Vector2 scale{}; // 중심에서부터의 거리 (반직경)
};