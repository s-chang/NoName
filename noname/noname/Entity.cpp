#include "Entity.h"

Entity::Entity()
{
	alive = true;
}

Entity::Entity()
{}

Entity::Entity(std::string name, Drawable info, Stats stats)
{
	this->name = name;
	this->info.init(info.getTranslate(), info.getScale(), info.getRotate(), info.getColor, info.getRect(), info.getIsSpriteSheet(), info.getDraw());
	this->stats.setAll(stats);
}

unsigned int Entity::getcHP()
{
	return stats.cHP;
}

unsigned int Entity::getmHP()
{
	return stats.mHP;
}

void Entity::addHP(int HP)
{
	stats.cHP += HP;
	if(stats.cHP > stats.mHP)
		stats.cHP = stats.mHP;
	if(stats.cHP < 0)
	{
		stats.cHP = 0;
		alive = false;
	}

}

unsigned int Entity::getcMP()
{
	return stats.cMP;
}

unsigned int Entity::getmMP()
{
	return stats.mMP;
}

void Entity::addMP(int MP)
{
	stats.cMP += MP;
	if(stats.cMP > stats.mMP)
		stats.cMP = stats.mMP;
}

void Entity::addXP(int XP)
{
	stats.cXP += XP;
	if(stats.cXP >= stats.lXP)
	{
		++stats.level;
		stats.cXP = 0;
		stats.lXP = (int)(stats.lXP * 1.2);
	}
}