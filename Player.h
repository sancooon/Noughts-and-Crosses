#pragma once
#include <string>
#include <chrono>
#include "Board.h"
#include <conio.h>
#include <iostream>

using std::string;

class Player
{
public:
	Player();
	Player(char side, string name, bool humanP);
	~Player();

	void makeTurn(Board &board);
	
private:
	struct gridCoord{
		int row;
		int col;
	};

	void humanTurn(Board &board);
	void cpuTurn(Board &board);
	gridCoord handleInput();

	

	string name;
	char player;
	bool human;
};

