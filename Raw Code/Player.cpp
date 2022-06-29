#include "Player.h"
#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>

bool Player::dead()
{
	if (this->HP <= 0)
		return true;
	return false;
}

void Player::newsave()
{
	std::ofstream save;
	save.open("Data/PlayerSave.txt");

	save << 14 << std::endl;
	save << 14 << std::endl;
	save << 0 << std::endl;
	save << 0 << std::endl;
	save << 3 << std::endl;
	save << 3 << std::endl;
	save << 1 << std::endl;
	save << 1 << std::endl;
	save << 0 << std::endl;
	save << 0 << std::endl;
	save << 10 << std::endl;
	save << 10 << std::endl;
	save << 0 << std::endl;
	save << 0 << std::endl;
	save << 0 << std::endl;
	save << 0 << std::endl;
	save << 0 << std::endl;
	save << 0 << std::endl;
	save << 1 << std::endl;
	save << 0 << std::endl;

	// Warrior-Mage-Rogue-Paladin-Barbarian-Cleric

	for (int i = 0; i < 6; i++)
		save << 0 << std::endl;

	save.close();
}

void Player::newload()
{
	std::ifstream save;
	save.open("Data/PlayerSave.txt");

	save >> this->maxHP;
	save >> this->HP;
	this->HP = maxHP;
	save >> this->maxMP;
	save >> this->MP;
	this->MP = this->maxMP;
	save >> this->maxDMG;
	save >> this->DMG;
	this->DMG = this->maxDMG;
	save >> this->maxAP;
	save >> this->AP;
	this->AP = this->maxAP;
	save >> this->maxARMOUR;
	save >> this->ARMOUR;
	this->ARMOUR = this->maxARMOUR;
	save >> this->maxSTAM;
	save >> this->STAM;
	this->STAM = this->maxSTAM;
	save >> this->bonusHP;
	save >> this->bonusMP;
	save >> this->bonusDMG;
	save >> this->bonusAP;
	save >> this->bonusARMOUR;
	save >> this->bonusSTAM;
	this->bonusHP = this->bonusMP = this->bonusDMG = this->bonusAP = this->bonusARMOUR = this->bonusSTAM = 0;
	save >> this->LVL;
	save >> this->XP;
	this->stunned = false;
	this->weapon = "None";

	// Warrior-Mage-Rogue-Paladin-Barbarian-Cleric

	for (int i = 0; i < 6; i++)
		save >> this->upgrades[i];

	this->save();
	save.close();
}

void Player::save()
{
	std::ofstream save;
	save.open("Data/PlayerSave.txt");

	save << this->maxHP << std::endl;
	save << this->HP << std::endl;
	save << this->maxMP << std::endl;
	save << this->MP << std::endl;
	save << this->maxDMG << std::endl;
	save << this->DMG << std::endl;
	save << this->maxAP << std::endl;
	save << this->AP << std::endl;
	save << this->maxARMOUR << std::endl;
	save << this->ARMOUR << std::endl;
	save << this->maxSTAM << std::endl;
	save << this->STAM << std::endl;
	save << this->bonusHP << std::endl;
	save << this->bonusMP << std::endl;
	save << this->bonusDMG << std::endl;
	save << this->bonusAP << std::endl;
	save << this->bonusARMOUR << std::endl;
	save << this->bonusSTAM << std::endl;
	save << this->LVL << std::endl;
	save << this->XP << std::endl;

	// Warrior-Mage-Rogue-Paladin-Barbarian-Cleric

	for (int i = 0; i < 6; i++)
		save << this->upgrades[i] << std::endl;

	save.close();
}

void Player::load()
{
	std::ifstream save;
	save.open("Data/PlayerSave.txt");

	save >> this->maxHP;
	save >> this->HP;
	save >> this->maxMP;
	save >> this->MP;
	save >> this->maxDMG;
	save >> this->DMG;
	save >> this->maxAP;
	save >> this->AP;
	save >> this->maxARMOUR;
	save >> this->ARMOUR;
	save >> this->maxSTAM;
	save >> this->STAM;
	save >> this->bonusHP;
	save >> this->bonusMP;
	save >> this->bonusDMG;
	save >> this->bonusAP;
	save >> this->bonusARMOUR;
	save >> this->bonusSTAM;
	save >> this->LVL;
	save >> this->XP;
	this->stunned = false;
	this->weapon = "None";

	// Warrior-Mage-Rogue-Paladin-Barbarian-Cleric

	for (int i = 0; i < 6; i++)
		save >> this->upgrades[i];

	save.close();
}

Player::Player()
{
	this->HP = this->maxHP = 14;
	this->MP = this->maxMP = 0;
	this->STAM = this->maxSTAM = 10;
	this->AP = this->maxAP = 1;
	this->DMG = this->maxDMG = 3;
	this->ARMOUR = this->maxARMOUR = 0;
	this->bonusHP = this->bonusDMG = this->bonusAP = this->bonusARMOUR = this->bonusMP = this->bonusSTAM = 0;
	this->LVL = 1;
	this->XP = 0;
	this->stunned = false;
	this->weapon = "None";

	for (int i = 0; i < 6; i++)
			this->upgrades[i] = 0;

	for (int i = 0; i < 21; i++)
		this->items[i] = 0;


}

void Player::recalculate()
{
	this->HP = this->maxHP = 14;
	this->MP = this->maxMP = 0;
	this->STAM = this->maxSTAM = 10;
	this->AP = this->maxAP = 1;
	this->DMG = this->maxDMG = 3;
	this->ARMOUR = this->maxARMOUR = 0;
	this->bonusHP = this->bonusDMG = this->bonusAP = this->bonusARMOUR = this->bonusMP = this->bonusSTAM = 0;

	if (upgrades[0] > 0)
	{
		if (upgrades[0] < 3)
		{
			this->maxDMG += 4;
			this->maxARMOUR += 5;
		}
		else if (upgrades[0] < 4)
		{
			this->maxDMG += 4;
			this->maxARMOUR += 5;
			this->maxHP += 6;
		}
		else if (upgrades[0] < 6)
		{

			this->maxDMG += 4;
			this->maxARMOUR += 10;
			this->maxHP += 6;
		}
		this->maxAP += (2 * upgrades[0]);
		this->maxDMG += (upgrades[0]);
	}

	//_______________________

	if (upgrades[1] > 0)
	{
		if (upgrades[1] < 2)
		{
			this->maxMP += 7;
		}
		else if (upgrades[1] < 3)
		{
			this->maxMP += 7;
			this->maxDMG += 7;
		}
		else if (upgrades[1] < 4)
		{
			this->maxMP += 13;
			this->maxDMG += 7;
			this->maxHP += 4;
		}
		this->maxAP += (upgrades[1] / 2);
		this->maxARMOUR += (upgrades[1]);
	}

	//_______________________

	if (upgrades[2] > 0)
	{
		if (upgrades[2] < 3)
		{
			this->maxDMG += 1;
			//also 1 bleed/atk
		}
		else if (upgrades[2] < 4)
		{
			this->maxDMG += 1;
			this->maxHP += 4;
			this->maxAP += 1;
		}
		this->maxAP += (upgrades[2]);
		this->maxARMOUR += (upgrades[2] / 2);
	}

	//_______________________
	if (upgrades[3] > 0)
	{
		if (upgrades[3] < 2)
		{
			this->maxMP += 4;
		}
		else if (upgrades[3] < 3)
		{
			this->maxMP += 4;
			this->maxHP += 5;
			this->maxARMOUR += 7;
		}
		else if (upgrades[3] < 4)
		{
			this->maxMP += 4;
			this->maxHP += 7;
			this->maxARMOUR += 9;
			this->maxDMG += 3;
		}
		this->maxAP += (upgrades[3]);
		this->maxARMOUR += (upgrades[3]);
	}

	//_______________________

	if (upgrades[4] > 0)
	{
		if (upgrades[4] < 3)
		{
			this->maxDMG += 4;
			this->maxHP += 8;
		}
		else if (upgrades[4] < 4)
		{
			this->maxHP += 14;
			this->maxARMOUR += 2;
			this->maxDMG += 4;
		}
		this->maxAP += (upgrades[4]);
	}

	//_______________________

	if (upgrades[5] > 0)
	{
		if (upgrades[5] < 2)
		{
			this->maxMP += 7;
		}
		else if (upgrades[5] < 3)
		{
			this->maxMP += 7;
			this->maxARMOUR += 2;
			this->maxDMG += 1;
			this->maxHP += 7;
		}
		else if (upgrades[5] < 4)
		{
			this->maxMP += 11;
			this->maxARMOUR += 2;
			this->maxDMG += 5;
			this->maxHP += 7;
		}
		this->maxDMG += (upgrades[5]);
		this->maxARMOUR += (upgrades[5]);
	}

	this->save();
}

void Player::getupgrade()
{
	system("CLS");

	std::string input = "0";

	// Warrior-Mage-Rogue-Paladin-Barbarian-Cleric
	while (input != "a" && input != "b" && input != "c" && input != "d" && input != "e" && input != "f")

	{
		std::cout << "a) Warrior Upgrades: " << std::endl;
		std::cout << "1) Kick: Deal 70% of your damage to an enemy, but you stun them. Consumes 2AP." << std::endl;
		std::cout << "2) +4 DMG +5 ARMOUR" << std::endl;
		std::cout << "3) +6 HP" << std::endl;
		std::cout << "4) Start your runs with an item." << std::endl;
		std::cout << "5) Sweep: Deal 140% damage to all enemies. Consumes 4AP. +5 ARMOUR" << std::endl;
		std::cout << "Unlock the weapon switch mechanic." << std::endl;
		std::cout << std::endl;

		std::cout << "b) Mage Upgrades: " << std::endl;
		std::cout << "1) Start with 7 base mana. Hail of Thorns: You attack with an extra 1-10DMG. Uses 2 MANA and 1AP." << std::endl;
		std::cout << "2) +7 DMG" << std::endl;
		std::cout << "3) +4 HP +6 mana" << std::endl;
		std::cout << "4) Start your runs with an item." << std::endl;
		std::cout << "5) Meteor Storm: deal 80% damage to target and 40% damage to others; apply 5 turns burn for 5 MANA." << std::endl;
		std::cout << "You magic will be stronger and you'll be able to convert AP to MP." << std::endl;
		std::cout << std::endl;


		std::cout << "c) Rogue Upgrades: " << std::endl;
		std::cout << "1) Multiple Strikes: Attack 1 + No. Rogue Upgrades times for 2AP." << std::endl;
		std::cout << "2) +1 bleed/attack +1 DMG" << std::endl;
		std::cout << "3) +4 HP +1 AP" << std::endl;
		std::cout << "4) Start your runs with an item." << std::endl;
		std::cout << "5) Backstab for 8xDMG, negate armour add 5 stacks of bleed for 3AP." << std::endl;
		std::cout << "Special ability: At level 3: 50% chance to dodge.\n";
		std::cout << "+ 1 AP / upgrade; +1 ARMOUR / 2 upgrades" << std::endl;
		std::cout << std::endl;

		std::cout << "d) Paladin Upgrades: " << std::endl;
		std::cout << "1) Start with 4 base mana. Lay On Hands: heal for 3HP for 1 MANA." << std::endl;
		std::cout << "2) +5 HP +7 ARMOUR" << std::endl;
		std::cout << "3) +3 DMG +2 HP +2 ARMOUR" << std::endl;
		std::cout << "4) Start your runs with an item." << std::endl;
		std::cout << "5) Thunderous Smite: deal 200% damage + 80% Stun Chance for 2 MANA." << std::endl;
		std::cout << "Special ability: At lvl 3: block now blocks all damage.\n";
		std::cout << "+1 AP / upgrade; +1 ARMOUR / upgrade" << std::endl;
		std::cout << std::endl;

		std::cout << "e) Barbarian Upgrades: " << std::endl;
		std::cout << "1) Headbutt: deal 130% damange, 80% chance to stun enemy, otherwise stun yourself for 1AP." << std::endl;
		std::cout << "2) +8 HP +4 DMG" << std::endl;
		std::cout << "3) +2 ARMOUR +6 HP" << std::endl;
		std::cout << "4) Start your runs with an item." << std::endl;
		std::cout << "5) Rage: build up your rage and attack with an extra 20% crit chance and a flat +7DMG for 3AP." << std::endl;
		std::cout << "Special ability: At lvl 3: 25% chance to critical strike; At lvl 5 : +15% crit chance.\n";
		std::cout << "+1AP/upgrade" << std::endl;
		std::cout << std::endl;

		std::cout << "f) Cleric Upgrades: " << std::endl;
		std::cout << "1) Start with 7 base mana. Channel Divinity: deal 150% damage to one enemy, apply necrotic flame for 3 MANA." << std::endl;
		std::cout << "2) +7 HP +2 ARMOUR +1 DMG" << std::endl;
		std::cout << "3) +4 DMG +4 MANA" << std::endl;
		std::cout << "4) Start your runs with an item." << std::endl;
		std::cout << "5) Turn Undead: harness the power of the last defeated enemy for the rest of the run for 8 MANA." << std::endl;
		std::cout << "+1 DMG and ARMOR / upgrade" << std::endl;
		std::cout << std::endl;

		std::cout << "Select class (a/b/c/d/e/f): ";
		std::cin >> input;
		if (input == "a")
		{
			if (this->upgrades[0] == 5)
				input = "0";
			else
				this->upgrades[0]++;
		}
		if (input == "b")
		{
			if (this->upgrades[1] == 5)
				input = "0";
			else
				this->upgrades[1]++;
		}
		if (input == "c")
		{
			if (this->upgrades[2] == 5)
				input = "0";
			else
				this->upgrades[2]++;
		}
		if (input == "d")
		{
			if (this->upgrades[3] == 5)
				input = "0";
			else
				this->upgrades[3]++;
		}
		if (input == "e")
		{
			if (this->upgrades[4] == 5)
				input = "0";
			else
				this->upgrades[4]++;
		}
		if (input == "f")
		{
			if (this->upgrades[5] == 5)
				input = "0";
			else
				this->upgrades[5]++;
		}
	}
	this->recalculate();
}

void Player::levelup()
{
	//per level : +3 HP
	//per 5 levels : +2 DMG; +1 ARMOUR
	int ok = this->LVL;

	std::cout << "You have died!\n";
	Sleep(500);
	while (true)
	{
		ok = this->LVL;
		switch (this->LVL)
		{
		case 1:
			if (this->XP > 69)
			{
				this->LVL++;
				this->maxHP += 3;
				this->maxDMG += 1;
				this->XP -= 70;
				getupgrade();
			}
			break;

		case 2:
			if (this->XP > 249)
			{
				this->LVL++;
				this->maxHP += 3;
				this->maxDMG += 1;
				this->XP -= 250;
				getupgrade();
			}
			break;

		case 3:
			if (this->XP > 899)
			{
				this->LVL++;
				this->maxHP += 3;
				this->maxDMG += 1;
				this->XP -= 900;
				getupgrade();
			}
			break;

		case 4:
			if (this->XP > 1799)
			{
				this->LVL++;
				this->XP -= 1800;
				this->maxDMG += 3;
				this->maxARMOUR += 2;
				getupgrade();
			}
			break;

		case 5:
			if (this->XP > 2999)
			{
				this->LVL++;
				this->maxHP += 3;
				this->maxDMG += 1;
				this->XP -= 3000;
				getupgrade();
			}
			break;

		case 6:
			if (this->XP > 3799)
			{
				this->LVL++;
				this->maxHP += 3;
				this->maxDMG += 1;
				this->XP -= 3800;
				getupgrade();
			}
			break;

		case 7:
			if (this->XP > 4999)
			{
				this->LVL++;
				this->maxHP += 3;
				this->maxDMG += 1;
				this->XP -= 5000;
				getupgrade();
			}
			break;

		case 8:
			if (this->XP > 5999)
			{
				this->LVL++;
				this->maxHP += 3;
				this->maxDMG += 1;
				this->XP -= 6000;
				getupgrade();
			}
			break;

		case 9:
			if (this->XP > 7499)
			{
				this->LVL++;
				this->XP -= 7500;
				this->DMG += 3;
				this->ARMOUR += 2;
				getupgrade();
			}
			break;

		default:
			if (this->XP > (7500 + (500 * (this->LVL - 10))))
			{
				if (this->LVL % 5 == 0)
				{
					this->LVL++;
					this->XP -= (7500 + (500 * (this->LVL - 10)));
					this->DMG += 3;
					this->ARMOUR += 2;
				}
				else
				{
					this->LVL++;
					this->maxHP += 3;
					this->maxDMG += 1;
					this->XP -= (7500 + (500 * (this->LVL - 10)));
				}
			}
			break;
		}

		if (ok == this->LVL)
			break;
		else
		{
			std::cout << "You are now level " << this->LVL << "!";
		}
	}
	this->refreshstats();
	this->save();
	std::cout << "\nRespawing...";
	Sleep(2000);
}

void Player::refreshstats()
{
	this->HP = this->maxHP;
	this->MP = this->maxMP;
	this->STAM = this->maxSTAM;
	this->AP = this->maxAP;
	this->DMG = this->maxDMG;
	this->ARMOUR = this->maxARMOUR;
	this->bonusHP = this->bonusDMG = this->bonusAP = this->bonusARMOUR = this->bonusMP = this->bonusSTAM = 0;
	this->stunned = false;
	this->weapon = "None";

	for (int i = 0; i < 21; i++)
		this->items[i] = 0;
}

int Player::attack(int bonus)
{
	int damage;
	damage = this->DMG;
	damage += this->bonusDMG;
	int modifier = rand() % 40 - 20;

	int crit = rand() % 100 + 1;
	int realcrit = 0;
	if (this->upgrades[4] > 2)
		realcrit += 25;
	else if (this->upgrades[4] > 4)
		realcrit += 15;
	realcrit += bonus;
	if (realcrit >= crit)
		damage *= 3;
	
	return (damage + damage*modifier/100);
}

std::string Player::magic()
{
	while (true)
	{
		if (this->upgrades[0] > 0)
		{
			if (this->upgrades[0] < 3)
			{
				std::cout << "Kick - 2AP\n";
				std::cout << "Sword (Switch Ability) - 1AP\n";
			}
			else if (this->upgrades[0] < 5)
			{
				std::cout << "Kick - 2AP\n";
				std::cout << "Sword (Switch Ability) - 1AP\n";
				std::cout << "Halberd (Switch Ability) - 3AP\n";
			}
			else if (this->upgrades[0] < 6)
			{
				std::cout << "Kick - 2AP\n";
				std::cout << "Sweep - 4AP\n";
				std::cout << "Sword (Switch Ability) - 1AP\n";
				std::cout << "Halberd (Switch Ability) - 3AP\n";
				std::cout << "Scythe (Switch Ability) - 5AP\n";
			}
		}

		if (this->upgrades[1] > 0)
		{
			if (this->upgrades[1] < 3)
			{
				std::cout << "Hail_of_Thorns - 2MP\n";
				std::cout << "Convert - 1AP\n";
			}
			else if (this->upgrades[1] < 5)
			{
				std::cout << "Hail_of_Thorns - 2MP\n";
				std::cout << "Convert - 1AP\n";
			}
			else if (this->upgrades[1] < 6)
			{
				std::cout << "Hail_of_Thorns - 2MP\n";
				std::cout << "Hail_of_Blades - 2MP\n";
				std::cout << "Meteor_Storm - 5MP\n";
				std::cout << "Convert - 1AP\n";
			}
		}
		if (this->upgrades[2] > 0)
		{
			if (this->upgrades[2] < 5)
			{
				std::cout << "Multiple_Strikes - 2AP\n";
			}
			else if (this->upgrades[2] < 6)
			{
				std::cout << "Multiple_Strikes - 2AP\n";
				std::cout << "Backstab - 3AP\n";
			}
		}

		if (this->upgrades[3] > 0)
		{
			if (this->upgrades[3] < 5)
			{
				std::cout << "Lay_On_Hands - 1MP\n";
			}
			else if (this->upgrades[3] < 6)
			{
				std::cout << "Lay_On_Hands - 2MP\n";
				std::cout << "Thunderous_Smite - 2MP\n";
			}
		}

		if (this->upgrades[4] > 0)
		{
			if (this->upgrades[4] < 5)
			{
				std::cout << "Headbutt - 1AP\n";
			}
			else if (this->upgrades[4] < 6)
			{
				std::cout << "Headbutt - 1AP\n";
				std::cout << "Rage - 2AP\n";
			}
		}

		if (this->upgrades[5] > 0)
		{
			if (this->upgrades[5] < 5)
			{
				std::cout << "Channel_Divinity - 3MP\n";
			}
			else if (this->upgrades[5] < 6)
			{
				std::cout << "Channel_Divinity - 3MP\n";
				std::cout << "Turn_Undead - 8MP\n";
			}
		}

		std::string input;
		std::cout << "Input name of the spell you wish to use or none if you wish to return: ";
		std::cin >> input;

		if (this->upgrades[0] > 0)
		{
			if (this->upgrades[0] < 2)
			{
				if ((input == "kick" || input == "Kick") && this->AP > 1)
					return "Kick";
				if ((input == "sword" || input == "Sword") && this->AP > 0)
					return "Sword";
			}
			else if (this->upgrades[0] < 4)
			{
				if ((input == "kick" || input == "Kick") && this->AP > 1)
					return "Kick";
				if ((input == "sword" || input == "Sword") && this->AP > 0)
					return "Sword";
				if ((input == "halberd" || input == "Halberd") && this->AP > 2)
					return "Halberd";
			}
			else if (this->upgrades[0] < 6)
			{
				if ((input == "kick" || input == "Kick") && this->AP > 1)
					return "Kick";
				if ((input == "sweep" || input == "Sweep") && this->AP > 3)
					return "Sweep";
				if ((input == "sword" || input == "Sword") && this->AP > 0)
					return "Sword";
				if ((input == "halberd" || input == "Halberd") && this->AP > 2)
					return "Halberd";
				if ((input == "scythe" || input == "Scythe") && this->AP > 4)
					return "Scythe";
			}
		}

		if (this->upgrades[1] > 0)
		{
			if (this->upgrades[1] < 2)
			{
				if ((input == "convert" || input == "Convert") && this->AP > 0)
					return "Convert";
				if ((input == "hail_of_thorns" || input == "Hail_of_Thorns") && this->MP > 1 && this->AP > 0)
					return "Thorns";
			}
			else if (this->upgrades[1] < 4)
			{
				if ((input == "convert" || input == "Convert") && this->AP > 0)
					return "Convert";
				if ((input == "hail_of_thorns" || input == "Hail_of_Thorns") && this->MP > 1 && this->AP > 0)
					return "Thorner";

			}
			else if (this->upgrades[1] < 6)
			{
				if ((input == "hail_of_thorns" || input == "Hail_of_Thorns") && this->MP > 1 && this->AP > 0)
					return "Thorner";
				if ((input == "hail_of_blades" || input == "Hail_of_Blades") && this->MP > 1 && this->AP > 0)
					return "Blades";
				if ((input == "meteor_storm" || input == "Meteor_Storm") && this->MP > 4)
					return "Meteor";
			}
		}

		if (this->upgrades[2] > 0)
		{
			if (this->upgrades[2] < 2)
			{
				if ((input == "multiple_strikes" || input == "Multiple_Strikes") && this->AP > 1)
					return "Strikes";
			}
			else if (this->upgrades[2] < 6)
			{
				if ((input == "multiple_strikes" || input == "Multiple_Strikes") && this->AP > 1)
					return "Strikes";
				if ((input == "backstab" || input == "Backstab") && this->AP > 2)
					return "Backstab";
			}
		}

		if(this->upgrades[3]>0)
		{
			if (this->upgrades[3] < 2)
			{
				if ((input == "lay_on_hands" || input == "Lay_On_Hands") && this->MP > 0)
					return "Hands";
			}
			else if (this->upgrades[3] < 6)
			{
				if ((input == "lay_on_hands" || input == "Lay_On_Hands") && this->MP > 0)
					return "Hands";
				if ((input == "thunderous_smite" || input == "Thunderous_Smite") && this->MP > 1)
					return "Thunder";
			}
		}

		if (this->upgrades[4])
		{
			if (this->upgrades[4] < 2)
			{
				if ((input == "headbutt" || input == "Headbutt") && this->AP > 0)
					return "Headbutt";
			}
			else if (this->upgrades[4] < 6)
			{
				if ((input == "headbutt" || input == "Headbutt") && this->AP > 0)
					return "Headbutt";
				if ((input == "rage" || input == "Rage") && this->AP > 1)
					return "Rage";
			}
		}

		if (this->upgrades[5] > 0)
		{
			if (this->upgrades[5] < 2)
			{
				if ((input == "channel_divinity" || input == "Channel_Divinity") && this->MP > 2)
					return "Divinity";
			}
			else if (this->upgrades[5] < 6)
			{
				if ((input == "channel_divinity" || input == "Channel_Divinity") && this->MP > 2)
					return "Divinity";
				if ((input == "turn_undead" || input == "Turn_Undead") && this->AP > 1)
					return "Undead";
			}
		}

		if (input == "none" || input == "None")
		{
			std::cout << std::endl;
			return "None";
		}
	}
}

int Player::block()
{
	//blocks (AP * 10)% dmg, max 65%
	// Paladin At lvl 3: blocks(AP * 20) % dmg, max 100 %
	int blk;
	if (upgrades[3] > 2)
	{
		blk = (this->AP * 20);
		this->AP = 0;
		if (blk > 100)
			return 100;
		else return blk;
	}
	else
	{
		blk = (this->AP * 10);
		this->AP = 0;
		if (blk > 65)
			return 65;
		else return blk;
	}
}