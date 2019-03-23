#pragma once
#include <unordered_map>
#include "d3dx9.h"
#include "iostream"
#include "GameGlobal.h"

using namespace std;

class CTexture
{
private:
	static CTexture * _instance;
	unordered_map<int, LPDIRECT3DTEXTURE9> textures;
public:
	CTexture();
	void Add(int id, LPCSTR filePath, D3DCOLOR transparentColor);
	LPDIRECT3DTEXTURE9 GetTexture(unsigned int id);

	static CTexture * GetInstance();
};