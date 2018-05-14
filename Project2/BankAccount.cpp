#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


/**************Savings Account Class***************/
class SavingsAccount:public Account {
protected:
	bool statOfAccount;
public:
	SavingsAccount() :Account() {
		statOfAccount = false;
	}
	SavingsAccount(double inputBalance, double inputInterest) :Account(inputBalance, inputInterest) {}
	int withdraw(double);
	void deposit(double);
	double monthlyProc();
};

int SavingsAccount::withdraw(double inputAmount) {
	if (stateOfAccount)
		Account::withdrawCount(amount);
	else
		return -1;
	stateOfAccount = balance >= 25;
	if (!stateofAccount)
		return -2;
	else
		return 1;
}
void SavingsAccount::deposit(double inputAmount) {
	if (!stateOfAccount && (balance + amount) >= 25) {
		stateOfAccount = true;
		Account::depositCount(amount);
	}
}
double SavingsAccount::monthlyProc() {
	if (withdrawCount > 4) {
		charge += withdraw;
	}
	double total = Account::monthlyProc();
	status = balance >= 25;
	return total;
}


/***************Savings Account Class ends***********/



/************Account Class being***************/
class Account {
protected:
	double balance;
	int deposit;
	int withdrawal;
	double interest;
	double charge;
	virtual void calcInt();
public:
	//Constructors
	Account();
	Account(double, double);

	//Virtual functions
	virtual void depositCount(double inputDeposit);
	virtual int withdrawCount(double inputWithdraw);
	virtual double monthlyProc();

	//Getters for withdrawals/deposit/balance
	int getWithdrawalCount();
	int getDepositCount();
	double getBalance();

};
	Account::Account() {
	balance = 0.00;
	deposit = 0;
	withdrawal = 0;
	interest = 0.00;
	charge = 0.00;
}
	Account::Account(double inputBalance, double inputInterest) {
	balance = inputBalance;
	deposit = 0;
	withdrawal = 0;
	interest = inputInterest;
	charge = 0;
}
	void Account::calcInt() {
		balance += (interest / 12) * balance;
}
	void Account::depositCount(double inputDeposit) {
	balance += inputDeposit;
	deposit++;
}

	int Account::withdrawCount(double inputDeposit) {
	balance -= inputDeposit;
	withdrawal++;
}
	double Account::monthlyProc() {
	calcInt();
	balance -= charge;
	withdrawal = 0;
	deposit = 0;
	double total = charge;
	charge = 0;
	return total;
}
//Getters - returns withdrawal/deposit/balance numebrs
int Account::getWithdrawalCount() { return withdrawal; }
int Account::getDepositCount() { return deposit; }
double Account::getBalance() { return balance; }
/****************Account Class Finished***************/







/*************Checking Account Class*************/
class Checking :public Account {
public:
	Checking() :Account() {};
	Checking(double inputBalance, double inputInterest) :Account(inputBalance, inputInterest) {};
	int withdraw(double inputAmount);
	void deposit(double inputAmount);
	double monthlyProc();
};
//Checkings.cpp
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
	Account::deposit(inputAmount);
}
double Checking::monthlyProc() {
	charge += 5 + (0.1*withdrawal);
	return Account::monthlyProc;
}
/***********End of Checking Class*************/


int main() {
	int userChoice;
	cout << "------Bank Account Menu------" << endl;
	cout << "1. Deposit into Savings Account" << endl;
	cout << "2. Deposit into Checkings Account" << endl;
	cout << "3. Withdraw from Savings Account" << endl;
	cout << "4. Withdraw from Checkings Account" << endl;
	cout << "5. Display bank account information" << endl;
	cout << "6. Exit from the program" << endl;
	cout << "Please choose a number from 1 to 6." << endl;
	cin >> userChoice;
	while (userChoice > 6 || userChoice < 1) {
		cout << "Please enter a number from 1 to 6";
		cin >> userChoice;
	}
	return 0;
}