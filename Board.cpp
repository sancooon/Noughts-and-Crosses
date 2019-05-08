#include "Board.h"
#include <iostream>

using std::cout;
using std::endl;


Board::Board()
{
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j].occupied = false;
			board[i][j].value = 0;
		}
	}

}

void Board::draw() {
	char index = 'A';
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j].occupied) {
				cout << board[i][j].player<<'|';
			}
			else {
				cout << index << '|';
			}

			index++;
		}

		cout << endl;

		if (i == 2) {
			break;
		}
		else {
			cout << "_ _ _\n";
		}
	}

	
}

char Board::checkWin() {
	//check board for horizontal wins
	for (int i = 0; i < 3; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += board[i][j].value;
		}

		if (sum == 15) {
			return 'x';
		}
		else if (sum == 3) {
			return 'o';
		}
	}

	//check board for vertical wins
	for (int i = 0; i < 3; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += board[j][i].value;
		}

		if (sum == 15) {
			return 'x';
		}
		else if (sum == 3) {
			return 'o';
		}
	}
	
	//check for diagonal wins
	int sum = board[0][0].value + board[1][1].value + board[2][2].value;
	if (sum == 15) {
		return 'x';
	}
	else if (sum == 3) {
		return 'o';
	}

	//other diagonal
	sum = board[2][0].value + board[1][1].value + board[0][2].value;
	if (sum == 15) {
		return 'x';
	}
	else if (sum == 3) {
		return 'o';
	}

	//check for draw
	bool tie = true;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			//no one has won. empty space available
			if (!board[i][j].occupied) {
				return 'n';
			}
		}
	}

	//no spaces left, nobody won return draw
	return 'd';
}

Board::~Board()
{
}
