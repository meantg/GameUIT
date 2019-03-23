#include "Textures.h"

CTexture * CTexture::_instance = NULL;

void CTexture::Add(int id, LPCSTR filePath, D3DCOLOR transparentColor)
{
	D3DXIMAGE_INFO info;
	HRESULT result = D3DXGetImageInfoFromFile(filePath, &info);

	LPDIRECT3DTEXTURE9 texture;

	result = D3DXCreateTextureFromFileEx(
		d3ddev,								// Pointer to Direct3D device object
		filePath,							// Path to the image to load
		info.Width,							// Texture width
		info.Height,						// Texture height
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transparentColor,
		&info,
		NULL,
		&texture);

	textures[id] = texture;
}

LPDIRECT3DTEXTURE9 CTexture::GetTexture(unsigned int i)
{
	return textures[i];
}

CTexture * CTexture::GetInstance()
{
	if (_instance == NULL) _instance = new CTexture();
	return _instance;
}

CTexture::CTexture()
{

}