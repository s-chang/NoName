/**
	Written by: Smyth Chang
	Description:  Create a Window for use
*/

#pragma once
#include <Windows.h>

//default width/height
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define WINDOW_TITLE L"GAME TEST"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam);

class Window
{
private:
	WNDCLASSEX wndClass;

public:
	Window();
	~Window();

	void init(HWND &hWnd, HINSTANCE &hInstance, bool windowed);

};

