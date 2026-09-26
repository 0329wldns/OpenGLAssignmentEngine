#pragma once
#include "pch.h"
#include "Object.h"

class Rect4 : public Object
{
public:
	Rect4();
	~Rect4() = default;

	void update() override;

	void render() const override;

	void setColor(float r, float g, float b) { color.r = r; color.g = g; color.b = b; }
	void setColor(Color _color) { color = _color; }

private:
	Color color;
};