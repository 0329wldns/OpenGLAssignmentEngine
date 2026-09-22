#pragma once

// 2차원 좌표나 크기를 표현할 때 쓰는 가장 기본 구조체
struct Vector2
{
	double x{};
	double y{};

	Vector2 operator+(const Vector2& rhs) { Vector2 temp{ x + rhs.x, y + rhs.y }; return temp; };
	Vector2 operator-(const Vector2& rhs) { Vector2 temp{ x - rhs.x, y - rhs.y }; return temp; };
};

struct Color
{
	float r{};
	float g{};
	float b{};
};