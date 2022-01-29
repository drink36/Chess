#include "Viewer.h"
Viewer::Viewer()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			board[i][j] = '\0';
	}
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 25; j++)
			outBoard[i][j] = ' ';
	point.clear();
}
void Viewer::mesSet(string mes)
{
	messenge = mes;
}
void Viewer::BoardSet(Board temp)
{

	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 25; j++)
			outBoard[i][j] = ' ';
	point.clear();
	temp.getBoard(board);
}
void Viewer::pointSet(vector<Position>point)
{
	this->point = point;
}
void Viewer::setTime(clock_t time)
{
	this->time = time;
}
void Viewer::boardOut()
{
	system("cls");
	for (int i = 0; i < 8; i++)
		outBoard[0][i * 3 + 2] = 'a' + i;
	for (int i = 0; i < 8; i++)
		outBoard[i * 3 + 2][0] = '1' + i;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] != '\0')
			{
				outBoard[i * 3 + 2][j * 3 + 2] = board[i][j];
			}
		}
	for (int i = 0; i < point.size(); i++)
	{
		setpointcase(point[i]);
	}
	for (int i = 24; i >= 0; i--)
	{
		for (int j = 0; j < 25; j++)
			cout << outBoard[i][j];
		cout << '\n';
	}
	cout << messenge;
	messenge = "\0";
	cout << "You have " << time << " s\n";
}
void Viewer::setpointcase(Position pos)
{
	for(int i=-1;i<=1;i++)
		for (int j = -1; j <= 1; j++)
		{
			if (!(i == 0 && j == 0))
			{
				if (board[pos.y][pos.x] != '\0')
					outBoard[pos.y * 3 + 2 + i][pos.x * 3 + 2 + j] = 'X';
				else
					outBoard[pos.y * 3 + 2 + i][pos.x * 3 + 2 + j] = 'O';
			}
		}
}