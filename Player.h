#pragma once
#include <string>
#include <chrono>
#include "Board.h"
#include <conio.h>
#include <iostream>
#include "KeyMap.h"
#include <map>
#include <cstdlib>
#include <ctime>

using std::string;

class Player
{
public:
	Player();
	Player(char side, string name, bool humanP);
	~Player();

	string getName();
	void makeTurn(Board &board);
	
private:

	void humanTurn(Board &board);
	void cpuTurn(Board &board);
	gridCoord handleInput();

	

	string name;
	char player;
	bool human;
};

