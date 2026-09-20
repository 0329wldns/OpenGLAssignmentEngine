#pragma once
#include "pch.h"

#include "Scene.h"

class Scene_Start : public Scene
{
public:
	Scene_Start();

	void drawBG() const override;
	void drawUI() const override {};

	void enter() override;
	void exit() override;

private:

};
