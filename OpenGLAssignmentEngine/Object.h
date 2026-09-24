#pragma once
#include "pch.h"
#include "Struct.h"

#include "collider.h"

class Collider;

class Object
{
public:
	Object();
	virtual ~Object();

	void createCollider();
	void creaeteAnimator() {};

	virtual void update() = 0;
	virtual void finalUpdate() final;

	virtual void onMouseEnter() {};
	virtual void onMouseLeave() {};
	virtual void onMouseDownLeft() {};
	virtual void onMouseDownRight() {};
	virtual void onMouseUpLeft() {};
	virtual void onMouseUpRight() {};

	virtual void render() const = 0;
	void componantRender() const;

	virtual void onCollision(Collider*) {};
	virtual void onCollisionEnter(Collider*) {};
	virtual void onCollisionExit(Collider*) {};

	void setPos(Vector2 _pos) { pos = _pos; }
	void setPos(int _posX, int _posY) { pos.x = (double)_posX; pos.y = (double)_posY; }
	void setPos(float _posX, float _posY) { pos.x = (double)_posX; pos.y = (double)_posY; }
	void setScale(Vector2 _scale) { scale = _scale; }
	void setScale(int _scaleX, int _scaleY) { scale.x = (float)_scaleX; scale.y = (float)_scaleY; }
	void setScale(float _scaleX, float _scaleY) { scale.x = _scaleX; scale.y = _scaleY; }
	void setOffset(Vector2 _offset) { offset = _offset; }
	void setOffset(float _offsetX, float _offsetY) { offset.x = _offsetX; offset.y = _offsetY; }

	Vector2 getPos() const { return pos; }
	Vector2 getScale() const { return scale; }
	Vector2 getOffset() const { return offset; }
	Collider* getCollider() const { return collider; }
	bool isDead() const { return !alive; }

private:
	void setDead() { alive = false; }

private:
	Vector2 pos;
	Vector2 scale;
	Vector2 offset;

	Collider* collider;

	bool alive;

	friend class EventManager;
};