#include "Board.h"
#include <iostream>

using std::cout;
using std::endl;


Board::Board()
{
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j].occupied = false;
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


Board::~Board()
{
}
