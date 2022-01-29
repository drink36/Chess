#pragma once
#include "Player.h"
class Human :public Player
{
	bool White;
	vector<Position> points;
public:
	Human();
	Human(bool Type);
	virtual	int Gameresult(Board board);
	virtual bool check(Board board);
	virtual bool legalPromte(Board board, Position pos);
	virtual bool Movetest(Board& board, Position outFromPos);
	virtual bool OnMove(Board& board, Position outFromPos, Position outToPos);
	virtual void OnPromote(Board& board, Position PawnPos,char Type); 
	virtual void outPoint(vector<Position>& point);
	virtual string outType();
};