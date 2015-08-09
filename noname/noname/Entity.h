#pragma once

#include "Drawable.h"
#include "Stats.h"
#include "Equipment.h"


class Entity 
{
private:
	std::string name;
	Drawable info;
	Stats stats;
	bool alive;

public:
	Entity();
	~Entity();

	Entity(std::string name, Drawable info, Stats stats);

	unsigned int getcHP();
	unsigned int getmHP();
	void addHP(int HP);

	unsigned int getcMP();
	unsigned int getmMP();
	void addMP(int MP);

	void addXP(int XP);


};