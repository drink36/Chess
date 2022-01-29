#pragma once
#include "Piece.h"
class King :public Piece
{
public:
	King();
	King(Position pos,bool Type);
	King(int x, int y, bool Type);
	virtual Piece* clone() { return new King(*this); };
	//move
	virtual void movePoint(vector<Position>& point, char board[8][8]);//提示玩家移動方式
};
class Queen :public Piece
{
public:
	Queen();
	Queen(Position pos, bool Type);
	Queen(int x, int y, bool Type);
	virtual Piece* clone() { return new Queen(*this); };
	virtual void movePoint(vector<Position>& point, char board[8][8]);
};
class Rook :public Piece
{
public:
	Rook();
	Rook(Position pos, bool Type);
	Rook(int x, int y, bool Type);
	virtual Piece* clone() { return new Rook(*this); };
	virtual void movePoint(vector<Position>& point, char board[8][8]);
};
class Bishop :public Piece
{
public:
	Bishop();
	Bishop(Position pos, bool Type);
	Bishop(int x, int y, bool Type);
	virtual Piece* clone() { return new Bishop(*this); };
	virtual void movePoint(vector<Position>& point, char board[8][8]);
};
class Knight :public Piece
{
public:
	Knight();
	Knight(Position pos, bool Type);
	Knight(int x, int y, bool Type);
	virtual Piece* clone() { return new Knight(*this); };
	virtual void movePoint(vector<Position>& point, char board[8][8]);
};
class Pawn :public Piece
{
public:
	Pawn();
	Pawn(Position pos, bool Type);
	Pawn(int x, int y, bool Type);
	virtual Piece* clone() { return new Pawn(*this); };
	/*virtual void move(Position pos);
	virtual void move(int x, int y);*/
	virtual void movePoint(vector<Position>& point, char board[8][8]);
};