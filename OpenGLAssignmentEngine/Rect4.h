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

	void setMovement(MOVEMENT _movement) { state.movement = _movement; };
	void toggleChangeScale() { state.changeScale = !state.changeScale; };
	void toggleChangeColor() { state.changeColor = !state.changeColor; };

	void setColor(float r, float g, float b) { color.r = r; color.g = g; color.b = b; }
	void setColor(Color _color) { color = _color; }
	void setOrgPos(Vector2 _pos) { orgPos.x = _pos.x; orgPos.y = _pos.y; };

	Vector2 getOrgPos() const { return orgPos; };

private:
	inline static State state;

	Color color;
	Vector2 orgPos;
	float changeColorCD;
};