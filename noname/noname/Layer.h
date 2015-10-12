#pragma once


#include <vector>

#include "Entity.h"


class Layer
{
private:
	
	std::vector<Entity *> actors;
	

public:
	Layer();
	~Layer();

	virtual void init();
	virtual void update();
	virtual void shutdown();



};