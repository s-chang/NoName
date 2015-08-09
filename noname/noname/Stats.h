#pragma once

struct Stats
{
	unsigned int level;
	unsigned int statPoints;
	unsigned int cHP;
	unsigned int cMP;
	unsigned int mHP;
	unsigned int mMP;

	unsigned short Str;
	unsigned short aStr;
	unsigned short Vit;
	unsigned short aVit;
	unsigned short Int;
	unsigned short aInt;
	unsigned short Mnd;
	unsigned short aMnd;
	unsigned short Dex;
	unsigned short aDex;
	unsigned short Agi;
	unsigned short aAgi;

	unsigned int cXP;
	unsigned int lXP;

	void zero(){ level = statPoints = cHP = cMP = mHP = mMP = Str = aStr = Vit = aVit = Int = aInt 
	 = Mnd = aMnd = Dex = aDex = Agi = aAgi = cXP = lXP = 0;}

	void setAll(Stats stats)
	{
		level = 1;
		statPoints = 0;
		cHP = stats.cHP;
		cMP = stats.cMP;
		mHP = stats.mHP;
		mMP = stats.mMP;
		Str = stats.Str;
		aStr = stats.aStr;
		Vit = stats.Vit;
		aVit = stats.aVit;
		Int = stats.Int;
		aInt = stats.aInt;
		Mnd = stats.Mnd;
		aMnd = stats.aMnd;
		Dex = stats.Dex;
		aDex = stats.aDex;
		Agi = stats.Agi;
		aAgi = stats.aAgi;
		cXP = stats.cXP;
		lXP = stats.lXP;
	}
};