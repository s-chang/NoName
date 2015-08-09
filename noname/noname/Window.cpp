#include "Window.h"

Window::Window()
{
	ZeroMemory(&wndClass, sizeof(wndClass));
}

Window::~Window()
{}

void Window::init(HWND &hWnd, HINSTANCE &hInstance, bool windowed)
{
	//set the window
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.lpfnWndProc = (WNDPROC)WndProc;
	wndClass.lpszClassName = WINDOW_TITLE;
	wndClass.hInstance = hInstance;
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOWFRAME);

	RegisterClassEx(&wndClass);

	hWnd = CreateWindow(
		WINDOW_TITLE, WINDOW_TITLE,
		windowed ? WS_OVERLAPPEDWINDOW | WS_VISIBLE : (WS_POPUP|WS_VISIBLE),
		CW_USEDEFAULT, CW_USEDEFAULT,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		NULL, NULL,
		hInstance,
		NULL);

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	//handle messages
	switch(message)
	{
	case WM_CREATE:
		{
			RAWINPUTDEVICE rid;
			rid.usUsagePage = 6;
			rid.usUsage = 5;
			rid.hwndTarget = hWnd;
			RegisterRawInputDevices(&rid, 1, sizeof(rid));
			break;
		}
	case WM_PAINT:
		{
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		}
	case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}
	case WM_KEYDOWN:
		{
		
			switch(wparam)
			{
			case VK_ESCAPE:
				{
					PostQuitMessage(0);
					break;
				}
			}
		}

	}
	return DefWindowProc(hWnd, message, wparam, lparam);
}