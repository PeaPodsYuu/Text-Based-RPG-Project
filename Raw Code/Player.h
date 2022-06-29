#pragma once
#include <iostream>
#include <string>
class Player
{
	friend class Combat;
	friend class Event;
	friend class MapGen;
	int HP, maxHP;
	int MP, maxMP;
	int STAM, maxSTAM;
	int AP, maxAP;
	int DMG, maxDMG;
	int ARMOUR, maxARMOUR;
	int bonusHP, bonusDMG, bonusAP, bonusARMOUR, bonusMP, bonusSTAM;
	int LVL;
	int XP;
	int upgrades[6];
	int items[21]; //stage 1 items - stage 3 - stage 5; x7/stage; order: HP,MP,STAM,AP,DMG,ARMOUR,SPEC
	bool stunned;
	std::string weapon;
public:
	Player();
	void newsave();
	void newload();
	void refreshstats();
	void save();
	void load();
	void levelup();
	void getupgrade();
	void recalculate();
	int attack(int);
	std::string magic();
	int block();
	bool dead();
};


/*
block: blocks (AP * 10)% dmg, max 65%

base hp: 14
base dmg: 3
base ap: 1
base mana: 0

per level: +3 HP; +1 DMG
per 5 levels: +3 DMG; +2 ARMOUR 

base stamina: 10
+1 STM / 2 upgrades
+3 STM / lvl (only on lvl)

*/


/*

Classes:

- (DONE)Warrior: (2AP)Kick (70% dmg; stun); +4 DMG +5 ARMOR; +6 HP; +item; +5 ARMOR (4)Sweep (140% dmg; hits all enemies)

+2 AP +1 DMG / upgrade

Weapon switch: 
	default / 1 AP: sword and shield ( +1 ARMOUR / upgrade)
	lvl 3 / 2 AP: halberd ( ignore enemy armor )
	lvl 5 / 5 AP: scythe ( lifesteal 30% of DMG )

_________________________________________

- (DONE)Mage: +7 mana and (2mn)Hail of Thorns(next attack deals and extra 1-10DMG); +7 DMG; +4 HP +6 mana; +item; (5mn)Meteor Storm (80% damage to target; 40% damage to others; apply 5 turns burn (4dmg/turn)) 

+1 AP / 2 upgrades; +1 ARMOUR / upgrade (magic shield)

Special:
	Default: turn 1 AP to +50% mana
	AT lvl 3: Hail of Thorns upgraded: 5-20DMG
	AT lvl 5: Hail of Thorns gains new option: 1-10DMG but hit all enemies

_________________________________________

- Rogue: (2AP)Multiple Strikes ( 1 + no. upgrades attacks ); +1 bleed/attack +1 DMG; +4 HP +1 AP; +item; (3 AP)Backstab (8xDMG, negate armour, +5 bleed)

+ 1 AP / upgrade; 1+ ARMOUR / 2 upgrades

AT level 3: 50% chance to dodge

_________________________________________

- (DONE)Paladin: +4 mana (1 mana)Lay On Hands(+3 HP); +5 HP +7 ARMOUR; +3 DMG +2 HP +2 ARMOUR; +item; (2 mana)Thunderous Smite (200% damage + 80% Stun Chance)

+1 AP / upgrade; +1 ARMOUR / upgrade

At lvl 3: blocks (AP * 20)% dmg, max 100%

_________________________________________

- (DONE)Barbarian: (1AP)Headbutt (130% damange, 80% chance to stun enemy, otherwise stun yourself); +8 HP +4 DMG; +2 ARMOUR +6 HP; +item; (3AP)Rage(crit chance + 15%; +7DMG/attack; lasts 1 turn and armour doesn't protect at end of that turn)

+1AP/upgrade

At lvl 3: 25% chance to critical strike, dealing 3x DMG

At lvl 5: 40% crit

_________________________________________

- Cleric: +7 mana (3 mana)Channel Divinity (150% damage, apply necrotic flame for 1 damage/turn, doesnt decay, doesnt allow healing); +7 HP +2 ARMOUR +1 DMG; +4 DMG +4 MANA; +item; (8 MANA)Turn Undead (usable if an enemy is defeated already; either gain the base attack of the last defeated enemy, or its base hp)

+1 DMG and ARMOR / upgrade

*/