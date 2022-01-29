#include "GameManager.h"
int main()
{
	GameManager game;
	char type;
	while (1)
	{
		cout << "=================================================================================================\n";
		cout << "=                     ==      =   =   ======  ======       ====                                 =\n";
		cout << "=                   =    =    =   =   =       =          =      =                               =\n";
		cout << "=                   =         =====   ======  ======       ==                                   =\n";
		cout << "=                   =    =    =   =   =       =         =     =                                 =\n";
		cout << "=                     ==      =   =   ======  ======     ====                                   =\n";
		cout << "=================================================================================================\n";
		cout << "=  Grade--> ";
		game.score();
		cout << "=  Choose the mode you want (T) Test mode (N) Normal mode (R) Read file (L) Log Reoly (Q) quit  =\n";
		cin >> type;
		if (type == 'T' || type == 't')
			game.teststart();
		if (type == 'N' || type == 'n')
			game.start();
		if (type == 'R' || type == 'r')
			game.read();
		if (type == 'L' || type == 'l')
			game.logOut();
		if (type == 'Q' || type == 'q')
			break;
		system("cls");
	}
	
	
}