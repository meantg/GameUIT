#pragma once
#include "d3d9.h"
#include "d3dx9.h"
#include "string"
#include "Textures.h"

using namespace std;

class CSprite
{
protected:
	int id; //sprite ID

	int left, top, right, bottom; //position of sprite in texture
	
	LPDIRECT3DTEXTURE9 texture;

	bool _isFlipVertical, _isFlipHorizontal;
public:
	CSprite() {};
	CSprite(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex);
	void Draw(float x = 0, float y = 0, bool _isFlipHoritzontal = false);
	void FlipHorizontal(bool flip);
	//void FlipVertical(bool flip);

	//bool isFlipVertical();
	bool isFlipHorizontal();
};

typedef CSprite * LPSPRITE;
