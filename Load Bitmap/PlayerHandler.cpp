#include "PlayerHandler.h"

Player * PlayerHandler::GetPlayer()
{
	return _player;
}

PlayerState * PlayerHandler::GetState()
{
	return _state;
}

void PlayerHandler::SetPlayer(Player * player)
{
	_player = player;
}

void PlayerHandler::SetState(PlayerState * state)
{
	_state = state;
}
