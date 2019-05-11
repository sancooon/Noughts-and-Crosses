#include "Player.h"

using namespace std;


Player::Player()
{
}

Player::Player(char side, string playerName, bool humanP) {
	name = playerName;
	player = side;
	human = humanP;
}

void Player::makeTurn(Board &board) {
	if (human) {
		humanTurn(board);
	}
	else {
		cpuTurn(board);
	}
}

void Player::humanTurn(Board &board) {
	auto timeStart = chrono::steady_clock::now();
	int eSeconds;
	do {

		//input handling
		if (_kbhit()) {
			//get grid coord
			gridCoord placeMove = handleInput();

			//if it is a valid input and board is empty at specified position
			if (placeMove.row != -1 && board.isEmpty(placeMove.row, placeMove.col)) {

				board.makeTurn(player, placeMove.row, placeMove.col);
			}
			else {//display error and continue
					cout << "\nInvalid Input. Try again\n";
			}

		}//end if

		//calculate delta time since start of turn
		auto timeNow = chrono::steady_clock::now();
		eSeconds = chrono::duration_cast<chrono::duration<int>>(timeStart - timeNow).count();

	} while (eSeconds < 10); // 10sec timer

}

Player::~Player()
{
}
