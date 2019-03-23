#pragma once
#include "PlayerState.h"
#include "Player.h"

class JumpState : public PlayerState
{
public:
	JumpState(PlayerHandler* _playerhandler);
	void Update(float dt) {};
	void HandleKeyboard(map<int, bool> keyCode) {};
	State GetName();
};