/*
*James Domingo
*CS256
*May 10th, 2018
*/
#include "stdafx.h"
#include <iostream> 
#include <ctime>
using namespace std;

//Dice class
class Dice {
public:
	int side;
	Dice() {
		side = 6;
	}
	//Roll function rolls a random number from 1 to 6
	int roll(){
		int dice = (rand() % side) + 1;
		return dice;
	}
};


int main() {
	srand(time(0));
	Dice dice1, dice2;
	//Original scores
	int playerScore = 0; 
	int computerScore = 0;

	while(true){
		int userAnswer;
		cout << "Roll dice? (Enter 1 to roll or Enter 2 to quit)" << endl;
		cin >> userAnswer;
		if (userAnswer != 1) {
			break;
		}
		//Original score
		computerScore += dice1.roll() + dice2.roll();
		playerScore += dice1.roll() + dice2.roll();

		if (playerScore > 21) {
			cout << "You went over 21..." << endl;
			break;
		}
		cout << "Your current score is: " << playerScore << endl;
	};
	
	cout << "\nGame has finished." << endl;
	cout << "Your total: " << playerScore << endl;
	cout << "Computer total: " << computerScore << endl;
	if (playerScore <= 21 && playerScore == computerScore) {
		cout << "It was a tie!" << endl;;
	}
	else if (playerScore <= 21 && playerScore > computerScore) {
		cout << "You have won!" << endl;
	}
	else {
		cout << "You have lost!" << endl;;
	}

	return 0;
}