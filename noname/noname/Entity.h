#pragma once

#include "Drawable.h"
#include "Stats.h"
#include "Equipment.h"



class Entity : public Drawable
{
private:
	std::string name;
	
	Stats stats;
	bool alive;	
	unsigned int status; 

public:
	Entity();
	~Entity();

	Entity(std::string name, Stats stats);

	unsigned int getcHP();
	unsigned int getmHP();
	void addHP(int HP);

	unsigned int getcMP();
	unsigned int getmMP();
	void addMP(int MP);

	void addXP(int XP);

	void setAlive(bool arg);
	bool getAlive();

	void setStatus(unsigned int StatusCode);
	unsigned int getStatusCode();
	void clearStatus();
};