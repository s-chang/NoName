#pragma once
#include "Stats.h"
#include <string>
#include "Gem.h"
#include "Item.h"

enum EQUIP
{
	HEAD,
	BODY,
	ARMS,
	LEGS,
	FEET,
	ACC1,
	ACC2,
	WEAPON
};


class Equipment : public Item
{
private:
	
	unsigned short whereToEquip;
	Gem * slot1;
	Gem * slot2;

public:
	Equipment();
	~Equipment();

	Equipment(Stats stats, std::string name, std::string description, unsigned short whereToEquip);

};