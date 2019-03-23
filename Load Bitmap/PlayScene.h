#pragma once
#include "Scene.h"
#include "Animation.h"
#include <vector>
#include "Textures.h"
#include "Player.h"
#include "Game.h"

class PlayScene : public Scene
{
private:
	Animations *animations;// Animation cừu chuyển động
	float _timeCounter;								// Counter nhằm Update Scene sau một khoảng thời gian

public:
	PlayScene();
	~PlayScene();
	void LoadResources();							// Load các resources cần thiết để khởi tạo Scene
	virtual void Update(float dt);							// Update các thông số các đối tượng trong Scene
	void Render();									// Tải Scene lên màn hình
};

class SampleKeyHander : public KeyEventHandler
{
	virtual void KeyState(BYTE *states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
};
