#include "Board.h"
#include <iostream>
#include "Player.h"
#include "KeyMap.h"

using namespace std;

void initializePvP();
void initializePvE();
void gameLoop(int mode);

Board board;
Player *player1;
Player *player2;

int main() {
	//initialize essential resources
	initializeKeyBind();
	srand(static_cast<int>(time(NULL)));

	//display menu options and get user input
	cout << "Choose your game-mode\n";
	cout << "1. Player vs Player\n";
	cout << "2. Player vs Computer\n";
	int gameMode;
	cin >> gameMode;

	//first game
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
		cout << "\n3.Quit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			board.reset();
			if (gameMode == 1) {
				gameLoop(1);
			}
			else {
				gameLoop(2);
			}
			break;
		case 2:
			cout << "Choose your game-mode\n";
			cout << "1. Player vs Player\n";
			cout << "2. Player vs Computer\n";
			cin >> gameMode;
			if (gameMode == 1) {
				initializePvP();
			}
			else {
				initializePvE();
			}
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
	system("cls");
	char temp[256];
	string name;

	cout << "\nPlayer 1, enter your name:\n";
	cin.getline(temp, 256);
	name = temp;
	player1 = new Player('X', name, true);

	cout << "\nPlayer 2, enter your name:\n";
	cin.getline(temp, 256);
	name = temp;
	player2 = new Player('O', name, true);
	gameLoop(1);
}

void initializePvE() {
	board.reset();
	system("cls");
	char temp[256];
	string name;
	
	cout << "Player 1, enter your name:\n";
	cin.getline(temp, 256);
	name = temp;
	player1 = new Player('X', name, true);
	player2 = new Player('O', "CPU", false);
	gameLoop(2);
}

void gameLoop(int mode) {
	char win;
	do {
		//update drawn board and make p1's turn
		system("cls");
		board.draw();
		cout << "\n\n" << player1->getName() << "'s Turn:\n";
		player1->makeTurn(board);
		//check for victory
		if (board.checkWin() != 'n') {
			break;
		}

		//print ui only if player 2 is human
		if (mode == 1) {
			//draw UI for player 2
			system("cls");
			board.draw();
			cout << "\n\n" << player2->getName() << "'s Turn:\n";
		}
		
		//make player 2's turn
		player2->makeTurn(board);

		if (board.checkWin() != 'n') {
			break;
		}

	} while (true); // loop game indefinately untill broken by condition

	//loop over. therefore game has ended
	system("cls");
	cout << "Game Over!\n";
	win = board.checkWin();

	switch (win)
	{
	case 'x':
		cout << "Player " << player1->getName() << " has won\n";
		break;
	case 'o':
		cout << "Player " << player2->getName() << "has won\n";
		break;
	case 'd':
		cout << "Draw!\n";
		break;
	}
	
	system("pause");
}