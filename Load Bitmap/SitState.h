#pragma once
#include "PlayerState.h"
#include "Player.h"

class SitState : public PlayerState
{
public:
	SitState(PlayerHandler * _playerhandler);
	void Update(float dt) {};
	void HandleKeyboard(map<int, bool> keyCode) {};
	State GetName();
};
