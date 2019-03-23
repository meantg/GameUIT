#include "Object.h"

Object::Object()
{
	x = y = 0;
	vx = 0.1f;
}

void Object::Update(DWORD dt)
{
	//Dich chuyen vi tri cua Anim
	x += vx * dt;
	if ((vx > 0 && x >= SCREEN_WIDTH) || (x < 0 && vx < 0))
		vx = -vx;
}

void Object::Render()
{
	LPANIMATION ani;
	ani = animations[8];
	ani->Render(x, y);
	
}

void Object::AddAnimation(int aniID)
{
	LPANIMATION ani = Animations::GetInstance()->Get(aniID);
	animations.push_back(ani);
}

Object::~Object(){}