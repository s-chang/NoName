#include "Item.h"

Item::Item()
{
	stats.zero();
	name = "No Name";
	description = "Nothing";
	item_num = 0;
}

Item::~Item()
{}

Item::Item(Stats stats, std::string name, std::string description, unsigned short item_num)
{
	this->stats.setAll(stats);
	this->name = name;
	this->description = description;
	this->item_num = item_num;
}

void Item::use(Entity* target)
{
	switch(item_num)
	{
	case SALVE:
		{
			target->addHP( (int)(target->getmHP() * 0.15));	break;
		}
	case POTENT_SALVE:
		{
			target->addHP( (int)(target->getmHP() * 0.40)); break;
		}
	case RECOVERY:
		{
			target->addHP( (int)(target->getmHP())); break;
		}
	case TONIC:
		{
			target->addMP( (int)(target->getmMP() * 0.10)); break;
		}
	case POTENT_TONIC:
		{
			target->addMP( (int)(target->getmMP() * 0.35)); break;
		}
	case RENEWAL:
		{
			target->addMP( (int)(target->getmMP())); break;
		}
	case ANTIDOTE:
	case EYE_DROPS:
	case HOURGLASS:
	case OINTMENT:
	case BALM:
	case BLANKET:
	case SMOKE_BOMB:
	case REVIVE:
	}
}