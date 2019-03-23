#include "SpritesManager.h"

CSpritesManager * CSpritesManager ::_instance = NULL;

CSpritesManager *CSpritesManager ::GetInstance()
{
	if (_instance == NULL) _instance = new CSpritesManager();
	return _instance;
}


void CSpritesManager::Add(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex)
{
	CSprite* s = new CSprite(id, left, top, right, bottom, tex);
	_sprites[id] = s;
}

LPSPRITE CSpritesManager::GetSprite(int id)
{
	return _sprites[id];
}

