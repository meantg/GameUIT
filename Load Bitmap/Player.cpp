#include "Player.h"

void Player::Update(DWORD dt)
{

	if (_curState == NINJA_RUN_RIGHT)
	{
		if (x <= SCREEN_WIDTH-20  && x >= 0)
			x += vx * dt*nx;
		if (x < 0 )
			x = 0;
		if (x > SCREEN_WIDTH-20)
			x = SCREEN_WIDTH-20;
	}
	if (_curState == NINJA_JUMP)
	{
			y+=dt*vy;
	}
}

void Player::Render()
{
	int ani = _curState;
	animations[ani]->FlipHorizontal(isReverse);
	animations[ani]->Render(x, y);
}

void Player::SetState(State state)
{
	switch (state)
	{
	case STANDING:
		vx = 0;
		_curState = NINJA_IDLE;
		break;
	case NINJA_RUN_RIGHT:
		vx = NINJA_WALKING_SPEED;
		_curState = 4;
		nx = 1;
		isReverse = false;
		break;
	case NINJA_RUN_LEFT:
		vx = NINJA_WALKING_SPEED;
		_curState = 4;
		nx = -1;
		isReverse = true;
		break;
	case NINJA_JUMP:
		if (y == 100)
			vy = -NINJA_JUMPING_SPEED_Y;
		_curState = NINJA_JUMP;
		break;
	case NINJA_SITTING:
		_curState = NINJA_SITTING;
		break;
	case NINJA_ATK_STANDING:
		_curState = NINJA_ATK_STANDING;
		break;
	default:
		break;
	}

}

void Player::ChangeAnimation(State state)
{
	_curanimation = _animations[_state];
}

void Player::ChangeState(PlayerState * newState)
{
	_playerhandler->SetState(newState);
	_state = newState->GetName();
	ChangeAnimation(_state);
}

void Player::HandleKeyboard(map<int, bool> keyCode)
{
	_playerhandler->GetState()->HandleKeyboard(keyCode);
}

void Player::OnKeyDown(int keyCode)
{
	switch (keyCode)
	{
	case DIK_A:
		/*ChangeState(new AttackState(_playerhandler);*/
		break;
	}
}


