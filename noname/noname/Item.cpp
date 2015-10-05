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

Item::Item(combineStats stats, std::string name, std::string description, unsigned int item_num)
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
	case SALVE: { target->addHP( (int)(target->getmHP() * 0.15));	break;	}
	case POTENT_SALVE: { target->addHP( (int)(target->getmHP() * 0.40)); break;	}
	case RECOVERY: { target->addHP( (int)(target->getmHP())); break; }
	case TONIC: { target->addMP( (int)(target->getmMP() * 0.10)); break; }
	case POTENT_TONIC: { target->addMP( (int)(target->getmMP() * 0.35)); break;	}
	case RENEWAL: { target->addMP( (int)(target->getmMP())); break; }
	case ANTIDOTE:	{ target->setStatus(POISON); break;	}
	case EYE_DROPS: { target->setStatus(BLIND); break;	}
	case HOURGLASS: { target->setStatus(SLOW); break; }
	case OINTMENT:	{ target->setStatus(STONE); break; }
	case BALM: { target->setStatus(BURN); break; }
	case BLANKET: {target->setStatus(FROZEN); break; }
	case LOTION: {target->setStatus(PARALYZED); break; }
	case WHETSTONE: {target->setStatus(WEAKENED); break;}
	case PATCH: {target->setStatus(VULNERABLE); break;}
	case PILL: {target->setStatus(BEFUDDLED); break; }
	case SMOKE_BOMB: {break;}
	case REVIVE: 
		{
			target->addHP( int(target->getmHP() * 0.25)); 
			target->addMP( int(target->getmMP() * 0.25));
			target->clearStatus();
		}
	}
}