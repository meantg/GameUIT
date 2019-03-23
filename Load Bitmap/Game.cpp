#include "Game.h"
#include "GameGlobal.h"
#include "PlayScene.h"
#include "SceneManager.h"

// Constructor khởi tạo Game
Game *Game::_instance = NULL;

// Khởi tạo Game từ Windows với các Device-Components cần thiết
void Game::Init()
{
	// Khởi tạo thư viện tổng và BackBuffer
	auto d3d = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferCount = 1;

	// Lấy thông tin khung Windows để tạo Back Buffer
	RECT r;
	GetClientRect(hWnd, &r);
	d3dpp.BackBufferHeight = r.bottom + 1;
	d3dpp.BackBufferWidth = r.right + 1;

	// Tạo Device
	d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &d3ddev);

	// Lấy BackBuffer
	d3ddev->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backBuffer);

	// Tạo Sprite Handler
	D3DXCreateSprite(d3ddev, &spriteHandler);
	SceneManager::GetInstance()->ReplaceScene(new PlayScene());
}

// Khởi chạy vòng lặp game và xử lí các thông điệp
void Game::Game_Run()
{
	MSG msg;
	auto frameStart = GetTickCount();
	auto tickPerFrame = 1000 / 120;

	while (isGameRunning)
	{
		// Nếu là thông điệp thoát thì thoát
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				isGameRunning = false;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		// Vòng lặp game chính (cập nhật thời gian, thông số và Render lại Frame hình)
		auto now = GetTickCount();
		auto dt = now - frameStart;

		if (dt >= tickPerFrame)
		{
			frameStart = now;
			this->ProcessKeyboard();
			Update(dt);
			Render();
		}
		else
		{
			Sleep(tickPerFrame - dt);
		}
	}
}

// Update các thông số của Game theo một khoảng delta-time
void Game::Update(int dt)
{
	SceneManager::GetInstance()->GetCurScene()->Update(dt);

}

// Render lại Frame hình sau khi đã Update các thông số
void Game::Render()
{
	auto scene = SceneManager::GetInstance()->GetCurScene();
	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, scene->GetBackColor(), 0.0f, 0);

	if (d3ddev->BeginScene())
	{
		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
		scene->Render();
		spriteHandler->End();
		d3ddev->EndScene();
	}
	d3ddev->Present(NULL, NULL, NULL, NULL);
}

void Game::Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom)
{
	D3DXVECTOR3 p(x, y, 0);
	RECT r;
	r.left = left;
	r.top = top;
	r.right = right;
	r.bottom = bottom;
	spriteHandler->Draw(texture, &r, NULL, &p, D3DCOLOR_XRGB(255, 255, 255));
}

int Game::IsKeyDown(int KeyCode)
{
	return (keyStates[KeyCode] & 0x80) > 0;
}



void Game::InitKeyboard(LPKEYEVENTHANDLER handler, HINSTANCE hInstance)
{
	HRESULT
		hr = DirectInput8Create
		(
		    hInstance,
			DIRECTINPUT_VERSION,
			IID_IDirectInput8, (VOID**)&di8, NULL
		);

	hr = di8->CreateDevice(GUID_SysKeyboard, &didv8, NULL);

	// TO-DO: put in exception handling


	// Set the data format to "keyboard format" - a predefined data format 
	//
	// A data format specifies which controls on a device we
	// are interested in, and how they should be reported.
	//
	// This tells DirectInput that we will be passing an array
	// of 256 bytes to IDirectInputDevice::GetDeviceState.

	hr = didv8->SetDataFormat(&c_dfDIKeyboard);

	hr = didv8->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);


	// IMPORTANT STEP TO USE BUFFERED DEVICE DATA!
	//
	// DirectInput uses unbuffered I/O (buffer size = 0) by default.
	// If you want to read buffered data, you need to set a nonzero
	// buffer size.
	//
	// Set the buffer size to DINPUT_BUFFERSIZE (defined above) elements.
	//
	// The buffer size is a DWORD property associated with the device.
	DIPROPDWORD dipdw;

	dipdw.diph.dwSize = sizeof(DIPROPDWORD);
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipdw.diph.dwObj = 0;
	dipdw.diph.dwHow = DIPH_DEVICE;
	dipdw.dwData = 1024; // Arbitary buffer size

	hr = didv8->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);

	hr = didv8->Acquire();

	this->keyHandler = handler;	
}
void Game::ProcessKeyboard()
{
	HRESULT hr;

	// Collect all key states first
	hr = didv8->GetDeviceState(sizeof(keyStates), keyStates);

	keyHandler->KeyState((BYTE *)&keyStates);

	// Collect all buffered events
	DWORD dwElements = 1024;
	hr = didv8->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), keyEvents, &dwElements, 0);
	if (FAILED(hr))
	{
		//DebugOut(L"[ERROR] DINPUT::GetDeviceData failed. Error: %d\n", hr);
		return;
	}

	// Scan through all buffered events, check if the key is pressed or released
	for (DWORD i = 0; i < dwElements; i++)
	{
		int KeyCode = keyEvents[i].dwOfs;
		int KeyState = keyEvents[i].dwData;
		if ((KeyState & 0x80) > 0)
			keyHandler->OnKeyDown(KeyCode);
		else
 			keyHandler->OnKeyUp(KeyCode);
	}
}
Game *Game::GetInstance()
{
	if (_instance == NULL) _instance = new Game();
	return _instance;
}