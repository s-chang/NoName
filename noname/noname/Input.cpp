#include "Input.h"

Engine::InputController::InputController()
{
	
	//default player number
	controlNum = 0;

	for(int i = 0; i < NUM_BUTTONS; i++)
		buttonState[i] = false;

}

Engine::InputController::InputController(int playerNum)
{
	

	//set player number
	controlNum = playerNum - 1;

	
	for(int i = 0; i < NUM_BUTTONS; i++)
		buttonState[i] = false;
}

Engine::InputController::~InputController()
{}

XINPUT_STATE Engine::InputController::getState()
{

	//clear the state
	ZeroMemory(&controlState, sizeof(XINPUT_STATE));

	//get the state
	XInputGetState(controlNum, &controlState);

	return controlState;

}

bool Engine::InputController::isConnected()
{
	//clear the state
	ZeroMemory(&controlState, sizeof(XINPUT_STATE));

	//Get state
	DWORD result = XInputGetState(controlNum, &controlState);

	if(result == ERROR_SUCCESS)
		return true;
	else
		return false;
}

bool Engine::InputController::getButtonState(int button)
{
	return buttonState[button];
}

void Engine::InputController::changeButtonState(int button)
{
	buttonState[button] ? buttonState[button] = false : buttonState[button] = true;
}

Engine::InputKeyboard::InputKeyboard()
{
	m_Input_Obj = 0;
	mouse = 0;
	keyboard = 0;
	ZeroMemory( buffer, sizeof(buffer));
	ZeroMemory( key_down, sizeof(key_down));
	ZeroMemory(&mouseState, sizeof( DIMOUSESTATE2 ));
}

Engine::InputKeyboard* Engine::InputKeyboard::instance()
{
	static InputKeyboard input;
	return &input;
}

void Engine::InputKeyboard::init(HINSTANCE &hInst, HWND &hWnd)
{


	DirectInput8Create( hInst,
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&m_Input_Obj,
		NULL);

	m_Input_Obj->CreateDevice( GUID_SysKeyboard,
		&keyboard,
		NULL);

	m_Input_Obj->CreateDevice( GUID_SysMouse,
		&mouse,
		NULL);

	keyboard->SetCooperativeLevel( hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE );
	mouse->SetCooperativeLevel( hWnd, DISCL_FOREGROUND | DISCL_EXCLUSIVE );
	keyboard->SetDataFormat(&c_dfDIKeyboard);
	mouse->SetDataFormat(&c_dfDIMouse2);

	
}

void Engine::InputKeyboard::update()
{
	HRESULT hr;

	hr = mouse->Acquire();

	//check for failure to acquire mouse
	if( FAILED(hr) )
	{
		ZeroMemory(&mouseState, sizeof( DIMOUSESTATE2 ) );  //if mouse fails, clear the memory out
		hr = mouse->Acquire();								//and re-acquire
	}else													//else get the state of the mouse
		hr = mouse->GetDeviceState( sizeof( DIMOUSESTATE2 ), &mouseState); 
	
	hr = keyboard->Acquire();

	if( FAILED(hr) )							//if keyboard fails to acquire
	{
		ZeroMemory(buffer, sizeof(buffer) );	//clear keyboard buffer memory
		hr = keyboard->Acquire();				//and re-acquire
	}else										//else get the state of the keyboard
		hr = keyboard->GetDeviceState( sizeof(buffer),  (LPVOID)&buffer ); 

}


bool Engine::InputKeyboard::push_button(unsigned char keycode)
{
	
	return ( buffer[keycode] & 0x80 )  != 0;

}

bool Engine::InputKeyboard::check_button_down(unsigned char keycode)
{
	return key_down[keycode];
}

void Engine::InputKeyboard::set_button(unsigned char keycode, bool change)
{
	key_down[keycode] = change;
}

long Engine::InputKeyboard::get_mouseX()		
{
	/***return change in X */
	return mouseState.lX;  
}

long Engine::InputKeyboard::get_mouseY()
{
	/**return change in Y */
	return mouseState.lY;
}

long Engine::InputKeyboard::get_mouseZ()
{
	return mouseState.lZ;
}


bool Engine::InputKeyboard::check_mouse_button(int mouse_button)
{
	return (mouseState.rgbButtons[mouse_button] & 0x80) != 0;

}

void Engine::InputKeyboard::shutdown()
{
	mouse->Unacquire();
	if(mouse)
	{
		mouse->Release();
		mouse = 0;
	}
	
	
	keyboard->Unacquire();
	if(keyboard)
	{
		keyboard->Release();
		keyboard = 0;
	}
	if(m_Input_Obj != 0)
	{
		m_Input_Obj->Release();
		m_Input_Obj = 0;
	}
}

Engine::InputKeyboard::~InputKeyboard()
{

}