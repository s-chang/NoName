#pragma once

#include "Entity.h"
#include "Job_Class.h"

#define MAX_NORMAL_SKILLS 8



class Player: public Entity
{
private:

	Job_Class job_class;

	int player_num;				
	int stat_points;
	int normal_skill_points;
	//int elemental_skill_points;
	int first_class_skill_points;
	int second_class_skill_points;

	int normal_skill_distribution[MAX_NORMAL_SKILLS];

public:
	Player();
	~Player();

	void setPlayerNum(int num);
	int getPlayerNum();

};