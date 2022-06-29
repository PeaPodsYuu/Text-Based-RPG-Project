#pragma once
#include "Player.h"
#include <fstream>
class Event
{
	Player player;
public:
	Event();
	void getevent(int, int);
	void getitem(int);
	int generateevent(int);
};

