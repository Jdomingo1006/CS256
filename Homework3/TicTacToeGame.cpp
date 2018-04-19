#include <iostream>
using namespace std;

bool DeclareResult(char ch, char gameboard[][3]);
bool isSelectFilledBoard(char gameboard[][3]);
void printGameBoard(char gameboard[][3]);

int main() {
	int rows;
	int columns;

	char gameboard[3][3] =
	{
	{'*', '*', '*'},
	{'*', '*', '*'},
	{'*', '*', '*'}
	};

	cout << "Tic Tac Toe Game" << endl << endl;
	cout << "Game board is a 3 by 3";
	printGameBoard(gameboard);

	while (true) {
		cout << "Player 1: Enter row index (0,1,2) to plot X";
		cin >> rows;
		cout << "Player 1: Enter column (0,1,2)";
		cin >> columns;
		if (gameboard[rows][columns] == '*') {
			gameboard[rows][columns] = 'X';
		}
		printGameBoard(gameboard);
		if (DeclareResult('x', gameboard)) {
			cout << "Player 1 won the game";
			system("pause");
			exit(0);
		}
		else if (isSelectFilledBoard(gameboard)) {
			cout << "Nobody wins";
			system("pause");
			exit(0);
		}

		//Player 2's turn
		cout << "Player 2: Enter row index (0,1,2) to plot O";
		cin >> rows;
		cout << "Player 2L Enter a column (0,1,2) to plot O";
		cin >> columns;
		if (gameboard[rows][columns] == '*') {
			gameboard[rows][columns] = '0';
		}
		printGameBoard(gameboard);
		if (DeclareResult('O', gameboard)) {
			cout << "Player 2 won the game!";
			system("pause");
			exit(0);
		}
		else if (isSelectFilledBoard(gameboard)) {
			cout << "Nobody wins";
			system("pause");
			exit(0);
		}
		system("pause");
		return 0;
	}
}
bool DeclareResult(char ch, char gameboard[][3]) {
		for (int i = 0; i < 3; i++) {
			if (ch == gameboard[i][0] && ch == gameboard[i][1] && ch == gameboard[i][2]){
			return true;
			}
		for (int j = 0; j < 3; j++) {
			if (ch == gameboard[0][j] && ch == gameboard[1][j] && ch == gameboard[2][j]) {
				return true;
			}
		}
		if (ch == gameboard[0][0] && ch == gameboard[1][1] && ch = gameboard[2][2]) {
			return true;
		}
		if (ch == gameboard[0][2] && ch == gameboard[1][1] && ch = gameboard[2][0]) {
			return true;
		}
		return false;

}

bool isSelectFilledBoard(char gameboard[][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (gameboard[i][j] == '*') {
				return false;
			}
		}
	}
	return true;

}
void printGameBoard(char gameboard[][3]) {
	cout << "\n------------";
	for (int i = 0; i < 3; i++) {
		cout << "|";
		for(int j = 0; j < 3; j++) {
			cout << gameboard[i][j] << "l";
		}
		cout << "\n------------";
	}
}


