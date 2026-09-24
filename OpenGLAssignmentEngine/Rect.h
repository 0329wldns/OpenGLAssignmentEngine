#pragma once
#include "pch.h"
#include "Object.h"

class Rect : public Object
{
public:
	Rect();
	~Rect();

	void update() override;

	void onMouseDownLeft() override;
	void onMouseUpLeft() override;

	void render() const override;

	void onCollision(Collider*) override;

	void setColor(float r, float g, float b) { color.r = r; color.g = g; color.b = b; }
	void setColor(Color _color) { color = _color; }

private:
	Color color;

	bool isHeld;
	Vector2 dragOffset{};
};