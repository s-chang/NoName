#pragma once

#include "Input.h"
#include <queue>

#define MAX_BUTTONS 14
enum
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	SELECT,
	START,
	X,
	Y,
	B,
	A,
	R1,
	R2,
	L1,
	L2
};


class Player
{
private:
	Engine::InputController * control;


	int player_num;
	std::queue<int> inputQ;

	bool input_buttons[MAX_BUTTONS];

	bool controller;

	//helper function
	void populateQ(int button, WORD controller_code);
	void populateQcheck(int button, WORD controller_code);

	void populateQkeyboard(int button, unsigned char keycode);
	void populateQcheckkeyboard(int button, unsigned char keycode);

public:

	Player();
	~Player();

	void init(Engine::InputController *control, int player_num);
	
	void update();
	void clearQ();
	std::queue<int> * getQ();

	int getPlayer();

	void setController(bool arg);

	void shutdown();


};