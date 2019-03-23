#include "Sprite.h"
#include "GameGlobal.h"

//Constructor - Khoi tao 1 Sprite tu duong dan
CSprite::CSprite(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex)
{
	this->id = id;
	this->left = left;
	this->top = top;
	this->right = right;
	this->bottom = bottom;
	this->texture = tex;
}



//Ve sprite tai toa do (x,y)
//Voi (x,y) la trung tam cua Sprite
void CSprite::Draw(float x, float y, bool _isFlipHorizontal)
{
	//Tao rect de ve Sprite

	D3DXVECTOR3 p(x, y, 0);
	RECT r;
	r.left = left;
	r.top = top;
	r.right = right;
	r.bottom = bottom;
	//spriteHandler->Draw(texture, &r, NULL, &p, D3DCOLOR_XRGB(255,255,255));
	int _width = right - left;
	int _height = bottom - top;
	// Nếu có lật hình (theo Ox hay Oy) thì thiết đặt biến đổi hình băng ma trận
	auto pCenter = D3DXVECTOR3(_width >> 1, _height >> 1, 0);
	auto pPosition = D3DXVECTOR3(x, y, 0);
	auto pRotationCenter = D3DXVECTOR2(_width >> 1, _height >> 1);	
	auto pScalingCenter = D3DXVECTOR2(x, y);
	auto pScaling = D3DXVECTOR2(_isFlipHorizontal ? -1 : 1, 1);

	D3DXMATRIX oldMatrix, curMatrix;
	D3DXMatrixTransformation2D(&curMatrix, &pScalingCenter, 0, &pScaling, &pRotationCenter, 0, NULL);
	spriteHandler->GetTransform(&oldMatrix);
	spriteHandler->SetTransform(&curMatrix);
	spriteHandler->Draw(texture, &r, &pCenter, &pPosition, D3DCOLOR_XRGB(255, 255, 255));
	spriteHandler->SetTransform(&oldMatrix);
}

//
void CSprite::FlipHorizontal(bool flip)
{
	if (_isFlipHorizontal != flip)
	{
		_isFlipHorizontal = flip;
	}
}
//
//void Sprite::FlipVertical(bool flag)
//{
//	if (_isFlipVertical != flag)
//	{
//		_isFlipVertical = flag;
//	}
//}
//
bool CSprite::isFlipHorizontal()
{
	return _isFlipHorizontal;
}

//bool Sprite::isFlipVertical()
//{
//	return _isFlipVertical;
//}

