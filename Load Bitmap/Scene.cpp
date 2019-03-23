#include "Scene.h"

// Constructor khởi tạo Scene: tạo màu nền và load resources
Scene::Scene()
{
	_backColor = D3DCOLOR_XRGB(255, 255, 255);
	LoadResources();
};

// Lấy màu nền
D3DCOLOR Scene::GetBackColor()
{
	return _backColor;
}

