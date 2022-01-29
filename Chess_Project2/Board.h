#pragma once
#include "Object.h"
class Board
{
	vector<Piece*>White;
	vector<Piece*>Black;
	bool B_castling[2] = { false,false };
	bool W_castling[2] = { false ,false };
	char board[8][8];
	int findPiece(vector<Piece*>White, vector<Piece*>Black, Position pos, bool Type);
	vector<Piece*> findPiecebyIcon(char Icon,bool Type);
	bool underAttack(Position target, vector<Piece*>White, vector<Piece*>Black, bool Type);
	void passent(Piece* temp, vector<Position>& point, bool Type);
	void castling(vector<Position>& point,bool Type);
	void setTempBoard(char Board[8][8], vector<Piece*>White, vector<Piece*>Black);
	void setBoard();
public:
	Board();
	Board(const Board& temp);
	bool moveTest(vector<Position>& point, Position pos, bool Type);
	bool moveTest(vector<Position>& point, int x, int y, bool Type);
	bool move(vector<Position>& point, Position begin, Position pos, bool Type);
	bool legalMove(int tempNum,vector<Position>& point,bool Type);
	bool KingunderAttack(bool Type);
	bool Checkmate(bool Type);
	bool SpceilPawn();
	char findPieceIcon(Position pos);
	void Promote(Position pawnPos,bool Type,char PieceType);
	void getBoard(char Board[8][8]);
	void outFile();
	//Board& operator=(Board temp);
	/*bool move(vector<Position>& point,int x, int y, bool Type);*/
};
