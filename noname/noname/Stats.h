#pragma once


enum{ STR, VIT, INTEL, MND, DEX, AGI, MAXSTATS

};


struct CoreStats
{
	 int str;
	 int vit;
	 int intel;
	 int mnd;
	 int dex;
	 int agi;

	void zero(){str = vit = intel = mnd = dex = agi = 0;}
	void setAll(CoreStats stats)
	{
		str = stats.str;
		vit = stats.vit;
		intel = stats.intel;
		mnd = stats.mnd;
		dex = stats.dex;
		agi = stats.agi;
	}

	void addOn(CoreStats stats)
	{
		str += stats.str;
		vit += stats.vit;
		intel += stats.intel;
		mnd += stats.mnd;
		dex += stats.dex;
		agi += stats.agi;
	}
};

struct MainStats
{
	 int attack;  //str/dex for str type class -> dex/str for dex type class
	 int defense; //vit/agi
	 int mAttack; //int/mnd for int type -> mnd/int for mnd type
	 int mDef;  //mnd/int for int type -> int/mnd for mnd type
	 int acc;   //dex/str for str type class -> str/dex for dex type class
	 int eva;   //agi/vit 

	void zero(){attack = defense = mAttack = mDef = acc = eva = 0;}

	void setAll(MainStats stats)
	{
		attack = stats.attack;
		defense = stats.defense;
		mAttack = stats.mAttack;
		mDef = stats.mDef;
		acc = stats.acc;
		eva = stats.eva;
	}

	void addOn(MainStats stats)
	{
		attack += stats.attack;
		defense += stats.defense;
		mAttack += stats.mAttack;
		mDef += stats.mDef;
		acc += stats.acc;
		eva += stats.eva;
	}
};

struct dualStats
{
	 int current;
	 int maximum;
	 int additional;
	 int total;

	void zero(){ current = maximum = additional = total = 0 ;}
	void setALL(dualStats stats)
	{
		current = stats.current;
		maximum = stats.maximum;
		additional = stats.additional;
		total = stats.total;
	}

	void addCurrent( int num){current += num;}
	void addMax( int num){maximum += num;}
	void addAdditional( int num){additional += num;}

	void addOn(dualStats stats)
	{
		current += stats.current;
		maximum += stats.maximum;
		additional += stats.additional;
		total += stats.total;
	}

	void calcTotal()
	{
		total = maximum + additional;
	}
};

struct combineStats
{

	//HP values
	dualStats HP;

	//MP values
	dualStats MP;

	//XP values
	dualStats XP;

	//Base starting stats, should be constant
	CoreStats baseStats;

	//Stat gained from stat point distribution
	CoreStats statDisStats;

	//Stats gained from equipment
	CoreStats equipStats;	

	//Total stats
	CoreStats totalStats;

	//applied stats from totalstats
	MainStats statOutput;

	//stats from equipment
	MainStats equipOutput;

	//augmented stats from active/passive skills
	MainStats augOutput;

	//total output
	MainStats totalOutputStats;

	void zero(){ HP.zero(); MP.zero(); XP.zero();
				 baseStats.zero(); statDisStats.zero(); equipStats.zero(); 	totalStats.zero();
				 statOutput.zero(); augOutput.zero(); totalOutputStats.zero(); equipOutput.zero();

	}
	
	void setAll(combineStats stats)
	{
		HP.setALL(stats.HP);
		MP.setALL(stats.MP);
		XP.setALL(stats.XP);
		baseStats.setAll(stats.baseStats);
		statDisStats.setAll(stats.statDisStats);
		equipStats.setAll(stats.equipStats);		
		totalStats.setAll(stats.totalStats);
		statOutput.setAll(stats.statOutput);
		augOutput.setAll(stats.augOutput);
		totalOutputStats.setAll(stats.totalOutputStats);
		equipOutput.setAll(stats.equipOutput);
	}

	void setEquipOutput(MainStats stats){equipOutput.setAll(stats);}
	void setAugOutput(MainStats stats){	augOutput.setAll(stats);}
	void setEquipStats(CoreStats stats){equipStats.setAll(stats);}
	void setDisStats(CoreStats stats){statDisStats.setAll(stats);}

	void calcTotalStats()
	{
		//zero out total stats
		totalStats.zero();
		totalStats.addOn(baseStats);
		totalStats.addOn(statDisStats);
		totalStats.addOn(equipStats);
	
	}

	void calcStatOutputSTRMND()
	{
		MainStats temp;
		temp.attack = totalStats.str*2 + totalStats.dex;
		temp.defense = totalStats.vit*2 + totalStats.agi;
		temp.mAttack = totalStats.mnd*2 + totalStats.intel;
		temp.mDef = totalStats.intel*2 + totalStats.mnd;
		temp.acc = totalStats.dex*2 + totalStats.str;
		temp.eva = totalStats.agi*2 + totalStats.vit;
		statOutput.setAll(temp);
	}

	void calcStatOutputDEXMND()
	{
		MainStats temp;
		temp.attack = totalStats.dex*2 + totalStats.str;
		temp.defense = totalStats.vit*2 + totalStats.agi;
		temp.mAttack = totalStats.mnd*2 + totalStats.intel;
		temp.mDef = totalStats.intel*2 + totalStats.mnd;
		temp.acc = totalStats.str*2 + totalStats.dex;
		temp.eva = totalStats.agi*2 + totalStats.vit;
		statOutput.setAll(temp);
	}

	void calcStatOutputSTRINT()
	{
		MainStats temp;
		temp.attack = totalStats.str*2 + totalStats.dex;
		temp.defense = totalStats.vit*2 + totalStats.agi;
		temp.mAttack = totalStats.intel*2 + totalStats.mnd;
		temp.mDef = totalStats.mnd*2 + totalStats.intel;
		temp.acc = totalStats.dex*2 + totalStats.str;
		temp.eva = totalStats.agi*2 + totalStats.vit;
		statOutput.setAll(temp);
	}

	void calcStatOutputDEXINT()
	{
		MainStats temp;
		temp.attack = totalStats.dex*2 + totalStats.str;
		temp.defense = totalStats.vit*2 + totalStats.agi;
		temp.mAttack = totalStats.intel*2 + totalStats.mnd;
		temp.mDef = totalStats.mnd*2 + totalStats.intel;
		temp.acc = totalStats.str*2 + totalStats.dex;
		temp.eva = totalStats.agi*2 + totalStats.vit;
		statOutput.setAll(temp);
	}	

	void calcTotalOutputStats()
	{
		//zero out total stats
		totalOutputStats.zero();
		totalOutputStats.addOn(statOutput);
		totalOutputStats.addOn(augOutput);
		totalOutputStats.addOn(equipOutput);
	}
};

struct ItemStats
{
	int HP;
	int MP;

	CoreStats coreStats;

	MainStats mainStats;

	void zero() {HP = MP = 0; coreStats.zero(); mainStats.zero();}

	void setAll(ItemStats stats)
	{
		HP = stats.HP;
		MP = stats.MP;
		coreStats.setAll(stats.coreStats);
		mainStats.setAll(stats.mainStats);
	}

};

struct Stats
{
	 int level;
	 int statPoints;
	 
	combineStats stats;	

	void zero(){ level = statPoints = 0; stats.zero(); 
				
	}

	void setStart()
	{
		level = 1;			
		stats.XP.maximum = 100;
	}

	
	void levelup(){ ++level; statPoints += 3;}

	//NOTE:  Must Recalculate Totals in Character/Entity/etc...
	void incStr(){ if(statPoints > 0) { ++stats.statDisStats.str;  --statPoints;}}
	void incVit(){ if(statPoints > 0) { ++stats.statDisStats.vit;  --statPoints;}}
	void incInt(){ if(statPoints > 0) { ++stats.statDisStats.intel; --statPoints;}}
	void incMnd(){ if(statPoints > 0) { ++stats.statDisStats.mnd; --statPoints;}}
	void incAgi(){ if(statPoints > 0) { ++stats.statDisStats.agi; --statPoints;}}
	void incDex(){ if(statPoints > 0) { ++stats.statDisStats.dex; --statPoints;}}

	void checkXP()
	{
		if (stats.XP.current >= stats.XP.maximum)
		{
			levelup();
			stats.XP.current -= stats.XP.maximum;
			stats.XP.maximum += level * 100;
		}
	
	}
			
};