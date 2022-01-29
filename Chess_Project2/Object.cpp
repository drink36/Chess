#include "Object.h"
King::King() :Piece(0, 0, 'K', 1) {}
King::King(Position pos, bool Type) : Piece(pos, Type ? 'K' : 'k', Type) {}
King::King(int x, int y, bool Type) : Piece(x, y, Type ? 'K' : 'k', Type) {}
//move
//void King::move(Position pos,bool Type) { Piece::move(pos); }
//void King::move(int x, int y,bool Type) { Piece::move(x, y); }
void King::movePoint(vector<Position>& point, char board[8][8])//提示玩家移動方式
{
	Position ppos = this->getPos();
	Position temp = ppos;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (this->Legal(ppos.x + i, ppos.y + j) && !(i == 0 && j == 0))
			{
				if (board[ppos.y + j][ppos.x + i] == '\0' || (board[ppos.y + j][ppos.x + i] >= 97 && board[ppos.y + j][ppos.x + i] <= 122 && this->getType()) || (board[ppos.y + j][ppos.x + i] >= 65 && board[ppos.y + j][ppos.x + i] <= 90 && (!this->getType())))
				{
					temp.y = ppos.y + j;
					temp.x = ppos.x + i;
					point.push_back(temp);
				}
			}
		}
	}
}
Queen::Queen() :Piece(0, 0, 'Q', 1) {}
Queen::Queen(Position pos, bool Type) : Piece(pos, Type ? 'Q' : 'q', Type) {}
Queen::Queen(int x, int y, bool Type) : Piece(x, y, Type ? 'Q' : 'q', Type) {}
void Queen::movePoint(vector<Position>& point, char board[8][8])
{
	Position ppos = this->getPos();
	Position temp = ppos;
	for (int k = 0; k <= 1; k++)
		for (int i = -1; i <= 1; i += 2)
			for (int j = 1; j <= 7; j++)
			{
				if (this->Legal(ppos.x + i * j * (1 - k), ppos.y + i * j * k))
					if (board[ppos.y + i * j * k][ppos.x + i * j * (1 - k)] == '\0')
					{
						temp.y = ppos.y + i * j * k;
						temp.x = ppos.x + i * j * (1 - k);
						point.push_back(temp);
					}
					else
					{
						if ((board[ppos.y + i * j * k][ppos.x + i * j * (1 - k)] >= 97 && board[ppos.y + i * j * k][ppos.x + i * j * (1 - k)] <= 122 && this->getType()) || (board[ppos.y + i * j * k][ppos.x + i * j * (1 - k)] >= 65 && board[ppos.y + i * j * k][ppos.x + i * j * (1 - k)] <= 90 && (!this->getType())))
						{
							temp.y = ppos.y + i * j * k;
							temp.x = ppos.x + i * j * (1 - k);
							point.push_back(temp);
						}
						break;
					}

				else
					break;
			}
	for (int k = -1; k <= 1; k += 2)
		for (int i = -1; i <= 1; i += 2)
			for (int j = 1; j <= 7; j++)
			{
				if (this->Legal(ppos.x + i * j, ppos.y + j * k))
				{
					if (board[ppos.y + j * k][ppos.x + i * j] == '\0')
					{
						temp.y = ppos.y + j * k;
						temp.x = ppos.x + i * j;
						point.push_back(temp);
					}
					else
					{
						if ((board[ppos.y + j * k][ppos.x + i * j] >= 97 && board[ppos.y + j * k][ppos.x + i * j] <= 122 && this->getType()) || (board[ppos.y + j * k][ppos.x + i * j] >= 65 && board[ppos.y + j * k][ppos.x + i * j] <= 90 && (!this->getType())))
						{
							temp.y = ppos.y + j * k;
							temp.x = ppos.x + i * j;
							point.push_back(temp);
						}
						break;
					}

				}
				else
					break;
			}


}
Rook::Rook() : Piece(0, 0, 'R', 1) {}
Rook::Rook(Position pos, bool Type) : Piece(pos, Type ? 'R' : 'r', Type) {}
Rook::Rook(int x, int y, bool Type) : Piece(x, y, Type ? 'R' : 'r', Type) {}
void Rook::movePoint(vector<Position>& point, char board[8][8])
{
	Position ppos = this->getPos();
	Position temp = ppos;
	for (int k = 0; k <= 1; k ++)
		for (int i = -1; i <= 1; i += 2)
			for (int j = 1; j <= 7; j++)
			{
				if (this->Legal(ppos.x + i * j*(1-k), ppos.y + i * j*k))
					if (board[ppos.y + i * j * k][ppos.x + i * j * (1 - k)] == '\0')
					{
						temp.y = ppos.y + i * j * k;
						temp.x = ppos.x + i * j * (1 - k);
						point.push_back(temp);
					}
					else
					{
						if ((board[ppos.y + i * j * k][ppos.x + i * j * (1 - k)] >= 97 && board[ppos.y + i * j * k][ppos.x + i * j * (1 - k)] <= 122 && this->getType()) || (board[ppos.y + i * j * k][ppos.x + i * j * (1 - k)] >= 65 && board[ppos.y + i * j * k][ppos.x + i * j * (1 - k)] <= 90 && (!this->getType())))
						{
							temp.y = ppos.y + i * j * k;
							temp.x = ppos.x + i * j * (1 - k);
							point.push_back(temp);
						}
						break;
					}
						
				else
					break;
			}
}
Bishop::Bishop() : Piece(0, 0, 'B', 1) {}
Bishop::Bishop(Position pos, bool Type) : Piece(pos, Type ? 'B' : 'b', Type) {}
Bishop::Bishop(int x, int y, bool Type) : Piece(x, y, Type ? 'B' : 'b', Type) {}
void Bishop::movePoint(vector<Position>& point, char board[8][8])
{
	Position ppos = this->getPos();
	Position temp = ppos;
	for(int k=-1;k<=1;k+=2)
		for(int i=-1;i<=1;i+=2)
			for (int j = 1; j <= 7; j++)
			{
				if (this->Legal(ppos.x + i * j, ppos.y + j * k))
				{
					if (board[ppos.y + j * k][ppos.x + i * j] == '\0')
					{
						temp.y = ppos.y + j * k;
						temp.x = ppos.x + i * j;
						point.push_back(temp);
					}
					else
					{
						if ((board[ppos.y + j * k][ppos.x + i * j] >= 97 && board[ppos.y + j * k][ppos.x + i * j] <= 122 && this->getType()) || (board[ppos.y + j * k][ppos.x + i * j] >= 65 && board[ppos.y + j * k][ppos.x + i * j] <= 90 && (!this->getType())))
						{
							temp.y = ppos.y + j * k;
							temp.x = ppos.x + i * j;
							point.push_back(temp);
						}
						break;
					}
						
				}
				else
					break;
			}
			
}
Knight::Knight() : Piece(0, 0, 'N', 1) {}
Knight::Knight(Position pos, bool Type) : Piece(pos, Type ? 'N' : 'n', Type) {}
Knight::Knight(int x, int y, bool Type) : Piece(x, y, Type ? 'N' : 'n', Type) {}
void Knight::movePoint(vector<Position>& point, char board[8][8])
{
	Position ppos = this->getPos();
	Position temp = ppos;
	for (int i = -2; i <= 2; i += 4)
		for (int j = -1; j <= 1; j += 2)
		{
			if (this->Legal(ppos.x + j, ppos.y + i))
				if (board[ppos.y + i][ppos.x + j] == '\0' || (board[ppos.y + i][ppos.x + j] >= 97 && board[ppos.y + i][ppos.x + j] <= 122 && this->getType()) || (board[ppos.y - 1][ppos.x + i] >= 65 && board[ppos.y - 1][ppos.x + i] <= 90 && (!this->getType())))
				{
					temp.y = ppos.y + i;
					temp.x = ppos.x + j;
					point.push_back(temp);
				}
		}
	for (int i = -1; i <= 1; i += 2)
		for (int j = -2; j <= 2; j += 4)
		{
			if (this->Legal(ppos.x + j, ppos.y + i))
				if (board[ppos.y + i][ppos.x + j] == '\0' || (board[ppos.y + i][ppos.x + j] >= 97 && board[ppos.y + i][ppos.x + j] <= 122 && this->getType()) || (board[ppos.y - 1][ppos.x + i] >= 65 && board[ppos.y - 1][ppos.x + i] <= 90 && (!this->getType())))
				{
					temp.y = ppos.y + i;
					temp.x = ppos.x + j;
					point.push_back(temp);
				}
		}
}
Pawn::Pawn() : Piece(0, 0, 'P', 1) {}
Pawn::Pawn(Position pos, bool Type) : Piece(pos, Type ? 'P' : 'p', Type) {}
Pawn::Pawn(int x, int y, bool Type) : Piece(x, y, Type ? 'P' : 'p', Type) {}
void Pawn::movePoint(vector<Position>& point, char board[8][8])
{
	Position ppos = this->getPos();
	Position temp = ppos;
	if (this->getType())
	{
		if (ppos.y == 1)//twice move
		{
			if (board[ppos.y + 1][ppos.x] == '\0')
			{
				temp.y++;
				point.push_back(temp);
				if (board[ppos.y + 2][ppos.x] == '\0')
				{
					temp.y++;
					point.push_back(temp);
				}
			}
		}
		else
		{
			if (this->Legal(ppos.x, ppos.y + 1))
			{
				if (board[ppos.y + 1][ppos.x] == '\0')
				{
					temp.y++;
					point.push_back(temp);
				}
			}
		}
		for (int i = -1; i <= 1; i += 2)
			if (this->Legal(ppos.x + i, ppos.y + 1))
				if (board[ppos.y + 1][ppos.x + i] >= 97 && board[ppos.y + 1][ppos.x + i] <= 122)
				{
					temp.x = ppos.x + i;
					temp.y = ppos.y + 1;
					point.push_back(temp);
				}
	}
	else
	{
		if (ppos.y == 6)//twice move
		{
			if (board[ppos.y - 1][ppos.x] == '\0')
			{
				temp.y--;
				point.push_back(temp);
				if (board[ppos.y - 2][ppos.x] == '\0')
				{
					temp.y--;
					point.push_back(temp);
				}
			}
		}
		else
		{
			if (this->Legal(ppos.x, ppos.y - 1))
			{
				if (board[ppos.y - 1][ppos.x] == '\0')
				{
					temp.y--;
					point.push_back(temp);
				}
			}
		}
		for (int i = -1; i <= 1; i += 2)
			if (this->Legal(ppos.x + i, ppos.y - 1))
				if (board[ppos.y - 1][ppos.x + i] >= 65 && board[ppos.y - 1][ppos.x + i] <= 90)
				{
					temp.x = ppos.x + i;
					temp.y = ppos.y - 1;
					point.push_back(temp);
				}
	}
}