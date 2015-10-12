#pragma once
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

#include "DX.h"
#include "Graphics.h"
#include "Text.h"
#include "Layer.h"

class View
{
private:
	View();

public:
	static View* instance();
	~View();

	void init(HINSTANCE &hInst, HWND &hWnd);	
	void render(std::vector<Layer *> layers);

	void shutdown();
};