#pragma once
#include "pch.h"

#include "Object.h"

class Scene
{
public:
	Scene();
	~Scene();

	virtual void update();
	void finalUpdate();
	virtual void render();

	virtual void drawBG() const = 0;
	virtual void drawUI() const = 0;
	virtual void drawClear() const {};

	virtual void enter() = 0;	// æ¿ ¡¯¿‘
	virtual void exit() = 0;	// æ¿ ≈ª√‚

	void reset();

	void addObject(Object* obj, OBJECT_GROUP group);

	const vector<Object*>& getGroupObject(OBJECT_GROUP _group) const { return object[(int)_group]; }

private:
	vector<Object*> object[(int)OBJECT_GROUP::END];
};
