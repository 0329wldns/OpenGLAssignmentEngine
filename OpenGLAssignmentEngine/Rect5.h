#pragma once
#include "pch.h"
#include "Object.h"

class Rect5 : public Object
{
public:
	Rect5();
	~Rect5() = default;

	void update() override;

	void render() const override;

	void onCollision(Collider*) override;

	void setColor(float r, float g, float b) { color.r = r; color.g = g; color.b = b; };
	void setColor(Color _color) { color = _color; };

private:
	Color color;
};