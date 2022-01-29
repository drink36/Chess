#include "Piece.h"
Piece::Piece()
{
	pos.x = 0;
	pos.y = 0;
	icon = '\0';
}
Piece::Piece(Position pos,char icon,bool white)
{
	this->pos = pos;
	this->icon = icon;
	this->white = white;
}
Piece::Piece(int x, int y,char icon,bool white)
{
	pos.x = x;
	pos.y = y;
	this->icon = icon;
	this->white = white;
}
void Piece::move(Position pos)
{
	this->isMove++;
	this->pos = pos;
}
void Piece::move(int x,int y)
{
	this->isMove++;
	pos.x = x;
	pos.y = y;
}
void Piece::movePoint(vector<Position>& point, char board[8][8])
{
	
}
void Piece::setPos(Position pos)
{
	this->pos = pos;
}
void Piece::setMovetime(int temp)
{
	this->isMove = temp;
}
char Piece::getIcon()
{
	return this->icon;
}
bool Piece::getType()
{
	return this->white;
}
int Piece::getMovetime()
{
	return this->isMove;
}
bool Piece::Legal(Position pos)
{
	if (pos.x > 7 || pos.y > 7 || pos.x < 0 || pos.y < 0)
	{
		return false;
	}
	return true;
}
bool Piece::Legal(int x, int y)
{
	if (x > 7 || y > 7 || x < 0 || y < 0)
	{
		return false;
	}
	return true;
}
Position Piece::getPos()
{
	return pos;
}