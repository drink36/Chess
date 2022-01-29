#include "GameManager.h"
GameManager::GameManager()
{
	players[0] = new Human(true);
	players[1] = new Human(false);
	record.clear();
}
void GameManager::start()
{
	double dead[2] = { 20,20 };
	clock_t t_start, t_end;
	t_start = clock();
	t_end = clock();
	bool flags = true;
	char Manage = '\0';
	char type = '\0';
	Position begin;
	Position end;
	vector<Position>points;
	t_start = t_start - t_end;
	while(flags)
	{
		
		for (int i = 0; i < 2; i++)
		{
			viewer.setTime(dead[i]);
			record.push_back(board);
			cout << players[i]->outType() << " turn\n";
			do
			{
				t_start = clock();
				viewer.BoardSet(board);
				viewer.boardOut();
				if (players[i]->check(board))
					cout << "You are be checkmated\n";
				cout << "Please choose the action you want\n(F) Save (U) Undo (S) Surrender (M) Move \n";
				cin >> Manage;
				if (Manage == 'F' || Manage == 'f')
					this->save();
				if (Manage == 'U' || Manage == 'u')
					if (!this->undo())
						viewer.mesSet("You can't undo\n");
				t_end = clock();
				if (!this->minustime(dead[i], t_start, t_end))
				{
					cout << players[i > 0 ? 0 : 1]->outType() << " Win\n";
					players[i > 0 ? 0 : 1]->Win();
					this->endGame();
					system("pause");
					return;
				}
			} while (Manage != 'S' && Manage != 's' && Manage != 'M' && Manage != 'm');
			if (Manage == 'M' || Manage == 'm')
			{
				t_start = clock();
				do
				{
					cout << "Please entry chess coordinate you wnat to choose(use Algebraic notation)\n";
					cin >> begin;
				} while (!players[i]->Movetest(board, begin));
				t_end = clock();
				if (!this->minustime(dead[i], t_start, t_end))
				{
					cout << players[i > 0 ? 0 : 1]->outType() << " Win\n";
					players[i > 0 ? 0 : 1]->Win();
					this->endGame();
					system("pause");
					return;
				}
				players[i]->outPoint(points);
				viewer.pointSet(points);
				viewer.boardOut();
				t_start = clock();
				do
				{
					cout << "Please entry chess coordinate you wnat to go(use Algebraic notation)\n";
					cin >> end;
				} while (!players[i]->OnMove(board, begin, end));
				t_end = clock();
				if (!this->minustime(dead[i], t_start, t_end))
				{
					cout << players[i > 0 ? 0 : 1]->outType() << " Win\n";
					players[i > 0 ? 0 : 1]->Win();
					this->endGame();
					system("pause");
					return;
				}
				if (players[i]->legalPromte(board, end))
				{
					t_start = clock();
					type = '\0';
					do
					{
						cout << "Please entry chess you want to Promote\n(Q) Queen (B) Bishop (R) Rook (N) Knight\n";
						cin >> type;

					} while (type != 'q' && type != 'Q' && type != 'b' && type != 'B' && type != 'r' && type != 'R' && type != 'n' && type != 'N');
					t_end = clock();
					if (!this->minustime(dead[i], t_start, t_end))
					{
						cout << players[i > 0 ? 0 : 1]->outType() << " Win\n";
						players[i > 0 ? 0 : 1]->Win();
						this->endGame();
						system("pause");
						return;
					}
					players[i]->OnPromote(board, end, type);
				}
				points.clear();
				if (players[i > 0 ? 0 : 1]->Gameresult(board) != 0)
				{
					int result = players[i > 0 ? 0 : 1]->Gameresult(board);
					if (result == 1)
					{
						cout << players[i]->outType() << " Win\n";
						players[i]->Win();
					}
					else if (result == -1)
						cout << "pawn\n";
					else
						cout << "error\n";
					this->endGame();
					system("pause");
					return;
				}
			}
			else if(Manage == 'S' || Manage == 's')
			{
				cout << players[i > 0 ? 0 : 1]->outType() << " Win\n";
				players[i > 0 ? 0 : 1]->Win();
				this->endGame();
				system("pause");
				return;
			}
		}
	}
}
void GameManager::teststart()
{
	double dead[2] = { 600.0,600.0 };
	clock_t t_start, t_end;
	t_start = clock();
	t_end = clock();
	bool flags = true;
	char type = '\0';
	Position begin;
	Position end;
	vector<Position>points;
	while (flags)
	{
		for (int i = 0; i < 2; i++)
		{
			viewer.setTime(dead[i]);
			record.push_back(board);
			viewer.BoardSet(board);
			viewer.boardOut();
			cout << players[i]->outType() << " turn\n";
			t_start = clock();
			do
			{
				if (players[i]->check(board))
					cout << "You are be checkmated\n";
				cout << "Please entry chess coordinate you wnat to choose(use Algebraic notation)\n";
				cin >> begin;
			} while (!players[i]->Movetest(board, begin));
			t_end = clock();
			if (!this->minustime(dead[i], t_start, t_end))
			{
				cout << players[i > 0 ? 0 : 1]->outType() << " Win\n";
				players[i > 0 ? 0 : 1]->Win();
				this->endGame();
				system("pause");
				return;
			}
			players[i]->outPoint(points);
			viewer.pointSet(points);
			viewer.boardOut();
			t_start = clock();
			do
			{
				cout << "Please entry chess coordinate you wnat to go(use Algebraic notation)\n";
				cin >> end;
			} while (!players[i]->OnMove(board, begin, end));
			t_end = clock();
			if (!this->minustime(dead[i], t_start, t_end))
			{
				cout << players[i > 0 ? 0 : 1]->outType() << " Win\n";
				players[i > 0 ? 0 : 1]->Win();
				this->endGame();
				system("pause");
				return;
			}
			if (players[i]->legalPromte(board, end))
			{
				t_start = clock();
				type = '\0';
				do
				{
					cout << "Please entry chess you want to Promote\n(Q) Queen (B) Bishop (R) Rook (N) Knight\n";
					cin >> type;

				} while (type != 'q' && type != 'Q' && type != 'b' && type != 'B' && type != 'r' && type != 'R' && type != 'n' && type != 'N');
				t_end = clock();
				if (!this->minustime(dead[i], t_start, t_end))
				{
					cout << players[i > 0 ? 0 : 1]->outType() << " Win\n";
					players[i > 0 ? 0 : 1]->Win();
					this->endGame();
					system("pause");
					return;
				}
				players[i]->OnPromote(board, end, type);
			}
			points.clear();
			if (players[i > 0 ? 0 : 1]->Gameresult(board) != 0)
			{
				int result = players[i > 0 ? 0 : 1]->Gameresult(board);
				if (result == 1)
				{
					cout << players[i]->outType() << " Win\n";
					players[i]->Win();
				}
				else if (result == -1)
					cout << "pawn\n";
				else
					cout << "error\n";
				this->endGame();
				system("pause");
				return;
			}
		}
	}
}
void GameManager::save()
{
	viewer.mesSet("Not finnish\n");
}
void GameManager::read()
{
	cout << "Not finish sorry \n ";
}
void GameManager::score()
{
	cout << players[0]->outType() << " : " << players[0]->Wintimes() << "\n";
	cout <<"=           " <<players[1]->outType() << " : " << players[1]->Wintimes() << "\n";
}
bool GameManager::undo()
{
	int temp;
	temp = record.size();
	if (temp < 3)
		return false;
	else
	{
		board = record[temp - 3];
		record.erase(record.end() - 1);
		record.erase(record.end() - 2);
	}
	return true;
}
void GameManager::endGame()
{
	log.push_back(record);
	record.clear();
	board = original;
	swap(players[0], players[1]);
}
void GameManager::logOut()
{
	int x;
	if (log.size() != 0)
	{
		cout << "You have " << log.size() << " data can reply\nPlease choose one\n";
		do
		{
			cin >> x;
		} while (x >= log.size() || x < 0);
		this->logBoardout(x);
	}
	else
	{
		cout << "You have no data to reply";
	}
}
void GameManager::logBoardout(int x)
{
	
	for (int i = 0; i < log[x].size(); i++)
	{
		viewer.BoardSet(log[x][i]);
		viewer.boardOut();
		system("pause");
	}
}
bool GameManager::minustime(double& o_time,clock_t start, clock_t end)
{
	o_time -= (end/1000 - start/1000);
	viewer.setTime(o_time);
	if (o_time > 0)
		return true;
	else
		return false;
}