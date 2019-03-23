#pragma once
#include "PlayerState.h"
#include "Player.h"

class AttackState : public PlayerState
{
private: 
	State _curState;
	bool _reverse;
public:
	AttackState(PlayerHandler * _playerhandler);
	void Update(float dt) {};
	void HandleKeyboard(map<int, bool> keyCode) {};
	State GetName();
};