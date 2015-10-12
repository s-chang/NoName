#include "Player.h"
#include "Input.h"

Player::Player()
{}

Player::~Player()
{}

void Player::init(Engine::InputController *control, int player_num)
{
	this->control = control;
	controller = false;
	this->player_num = player_num;
	if(!inputQ.empty())
		inputQ.pop();
	for(int i = 0; i < MAX_BUTTONS; i++)
	{
		input_buttons[i] = false;
	}
}

void Player::update()
{
	//get input from controller and fill the queue

	//check if the controller is connected
	if(controller)
	{
		if(control->isConnected())
		{
			populateQcheck(A, XINPUT_GAMEPAD_A);
			populateQcheck(B, XINPUT_GAMEPAD_B);
			populateQcheck(X, XINPUT_GAMEPAD_X);
			populateQcheck(Y, XINPUT_GAMEPAD_Y);
			populateQcheck(SELECT, XINPUT_GAMEPAD_BACK);
			populateQcheck(START, XINPUT_GAMEPAD_START);
			//populateQcheck(R1, XINPUT_GAMEPAD_RIGHT_SHOULDER);
			//populateQcheck(R2, XINPUT_GAMEPAD_A);
			//populateQcheck(L1, XINPUT_GAMEPAD_A);
			//populateQcheck(L2, XINPUT_GAMEPAD_A);
			populateQ(UP, XINPUT_GAMEPAD_DPAD_UP);
			populateQ(DOWN, XINPUT_GAMEPAD_DPAD_DOWN);
			populateQ(LEFT, XINPUT_GAMEPAD_DPAD_LEFT);
			populateQ(RIGHT, XINPUT_GAMEPAD_DPAD_RIGHT);

		}

	}else
	{
		populateQcheckkeyboard(A, DIK_J);
		populateQcheckkeyboard(B, DIK_K);
		populateQcheckkeyboard(X, DIK_U);
		populateQcheckkeyboard(Y, DIK_I);
		populateQcheckkeyboard(SELECT, DIK_R);
		populateQcheckkeyboard(START, DIK_T);
		populateQcheckkeyboard(R1, DIK_Y);
		populateQcheckkeyboard(R2, DIK_O);
		populateQcheckkeyboard(L1, DIK_Q);
		populateQcheckkeyboard(L2, DIK_E);
		populateQkeyboard(UP, DIK_W);
		populateQkeyboard(DOWN, DIK_S);
		populateQkeyboard(LEFT, DIK_A);
		populateQkeyboard(RIGHT, DIK_D);

	}


}

void Player::clearQ()
{
	if(!inputQ.empty())
		inputQ.pop();
}

std::queue<int> * Player::getQ()
{
	return &inputQ;
}

int Player::getPlayer()
{
	return player_num;
}

void Player::populateQcheck(int button, WORD controller_code)
{
	if(control->getState().Gamepad.wButtons & controller_code)
	{
		if(!input_buttons[button])
		{
			input_buttons[button] = true;
			inputQ.push(button);
		}
	}else
		input_buttons[A] = false;


}

void Player::populateQ(int button, WORD controller_code)
{
	if(control->getState().Gamepad.wButtons & controller_code)
		inputQ.push(button);
}

void Player::populateQcheckkeyboard(int button, unsigned char keycode)
{
	if(Engine::InputKeyboard::instance()->push_button(keycode))
	{
		if(!Engine::InputKeyboard::instance()->check_button_down(keycode))
		{
			Engine::InputKeyboard::instance()->set_button(keycode, true);
			inputQ.push(button);
		}
	}else
		Engine::InputKeyboard::instance()->set_button(keycode, false);
}

void Player::populateQkeyboard(int button, unsigned char keycode)
{
	if(Engine::InputKeyboard::instance()->push_button(keycode))
		inputQ.push(button);
}

void Player::shutdown()
{
	control = nullptr;
}

void Player::setController(bool arg)
{
	controller = arg;
}