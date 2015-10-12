#pragma once

#include "Input.h"
#include "Player.h"



#define MAX_PLAYERS 4


class Controller
{
private:
	std::vector<Player* > players;
	std::vector<Engine::InputController*> controllers;
	Controller();
public:
	static Controller *instance();

	~Controller();

	void init(HINSTANCE &hInst, HWND &hWnd);
	
	void update();

	std::queue<int> * getPlayerInputQ(int player_num);
	void clearPlayerQ(int player_num);
	void setPlayerController(int player_num, bool arg);

	void shutdown();
};