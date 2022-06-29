#include "Enemy.h"
#include <iostream>
#include <fstream>
#include <random>


Enemy::Enemy(int lvl, int type)
{
	this->HP = HP;
	this->DMG = DMG;
	this->ARMOUR = ARMOUR;
	this->gainXP = gainXP;
	this->bleedPROC = bleedPROC;
	this->burnPROC = burnPROC;
	this->critPROC = critPROC;
	this->necroburnPROC = necroburnPROC;
	this->bleedSTACKS = 0;
	this->burnSTACKS = 0;
	this->necroburnSTACKS = 0;
	this->stunned = false;
	this->dead = false;
	this->isboss = false;


	int id = rand() % 3 + 1;

	if (type == 2)
		id = rand() % 2 + 4;
	else if (type == 3)
	{
		id = 6;
		isboss = true;
	}

	id += 6 * (lvl - 1);

	std::ifstream enemydata;

	switch (id)
	{
	case 1:
		enemydata.open("Data/Enemy/Enemy11.txt");
		break;

	case 2:
		enemydata.open("Data/Enemy/Enemy12.txt");
		break;

	case 3:
		enemydata.open("Data/Enemy/Enemy13.txt");
		break;

	case 4:
		enemydata.open("Data/Enemy/EliteEnemy11.txt");
		break;

	case 5:
		enemydata.open("Data/Enemy/EliteEnemy12.txt");
		break;

	case 6:
		enemydata.open("Data/Enemy/Boss1.txt");
		break;

	case 7:
		enemydata.open("Data/Enemy/Enemy21.txt");
		break;

	case 8:
		enemydata.open("Data/Enemy/Enemy22.txt");
		break;

	case 9:
		enemydata.open("Data/Enemy/Enemy23.txt");
		break;

	case 10:
		enemydata.open("Data/Enemy/EliteEnemy21.txt");
		break;

	case 11:
		enemydata.open("Data/Enemy/EliteEnemy22.txt");
		break;

	case 12:
		enemydata.open("Data/Enemy/Boss2.txt");
		break;

	case 13:
		enemydata.open("Data/Enemy/Enemy31.txt");
		break;

	case 14:
		enemydata.open("Data/Enemy/Enemy32.txt");
		break;

	case 15:
		enemydata.open("Data/Enemy/Enemy33.txt");
		break;

	case 16:
		enemydata.open("Data/Enemy/EliteEnemy31.txt");
		break;

	case 17:
		enemydata.open("Data/Enemy/EliteEnemy32.txt");
		break;

	case 18:
		enemydata.open("Data/Enemy/Boss3.txt");
		break;

	case 19:
		enemydata.open("Data/Enemy/Enemy41.txt");
		break;

	case 20:
		enemydata.open("Data/Enemy/Enemy42.txt");
		break;

	case 21:
		enemydata.open("Data/Enemy/Enemy43.txt");
		break;

	case 22:
		enemydata.open("Data/Enemy/EliteEnemy41.txt");
		break;

	case 23:
		enemydata.open("Data/Enemy/EliteEnemy42.txt");
		break;

	case 24:
		enemydata.open("Data/Enemy/Boss4.txt");
		break;

	case 25:
		enemydata.open("Data/Enemy/Enemy51.txt");
		break;

	case 26:
		enemydata.open("Data/Enemy/Enemy52.txt");
		break;

	case 27:
		enemydata.open("Data/Enemy/Enemy53.txt");
		break;

	case 28:
		enemydata.open("Data/Enemy/EliteEnemy51.txt");
		break;

	case 29:
		enemydata.open("Data/Enemy/EliteEnemy52.txt");
		break;

	case 30:
		enemydata.open("Data/Enemy/Boss5.txt");
		break;
	}

	getline(enemydata,this->name);
	enemydata >> this->HP;
	enemydata >> this->DMG;
	enemydata >> this->ARMOUR;
	enemydata >> this->gainXP;
	enemydata >> this->bleedPROC;
	enemydata >> this->burnPROC;
	enemydata >> this->critPROC;
	enemydata >> this->necroburnPROC;

	/*
	
	lvl 1 ids: 1,2,3; elites: 4,5; boss: 6
	lvl 2: 7,8,9; 10,11; 12...

	=> ( rand(0-2)+1 / eliterand(0-1)+4 / boss(6) ) + 6 * (lvl-1)

	*/
}

int Enemy::attack(bool cancrit)
{
	int damage;
	damage = this->DMG;
	int modifier = rand() % 40 - 20;

	int crit = rand() % 100 + 1;
	int realcrit = this->critPROC;
	if (realcrit >= crit && cancrit == true)
		damage *= 3;

	return (damage + damage * modifier / 100);
}

int Enemy::burn()
{
	int damage;
	damage = this->DMG;
	int modifier = rand() % 40 - 20;

	int crit = rand() % 100 + 1;
	int realcrit = this->critPROC;
	if (realcrit >= crit)
		damage *= 1.5;

	return (damage + damage * modifier / 100);
}

int Enemy::bleed()
{
	int damage;
	damage = this->DMG;
	int modifier = rand() % 40 - 20;

	return (damage + damage * modifier / 100);
}

int Enemy::necro()
{
	int damage;
	damage = this->DMG;

	return (damage);
}