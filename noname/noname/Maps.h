#pragma once

#include <vector>
#include "Layer.h"

#define MAX_LAYERS 7

enum{
	terrain,
	foliage,
	collideable,
	interactable,
	trigger,
	enemy,
	player

};


class Maps
{
private:
	std::vector<Layer *> layers;
public:
	Maps();
	~Maps();

	virtual void init();
	virtual void update();
	virtual void shutdown();

};