#include "StandState.h"

StandState::StandState(PlayerHandler * _playerhandler)
{
	_playerHandler = _playerhandler;
}

State StandState::GetName()
{
	return STANDING;
}
