#include "RunState.h"

RunState::RunState(PlayerHandler * _playerhandler)
{
	_playerHandler = _playerhandler ;
}

State RunState::GetName()
{
	return RUNNING;
}
