#pragma once

#include "WarriorSkills.h"

class Slash : public WarriorSkills
{
private:
	const int width = 10;
	const int height = 5;

public:
	Slash(){};
	~Slash(){};



	virtual void use(std::vector<Entity *> targets)
	{
		//assumes first target is always the player initiating the skill
		//2nd target is the next player
		//the rest of the targets are enemies within the skill's AoE

		//TODO:  check if targets are within the AoE, then calculate damage

	}

};