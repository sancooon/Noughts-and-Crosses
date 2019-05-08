#pragma once
class Board
{
public:
	Board();
	~Board();
	void draw();
	char checkWin();
	void makeTurn(char player, int row, int collumn);
	void reset();
private:
	struct Node {
		bool occupied;
		int value;
		char player;
	};
	Node board[3][3];
};

