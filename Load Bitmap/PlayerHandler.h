#pragma once
class Player;
class PlayerState;

class PlayerHandler 
{
	Player* _player;
	PlayerState* _state;
public:
	Player* GetPlayer();
	PlayerState * GetState();
	void SetPlayer(Player * player);
	void SetState(PlayerState * state);
};