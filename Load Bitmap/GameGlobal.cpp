﻿#include "GameGlobal.h"

HINSTANCE hInstance = NULL;						// hInstance của windows hiện tại
HWND hWnd = NULL;								// hWnd hiện tại
LPD3DXSPRITE spriteHandler = nullptr;			// SpriteHanlder hiện tại
LPDIRECT3DDEVICE9 d3ddev = nullptr;				// Device directX hiện tại (nhằm đại diện card màn hình)
LPDIRECT3DSURFACE9 backBuffer = nullptr;		// BackBuffer
LPDIRECT3DSURFACE9 surface = nullptr;
bool isGameRunning = true;						// Kiểm tra trạng thái game đang chạy HINSTANCE hIN