#include <iostream>
#include <string> 
using namespace std;
class TicTacToe
{
private:
	char board[3][3]; 
public:
	TicTacToe() {}

	//This sets up the game board
	//Variable n is the numbers being set up
	void SetGameBoard()
	{
		int n = 1;
		int i = 0;
		int j = 0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				board[i][j] = '0' + n; 
				n++;
			}
		}
	}
	//Manually creating the game board of tic tac toe using "|"
	void PrintGameBoard()
	{
		int i = 0;
		int j = 0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (j < 2)
				{
					cout << board[i][j] << " | ";
				}
				else
				{
					cout << board[i][j] << endl;
				}
			}
		}
	} 
	//Function that checks player's move.
	//If a spot is filled, it tells the player to choose another spot
	void PlayerTurn(char num, char Player)
	{
		int i = 0;
		int j = 0;
		bool filledSpot = true; 
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (board[i][j] == num)
				{
					board[i][j] = Player; 
					filledSpot = false;
				}
			}
		}
		if (filledSpot == true) { cout << "Please choose an open spot!\n"; }
	} 

	//Checks to see if anyone has won. If not, then it calls to see if the game was a draw
	bool CheckFinalResult(char Player, bool GameOver)
	{
		//List of possible tic tac toe possible wins
		for (int i = 0; i < 3; i++) 
		{
			if (board[i][0] == board[i][1] && board[i][1] ==
				board[i][2]) GameOver = true;
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[0][i] == board[1][i] && board[1][i] ==
				board[2][i]) GameOver = true;
		}

		if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
		{
			GameOver = true;
		}
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
		{
			GameOver = true;
		}
		if (GameOver == true)
		{
			cout << "Player " << Player << " wins!\n\n";
			cout << "Congratulations!\n\n";
		}
		return GameOver;
	}
	//Function for when the game goes to a draw
	bool CheckGameDraw(bool GameOver)
	{
		int n = 1;
		int i = 0;
		int j = 0;
		int counter = 0;
		//Checks to see each spot
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (board[i][j] == '0' + n)
				{
					counter++;
				}
				n++;
			}
		}
		//If there isn't a winner, then it keeps playing
		if (counter < 1)
		{
			cout << "Nobody wins.\n\n";
			GameOver = true;
		}
		return GameOver;
	}
};
int main(){
	//Variables assigned
	bool done = false, GameOver = false;
	char Player = 'O', num;
	cout << "Welcome to Tic Tac Toe!\n";
	TicTacToe myGame;
	myGame.SetGameBoard();
	
	//Do-while loop while game is not done
	do{
		//Keeps switching between X and 0 since its only one "Player" variable
		if (Player == 'X')
		{
			Player = 'O';
		}
		else
		{
			Player = 'X';
		}

		//Prints out the gameboard
		myGame.PrintGameBoard();
		cout << "\nPlayer \"" << Player << "\", please choose a number: ";
		cin >> num;
		cout << "\n";

		//Calls all the functions in order to play 
		myGame.PlayerTurn(num, Player);
		GameOver = myGame.CheckFinalResult(Player, GameOver);
		GameOver = myGame.CheckGameDraw(GameOver);

		//Once its gameover, it'll reset the board and reassign boolean value to false
		if (GameOver == true)
		{
			myGame.SetGameBoard();
			GameOver = false;
		}
	} while (!done);
	return 0;
}