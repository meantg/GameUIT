#include "JumpState.h"

JumpState::JumpState(PlayerHandler * _playerhandler)
{
	_playerHandler = _playerhandler;
}

State JumpState::GetName()
{
	return JUMPING;
}
