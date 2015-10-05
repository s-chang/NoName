#pragma once

#include "Entity.h"
#include "Job_Class.h"

#define MAX_NORMAL_SKILLS 10

class Character: public Entity
{
	Job_Class job_class;

	int character_num;

	
	int normal_skill_points;
	int first_class_skill_points;
	int second_class_skill_points;
	int third_class_skill_points;

	int normal_skill_distribution[MAX_NORMAL_SKILLS];
	
	int first_class_sd[MAX_NORMAL_SKILLS];
	int second_class_sd[MAX_NORMAL_SKILLS];
	int third_class_sd[MAX_NORMAL_SKILLS];

public:

	Character();
	~Character();

	void setCharacterNum(int num);
	int getCharNum();

};