#include "WarriorSkills.h"

class WarriorEndure: public WarriorSkills
{
private:

public:
	WarriorEndure(){}
	~WarriorEndure(){}

	virtual void use(Entity *targets){
		//self buff, ignore knockbacks for a duration
	
	}


};