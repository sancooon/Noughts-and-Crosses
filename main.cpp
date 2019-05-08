#include "Board.h"
#include <iostream>;

using namespace std;

int main() {
	Board board;
	board.draw();
	char winner = board.checkWin();
	switch (winner)
	{
	case 'd':
		cout << "\n player O has won";
	default:
		break;
	}
	system("pause");
}