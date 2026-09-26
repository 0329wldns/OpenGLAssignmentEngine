#pragma once
#include "pch.h"
#include "Scene.h"

class Scene_Assignment4 : public Scene
{
public:
	Scene_Assignment4() = default;
	~Scene_Assignment4() = default;

	void update() override;

	void drawBG() const override {};
	void drawUI() const override {};

	void enter() override;
	void exit() override;

	void processKeyInput();

private:

};