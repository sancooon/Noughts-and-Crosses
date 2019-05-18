#include "Board.h"
#include <iostream>

using std::cout;
using std::endl;


Board::Board()
{
	//initialize board so it is empty and not occupied
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j].occupied = false;
			board[i][j].value = 0;
		}
	}

}

void Board::draw() {
	char index = 'A';
	//draw board
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			//if position is occupied, display X or O. Otherwise show the key needed to play that position
			if (board[i][j].occupied) {
				cout << board[i][j].player<<'|';
			}
			else {
				cout << index << '|';
			}

			index++;
		}

		//new line for the new line of the board
		cout << endl;

		//if it is not the end of the board, print the horizontal separators
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

		//return if player has won
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

		//return if player has won
		if (sum == 15) {
			return 'x';
		}
		else if (sum == 3) {
			return 'o';
		}
	}
	
	//check for diagonal wins and return if won
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
			//no one has won. empty space available return not over
			if (!board[i][j].occupied) {
				return 'n';
			}
		}
	}

	//no spaces left, nobody won return draw
	return 'd';
}

void Board::makeTurn(char player, int row, int collumn) {
	int iValue;

	//decide the value to associate with the symbon
	if (player == 'O') {
		iValue = 1;
	}
	else {
		iValue = 5;
	}

	//occopy the selected space
	board[row][collumn].occupied = true;
	board[row][collumn].value = iValue;
	board[row][collumn].player = player;
}

void Board::reset() {
	//reset the board back to its initial condition
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j].occupied = false;
			board[i][j].value = 0;
			board[i][j].player = NULL;
		}
	}
}

bool Board::isEmpty(int row, int col) {
	//returns whether or not the specified position is filled
	if (board[row][col].occupied == true) {
		return false;
	}
	else {
		return true;
	}
}

int Board::rowValue(int row) {
	//returns the total value of the specified row
	return board[row][0].value + board[row][1].value + board[row][2].value;
}

int Board::colValue(int col) {
	//returns total value of specified collumn
	return board[0][col].value + board[1][col].value + board[2][col].value;
}

int Board::value(int row, int col) {
	//returns value of specified position
	return board[row][col].value;
}

Board::~Board()
{
}
