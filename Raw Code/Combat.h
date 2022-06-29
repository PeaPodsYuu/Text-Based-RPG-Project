#pragma once
#include "Player.h"
#include "Enemy.h"
#include <string>
class Combat
{
	Player player;
	int type;

public:

	Combat();
	int gettarget(int, Enemy*[]);
	int initializecombat(int,int);
	int playcombat(Enemy*[], int);
	void getspell(std::string, Enemy*[], int, int, Enemy*, bool);
	std::string getaction(Enemy*);
};

