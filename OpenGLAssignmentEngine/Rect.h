#pragma once
#include "pch.h"
#include "Object.h"

class Rect : public Object
{
public:
	Rect();
	~Rect();

	void update() override;
	void render() const override;

	void onCollision(Collider*) override;

private:
	Color color;

};