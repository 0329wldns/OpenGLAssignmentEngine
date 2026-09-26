#pragma once
#include "pch.h"
#include "Scene.h"

class Scene_Assignment5 : public Scene
{
public:
	Scene_Assignment5() = default;
	~Scene_Assignment5() = default;

	void update() override;

	void drawBG() const override {};
	void drawUI() const override {};

	void enter() override;
	void exit() override;

	void init();

	void processKeyInput();

private:

};