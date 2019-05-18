#include "Player.h"


using namespace std;
//use an existing map object
extern map<char, gridCoord> keyBinds;

Player::Player()
{
}

Player::Player(char side, string playerName, bool humanP) {
	//initialize the player with a side, name and if it is human
	name = playerName;
	player = side;
	human = humanP;
}

void Player::makeTurn(Board &board) {
	//call the correct turn making process depeding on whether the player is human
	if (human) {
		humanTurn(board);
	}
	else {
		cpuTurn(board);
	}
}

void Player::humanTurn(Board &board) {
	//record time at start of turn
	auto timeStart = chrono::steady_clock::now();
	int eSeconds;
	do {

		//input handling. if player hits keyboard, game will record pressed key.
		if (_kbhit()) {
			//get grid coord
			gridCoord placeMove = handleInput();

			//if it is a valid input and board is empty at specified position
			if (placeMove.row != -1 && board.isEmpty(placeMove.row, placeMove.col)) {
				//if returned the reset key
				if (placeMove.row == -2) {
					board.reset();
					break;
				}
				else { //otherwise play the move and end turn
					board.makeTurn(player, placeMove.row, placeMove.col);
					break;
				}
			}
			else {//display error and continue
					cout << "\nInvalid Input. Try again\n";
			}

		}//end if

		//calculate delta time since start of turn
		auto timeNow = chrono::steady_clock::now();
		//get elapsed time since start of turn
		eSeconds = chrono::duration_cast<chrono::duration<int>>(timeNow-timeStart).count();

	} while (eSeconds < 10); // 10sec timer

}

void Player::cpuTurn(Board &board) {
	//////////////////////////////////////////
	////prioritize winning first          ////
	////before trying to draw             ////
	//////////////////////////////////////////

	//check rows and col for potential victory
	for (int i = 0; i < 3; i++) {
		//if cpu has a row where it has claimed 2 spots and the third is free
		if (board.rowValue(i) == 10) {
			if (board.isEmpty(i, 0)) {
				board.makeTurn(player, i, 0);
				return;
			}
			else if (board.isEmpty(i, 1)) {
				board.makeTurn(player, i, 1);
				return;
			}
			else {
				board.makeTurn(player, i, 2);
				return;
			}
		}//end if

		//if cpu has a collumn where it has claimed 2 spots and third is free
		if (board.colValue(i) == 10) {
			if (board.isEmpty(0, i)) {
				board.makeTurn(player, 0, i);
				return;
			}
			else if (board.isEmpty(1, i)) {
				board.makeTurn(player, 1, i);
				return;
			}
			else {
				board.makeTurn(player, 2, i);
				return;
			}
		}//end if

	}//end for

	//check if can win by diagonal
	if (board.value(0, 0) + board.value(1, 1) + board.value(2, 2) == 10) {
		if (board.isEmpty(0, 0)) {
			board.makeTurn(player, 0, 0);
			return;
		}
		else if (board.isEmpty(1, 1)) {
			board.makeTurn(player, 1, 1);
			return;
		}
		else {
			board.makeTurn(player, 2, 2);
			return;
		}
	}//end if

	//check if can win by other diagonal
	if (board.value(0, 2) + board.value(1, 1) + board.value(2, 0) == 10){
		if (board.isEmpty(0, 2)) {
			board.makeTurn(player, 0, 2);
			return;
		}
		else if (board.isEmpty(1, 1)) {
			board.makeTurn(player, 1, 1);
			return;
		}
		else {
			board.makeTurn(player, 2, 0);
			return;

		}
	}

	///////////////////////////////////////
	////check if going to lose         ////
	////next turn and try draw         ////
	///////////////////////////////////////

	//checking for imminemt loss on horizontal or vertical
	for (int i = 0; i < 3; i++) {
		if (board.rowValue(i) == 2) {
			if (board.isEmpty(i, 0)) {
				board.makeTurn(player, i, 0);
				return;
			}
			else if (board.isEmpty(i, 1)) {
				board.makeTurn(player, i, 1);
				return;
			}
			else {
				board.makeTurn(player, i, 2);
				return;
			}
		}//end if

		if (board.colValue(i) == 2) {
			if (board.isEmpty(0, i)) {
				board.makeTurn(player, 0, i);
				return;
			}
			else if (board.isEmpty(1, i)) {
				board.makeTurn(player, 1, i);
				return;
			}
			else {
				board.makeTurn(player, 2, i);
				return;
			}
		}//end if
	}//end for

	//now check for loss on the 2 diagonals
	if (board.value(0, 0) + board.value(1, 1) + board.value(2, 2) == 2) {
		if (board.isEmpty(0, 0)) {
			board.makeTurn(player, 0, 0);
			return;
		}
		else if (board.isEmpty(1, 1)) {
			board.makeTurn(player, 1, 1);
			return;
		}
		else {
			board.makeTurn(player, 2, 2);
			return;
		}
	}

	if (board.value(0, 2) + board.value(1, 1) + board.value(2, 0) == 2) {
		if (board.isEmpty(0, 2)) {
			board.makeTurn(player, 0, 2);
			return;
		}
		else if (board.isEmpty(1, 1)) {
			board.makeTurn(player, 1, 1);
			return;
		}
		else {
			board.makeTurn(player, 2, 0);
			return;
		}
	}

	//if cpu is not about to win and player is not about to win then
	//randomize the computer's turn
	int row;
	int col;
	//keep randomizing position until an unfilled spot is found
	do {
		row = rand() % 3;
		col = rand() % 3;
	} while (!board.isEmpty(row, col));

	board.makeTurn(player, row, col);
}

gridCoord Player::handleInput() {
	//get the value of the button press
	char buttonPress = _getch();
	//if player pressed reset key then return row value of -2
	if (buttonPress == 'r' || buttonPress == 'R') {
		return { -2,0 };
	}
	else if (buttonPress == 'q' || buttonPress == 'Q') { // player pressed quit button so exit game
		exit(0);
	}
	else if ((buttonPress >= 'a' && buttonPress <= 'i') || (buttonPress >= 'A' && buttonPress <='I')){ //if player pressed button within bounds of the game field. return mapped key
		return keyBinds[buttonPress];
	}
	else { //otherwise out of bounds keypress, return row val of -1
		return { -1,0 };
	}
}

string Player::getName() {
	//return name of player
	return name;
}

Player::~Player()
{
}
