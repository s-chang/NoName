#include "Controller.h"

Controller::Controller()
{}

Controller::~Controller()
{}

Controller *Controller::instance()
{
	static Controller instance;
	return &instance;
}

void Controller::init(HINSTANCE &hInst, HWND &hWnd)
{
	

	for(int i = 0; i < MAX_PLAYERS; i++)
	{
		controllers[i] = new Engine::InputController(i+1);
	}

	for(int i = 0; i < MAX_PLAYERS; i++)
	{
		players[i] = new Player();
		players[i]->init(controllers[i], i+1);
	}

	Engine::InputKeyboard::instance()->init(hInst, hWnd);
}

void Controller::update()
{
	Engine::InputKeyboard::instance()->update();

	for(int i = 0; i < MAX_PLAYERS; i++)
	{
		players[i]->update();
	}
}

std::queue<int> *Controller::getPlayerInputQ(int player_num)
{

	return players[player_num]->getQ();
}

void Controller::clearPlayerQ(int player_num)
{
	players[player_num]->clearQ();
}

void Controller::setPlayerController(int player_num, bool arg)
{
	players[player_num]->setController(arg);
}

void Controller::shutdown()
{
	for(int i = 0; i < MAX_PLAYERS; i++)
	{
		delete players[i];
		players[i] = nullptr;
	}

	Engine::InputKeyboard::instance()->shutdown();
}