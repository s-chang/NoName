#pragma once
#include <string>
#include "Stats.h"
#include "Entity.h"

enum USEABLES
{
	SALVE,
	POTENT_SALVE,
	RECOVERY,
	TONIC,
	POTENT_TONIC,
	RENEWAL,
	ANTIDOTE,
	EYE_DROPS,
	HOURGLASS,
	OINTMENT,
	BALM,
	BLANKET,
	SMOKE_BOMB,
	REVIVE

};

class Item
{
private:
	Stats stats;
	std::string name;
	std::string description;
	unsigned short item_num;

public:
	Item();
	~Item();

	Item(Stats stats, std::string name, std::string description, unsigned short item_num);
	
	virtual void use(Entity * target);

};