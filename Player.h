#pragma once
#include <string>
#include <chrono>
#include "Board.h"
#include <conio.h>

using std::string;

class Player
{
public:
	Player();
	Player(char side, string name, bool humanP);
	~Player();

	void makeTurn(Board &board);
	
private:
	void humanTurn(Board &board);
	void cpuTurn(Board &board);
	string name;
	char player;
	bool human;
};

