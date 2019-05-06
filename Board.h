#pragma once
class Board
{
public:
	Board();
	~Board();
	void draw();
private:
	struct Node {
		bool occupied;
		int value;
		char player;
	};
	Node board[3][3];
};

