#include "PlayerObject.h"
Human::Human()
{
	this->White = false;
}
Human::Human(bool Type)
{
	this->White = Type;
	this->points.clear();
}
//1:Die,0:Keep,-1:pawn
int Human::Gameresult(Board board)
{
	if (board.Checkmate(White))
	{
		if (board.KingunderAttack(White))
			return 1;
		else
		{
			return -1;
		}
	}
	else if (board.SpceilPawn())
		return -1;
	else
		return 0;
}
bool Human::check(Board board)
{
	if (board.KingunderAttack(White))
		return true;
	else
		return false;
}
bool Human::legalPromte(Board board, Position pos)
{
	if (White)
	{
		if (board.findPieceIcon(pos) == 'P' && pos.y == 7)
			return true;
	}
	else
	{
		if (board.findPieceIcon(pos) == 'p' && pos.y == 0)
			return true;
	}
	return false;
}
bool Human::Movetest(Board& board, Position outFromPos)
{
	if (board.moveTest(points, outFromPos, White))
		return true;
	else
		return false;
}
bool Human::OnMove(Board& board, Position outFromPos, Position outToPos)
{
	if (board.move(points, outFromPos, outToPos, White))
	{
		/*if ((White && board.findPieceIcon(outToPos) == 'P' && outToPos.y == 7) || (!White && board.findPieceIcon(outToPos) == 'p' && outToPos.y == 0))
		{
			OnPromote(board, outToPos);
		}*/
		return true;
	}
	else
		return false;
}
void Human::OnPromote(Board& board, Position PawnPos,char Type)
{
	/*char type = '\0';
	cout << "Choose which chess piece you want to be promoted\n(Q) Queen (B) Bishop (R) Rook (N) Knight\n";
	do
	{
		cin >> type;
	} while (type != 'q' && type != 'Q' && type != 'b' && type != 'B' && type != 'r' && type != 'R' && type != 'n' && type != 'N');
	board.Promote(PawnPos, White, type);*/
	board.Promote(PawnPos, White, Type);
}
void Human::outPoint(vector<Position>& point)
{
	point = this->points;
}
string Human::outType()
{
	return White ? "White" : "Black";
}