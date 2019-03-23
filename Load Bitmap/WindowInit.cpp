#include <d3d9.h>
#include <d3dx9.h>
#include "Game.h"
#include "GameGlobal.h"
#include "PlayScene.h"

HINSTANCE               mHInstance;
int                     mCmdShow;
HWND initWindow(HINSTANCE hInstance,int cmdShow);
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int cmdShow)
{
	hWnd = initWindow(hInstance,cmdShow);
	Game::GetInstance()->Init();

	SampleKeyHander *keyHandler = new SampleKeyHander();
	Game::GetInstance()->InitKeyboard(keyHandler, hInstance);
	Game::GetInstance()->Game_Run();
	return 0;
}

HWND initWindow(HINSTANCE hInstace,int cmdShow)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = mHInstance;

	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;

	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WIN_NAME;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);
	//WS_OVERLAPPEDWINDOW <=> WS_EX_TOPMOST | WS_POPUP | WS_VISIBLE
	HWND hWnd = CreateWindow(
		WIN_NAME,
		WIN_NAME,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		NULL,
		NULL,
		mHInstance,
		NULL);


	ShowWindow(hWnd, cmdShow);
	UpdateWindow(hWnd);
	return hWnd;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	/*
	su dung cac event cua window
	*/
	switch (message)
	{
	case WM_DESTROY:
		isGameRunning = false;
		PostQuitMessage(0);
		break;

	case WM_LBUTTONDOWN:

		break;

	case WM_KEYDOWN:

		break;

	case WM_KEYUP:

		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}