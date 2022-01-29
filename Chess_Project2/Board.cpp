#include "Board.h"
Board::Board()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			board[i][j] = '\0';
	White.resize(16);
	Black.resize(16);
	for (int i = 8; i < 16; i++)
	{
		White[i] = new Pawn(i - 8, 1, true);
		Black[i] = new Pawn(i - 8, 6, false);
	}
	White[0] = new King(4, 0, true);
	Black[0] = new King(4, 7, false);
	White[1] = new Knight(1, 0, true);
	Black[1] = new Knight(1, 7, false);
	White[2] = new Bishop(2, 0, true);
	Black[2] = new Bishop(2, 7, false);
	White[3] = new Queen(3, 0, true);
	Black[3] = new Queen(3, 7, false);
	White[4] = new Rook(0, 0, true);
	Black[4] = new Rook(0, 7, false);
	White[5] = new Bishop(5, 0, true);
	Black[5] = new Bishop(5, 7, false);
	White[6] = new Knight(6, 0, true);
	Black[6] = new Knight(6, 7, false);
	White[7] = new Rook(7, 0, true);
	Black[7] = new Rook(7, 7, false);
	for (int i = 0; i < 16; i++)
	{
		board[White[i]->getPos().y][White[i]->getPos().x] = White[i]->getIcon();
		board[Black[i]->getPos().y][Black[i]->getPos().x] = Black[i]->getIcon();
	}
}
Board::Board(const Board& temp)
{
	*this = temp;
}
bool Board::moveTest(vector<Position>& point, Position pos, bool Type)
{
	point.clear();
	for (int i = 0; i < 16; i++)
	{
		if (Type)
		{
			if (White.size() > i)
			{
				if (White[i]->getPos() == pos)
				{
					White[i]->movePoint(point, board);
					if (White[i]->getIcon() == 'P')
						this->passent(White[i], point, Type);
					if (White[i]->getIcon() == 'K')
						this->castling(point, Type);
					if (point.size() == 0)
					{
						cout << "No legal moves\n";
						return false;
					}
					else if (this->legalMove(i, point, Type))
						return true;
					else
					{
						cout << "King can not commit suicide\n";
						return false;
					}
				}
			}
		}
		else
		{
			if (Black.size() > i)
			{
				if (Black[i]->getPos() == pos)
				{
					Black[i]->movePoint(point, board);
					if (Black[i]->getIcon() == 'p')
						this->passent(Black[i], point, Type);
					if (White[i]->getIcon() == 'k')
						this->castling(point, Type);
					if (point.size() == 0)
					{
						cout << "No legal moves\n";
						return false;
					}
					else if (this->legalMove(i, point, Type))
						return true;
					else
					{
						cout << "King can not commit suicide\n";
						return false;
					}
				}
			}
		}
		if (i == 15)
		{
			cout << "Wrong entry\n";
			return false;
		}
	}
	return true;
}
bool Board::moveTest(vector<Position>& point, int x, int y, bool Type)
{
	Position pos;
	pos.x = x;
	pos.y = y;
	return moveTest(point, pos, Type);
}
bool Board::move(vector<Position>& point, Position begin, Position pos, bool Type)
{
	int temp;
	int R_temp;
	Position tpos;
	vector <Piece*> tempP;
	if (find(point.begin(), point.end(), pos) != point.end())
	{
		for (int i = 0; i < 16; i++)
		{
			if (Type)
			{
				if (White.size() > i)
				{
					if (White[i]->getPos() == begin)
					{
						White[i]->move(pos);
						temp = this->findPiece(White, Black, pos, !Type);
						if (temp != -1)
							Black.erase(Black.begin() + temp);
						if (White[i]->passent == (pos.x - begin.x) && White[i]->passent != 0 && White[i]->getIcon() == 'P')
						{
							tpos = pos;
							tpos.y--;
							temp = this->findPiece(White, Black, tpos, !Type);
							Black.erase(Black.begin() + temp);
							White[i]->passent = 0;
						}
						if (White[i]->getIcon() == 'K')
						{
							if (pos.x == 2 && W_castling[0])
							{
								Position tempR;
								tempR.x = 0;
								tempR.y = 0;
								R_temp = this->findPiece(White, Black, tempR, Type);
								tempR.x = 3;
								White[R_temp]->move(tempR);
							}
							else
							{
								if (pos.x == 6 && W_castling[1])
								{
									Position tempR;
									tempR.x = 7;
									tempR.y = 0;
									R_temp = this->findPiece(White, Black, tempR, Type);
									tempR.x = 5;
									White[R_temp]->move(tempR);
								}
							}
							W_castling[0] = false;
							W_castling[1] = false;
						}
						tempP = this->findPiecebyIcon('p',!Type);
						for (int j = 0; j < tempP.size(); j++)
						{
							if(tempP[j]->getPos().y==4)
								tempP[j]->move(tempP[j]->getPos());
						}
							
						break;
					}
				}
			}
			else
			{
				if (Black.size() > i)
				{
					if (Black[i]->getPos() == begin)
					{
						Black[i]->move(pos);
						temp = this->findPiece(White, Black, pos, !Type);
						if (temp != -1)
							White.erase(White.begin() + temp);
						if (Black[i]->passent == (pos.x - begin.x) && Black[i]->passent != 0 && Black[i]->getIcon() == 'p')
						{
							tpos = pos;
							tpos.y++;
							temp = this->findPiece(White, Black, tpos, !Type);
							White.erase(White.begin() + temp);
							Black[i]->passent = 0;
						}
						if (Black[i]->getIcon() == 'K')
						{
							if (pos.x == 2 && B_castling[0])
							{
								Position tempR;
								tempR.x = 0;
								tempR.y = 7;
								R_temp = this->findPiece(White, Black, tempR, Type);
								tempR.x = 3;
								Black[R_temp]->move(tempR);
							}
							else if (pos.x == 6 && B_castling[1])
							{
								Position tempR;
								tempR.x = 7;
								tempR.y = 7;
								R_temp = this->findPiece(White, Black, tempR, Type);
								tempR.x = 5;
								Black[R_temp]->move(tempR);
							}
							
							B_castling[0] = false;
							B_castling[1] = false;
						}
						tempP = this->findPiecebyIcon('P', !Type);
						for (int j = 0; j < tempP.size(); j++)
						{
							if (tempP[j]->getPos().y == 3)
								tempP[j]->move(tempP[j]->getPos());
						}
							
						break;
					}
				}
			}
		}
	}
	else
		return false;
	this->setBoard();
	return true;
}
void Board::Promote(Position pawnPos,bool Type, char PieceType)
{
	int temp = this->findPiece(White, Black, pawnPos, Type);
	switch (PieceType)
	{
		case'Q':
		{
			if (Type)
			{
				delete White[temp];
				White[temp] = new Queen(pawnPos, Type);
				White[temp]->setMovetime(1);
			}
			else
			{
				delete Black[temp];
				Black[temp] = new Queen(pawnPos, Type);
				Black[temp]->setMovetime(1);

			}
			break;
		}
		case'R':
		{
			if (Type)
			{
				delete White[temp];
				White[temp] = new Rook(pawnPos, Type);
				White[temp]->setMovetime(1);
			}
			else
			{
				delete Black[temp];
				Black[temp] = new Rook(pawnPos, Type);
				Black[temp]->setMovetime(1);
			}
			break;
		}
		case'B':
		{
			if (Type)
			{
				delete White[temp];
				White[temp] = new Bishop(pawnPos, Type);
				White[temp]->setMovetime(1);
			}
			else
			{
				delete Black[temp];
				Black[temp] = new Bishop(pawnPos, Type);
				Black[temp]->setMovetime(1);
			}
			break;
		}
		case'N':
		{
			if (Type)
			{
				delete White[temp];
				White[temp] = new Knight(pawnPos, Type);
				White[temp]->setMovetime(1);
			}
			else
			{
				delete Black[temp];
				Black[temp] = new Knight(pawnPos, Type);
				Black[temp]->setMovetime(1);
			}
			break;
		}
	}
	this->setBoard();
}
void Board::castling(vector<Position>& point,bool Type)
{
	Position temp;
	Position R[2];
	int tempNum;
	if (Type)
	{
		R[0].x = 0;
		R[0].y = 0;
		R[1].x = 7;
		R[1].y = 0;
		if (White[0]->getMovetime() == 0)
		{
			for (int i = 0; i < 2; i++)
			{
				temp = White[0]->getPos();
				tempNum = this->findPiece(White, Black, R[i], Type);
				if (tempNum != -1)
				{
					if (White[tempNum]->getIcon() == 'R' && White[tempNum]->getMovetime() == 0)
					{
						int change = temp.x > R[i].x ? -1 : 1;
						for (int j = 0; j < 3; j++)
						{
							if (this->underAttack(temp, White, Black, Type) || (board[temp.y][temp.x] != '\0' && j != 0))
								break;
							if(j!=2)
								temp.x += change;
							else
							{
								point.push_back(temp);
								W_castling[i] = true;
							}
						}
					}
				}
				else
				{
					continue;
				}
			}
			
		}
	}
	else
	{
		R[0].x = 0;
		R[0].y = 7;
		R[1].x = 7;
		R[1].y = 7;
		if (Black[0]->getMovetime() == 0)
		{
			for (int i = 0; i < 2; i++)
			{
				temp = Black[0]->getPos();
				tempNum = this->findPiece(White, Black, R[i], Type);
				if (tempNum != -1)
				{
					if (Black[tempNum]->getIcon() == 'r' && Black[tempNum]->getMovetime() == 0)
					{
						int change = temp.x > R[i].x ? -1 : 1;
						for (int i = 0; i < 3; i++)
						{
							if (this->underAttack(temp, White, Black, Type) || board[temp.y][temp.x] != '\0')
								break;
							if (i != 2)
								temp.x += change;
							else
							{
								point.push_back(temp);
								B_castling[i] = true;
							}
						}
					}
				}
				else
				{
					continue;
				}
			}

		}
	}
}
void Board::passent(Piece* temp, vector<Position>& point, bool Type)
{
	int tempNum = 0;
	Position t_pos;
	if (Type)
	{
		if (temp->getPos().y == 4)
		{
			for (int i = -1; i <= 1; i += 2)
			{
				if (board[temp->getPos().y][temp->getPos().x + i] == 'p')
				{
					t_pos = temp->getPos();
					t_pos.x += i;
					tempNum = this->findPiece(White, Black, t_pos, !Type);
					if (Black[tempNum]->getMovetime() == 1)
					{
						temp->passent = i;
						t_pos.y += 1;
						point.push_back(t_pos);
					}
				}
			}
		}
	}
	else
	{
		if (temp->getPos().y == 3)
		{
			for (int i = -1; i <= 1; i += 2)
			{
				if (board[temp->getPos().y][temp->getPos().x + i] == 'P')
				{
					t_pos = temp->getPos();
					t_pos.x += i;
					tempNum = this->findPiece(White, Black, t_pos, !Type);
					if (White[tempNum]->getMovetime() == 1)
					{
						temp->passent = i;
						t_pos.y -= 1;
						point.push_back(t_pos);
					}
				}
			}
		}
	}
}
bool Board::legalMove(int tempNum,vector<Position>& point, bool Type)
{
	vector<Piece*> t_White;
	vector<Piece*> t_Black;
	int temp;
	for (int i = 0; i < point.size(); i++)
	{
		t_White.clear();
		t_Black.clear();
		for (int j = 0; j < White.size(); j++)
		{
			t_White.push_back(White[j]->clone());
		}
		for (int j = 0; j < Black.size(); j++)
		{
			t_Black.push_back(Black[j]->clone());
		}
		if (Type)
		{
			t_White[tempNum]->move(point[i]);
			temp = this->findPiece(t_White, t_Black, point[i], !Type);
			if (temp != -1)
				t_Black.erase(t_Black.begin() + temp);
		}
		else
		{
			t_Black[tempNum]->move(point[i]);
			temp = this->findPiece(t_White, t_Black, point[i], !Type);
			if (temp != -1)
				t_White.erase(t_White.begin() + temp);
		}
		if (this->underAttack(Type ? t_White[0]->getPos() : t_Black[0]->getPos(), t_White, t_Black, Type))
		{
			point.erase(point.begin() + i);
			i--;
		}
	}
	if (point.size() != 0)
		return true;
	else
		return false;
}
//Check whether movepos legal
bool Board::underAttack(Position target,vector<Piece*>White, vector<Piece*>Black, bool Type)
{
	char board[8][8];
	this->setTempBoard(board, White, Black);
	vector<Position>point;
	if (Type)
	{
		for (int i = 0; i < Black.size(); i++)
		{
			Black[i]->movePoint(point, board);
			if (find(point.begin(), point.end(), White[0]->getPos()) != point.end())
				return true;
			point.clear();
		}
	}
	else
	{
		for (int i = 0; i < White.size(); i++)
		{
			White[i]->movePoint(point, board);
			if (find(point.begin(), point.end(), Black[0]->getPos()) != point.end())
				return true;
			point.clear();
		}
	}
	return false;
}
bool Board::KingunderAttack(bool Type)
{
	return this->underAttack(Type ? White[0]->getPos() : Black[0]->getPos(), White, Black, Type);
}
//Whether Piece can move
bool Board::Checkmate(bool Type)
{
	vector<Position> point;
	for (int i = 0; i < 16; i++)
	{
		if (Type)
		{
			if (White.size() > i)
			{
				White[i]->movePoint(point, board);
				if (White[i]->getIcon() == 'P')
					this->passent(White[i], point, Type);
				if (this->legalMove(i, point, Type))
				{
					return false;
				}
			}
		}
		else
		{
			if (Black.size() > i)
			{
				Black[i]->movePoint(point, board);
				if (Black[i]->getIcon() == 'p')
					this->passent(Black[i], point, Type);
				if (this->legalMove(i, point, Type))
				{
					return false;
				}
			}
		}
		point.clear();
	}
	return true;
}
bool Board::SpceilPawn()
{
	if (White.size() == 1 && Black.size() == 1)
		return true;
	if (White.size() <= 2 && Black.size() <= 2)
	{
		if (White.size() == 1)
		{
			if (Black[1]->getIcon() == 'b' || Black[1]->getIcon() == 'k')
				return true;
		}
		else if(Black.size() == 1)
		{
			if (White[1]->getIcon() == 'B' || White[1]->getIcon() == 'K')
				return true;
		}
		else
		{
			if (White[1]->getIcon() == 'B' && Black[1]->getIcon() == 'b' && (White[1]->getPos().x - Black[1]->getPos().x) % 2 == 0 && (White[1]->getPos().y - Black[1]->getPos().y) % 2 == 0)
				return true;
		}
	}
	return false;
	
}
//find posisition of piece
int Board::findPiece(vector<Piece*>White, vector<Piece*>Black,Position pos, bool Type)
{
	for (int i = 0; i < 16; i++)
	{
		if (Type)
		{
			if (White.size() > i)
			{
				if (White[i]->getPos() == pos)
				{
					return i;
					break;
				}
			}
		}
		else
		{
			if (Black.size() > i)
			{
				if (Black[i]->getPos() == pos)
				{
					return i;
					break;
				}
			}
		}
	}
	return -1;
}
char Board::findPieceIcon(Position pos)
{
	return board[pos.y][pos.x];
}
vector<Piece*> Board::findPiecebyIcon(char Icon,bool Type)
{
	vector<Piece*> temp;
	if (Type)
	{
		for (int i = 0; i < White.size(); i++)
		{
			if (White[i]->getIcon() == Icon)
			{
				temp.push_back(White[i]);
			}
		}
	}
	else
	{
		for (int i = 0; i < Black.size(); i++)
		{
			if (Black[i]->getIcon() == Icon)
			{
				temp.push_back(Black[i]);
			}
		}
	}
	return temp;
}
void Board::setTempBoard(char Board[8][8], vector<Piece*>White, vector<Piece*>Black)
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			Board[i][j] = '\0';
	for (int i = 0; i < White.size(); i++)
		Board[White[i]->getPos().y][White[i]->getPos().x] = White[i]->getIcon();
	for (int i = 0; i < Black.size(); i++)
		Board[Black[i]->getPos().y][Black[i]->getPos().x] = Black[i]->getIcon();
}
void Board::setBoard()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			board[i][j] = '\0';
	for (int i = 0; i < White.size(); i++)
		board[White[i]->getPos().y][White[i]->getPos().x] = White[i]->getIcon();
	for(int i=0;i<Black.size();i++)
		board[Black[i]->getPos().y][Black[i]->getPos().x] = Black[i]->getIcon();
}
void Board::getBoard(char Board[8][8])
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			Board[i][j] = this->board[i][j];
}
//Board& Board::operator=(Board temp)
//{
//	*this = temp;
//	return *this;
//}
//bool Board::move(vector<Position>& point, , int x, int y, bool Type)
//{
//
//}