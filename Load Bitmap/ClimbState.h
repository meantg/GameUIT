#pragma once
#include "PlayerState.h"
#include "Player.h"

class ClimbState : public PlayerState
{
public:
	ClimbState(PlayerHandler* _playerhandler);
	void Update(float dt) {};
	void HandleKeyboard(map<int, bool> keyCode) {};
	State GetName();
};
