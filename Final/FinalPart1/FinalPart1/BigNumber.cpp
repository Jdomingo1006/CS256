/*
* James Domingo
* CS256
* May 31 2018
*/

#include "stdafx.h"
#include <iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

	//BigNumbers class
class BigNumbers {
public:
	//variables
	int sum, difference, product, mod;
	double quotient;
	vector<long long> vector;
public:
	//Addition function
	void ADD(int inputNum1, int inputNum2) {
		vector.push_back(inputNum1);
		vector.push_back(inputNum2);
		sum = inputNum1 + inputNum2;
		cout << "Sum of" << inputNum1 << " and " << inputNum2 << " is " << sum << endl;
	}
	//Subtract function
	void SUBTRACT(int inputNum1, int inputNum2) {
		vector.push_back(inputNum1);
		vector.push_back(inputNum2);
		difference = inputNum1 - inputNum2;
		cout << "Difference of " << inputNum1 << " and " << inputNum2 << " is " << difference << endl;
	}
	//Product function
	void PRODUCT(int inputNum1, int inputNum2) {
		vector.push_back(inputNum1);
		vector.push_back(inputNum2);
		product = inputNum1 * inputNum2;
		cout << "Product of " << inputNum1 << " and " << inputNum2 << " is " << product << endl;
	}
	//Quotient function
	void QUOTIENT(int inputNum1, int inputNum2) {
		vector.push_back(inputNum1);
		vector.push_back(inputNum2);
		quotient = inputNum1 / inputNum2;
		cout << "Quotient of " << inputNum1 << " and " << inputNum2 << " is " << product << endl;
	}
	//Module function
	void MODULE(int inputNum1, int inputNum2) {
		vector.push_back(inputNum1);
		vector.push_back(inputNum2);
		mod = inputNum1 % inputNum2;
		cout << "Module of " << inputNum1 << " and " << inputNum2 << " is " << mod << endl;
	}
};

int main() {
	BigNumbers BigNum;
	BigNum.ADD(10, 1);
	BigNum.SUBTRACT(10, 23);
	BigNum.PRODUCT(200, 5);
	BigNum.QUOTIENT(40, 5);
	BigNum.MODULE(100, 23);
}

