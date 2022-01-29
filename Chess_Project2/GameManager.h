#pragma once
#include "PlayerObject.h"
#include "Viewer.h"
class GameManager
{
	vector<Board> record;
	vector<vector<Board> >log;
	Player* players[2];
	Board board;
	Board original;
	Viewer viewer;
public:
	GameManager();
	void start();
	void teststart();
	void save();
	void read();
	bool minustime(double& o_time,clock_t start, clock_t end);
	void score();
	void endGame();
	void logOut();
	void logBoardout(int x);
	bool undo();

};