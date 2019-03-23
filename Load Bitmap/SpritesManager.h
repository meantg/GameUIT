#pragma once
#include "Sprite.h"

class CSpritesManager : CSprite
{
	unordered_map<int, LPSPRITE> _sprites;
	static CSpritesManager *_instance;

public:
	void Add(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex);
	static CSpritesManager * GetInstance();
	LPSPRITE GetSprite(int id);
};