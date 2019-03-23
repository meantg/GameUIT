#pragma once
#include "PlayerState.h"
#include "Player.h"

class RunState : public PlayerState
{
	public:
		RunState(PlayerHandler * _playerhandler);
		void Update(float dt) {};
		void HandleKeyboard(map<int, bool> keyCode) {};
		State GetName();
};