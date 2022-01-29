#pragma once
#include "Board.h"
class Viewer
{
	char board[8][8];
	char outBoard[25][25];
	vector<Position>point;
	string messenge;
	double time = 0;
	void setpointcase(Position pos);
public:
	Viewer();
	void mesSet(string mes);
	void BoardSet(Board temp);
	void pointSet(vector<Position>point);
	void setTime(clock_t time);
	void boardOut();
};