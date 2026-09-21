#pragma once
#include "pch.h"

#include "Scene.h"

class Scene_Assignment3 : public Scene
{
public:
	Scene_Assignment3() = default;
	~Scene_Assignment3() = default;

	void update() override;

	void drawBG() const override {};
	void drawUI() const override {};

	void enter() override;
	void exit() override;

private:

};