#include "ClimbState.h"

ClimbState::ClimbState(PlayerHandler * _playerhandler)
{
	_playerHandler = _playerhandler ;
}

State ClimbState::GetName()
{
	return CLIMBING;
}
