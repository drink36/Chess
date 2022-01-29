#pragma once
#include "Position.h"
class Piece
{
	Position pos;
	int isMove = 0;
	bool white = true;//1:white,0:black
	char icon = '\0';
public:
	int passent = 0;
	Piece();
	virtual ~Piece() {};
	Piece(Position pos, char icon, bool white);
	Piece(int x, int y, char icon, bool white);
	virtual void movePoint(vector<Position>& point, char board[8][8]);
	virtual Piece* clone() { return new Piece(*this); };
	void move(Position pos);
	void move(int x, int y);
	void setPos(Position pos);
	void setMovetime(int temp);
	char getIcon();
	bool getType();
	bool Legal(Position);
	bool Legal(int x, int y);
	int getMovetime();
	Position getPos();

};