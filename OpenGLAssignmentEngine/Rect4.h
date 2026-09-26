#pragma once
#include "pch.h"
#include "Object.h"

enum class MOVEMENT
{
	NONE,
	DIAGNAL,
	ZIGZAG,
	CLOCKWISE
};

struct State
{
	MOVEMENT movement{ MOVEMENT::NONE};
	bool changeScale{ false };
	bool changeColor{ false };
};

class Rect4 : public Object
{
public:
	Rect4();
	~Rect4() = default;

	void update() override;
	void render() const override;

	static void setMovement(MOVEMENT _movement) { state.movement = _movement; };
	static void toggleChangeScale() { state.changeScale = !state.changeScale; };
	static void toggleChangeColor() { state.changeColor = !state.changeColor; };

	void setColor(float r, float g, float b) { color.r = r; color.g = g; color.b = b; }
	void setColor(Color _color) { color = _color; }
	void setOrgPos(Vector2 _pos) { orgPos.x = _pos.x; orgPos.y = _pos.y; };
	void setOrgScale(Vector2 _scale) { orgScale.x = _scale.x; orgScale.y = _scale.y; };

	static State getState() { return state; };
	Vector2 getOrgPos() const { return orgPos; };
	Vector2 getOrgScale() const { return orgScale; };

private:
	inline static State state;

	Color color;
	Vector2 orgPos;
	Vector2 orgScale;

	float changeColorCD;
	float changeScaleCD;
	bool flag;

	Vector2 moveDir{ 1.0f, 1.0f }; // 초기 대각선 방향 설정
	float moveSpeed{ 300.0f };     // 초당 300픽셀 이동 (필요에 따라 조절)
};