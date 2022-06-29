#pragma once
#include <string>
class Enemy
{
	friend class Combat;
	std::string name;
	int HP;
	int DMG;
	int ARMOUR;
	int gainXP;
	int bleedPROC;
	int burnPROC;
	int critPROC;
	int necroburnPROC;
	int bleedSTACKS;
	int burnSTACKS;
	int necroburnSTACKS;
	bool stunned;
	bool dead;
	bool isboss;

public:

	Enemy(int,int);
	int attack(bool); 
	int burn();
	int bleed();
	int necro();
};

