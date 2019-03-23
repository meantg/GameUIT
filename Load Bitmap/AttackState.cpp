#include "AttackState.h"

AttackState::AttackState(PlayerHandler* _playerhandler)
{
	_playerHandler = _playerhandler;
}

State AttackState::GetName()
{
	return ATTACKING;
}
