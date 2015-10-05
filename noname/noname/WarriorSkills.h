#pragma once

#include "Skills.h"

class WarriorSkills : public Skills
{
private:

public:
	WarriorSkills(){};
	~WarriorSkills(){};
	virtual void use(std::vector<Entity *>targets){};

};