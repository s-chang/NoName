#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "Window.h"
#include <time.h>
#include "DX.h"
#include <crtdbg.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//memory leak check
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(unsigned int (time(NULL)));
	
	//handle to the window
	HWND myhWnd = NULL;

	//current instance 
	HINSTANCE myInstance = hInstance;

	//window mode
	bool window = true;

	//create a window for use
	Window myWindow;

	myWindow.init(myhWnd, myInstance, window);

	//TODO: MOVE TO VIEW
	Engine::DX::instance()->init(myhWnd, window);

	//TODO: create game instance

	//Use msg structure to catch window messages
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while(msg.message != WM_QUIT)
	{
		//hide cursor
		ShowCursor(false);

		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}else
		{
			//TODO: update game

			//TODO: render game

			//TODO:  Sleep -> 60 fps
		}
	}

	//TODO:  Shutdown code
	Engine::DX::instance()->shutdown();

	UnregisterClass(WINDOW_TITLE, myInstance);
	return 0;
}