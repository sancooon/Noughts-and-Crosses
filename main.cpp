#include "Board.h"
#include <iostream>;

using namespace std;

void initializePvP();
void initializePvE();
void gameLoop(int mode);

Board board;

int main() {
	cout << "Choose your game-mode\n";
	cout << "1. Player vs Player\n";
	cout << "2. Player vs Computer\n";
	int gameMode;
	cin >> gameMode;

	//initial game
	switch (gameMode)
		{
		case 1:
			initializePvP();
			break;
		case 2:
			initializePvE();
			break;
		default:
			cout << "\nNot a valid input. Game will now exit.\n";
			system("pause");
			exit(0);
	}

	//replay game?
	int choice;
	do {
		system("cls");
		cout << "\nPlay again?";
		cout << "\n1. Yes";
		cout << "\n2. Change Mode";
		cout << "\n3.Quit";
		cin >> choice;
		switch (choice)
		{
		case 1:
			if (gameMode == 1) {
				initializePvP();
			}
			else {
				initializePvE();
			}
			break;
		case 2:
			cout << "Choose your game-mode\n";
			cout << "1. Player vs Player\n";
			cout << "2. Player vs Computer\n";
			cin >> gameMode;
			break;
		case 3:
			exit(0);
			break;
		default:
			cout << "\nNot a valid Input. Try again\n";
			system("pause");
			break;
		}
	} while (choice != 3);

	return 0;
}

void initializePvP() {
	board.reset();
	gameLoop(1);
}

void initializePvE() {
	board.reset();
	gameLoop(2);
}

void gameLoop(int mode) {
	char win;
	do {

		win = board.checkWin();
	} while (win=='n');

	system("cls");
	cout << "Game Over!\n";

	switch (win)
	{
	case 'x':
		cout << "Player " << name << "has won";
		break;
	case 'o':
		cout << "Player " << name << "has won";
		break;
	case 'd':
		cout << "Draw!";
		break;
	}
	
}