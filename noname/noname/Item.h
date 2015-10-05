#pragma once
#include <string>
#include "Stats.h"
#include "Entity.h"
#include "Globals.h"

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
	LOTION,
	WHETSTONE,
	PATCH,
	PILL,
	SMOKE_BOMB,
	REVIVE

};

class Item
{
private:
	combineStats stats;
	std::string name;
	std::string description;
	unsigned int item_num;

public:
	Item();
	~Item();

	Item(combineStats stats, std::string name, std::string description, unsigned int item_num);
	
	virtual void use(Entity * target);

};