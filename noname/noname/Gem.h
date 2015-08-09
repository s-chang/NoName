#pragma once
#include "Item.h"


class Gem : public Item
{
private:
	Gem();
	~Gem();
	Gem(Stats stats, std::string name, std::string description);

	virtual void use(Entity * target);
};