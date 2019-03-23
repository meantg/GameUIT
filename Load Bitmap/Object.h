#pragma once
#include <Windows.h>
#include <d3dx9.h>
#include <vector>
#include "Sprite.h"
#include "Animation.h"

class Object
{
protected:
	float x, y;
	float vx;

	int _curState;

	vector<LPANIMATION> animations;
public:
	void SetPosition(float x, float y) { this->x = x; this->y = y; }
	void SetState(int state) { this->_curState = state; }
	void AddAnimation(int aniID);

	Object();

	virtual void Update(DWORD dt);
	virtual void Render();
	~Object();
};