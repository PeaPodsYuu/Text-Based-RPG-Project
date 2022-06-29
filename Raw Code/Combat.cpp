#include "Combat.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <Windows.h>

Combat::Combat()
{
	this->player.load();
}

int Combat::gettarget(int nb_of_enemies, Enemy* foes[])
{
	std::string select = "10";
	std::cout << "Select a target from 0 to " << nb_of_enemies-1 << ": ";

	while ((stoi(select) < 0 || stoi(select) >= nb_of_enemies))
	{
		std::cin >> select;
	}
	return stoi(select);
}

int merryberry(int berries)
{
	int merry = 15 * berries;
	if (merry > 100)
		merry = 100;
	int merrychance = rand() % 100 + 1;
	if (merrychance > 100 - merry - 1)
		return 1;
	return 0;
}

void Combat::getspell(std::string spell, Enemy* foes[], int target, int nb_of_enemies, Enemy* lastdead, bool necroeffect)
{
	/*
		std::cout << "Sword (Switch Ability) - 1AP\n";
		std::cout << "Halberd (Switch Ability) - 3AP\n";
		std::cout << "Scythe (Switch Ability) - 5AP\n";*/
	if (spell == "None")
	{
		return;
	}
	if (spell == "Sword")
	{
		if (this->player.weapon != "Sword")
		{
			this->player.bonusARMOUR += 1 * this->player.upgrades[0];
			this->player.bonusARMOUR += 1 * this->player.items[3];
		}
		this->player.weapon = "Sword";
		if (merryberry(this->player.items[6]) == 0)
			this->player.AP -= 1;
	}

	if (spell == "Halberd")
	{
		if (this->player.weapon == "Sword")
		{
			this->player.bonusARMOUR -= 1 * this->player.upgrades[0];
			this->player.bonusARMOUR -= 1 * this->player.items[3];
		}
		this->player.weapon = "Halberd";
		if (merryberry(this->player.items[6]) == 0)
			this->player.AP -= 3;
	}

	if (spell == "Scythe")
	{
		if (this->player.weapon == "Sword")
		{
			this->player.bonusARMOUR -= 1 * this->player.upgrades[0];
			this->player.bonusARMOUR -= 1 * this->player.items[3];
		}
		this->player.weapon = "Scythe";
		if (merryberry(this->player.items[6]) == 0)
			this->player.AP -= 5;
	}

	if (spell == "Convert")
	{
		if (merryberry(this->player.items[6]) == 0)
			this->player.AP -= 1;
		this->player.MP += this->player.maxMP / 2;
		if (this->player.MP > this->player.maxMP + this->player.bonusMP)
			this->player.MP = this->player.maxMP + this->player.bonusMP;
	}

	if (spell == "Kick")
	{
		if (merryberry(this->player.items[6]) == 0)
			this->player.AP -= 2;
		int dmg = this->player.attack(0) * 70 / 100;
		dmg -= foes[target]->ARMOUR;
		if (dmg <= 0)
			dmg = 1;
		foes[target]->HP -= dmg;
		foes[target]->stunned = true;
	}

	if (spell == "Sweep")
	{
		if (merryberry(this->player.items[6]) == 0)
			this->player.AP -= 4;
		int dmg = this->player.attack(0) * 140 / 100;
		for (int i = 0; i < nb_of_enemies; i++)
		{
			int clonedmg = dmg;
			clonedmg -= foes[i]->ARMOUR;
			if (clonedmg <= 0)
				clonedmg = 1;
			foes[i]->HP -= clonedmg;
		}
	}

	if (spell == "Thorns")
	{
		if (merryberry(this->player.items[6]) == 0)
		{
			this->player.MP -= 2;
			this->player.AP--;
		}
		int dmg = this->player.attack(0);
		dmg += rand() % 10 + 1;
		int stun = rand() % 100 + 1;
		dmg -= foes[target]->ARMOUR;
		if (dmg <= 0)
			dmg = 1;
		foes[target]->HP -= dmg;
		if (stun >= (100 - 20 * this->player.items[1]) + 1)
			foes[target]->stunned = true;
	}

	if (spell == "Thorner")
	{
		if (merryberry(this->player.items[6]) == 0)
		{
			this->player.MP -= 2;
			this->player.AP--;
		}
		int dmg = this->player.attack(0);
		dmg += rand() % 10 + 1;
		for (int i = 0; i < nb_of_enemies; i++)
		{
			int clonedmg = dmg;
			clonedmg -= foes[target]->ARMOUR;
			if (clonedmg <= 0)
				clonedmg = 1;
			foes[i]->HP -= clonedmg;
			int stun = rand() % 100 + 1;
			if (stun > (100 - 20 * this->player.items[1]) + 1)
				foes[i]->stunned = true;
		}
	}

	if (spell == "Blades")
	{
		if (merryberry(this->player.items[6]) == 0)
		{
			this->player.MP -= 2;
			this->player.AP--;
		}
		int dmg = this->player.attack(0);
		dmg += rand() % 16 + 5;
		int stun = rand() % 100 + 1;
		dmg -= foes[target]->ARMOUR;
		if (dmg <= 0)
			dmg = 1;
		foes[target]->HP -= dmg;
		if (stun > 79)
			foes[target]->stunned = true;
	}

	if (spell == "Meteor")
	{
		if (merryberry(this->player.items[6]) == 0)
			this->player.MP -= 5;
		int dmg = this->player.attack(0) * 40 / 100;
		int clonedmg = dmg;
		clonedmg -= foes[target]->ARMOUR;
		if (clonedmg <= 0)
			clonedmg = 1;
		foes[target]->HP -= clonedmg;
		for (int i = 0; i < nb_of_enemies; i++)
			if (i != target)
			{
				clonedmg = dmg;
				clonedmg -= foes[i]->ARMOUR;
				if (clonedmg <= 0)
					clonedmg = 1;
				foes[i]->HP -= clonedmg;
				foes[i]->burnSTACKS += 5;
			}
	}

	if (spell == "Strikes")
	{
		if (merryberry(this->player.items[6]) == 0)
			this->player.AP -= 2;
		int dmg = this->player.attack(0);
		for (int i = 0; i <= this->player.upgrades[2]; i++)
		{
			int clonedmg = dmg;
			clonedmg -= foes[target]->ARMOUR;
			if (clonedmg <= 0)
				clonedmg = 1;
			foes[target]->HP -= clonedmg;
			foes[target]->bleedSTACKS += 1;
			foes[target]->bleedSTACKS += 3 * this->player.items[19];
		}
	}

	if (spell == "Backstab")
	{
		if (merryberry(this->player.items[6]) == 0)
			this->player.AP -= 3;
		int dmg = 8 * this->player.attack(0);
		foes[target]->HP -= dmg;
		foes[target]->bleedSTACKS += 5;
		foes[target]->bleedSTACKS += 3 * this->player.items[19];
	}

	if (spell == "Hands")
	{
		if (merryberry(this->player.items[6]) == 0)
			this->player.MP -= 1;
		if (necroeffect == false)
		{
			this->player.HP += 3;
			if (this->player.HP > this->player.maxHP + this->player.bonusHP)
				this->player.HP = this->player.maxHP + this->player.bonusHP;
		}
	}

	if (spell == "Thunder")
	{
		if (merryberry(this->player.items[6]) == 0)
			this->player.MP -= 2;
		int dmg = 2 * this->player.attack(0);
		dmg += (dmg * 50 / 100) * this->player.items[2];
		int stun = rand() % 100 + 1;
		dmg -= foes[target]->ARMOUR;
		if (dmg <= 0)
			dmg = 1;
		foes[target]->HP -= (dmg - foes[target]->ARMOUR);;
		if (stun > 19 || this->player.items[2] > 0)
			foes[target]->stunned = true;
	}

	if (spell == "Headbutt")
	{
		if (merryberry(this->player.items[6]) == 0)
			this->player.AP -= 1;
		int stun = rand() % 100 + 1;
		int dmg = this->player.attack(0) * 130 / 100;
		dmg -= foes[target]->ARMOUR;
		if (dmg <= 0)
			dmg = 1;
		foes[target]->HP -= dmg;
	}

	if (spell == "Rage") // Fix no armour
	{
		if (merryberry(this->player.items[6]) == 0)
			this->player.AP -= 2;
		int dmg = this->player.attack(20 + (15 * this->player.items[0]));
		dmg += 7;
		dmg -= foes[target]->ARMOUR;
		if (dmg <= 0)
			dmg = 1;
		foes[target]->HP -= (dmg - foes[target]->ARMOUR);;
	}

	if (spell == "Divinity")
	{
		if (merryberry(this->player.items[6]) == 0)
			this->player.MP -=	3;
		int dmg = this->player.attack(0) * 150 / 100;
		dmg -= foes[target]->ARMOUR;
		if (dmg <= 0)
			dmg = 1;
		foes[target]->HP -= dmg;
		foes[target]->necroburnSTACKS += 1;
		foes[target]->necroburnSTACKS += 2 * this->player.items[5];
	}

	if (spell == "Undead")
	{
		if (merryberry(this->player.items[6]) == 0)
			this->player.MP -= 8;
		this->player.bonusHP += lastdead->DMG * 3 / 2;
		this->player.bonusDMG += lastdead->DMG / 2;
	}
}

int Combat::playcombat(Enemy* foes[], int nb_of_enemies)
{
	int tempdmg = 0;
	int combatfinish = 0;
	int hasbleed = 0;
	int hasburn = 0;
	int hasnecro = 0;
	bool fleeing = false;

	Enemy* lastdead = new Enemy(1, 1);
	while (this->player.HP > 0 && combatfinish == 0)
	{
		this->player.AP = this->player.maxAP + this->player.bonusAP;
		int def = 0;
		std::string input;

		
		int target = 0;
		

		while (this->player.AP > 0)
		{
			input = "none";
			while (input != "attack" && input != "block" && input != "special" && input != "flee")
			{
				system("CLS");
				std::cout << "The Adventurer:\n" << this->player.HP << "HP\n" << this->player.MP << "MP\n" << this->player.AP << "AP\n\n";
				for (int i = 0; i < nb_of_enemies; i++)
				{
					if(foes[i]->HP>0)
						std::cout << foes[i]->name << ": " << foes[i]->HP << "HP" << std::endl;
					else
						std::cout << foes[i]->name << ": Defeated" << std::endl;

				}


				std::cout << "Action ( attack / block / special / flee ): ";

				std::cin >> input;

				if (nb_of_enemies > 1)
					target = gettarget(nb_of_enemies, foes);
			}

			if (this->player.stunned == true)
			{
				this->player.stunned = false;
				std::cout << "You are stunned.\n";
				Sleep(2000);
				break;
			}

			else if (input == "attack")
			{
				if (merryberry(this->player.items[6]) == 0)
					this->player.AP--;

				int dmg = this->player.attack(0) + tempdmg + this->player.bonusDMG;
				int clonedmg = dmg;
				clonedmg -= foes[target]->ARMOUR;
				if (clonedmg <= 0)
					clonedmg = 1;
				foes[target]->HP -= clonedmg;

				if (this->player.upgrades[2] > 1)
					foes[target]->bleedSTACKS += 1;

				foes[target]->bleedSTACKS += 3 * this->player.items[19];

				if(this->player.weapon=="Halberd")
					for(int i=0;i<nb_of_enemies;i++)
						if (i != target)
						{
							clonedmg = dmg;
							clonedmg -= foes[i]->ARMOUR;
							if (clonedmg <= 0)
								clonedmg = 1;
							foes[i]->HP -= clonedmg;

							if (this->player.upgrades[2] > 1)
								foes[i]->bleedSTACKS += 1;

							foes[i]->bleedSTACKS += 3 * this->player.items[19];
						}

				if (this->player.weapon == "Scythe" && hasnecro==0)
				{
					int heal = min(foes[target]->HP, dmg);
					heal = heal * (40 * this->player.items[3]) / 100;
					this->player.HP += heal;
					if (this->player.HP > this->player.maxHP + this->player.bonusHP)
						this->player.HP = this->player.maxHP + this->player.bonusHP;
				}
			}
			else if (input == "special")
			{
				std::string spell = this->player.magic();
				bool necroeffect = false;
				if (hasnecro > 0)
					necroeffect = true;

				if (spell == "None")
					continue;
				else
					getspell(spell, foes, target, nb_of_enemies, lastdead, necroeffect);
			}

			else if (input == "block")
			{
				def = this->player.block();
			}
			else if (input == "flee")
			{
				int ok = 1;
				for (int i = 0; i < nb_of_enemies; i++)
					if (foes[i]->isboss == true)
						ok = 0;
				if (ok == 1)
					fleeing = true;
				else
					std::cout << "\nThe boss of this area prevents you from leaving.\n";
				break;
			}
		}
		tempdmg += 2 * this->player.items[13];
		this->player.MP += 2 * this->player.items[15];
		if (this->player.MP > this->player.maxMP + this->player.bonusMP)
			this->player.MP = this->player.maxMP + this->player.bonusMP;

		int alldead = 1;
		for (int i = 0; i < nb_of_enemies; i++)
		{
			if (foes[i]->HP <= 0 || foes[i]->dead == true)
				std::cout << "The " << foes[i]->name << " lays defeated.\n";
			
			else if (foes[i]->stunned == true && foes[i]->HP > 0 && foes[i]->isboss==false)
			{
				foes[i]->stunned = false;
				std::cout << "The " << foes[i]->name << " wakes up from its stunned state.\n";
				Sleep(500);
			}

			else if (foes[i]->HP > 0)
			{
				std::string action = getaction(foes[i]);

				if (action == "Attack")
				{
					std::cout << "The " << foes[i]->name << " attacks!\n";
					bool cancrit = true;
					if (this->player.items[16] > 0)
						cancrit = false;
					int dmg = (foes[i]->attack(cancrit) - (this->player.ARMOUR + this->player.bonusARMOUR));
					dmg -= dmg * def / 100;
					if (dmg < 0)
						dmg = 0;
					if (dmg > 0)
						this->player.HP -= dmg;
					Sleep(150);
				}

				else if (action == "Bleed")
				{
					std::cout << "The " << foes[i]->name << " attacks you with a bleeding attack!\n";
					hasbleed += foes[i]->bleed();
					Sleep(150);
				}

				else if (action == "Burn")
				{
					std::cout << "The " << foes[i]->name << " casts a pyromancy spell at you!\n";
					hasburn += foes[i]->burn();
					Sleep(150);
				}

				else if (action == "Necro")
				{
					std::cout << "The " << foes[i]->name << " casts a necromantic spell at you!\n";
					hasnecro += foes[i]->necro();
					Sleep(150);
				}
			}
		}

		Sleep(1350);
		system("CLS");

		if (hasburn > 0)
		{
			int finaldmg = hasburn;
			for (int i = 0; i < this->player.items[9]; i++)
				finaldmg /= 2;
			this->player.HP -= finaldmg;
			hasburn /= 2;
		}

		if (hasbleed > 0)
		{
			this->player.HP -= hasbleed;
			hasbleed--;
		}

		if (hasnecro > 0)
		{
			this->player.HP -= hasnecro;
		}

		for (int i = 0; i < nb_of_enemies; i++)
		{
			if (foes[i]->burnSTACKS > 0)
			{
				foes[i]->HP -= foes[i]->burnSTACKS;
				foes[i]->burnSTACKS /= 2;
			}

			if (foes[i]->bleedSTACKS > 0)
			{
				int ok = 0;
				if (foes[i]->HP > 0)
					ok = 1;
				foes[i]->HP -= foes[i]->bleedSTACKS;
				foes[i]->bleedSTACKS--;
				if (foes[i]->HP <= 0 && ok == 1)
					this->player.bonusDMG += this->player.items[4];
			}

			if (foes[i]->necroburnSTACKS > 0)
			{
				foes[i]->HP -= foes[i]->necroburnSTACKS;
			}

			if (foes[i]->HP <= 0 && foes[i]->dead == false)
			{
				foes[i]->dead = true;
				this->player.XP += foes[i]->gainXP;
				this->player.bonusHP += foes[i]->DMG * (50 * this->player.items[20]) / 100;
			}

			if (foes[i]->HP > 0)
				alldead = 0;
		}

		if (alldead == 1)
		{
			combatfinish = 1;
			this->player.save();
		}

		if (this->player.HP <= 0)
		{
			this->player.save();
			this->player.levelup();
			return 1;
		}

		if (fleeing == true)
		{
			this->player.save();
			break;
		}

	}
	return 0;
}

std::string Combat::getaction(Enemy* foe)
{

	int options[4];
	int nb = 0;
	for (int i = 0; i < 4; i++)
		options[i] = 0;

	if (foe->DMG > 0)
		options[0] = 100;
	if (foe->bleedPROC > 0)
		options[1] = 100;
	if (foe->burnPROC > 0)
		options[2] = 100;
	if (foe->necroburnPROC > 0)
		options[3] = 100;

	//calculate attack chances: regular, bleed, burn, necro
	nb = options[0] / 100 + options[1] / 100 + options[2] / 100 + options[3] / 100;
	for (int i = 0; i < 4; i++)
	{
		if (options[i] > 0)
			options[i] /= nb;
	}
	if (nb == 3)
		options[0]++;

	
	while (true)
	{
		int selection = rand() % 100 + 1;

		if ((selection < options[0]) && options[0] > 0)
			return "Attack";
		else if ((selection < options[0] + options[1]) && options[1] > 0)
			return "Bleed";
		else if ((selection < options[0] + options[1] + options[2]) && options[2] > 0)
			return "Burn";
		else if (options[3] > 0)
			return "Necro";
	}
}

int Combat::initializecombat(int lvl, int type)
{
	Enemy* foes[10];
	foes[0] = new Enemy(lvl, type);

	int nb_of_enemies = 1;

	if (type == 1)
	{
		
		nb_of_enemies += ((rand() % 3) * (lvl - 1));

		if (nb_of_enemies > 1)
			for (int i = 1; i < nb_of_enemies; i++)
			{
				foes[i] = new Enemy(lvl, type);
			}
	}
	else if (type == 2)
	{
		nb_of_enemies += (lvl / 2);

		if (nb_of_enemies > 1)
			for (int i = 1; i < nb_of_enemies; i++)
				foes[i] = new Enemy(lvl, type);
	}
	else if (type == 3)
		switch (lvl)
		{
		case 1:
			break;

		case 2:
			foes[1] = new Enemy(1, 1);
			foes[2] = new Enemy(1, 1);
			nb_of_enemies = 3;
			break;

		case 3:
			foes[1] = new Enemy(3, 1);
			foes[2] = new Enemy(2, 1);
			nb_of_enemies = 3;
			break;

		case 4:
			break;

		case 5:
			foes[1] = new Enemy(5, 2);
			foes[2] = new Enemy(5, 2);
			nb_of_enemies = 3;
			break;
		}
	int death = playcombat(foes,nb_of_enemies);
	return death;
}