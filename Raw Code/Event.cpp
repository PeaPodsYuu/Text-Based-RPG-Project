#include "Event.h"
#include "Player.h"
#include "Combat.h"
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <random>

Event::Event()
{
	this->player.load();
}

void Event::getitem(int id)
{
	this->player.items[id] += 1;
	switch (id)
	{
	case(0): //Smash Potatoes : +15 % crit for Rage skill, +5 HP
		std::cout << "Got Smash Potatoes! You gain a small amount of health, if you are a Barbarian, you are now stronger!";
		this->player.bonusHP += 5;
		break;

	case(1): //Hailment of the Basilisk: Hail of thorns gets 20% stun chance; + 4 mana; +1 ARMOUR
		std::cout << "Got Hailment of the Basilisk! You gain a small amount of mana and some protection, if you are a Mage, you are now stronger!";
		this->player.bonusMP += 4;
		break;

	case(2): //Thundersoul Iron Platemail : Thunderous smite + 50 % dmg and always stuns, +3 ARMOUR
		std::cout << "Got Iron Platemail! You gain a small amount of defence, if you are a Paladin, you are now stronger!";
		this->player.bonusARMOUR += 3;
		break;

	case(3): //Vow of Resilience : +4 STAM For warrior :
			 //default / 1 AP : sword and shield(+2 ARMOUR / upgrade)
			 //lvl 3 / 2 AP : halberd(ignore enemy armor + 20 % sweep damage to nontargeted enemies)
			 //lvl 5 / 3 AP : scythe(lifesteal 40 % of DMG)
		std::cout << "Got Vow of Resilience! You gain a small amount of stamina, if you are a Warrior, you are now stronger!";
		this->player.bonusSTAM += 2;
		break;

	case(4): //End of Greed: For every enemy who dies of bleed +1 bonus DMG for the run, +1 AP;
		std::cout << "Got End of Greed! You gain one action point, if you are a Rogue, you are now stronger!";
		this->player.AP += 1;
		break;

	case(5): //Vestment of Unholy Powers: For Channel Divinity +2 Burn dmg; +2 DMG
		std::cout << "Got Vestment of Unholy Powers! You gain a small amount of damange, if you are a Cleric, you are now stronger!";
		this->player.bonusDMG += 1;
		break;

	case(6): //Merry Berry: 15% chance not to use mana/AP when you cast/attack
		std::cout << "Got Merry Berry! Your attacks and special abilities are sometimes free of cost!";
		break;

	case(7): //Amulet of Health: +10 HP; +1 Armour
		std::cout << "Got Amulet of Health! You gain an average amount of health and a small amount of armour!";
		this->player.bonusHP += 10;
		this->player.bonusARMOUR += 1;
		break;

	case(8): //Wyrm Scale Dagger: +8 mana; +2 DMG
		std::cout << "Got Wyrm Scale Dagger! You gain an average amount of mana and a small amount of damage!";
		this->player.bonusMP += 8;
		this->player.bonusDMG += 2;
		break;

	case(9): //Fortune of the Steel Dragon: +4 ARMOUR; Burn damage /2
		std::cout << "Got Fortune of the Steel Dragon! You gain an average amount of armour and are protected from burn damage!";
		this->player.bonusARMOUR += 4;
		break;

	case(10): //Djinn and Tonic: +10 STAM; +4 HP
		std::cout << "Got Djinn and Tonic! You gain an average amount of stamina and a small amount of health!";
		this->player.bonusSTAM += 10;
		this->player.bonusHP += 4;
		break;

	case(11): //Sash of Sorcerous Synergy: +2 AP
		std::cout << "Got Sash of Sorcerous Synergy! You gain an two action points!";
		this->player.bonusAP += 2;
		break;

	case(12): //Love's Embrace: +4 DMG; +4 HP
		std::cout << "Got Love's Embrace! You gain an average amount of damage and a small amount of health!";
		this->player.bonusDMG += 4;
		this->player.bonusHP += 4;
		break;

	case(13): //Oath of the Patient: +2 bonus damage / turn, lose it on end of combat
		std::cout << "Got Oath of Patience! You grow stronger the longer you are in battle!";
		this->player.bonusHP += 10;
		this->player.bonusARMOUR += 1;
		break;

	case(14): //Liquor of Eternal Life: +20 HP, +4 Armour
		std::cout << "Got Liquor of Eternal Life! You gain an hearty amount of health and a medium amount of armour!";
		this->player.bonusHP += 20;
		this->player.bonusARMOUR += 4;
		break;

	case(15): //Chronomancer's Eyepiece: +14 mana; +2 mana/turn in combat; +1 AP
		std::cout << "Got Chronomancer's Eyepiece! You gain an hearty amount of mana and an action point!\nThanks to the eyepiece, you can manipulate time just enough to cast your spells more efficiently!";
		this->player.bonusMP += 14;
		this->player.bonusAP += 1;
		break;

	case(16): //Adamantite Armour: +6 ARMOUR; Can't be critted
		std::cout << "Got Adamantite Armour! You gain an hearty amount of armour and are shielded from the deadliest of attacks!";
		this->player.bonusARMOUR += 6;
		break;

	case(17): //Hearty Meal: +15 STAMINA; +10 HP
		std::cout << "Got Hearty Meal! You gain an hearty amount of stamina and a medium amount of health!";
		this->player.bonusSTAM += 15;
		this->player.bonusHP += 10;
		break;

	case(18): //Freerunner's Armour: +3 AP; +3 ARMOUR
		std::cout << "Got Freerunner's Armour! You gain three action points and a medium amount of armour!";
		this->player.bonusAP += 3;
		this->player.bonusARMOUR += 3;
		break;

	case(19): //Blackthorn Spear of the Moonless Hunter: +5 DMG; +3 Bleed Stacks
		std::cout << "Got Blackthorn Spear of the Moonless Hunter! You gain an hearty amount of damage, but it is mostly in the form of bleeding!";
		this->player.bonusDMG += 5;
		break;

	case(20): //Instatiable Tome: For all enemy kills, heal for 50% of the defeated enemy's max HP
		std::cout << "Got The Insatiable Tome! You grow more resilient by absorbing your enemies' life essence!";
		break;

	}
}

int Event::generateevent(int lvl)
{
	std::ifstream f;
	int select = rand() % 2 + 1;
	switch (lvl)
	{
	case 1:
		if (select == 1)
		{
			f.open("Data/Events/Event1.txt");
			std::string text;
			while (getline(f, text))
				std::cout << text << std::endl;
			std::cout << std::endl;
			f.close();
			return 1;
		}
		else
		{
			f.open("Data/Events/Event2.txt");
			std::string text;
			while (getline(f, text))
				std::cout << text << std::endl;
			std::cout << std::endl;
			f.close();
			return 2;
		}
		break;

	case 2:
		if (select == 1)
		{
			f.open("Data/Events/Event3.txt");
			std::string text;
			while (getline(f, text))
				std::cout << text << std::endl;
			std::cout << std::endl;
			f.close();
			return 3;
		}
		else
		{
			f.open("Data/Events/Event4.txt");
			std::string text;
			while (getline(f, text))
				std::cout << text << std::endl;
			std::cout << std::endl;
			f.close();
			return 4;
		}
		break;

	case 3:
		if (select == 1)
		{
			f.open("Data/Events/Event5.txt");
			std::string text;
			while (getline(f, text))
				std::cout << text << std::endl;
			std::cout << std::endl;
			f.close();
			return 5;
		}
		else
		{
			f.open("Data/Events/Event6.txt");
			std::string text;
			while (getline(f, text))
				std::cout << text << std::endl;
			std::cout << std::endl;
			f.close();
			return 6;
		}
		break;

	case 4:
		if (select == 1)
		{
			f.open("Data/Events/Event7.txt");
			std::string text;
			while (getline(f, text))
				std::cout << text << std::endl;
			std::cout << std::endl;
			f.close();
			return 7;
		}
		else
		{
			f.open("Data/Events/Event8.txt");
			std::string text;
			while (getline(f, text))
				std::cout << text << std::endl;
			std::cout << std::endl;
			f.close();
			return 8;
		}
		break;

	case 5:
		if (select == 1)
		{
			f.open("Data/Events/Event9.txt");
			std::string text;
			while (getline(f, text))
				std::cout << text << std::endl;
			std::cout << std::endl;
			f.close();
			return 9;
		}
		else
		{
			f.open("Data/Events/Event10.txt");
			std::string text;
			while (getline(f, text))
				std::cout << text << std::endl;
			std::cout << std::endl;
			f.close();
			return 10;
		}
		break;

	}
}
void Event::getevent(int lvl, int type)
{
	while (type == 2)
	{
		system("CLS");
		std::string input;
		std::cout << "Input (rest / meditate): ";
		while(input!="rest" && input!="meditate")
			std::cin >> input;
		if (input == "rest")
		{
			this->player.HP = this->player.maxHP + this->player.bonusHP;
			std::cout << std::endl << "Healed!";
			Sleep(2500);
			break;
		}
		if (input == "meditate")
		{
			this->player.MP += (this->player.maxMP + this->player.bonusMP) / 2;
			if (this->player.MP > (this->player.maxMP + this->player.bonusMP))
				this->player.MP = (this->player.maxMP + this->player.bonusMP);
			std::cout << std::endl << "Restored half mana!";
			Sleep(2500);
			break;
		}
	}
	while (type == 1)
	{
		int chance = rand() % 100 + 1;
		system("CLS");
		if (chance > 69)
		{
			//stage 1 items - stage 3 - stage 5; x7/stage; order: HP,MP,ARMOUR,STAM,AP,DMG,SPEC
			// => formula rand 7 * (stage / 2 + 1)
			int modifier = 3;
			if (lvl < 3)
				modifier = 1;
			else if (lvl < 5)
				modifier = 2;
			int id = rand() % (modifier * 7);
			getitem(id);
			Sleep(4500);
			break;
		}
		else
		{
			int id = generateevent(lvl);
			std::string input = "none";
			if (id == 1 || id == 2 || id == 3 || id == 4 || id == 6 || id == 10)
				while (input != "yes" && input != "no")
					std::cin >> input;
			else
				Sleep(6000);
			int decide = rand() % 100 + 1;

			Combat* a = new Combat();

			switch (id)
			{
			case 1:
				if (input == "yes")
				{
					if (decide < 96)
					{
						std::cout<<"\nYou were bitten by spiderlings! Fortunately, it is not fatal.\n";
						this->player.HP -= 3;
						if (this->player.HP < 0)
							this->player.HP = 1;
					}
					else
					{
						std::cout << "\nYou found a whole Hearty Meal inside!\n";
						this->player.items[17]++;
					}
				}
				break;

			case 2:
				if (input == "yes")
				{
					if (decide < 51)
					{
						std::cout << "\nThe soup was bland. Not very nutritious either.\n";
					}
					else
					{
						std::cout << "\nThe soup tasted amazing! You feel invigorated.\n";
						this->player.HP += 4;
						if (this->player.HP > this->player.maxHP + this->player.bonusHP)
							this->player.HP = this->player.maxHP + this->player.bonusHP;
					}
				}
				break;

			case 3:
				if (input == "yes")
				{
					if (decide < 51)
					{
						std::cout << "\nThe berry was enchanted, it drained your mana! The man is nowhere to be seen anymore...\n";
						this->player.MP = 0;
					}
					else
					{
						std::cout << "\nAfter eating the berry, the man notices your obvious delight and gives you another. You got a Merry Berry!\n";
						this->player.items[6]++;
					}
				}
				break;

			case 4:
				if (input == "yes")
				{
					if (decide < 31)
					{
						std::cout << "\nThe meat tasted absolutely rancid. You feel worse for wear.\n";
						this->player.HP -= 4;
						if (this->player.HP < 0)
							this->player.HP = 1;
						this->player.MP -= 5;
						if (this->player.MP < 0)
							this->player.MP = 0;
					}
					else
					{
						std::cout << "\nThe meat you ate was blessed by the Gods, making you feel like new!\n";
						this->player.HP = this->player.maxHP + this->player.bonusHP;
					}
				}
				break;

			case 5:
				if (decide < 51)
				{
					this->player.XP += 35;
				}
				break;

			case 6:
				if (input == "yes")
				{
					if (decide < 76)
					{
						std::cout << "\nThe room was infested by corrupted creatures. You managed to fight them off, but you escaped wounded.\n";

						this->player.HP -= 8;
						if (this->player.HP < 0)
							this->player.HP = 1;
					}
					else
					{
						std::cout << "\nThe creatures inside proved aggressive, but with much patience, you managed to tame them. You've earned an Oath of the Patient.\n";
						this->player.items[16]++;
					}
				}
				break;

			case 7:
				a->initializecombat(lvl, 1);
				break;

			case 8:
				this->player.items[19]++;
				break;

			case 9:
				if (decide < 86)
				{
					std::cout << "\nCrossing the gap hurts you greatly, but you cling on to your life.\n";
					this->player.HP -= 10;
					if (this->player.HP < 0)
						this->player.HP = 1;
				}
				else
				{
					std::cout << "\nYou manage to get by unscathed, but for how long will this blind luck last?\n";
				}
				break;

			case 10:
				if (input == "yes")
				{
					if (decide < 81)
					{
						std::cout << "\nWhatever God or Deities guard this damned place smiled upon your gift. You feel invigorated.\n";
						this->player.HP = this->player.maxHP + this->player.bonusHP;
						this->player.MP = this->player.maxMP + this->player.bonusMP;
						this->player.STAM = this->player.maxSTAM + this->player.bonusSTAM;
						this->player.bonusARMOUR += 3;
					}
					else
					{
						std::cout << "\nAfter a while, you realize nothing is happening. This place is damned by the Gods-- even worse, you now find yourself fighting the denizens of it!\n";
						a->initializecombat(lvl, 1);
					}
				}
				break;

			}
			Sleep(4000);
			break;
		}
	}
	this->player.save();
}
