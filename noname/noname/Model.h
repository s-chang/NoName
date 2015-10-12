#pragma once

#include <queue>
#include "Layer.h"
#include "Sound.h"
#include "Timer.h"

#define MAX_PLAYERS 4

class Model
{
private:
	int player_amount[MAX_PLAYERS];

	Model();
public:
	
	static Model * instance();

	~Model();

	void init();
	void update(std::queue<int> *playerInputQ);
	void shutdown();

};