#pragma once

#include <string>
#include "Entity.h"
#include <vector>

class Skills
{
private:
	std::string name;
	std::string description;
	
public:
	Skills();
	~Skills();

	void setSkill(std::string name, std::string description);
	std::string getName();
	std::string getDesc();

	virtual void use(std::vector<Entity *> targets);

};