#pragma once
#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>

#define SCREEN_WIDTH 1024					// Chiều rộng cửa sổ
#define SCREEN_HEIGHT 768					// Chiều dài cửa sổ
#define MAX_FRAME_RATE 60					// FPS
#define WIN_NAME "Game DirectX"
#define WIN_TITLE "Game DirectX"
#define FPS 60
#define KEYBOARD_BUFFERD_SIZE	1024
#define NINJA_WALKING_SPEED		0.2f
#define NINJA_JUMPING_SPEED_Y	0.5f
#define NINJA_GRAVITY			0.2f

//State
#define NINJA_ATK				10
#define NINJA_RUN				11
#define NINJA_STAND

//Animation
#define NINJA_IDLE				0
#define NINJA_ATK_STANDING		1
#define NINJA_THROWING			2
#define NINJA_CLIMBING			3
#define NINJA_RUN_RIGHT			4
#define NINJA_RUN_LEFT			9
#define NINJA_SITTING			5
#define NINJA_ATK_SITTING		6
#define NINJA_JUMP				7
#define NINJA_JUMP_ATK			8


extern HWND hWnd; // window handle
extern HINSTANCE hInstance; // The hien
extern LPD3DXSPRITE spriteHandler; //con tro sprite
extern LPDIRECT3DDEVICE9 d3ddev; //con tro den thiet bi
extern int width, height; // thuoc tinh cua window
extern LPDIRECT3DSURFACE9 backBuffer; //
extern LPDIRECT3DSURFACE9 surface;
extern bool isGameRunning;

extern enum State
	{
		STANDING,
		RUNNING,
		JUMPING,
		FALLING,
		SITTING,
		ATTACKING,
		ATTACKING_STAND,
		ATTACKING_SIT,
		CLIMBING,
	};