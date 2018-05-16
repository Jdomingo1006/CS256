#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

/************Account Class being***************/
class Account {
public:
	double interest = 0.0;
	double charge = 0.0;
	double balance = 0.0;
	int deposits = 0;
	int withdrawal = 0;

	Account();
	virtual void calcInt();
	virtual void depositCount(double inputDeposit);
	virtual void withdrawCount(double inputWithdraw);
	virtual void monthlyProc();
};
Account::Account() {
	cout << "Enter balance: $";
	cin >> balance;
	cout << "Enter interest rate: ";
	cin >> interest;
}
void Account::depositCount(double inputDeposit) {
	balance += inputDeposit;
	deposits++;
}
void Account::withdrawCount(double inputDeposit) {
	balance -= inputDeposit;
	withdrawal++;
}
void Account::calcInt() {
	double monthInterestRate = (interest / 12);
	double monthInterest = balance * monthInterestRate;
	balance = balance + monthInterest;
}

void Account::monthlyProc() {
	calcInt();
	balance -= charge;
	withdrawal = 0;
	deposits = 0;
	charge = 0;
}
/****************Account Class Finished***************/

/**************Savings Account Class***************/
class SavingsAccount : public Account {
protected:
	bool stateOfAccount;
public:
	void withdraw(double inputAmount);
	void deposit(double inputAmount);
	void monthlyProc();
};
void SavingsAccount::withdraw(double inputAmount) {
	if (stateOfAccount == 0) {
		cout << "Unable to withdraw. " << endl;
		cout << "Reason: Balance too low." << endl;
	}
	if (stateOfAccount) {
		cout << "Withdraw confirmed" << endl;
		Account::withdrawCount(inputAmount);
	}
	if (balance < 25)
		stateOfAccount = 0;
}
void SavingsAccount::deposit(double inputAmount) {
	if ((balance + inputAmount) > 25) {
		stateOfAccount = 1;
		cout << "Deposit saved." << endl;
		Account::depositCount(inputAmount);
	}
}
void SavingsAccount::monthlyProc() {
	if (withdrawal > 4) {
		charge = withdrawal - 4;
	}
	if (balance < 25)
		stateOfAccount = 0;
	cout << "Cost of service charge: $" << charge << endl;
	Account::monthlyProc();
}
/***************Savings Account Class ends***********/

/************Checking Account Class*************/
class Checking : public Account {
public:
	void withdraw(double inputAmount);
	void deposit(double inputAmount);
	void monthlyProc();
};
void Checking::withdraw(double inputAmount) {
	if ((balance - inputAmount) < 0) {
		balance = balance - 15;
		charge = charge + 15;
	}
	Account::withdrawCount(inputAmount);
}
void Checking::deposit(double inputAmount) {
	Account::depositCount(inputAmount);
}
void Checking::monthlyProc() {
	charge += 5 + (0.1*withdrawal);
	cout << "Charge of service: " << charge << endl;
	Account::monthlyProc();
}
/***********End of Checking Class*************/

/***********Print Menu*************/
void PrintMenu(SavingsAccount& userSavings, Checking& userCheckings) {
	int userChoice;
	double userDeposit, userWithdraw;
	bool done = false;
	do {
		cout << "\n\n" << endl;
		cout << "Welcome to the bank!" << endl;
		cout << "1. Deposit to your Savings Account" << endl;
		cout << "2. Deposit to your Checkings Account" << endl;
		cout << "3. Withdraw from your Savings Account" << endl;
		cout << "4. Withdraw from your Checkings Account" << endl;
		cout << "5. Display Account Information" << endl;
		cout << "6. Exit" << endl;
		cout << "Please choose a number from 1 to 6" << endl;
		cin >> userChoice;
		if (userChoice < 1 || userChoice > 6) {
			do {
				cout << "\n\n" << endl;
				cout << "Please enter a nnumber from 1 to 6..." << endl;
				cout << "1. Deposit to your Savings Account" << endl;
				cout << "2. Deposit to your Checkings Account" << endl;
				cout << "3. Withdraw from your Savings Account" << endl;
				cout << "4. Withdraw from your Checkings Account" << endl;
				cout << "5. Display Account Information" << endl;
				cout << "6. Exit" << endl;
				cin >> userChoice;
			} while (userChoice < 1 || userChoice > 6);
		};
		switch (userChoice) {
		case 1:
			cout << "Chosen: Deposit to your Savings Account." << endl;
			cout << "Enter amount to deposit: $";
			cin >> userDeposit;
			userSavings.deposit(userDeposit);
			cout << "Your balance: $" << userSavings.balance << endl;
			break;
		case 2:
			cout << "Chosen: Deposit to your Checkings Account." << endl;
			cout << "Enter amount to deposit: $";
			cin >> userDeposit;
			userCheckings.deposit(userDeposit);
			cout << "Your balance: $" << userCheckings.balance << endl;
			break;
		case 3:
			cout << "Chosen: Withdraw from your Savings Account" << endl;
			cout << "Enter amount to withdraw: $" << endl;
			cin >> userWithdraw;
			userSavings.withdraw(userWithdraw);
			cout << "Your balance: $" << userSavings.balance << endl;
			break;
		case 4:
			cout << "Chosen: Withdraw from your Checkings Account" << endl;
			cout << "Enter amount to withdraw: $" << endl;
			cin >> userWithdraw;
			userCheckings.withdraw(userWithdraw);
			cout << "Your balance: $" << userCheckings.balance << endl;
			break;
		case 5:
			cout << "Chosen: Display information" << endl;
			cout << "\n\n" << endl;
			cout << "-----------Savings Account-----------" << endl;
			cout << "Savings Account information:" << endl;
			cout << "Withdrawal count: " << userSavings.withdrawal << endl;
			cout << "Deposit count: " << userSavings.deposits << endl;
			userSavings.monthlyProc();
			cout << "Total balance: $" << userSavings.balance << endl;

			cout << "\n\n" << endl;
			cout << "-----------Checkings Account----------- " << endl;
			cout << "Withdrawal count: " << userCheckings.withdrawal << endl;
			cout << "Deposit count: " << userCheckings.deposits << endl;
			userCheckings.monthlyProc();
			cout << "Total balance: $ " << userCheckings.balance << endl;
			break;
		case 6:
			cout << "Thank you for visiting the bank." << endl;
			done = true;
			break;
		}
	} while (!done);
}


int main() {
	cout << "-----------Savings Account-----------" << endl;
	SavingsAccount userSavings;
	cout << endl;
	cout << "-----------Checkings Account----------- " << endl;
	Checking userCheckings;
	cout << endl;

	PrintMenu(userSavings, userCheckings);
	return 0;
}