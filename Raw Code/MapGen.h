#pragma once
#include <iostream>
#include "Player.h"

class MapGen
{
	Player player;
	int lvl;
	int map[13][13];
public:
	MapGen(int);
	void generateMap();
	void showMap();
	int moveMap();
};

