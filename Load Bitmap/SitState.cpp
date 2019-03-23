#include "SitState.h"

SitState::SitState(PlayerHandler * _playerhandler)
{
	_playerHandler = _playerhandler ;
}

State SitState::GetName()
{
	return SITTING;
}
