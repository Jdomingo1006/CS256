#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

/************Account Class being***************/
class Account {
protected:
	double interest;
	double charge;
	virtual void calcInt();
public:
	double balance;
	int deposits;
	int withdrawal;
	Account();
	Account(double, double);
	virtual void depositCount(double inputDeposit);
	virtual int withdrawCount(double inputWithdraw);
	virtual double monthlyProc();
	int getWithdrawalCount();
	int getDepositCount();
	double getBalance();

};
Account::Account() {
	balance = 0.00;
	deposits = 0;
	withdrawal = 0;
	interest = 0.00;
	charge = 0.00;
}
Account::Account(double inputBalance, double inputInterest) {
	balance = inputBalance;
	deposits = 0;
	withdrawal = 0;
	interest = inputInterest;
	charge = 0;
}
void Account::calcInt() {
	balance += (interest / 12) * balance;
}
void Account::depositCount(double inputDeposit) {
	balance += inputDeposit;
	deposits++;
}

int Account::withdrawCount(double inputDeposit) {
	balance -= inputDeposit;
	withdrawal++;
	return withdrawal;
}
double Account::monthlyProc() {
	calcInt();
	balance -= charge;
	withdrawal = 0;
	deposits = 0;
	double total = charge;
	charge = 0;
	return total;
}
int Account::getWithdrawalCount() { return withdrawal; }
int Account::getDepositCount() { return deposits; }
double Account::getBalance() { return balance; }
/****************Account Class Finished***************/

/**************Savings Account Class***************/
class SavingsAccount : public Account {
protected:
	bool stateOfAccount;
public:
	SavingsAccount() :Account() {
		stateOfAccount = false;
	}
	SavingsAccount(double inputBalance, double inputInterest) :Account(inputBalance, inputInterest) {}
	int withdraw(double);
	void deposit(double);
	double monthlyProc();
};
int SavingsAccount::withdraw(double inputAmount) {
	if (stateOfAccount == 0)
		cout << "Sorry, you will not be able to withdraw, balance too low." << endl;
	if (stateOfAccount) {
		cout << "saving withdrawl" << endl;
		Account::withdrawCount(inputAmount);
	}
	if (balance < 25)
		stateOfAccount = 0;
	return withdrawal;
}
void SavingsAccount::deposit(double inputAmount) {
	if (!stateOfAccount && (balance + inputAmount) >= 25) {
		stateOfAccount = true;
		Account::depositCount(inputAmount);
	}
}
double SavingsAccount::monthlyProc() {
	if (withdrawal > 4) {
		charge += withdrawal - 4;
	}
	double total = Account::monthlyProc();
	stateOfAccount = balance >= 25;
	return Account::monthlyProc();
}
/***************Savings Account Class ends***********/

/************Checking Account Class*************/
class Checking : public Account {
public:
	Checking() :Account() {};
	Checking(double inputBalance, double inputInterest) :Account(inputBalance, inputInterest) {};
	int withdraw(double inputAmount);
	void deposit(double inputAmount);
	double monthlyProc();
};
int Checking::withdraw(double inputAmount) {
	double newBalance = balance - inputAmount;
	if (newBalance < 0) {
		charge = charge - 15;
		return -1;
	}
	else {
		balance = newBalance;
		withdrawal++;
	}
	return 1;
}
void Checking::deposit(double inputAmount) {
	Account::depositCount(inputAmount);
}
double Checking::monthlyProc() {
	charge += 5 + (0.1*withdrawal);
	cout << "Service charge: " << charge << endl;
	return Account::monthlyProc();
}
/***********End of Checking Class*************/

/***********Print Menu*************/
void PrintMenu(SavingsAccount& userSavings, Checking& userCheckings) {
	int userChoice;
	double userDeposit, userWithdraw;
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
	case 2:
		cout << "Chosen: Deposit to your Checkings Account." << endl;
		cout << "Enter amount to deposit: $";
		cin >> userDeposit;
		userCheckings.deposit(userDeposit);
		cout << "Your balance: $" << userCheckings.balance << endl;
	case 3:
		cout << "Chosen: Withdraw from your Savings Account" << endl;
		cout << "Enter amount to withdraw: $" << endl;
		cin >> userWithdraw;
		userSavings.withdraw(userWithdraw);
		cout << "Your balance: $" << userSavings.balance << endl;
	case 4:
		cout << "Chosen: Withdraw from your Checkings Account" << endl;
		cout << "Enter amount to withdraw: $" << endl;
		cin >> userWithdraw;
		userCheckings.withdraw(userWithdraw);
		cout << "Your balance: $" << userCheckings.balance << endl;
	case 5:
		cout << "Chosen: Display information" << endl;
		cout << "Savings Account information:" << endl;
		cout << "Withdrawal count: " << userSavings.withdrawal << endl;
		cout << "Deposit count: " << userSavings.deposits << endl;
		userSavings.monthlyProc();
		cout << "Total balance: $" << userSavings.balance << endl;

		cout << "\n\nCheckings Account Information:" << endl;
		cout << "Withdrawal count: " << userCheckings.withdrawal << endl;
		cout << "Deposit count: " << userCheckings.deposits << endl;
		userCheckings.monthlyProc();
		cout << "Total balance: $ " << userCheckings.balance << endl;
	case 6:
		cout << "Thank you for visiting the bank." << endl;
		break;

	}
}


int main() {
	//cout << "Enter Saving Information: " << endl;
	SavingsAccount userSavings;
	cout << endl;
	//cout << "Enter Checking information: " << endl;
	Checking userCheckings;
	cout << endl;
	PrintMenu(userSavings, userCheckings);


	return 0;
}
