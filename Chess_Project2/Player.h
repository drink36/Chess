#pragma once
#include "Board.h"
class Player
{
	int Wintime = 0;
public:
	virtual	int Gameresult(Board board) = 0;
	virtual bool check(Board board) = 0;
	virtual bool Movetest(Board& board, Position outFromPos) = 0;
	virtual bool OnMove(Board& board, Position outFromPos,Position outToPos) = 0;
	virtual bool legalPromte(Board board, Position pos) = 0;
	virtual void OnPromote(Board& board, Position PawnPos,char Type) = 0;
	virtual void outPoint(vector<Position>& point) = 0;
	virtual string outType() = 0;
	virtual void Win(void) { this->Wintime++; };
	virtual int Wintimes(void) { return this->Wintime; };
};