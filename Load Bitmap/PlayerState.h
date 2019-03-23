#pragma once
#include "PlayerHandler.h"
#include <map>
#include "Object.h"

class PlayerState
{
protected:
	PlayerHandler * _playerHandler;
public:
	PlayerState() {};
	PlayerState(PlayerHandler * playerhandler) { _playerHandler = playerhandler; };
	virtual ~PlayerState() { if (_playerHandler) delete _playerHandler; }

	virtual State GetName() = 0;
	virtual void HandleKeyboard(std::map<int, bool> keyCode) = 0;
	virtual void Update(float dt) = 0;
};