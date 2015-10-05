#include "Skills.h"

Skills::Skills()
{}

Skills::~Skills()
{}

void Skills::use(std::vector<Entity *> targets)
{}

void Skills::setSkill(std::string name, std::string description)
{
	this->name = name;
	this->description = description;

}

std::string Skills::getName()
{
	return name;
}

std::string Skills::getDesc()
{
	return description;
}