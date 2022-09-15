//Joglul Shantau
// Mac 125 Proff Muller
// TTT lab


#include <iostream>
#include <string>

using namespace std;

const int ROWS = 3;
const int Collumns = 3;
int row;
int col;
int winner = 0;
bool gameover = false;
char board[Collumns][ROWS] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
string NameofPlayer1;
string NameofPlayer2;

void printboard()
{
	cout << board[0][2] << " | " << board[1][2] << " | " << board[2][2] << endl;
	cout << "__________" << endl;
	cout << board[0][1] << " | " << board[1][1] << " | " << board[2][1] << endl;
	cout << "__________" << endl;
	cout << board[0][0] << " | " << board[1][0] << " | " << board[2][0] << endl;
}

void movex()
{
	cout << "Column:";
	cin >> col;
	cout << endl << "Row:";
	cin >> row;
	board[col][row] = 'X';
}

void moveo()
{
	cout << "Column:";
	cin >> col;
	cout << endl << "Row:";
	cin >> row;
	board[col][row] = 'O';
}

void checkwinner()
{
	if (gameover == false)
	{
		winner = -1;
	}
	else if (board[0][2] == board[1][2] == board[2][2])
	{
		if(board[0][2] == 'X')
		{
			winner = 1;
		}
		else
		{
			winner = 2;
		}
	}
	else if (board[0][1] == board[1][1] == board[2][1])
	{
		if(board[0][1] == 'X')
		{
			winner = 1;
		}
		else
		{
			winner = 2;
		}
	}
	else if (board[0][0] == board[1][0] == board[2][0])
	{
		if(board[0][0] == 'X')
		{
			winner = 1;
		}
		else
		{
			winner = 2;
		}
	}
	else if (board[0][0] == board[0][1] == board[0][2])
	{
		if(board[0][0] == 'X')
		{
			winner = 1;
		}
		else
		{
			winner = 2;
		}
	}
	else if (board[1][0] == board[1][1] == board[1][2])
	{
		if(board[1][0] == 'X')
		{
			winner = 1;
		}
		else
		{
			winner = 2;
		}
	}
	else if (board[2][0] == board[2][1] == board[2][2])
	{
		if(board[2][0] == 'X')
		{
			winner = 1;
		}
		else
		{
			winner = 2;
		}
	}
	else if (board[0][2] == board[1][1] == board[2][0])
	{
		if(board[0][2] == 'X')
		{
			winner = 1;
		}
		else
		{
			winner = 2;
		}
	}
	else if (board[0][0] == board[1][1] == board[2][2])
	{
		if(board[0][0] == 'X')
		{
			winner = 1;
		}
		else
		{
			winner = 2;
		}
	}
	else if (gameover == true)
	{
		winner = 5;
	}
	system("PAUSE");
}

void checkgameover()
{
	int otherc = 5;
	for(int c = 0; c <= 2; c++)
	{
		for(int r = 0; r <= 2; r++)
		{
			if(board[c][r] == ' ')
			{
				gameover = false;
				c = 5;
				r = 5;
				otherc = 10;
			}
		}
	}
	if(otherc == 5)
	{
		gameover == true;
	}
	else if(otherc == 10)
	{

	}
}

int main()
{
	cout << "Welcome Professor !" << endl << endl;
	cout << "Player 1, Type your name:";
	cin >> NameofPlayer1;
	cout << "Hello " << NameofPlayer1 << ", you are X." << endl;
	cout << "Player 2, Type your name:";
	cin >> NameofPlayer2;
	cout << "Hello " << NameofPlayer2 << ", you are O." << endl;
	system("PAUSE>nul");
	cout << "So " << NameofPlayer1 << ", its your turn." << endl;
	cout << "To move, Type the column you prefer and press return." << endl << "Then Type the row you prefer and press return." << endl;
	cout << "The bottom left is Col:0 and Row:0, far left middle is col:0 Row:1, top left is col:0 Row:2, the middle is Col:1 and Row:1,middle top square is Col:1 Row:2, middle row bottom square is Col:1 Row:0 and the far right middle Col:2 Row:1 far right bottom Col:2 Row:0 top right is Col:2 and Row:2" << endl;
	printboard();
	movex();
	printboard();
	cout << endl << "And now it's " << NameofPlayer2 << "'s turn." << endl;
	moveo();
	printboard();
	for(int i = winner; i <= 1; i++)
	{
		cout << endl << "X turn" << endl;
		movex();
		printboard();
		cout << endl << "O turn" << endl;
		moveo();
		printboard();
		checkgameover();
		checkwinner();
		if(winner == 5)
		{
			cout << "Hah we both suck. Nobody wins.";
			system("PAUSE>nul");
		}
		else if (winner == 1)
		{
			cout << "Good job you filthy animal " << NameofPlayer1 << "! X wins!" << endl;
			system("PAUSE>nul");
		}
		else if (winner == 2)
		{
		cout << "Good job you filthy animal " << NameofPlayer2 << "! O wins!" << endl;
		system("PAUSE>nul");
	}
}
}
