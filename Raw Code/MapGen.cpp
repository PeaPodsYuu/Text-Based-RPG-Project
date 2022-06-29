#include "MapGen.h"
#include "Combat.h"
#include "Event.h"
#include "Player.h"
#include <time.h>
#include <iostream>
#include <string>
#include <Windows.h>

void MapGen::generateMap()
{

	srand(time(NULL));
	

	//generate levels
	switch (lvl)
	{
	case 1:
		//5x5 map
		//empty = 0 (40%); enemy = 1 (30%); elite enemy = 2 (12%); event = 3 (10%); boss = 4; rest/training = 5 (8%)
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
			{
				int tile = rand() % 100 + 1;

				if (tile < 41)
					this->map[i][j] = 0;

				else if (tile < 71)
					this->map[i][j] = 1;

				else if (tile < 83)
					this->map[i][j] = 2;

				else if (tile <93)
					this->map[i][j] = 3;
				else
					this->map[i][j] = 5;
			}
		

		this->map[4][2] = 7;
		this->map[2][2] = 4;

		break;

	case 2:
		//7x7 map
		//empty = 0 (35%); enemy = 1 (33%); elite enemy = 2 (14%); event = 3 (12%); boss = 4; rest/training = 5 (6%)

		for (int i = 0; i < 7; i++)
			for (int j = 0; j < 7; j++)
			{
				int tile = rand() % 100 + 1;

				if (tile < 36)
					this->map[i][j] = 0;

				else if (tile < 69)
					this->map[i][j] = 1;

				else if (tile < 83)
					this->map[i][j] = 2;

				else if (tile < 95)
					this->map[i][j] = 3;
				else
					this->map[i][j] = 5;
			}


		this->map[5][3] = 7;
		this->map[2][3] = 4;

		break;

	case 3:
		//9x9 map
		//empty = 0 (30%); enemy = 1 (36%); elite enemy = 2 (20%); event = 3 (10%); boss = 4; rest/training = 5 (4%)

		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
			{
				int tile = rand() % 100 + 1;

				if (tile < 31)
					this->map[i][j] = 0;

				else if (tile < 67)
					this->map[i][j] = 1;

				else if (tile < 87)
					this->map[i][j] = 2;

				else if (tile < 97)
					this->map[i][j] = 3;
				else
					this->map[i][j] = 5;
			}


		this->map[7][4] = 7;
		this->map[4][4] = 4;

		break;

	case 4:
		//11x11 map
		//empty = 0 (30%); enemy = 1 (28%); elite enemy = 2 (28%); event = 3 (11%); boss = 4; rest/training = 5 (3%)

		for (int i = 0; i < 11; i++)
			for (int j = 0; j < 11; j++)
			{
				int tile = rand() % 100 + 1;

				if (tile < 31)
					this->map[i][j] = 0;

				else if (tile < 59)
					this->map[i][j] = 1;

				else if (tile < 87)
					this->map[i][j] = 2;

				else if (tile < 98)
					this->map[i][j] = 3;
				else
					this->map[i][j] = 5;
			}


		this->map[9][5] = 7;
		this->map[4][5] = 4;

		break;

	case 5:
		//13x13 map
		//empty = 0 (25%); enemy = 1 (25%); elite enemy = 2 (36%); event = 3 (12%); boss = 4; rest/training = 5 (2%)

		for (int i = 0; i < 13; i++)
			for (int j = 0; j < 13; j++)
			{
				int tile = rand() % 100 + 1;

				if (tile < 26)
					this->map[i][j] = 0;

				else if (tile < 51)
					this->map[i][j] = 1;

				else if (tile < 87)
					this->map[i][j] = 2;

				else if (tile < 99)
					this->map[i][j] = 3;
				else
					this->map[i][j] = 5;
			}


		this->map[10][6] = 7;
		this->map[2][6] = 4;

		break;

	}
}

MapGen::MapGen(int lvl)
{
	this->player.load();
	this->lvl = lvl;
	this->generateMap();
}

int getMap(int lvl)
{
	//get the height and width of the map
	int n = 5;
	switch (lvl)
	{
	case 1:
		n = 5;
		break;
	case 2:
		n = 7;
		break;
	case 3:
		n = 9;
		break;
	case 4:
		n = 11;
		break;
	case 5:
		n = 13;
		break;
	}
	return n;
}  

void MapGen::showMap()
{
	//display the map

	int n = getMap(this->lvl);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << this->map[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

int handleEvent(int event, int lvl)
{
	Combat* a = new Combat();
	Event* b = new Event();
	int death = 0;
	switch (event)
	{
	case 0:
		if (death == 0)
			return 0;
		else if (death == 1)
			return 2;
		break;
	case 1:
		death = a->initializecombat(lvl,1);
		if (death == 0)
			return 0;
		else if (death == 1)
			return 2;
		break;
	case 2:
		death = a->initializecombat(lvl, 2);
		if (death == 0)
			return 0;
		else if (death == 1)
			return 2;
		break;
	case 3:
		b->getevent(lvl,1);
		if (death == 0)
			return 0;
		else if (death == 1)
			return 2;
		break;
	case 4:
		death = a->initializecombat(lvl, 3);
		if (death == 0)
			return 1;
		else if (death == 1)
			return 2;
		break;
	case 5:
		b->getevent(lvl,2);
		if (death == 0)
			return 0;
		else if (death == 1)
			return 2;
		break;
	}
}

int MapGen::moveMap()
{
	int bossdefeated = 0;
	int player_pos[2] = { 0,0 };
	int n = getMap(this->lvl);
	std::string input;

	//Display map
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << this->map[i][j] << ' ';
			if (this->map[i][j] == 7)
			{
				player_pos[0] = i; player_pos[1] = j;
			}
		}
		std::cout << std::endl;
	}

	//get movement input
	std::cout << "\nStamina: " << this->player.STAM << " / " << this->player.maxSTAM;
	std::cout << "\nInput (east / west / north / south / exit): ";
	std::cin >> input;
	if (input == "exit")
	{
		auto wnd = GetConsoleWindow();
		PostMessage(wnd, WM_CLOSE, 0, 0);
	}

	//movement

	if ( (input == "west" || input == "w") && player_pos[1] != 0)
	{
		if ((this->map[player_pos[0]][player_pos[1] - 1] != 4 && this->player.STAM > 0) || this->map[player_pos[0]][player_pos[1] - 1] == 4 || this->map[player_pos[0]][player_pos[1] - 1] == 0)
		{
			if(this->map[player_pos[0]][player_pos[1] - 1]!=0 && this->map[player_pos[0]][player_pos[1] - 1]!=4)
				this->player.STAM -= 1;
			this->map[player_pos[0]][player_pos[1]] = 0;
			player_pos[1] -= 1;
			bossdefeated = handleEvent(this->map[player_pos[0]][player_pos[1]], this->lvl);
			this->map[player_pos[0]][player_pos[1]] = 7;
		}
		else
			std::cout << "\nYou lack the stamina to move there. You must fight the boss now.\n";
	}
	else if ( (input == "east" || input == "e") && player_pos[1] != n-1)
	{
		if ((this->map[player_pos[0]][player_pos[1] + 1] != 4 && this->player.STAM > 0) || this->map[player_pos[0]][player_pos[1] + 1] == 4 || this->map[player_pos[0]][player_pos[1] + 1] == 0)
		{
			if (this->map[player_pos[0]][player_pos[1] + 1] != 0 && this->map[player_pos[0]][player_pos[1] + 1] != 4)
				this->player.STAM -= 1;
			this->map[player_pos[0]][player_pos[1]] = 0;
			player_pos[1] += 1;
			bossdefeated = handleEvent(this->map[player_pos[0]][player_pos[1]], this->lvl);
			this->map[player_pos[0]][player_pos[1]] = 7;
		}
		else
			std::cout << "\nYou lack the stamina to move there. You must fight the boss now.\n";
	}

	else if ( (input == "north" || input == "n") && player_pos[0] != 0)
	{
		if ((this->map[player_pos[0] - 1][player_pos[1]] != 4 && this->player.STAM > 0) || this->map[player_pos[0] - 1][player_pos[1]] == 4 || this->map[player_pos[0] - 1][player_pos[1]] == 0)
		{
			if (this->map[player_pos[0] - 1][player_pos[1]] != 0 && this->map[player_pos[0] - 1][player_pos[1]] != 4)
				this->player.STAM -= 1;
			this->map[player_pos[0]][player_pos[1]] = 0;
			player_pos[0] -= 1;
			bossdefeated = handleEvent(this->map[player_pos[0]][player_pos[1]], this->lvl);
			this->map[player_pos[0]][player_pos[1]] = 7;
		}
		else
			std::cout << "\nYou lack the stamina to move there. You must fight the boss now.\n";
	}

	else if ( (input == "south" || input == "s") && player_pos[0] != n-1)
	{
		if ((this->map[player_pos[0] + 1][player_pos[1]] != 4 && this->player.STAM > 0) || this->map[player_pos[0] + 1][player_pos[1]] == 4 || this->map[player_pos[0] + 1][player_pos[1]] == 0)
		{
			if (this->map[player_pos[0] + 1][player_pos[1]] != 0 && this->map[player_pos[0] + 1][player_pos[1]] != 4)
				this->player.STAM -= 1;
			this->map[player_pos[0]][player_pos[1]] = 0;
			player_pos[0] += 1;
			bossdefeated = handleEvent(this->map[player_pos[0]][player_pos[1]], this->lvl);
			this->map[player_pos[0]][player_pos[1]] = 7;
		}
		else
			std::cout << "\nYou lack the stamina to move there. You must fight the boss now.\n";
	}
	
	return bossdefeated;
}